#include "../include/HCL/DaemonManager.hpp"

// C
#include <signal.h>
#include <unistd.h>
// Qt
#include <QTemporaryFile>
#include <QtDBus/QtDBus>
// HCL
#include "../include/HCL/Exception.hpp"

#ifndef __linux
# ifdef _WIN32
#  error "HCL Daemonization module will not work on Windows, aborting"
# else
#  warning "HCL Daemonization module is designed for running on Linux OS family and may misbehave"
# endif // _WIN32
#endif

namespace Hcl
{
    DaemonManager::DaemonManager(int argc, char** argv, DaemonWorker* worker)
    {
        f_argc = argc;
        f_argv = argv;
        f_daemonWorker = worker;
        worker->setManager(this);
        defaultConfig();
    }

    DaemonManager::~DaemonManager(){}

    bool DaemonManager::daemonize()
    {
        pid_t pid = fork();
        if(pid < 0) // Failure
        {
            throw Hcl::Exception("Failed to start Daemon");
        }
        if(pid != 0) // Success, daemon runner should exit
        {
            return false;
        }

        // Continue fixig daemon

        // Continue running after terminal closing/disconnect
        struct sigaction siga;
        siga.sa_handler = SIG_IGN;
        sigemptyset(&siga.sa_mask);
        if(sigaction(SIGHUP, &siga, 0) < 0)
            throw Hcl::Exception("Failed to setup SIGHUP ignoration");

        // Move to ROOT to prevent errors on disk device unmounting
        if(chdir("/") < 0)
            throw Hcl::Exception("chdir(\"/\") failed");

        // Safely disable manual IO to prevent unexpected daemon failure
        if(f_config["NoOutut"].toBool())
        {
            freopen("/dev/null", "r", stdin);
            freopen("/dev/null", "w", stdout);
            freopen("/dev/null", "w", stderr);
        }

        return true;
    }

    void DaemonManager::parseArgs(int argc, char** argv)
    {
        int t = 0;
        for(int i = 1; i < argc; i += t)
        {
            t = f_daemonWorker->parseArg(i, argv+i);
            if(!t)
            {
                throw Exception(tr("Unknown option: %1").arg(*(argv + i)));
            }
        }
    }

    int DaemonManager::exec()
    {
        try
        {
            parseArgs(f_argc, f_argv);
            int mode = f_config["DaemonMode"].toULongLong();
            printf("DEBUG: mode=%i\n", mode);
            if(mode == HCL_HELP) // !mode
            {
                f_daemonWorker->help();
            }
            f_qCoreApplication = new QCoreApplication(f_argc, f_argv);
            if(!(mode & HCL_DAEMON) || daemonize()) // Daemonization is only done if mode has HCL_DAEMON flag
            {
                DaemonWorker* dw = f_daemonWorker;
                dw->moveToThread(&f_daemonThread);
                connect(&f_daemonThread, &QThread::started , [dw](){ dw->exec(); }); // Lambda to hold virtual slot
                connect(&f_daemonThread, &QThread::finished, dw, &DaemonWorker::deleteLater); // Stop QApplication when f_thread has stopped
                connect(&f_daemonThread, &QThread::finished, f_qCoreApplication, &QCoreApplication::quit); // Stop QApplication when f_thread has stopped
                f_daemonThread.start();
                f_qCoreApplication->exec();
                return f_daemonThread.wait();
            }
        }
        catch(Exception& e)
        {
            printf("Exception: %s\n", e.getText().toUtf8().data());
        }
        catch(...)
        {
            printf("Unknown exception\n");
        }
        return false;
    }

    // Virtual empty

    void DaemonManager::defaultConfig()
    {
        f_config["Mode"      ] = HCL_DAEMON;
        f_config["ModeMask"  ] = 0x0F;
        f_config["ModeForced"] = false;
    }
}

