#include "../include/HCL/DaemonWorker.hpp"

/**
 * This file is a part of Haont Common Library (HCL)
 *
 * @project HCL
 * @author k1-801
 */

// HCL
#include "../include/HCL/DaemonManager.hpp"
#include "../include/HCL/Exception.hpp"

namespace Hcl
{
    DaemonWorker::DaemonWorker() : QObject(){}
    DaemonWorker::~DaemonWorker(){}

    QString& DaemonWorker::getName()
    {
        static QString name = "Unnamed_HCL_Daemon";
        return name;
    }

    void DaemonWorker::lockMode()
    {
        if(f_daemonManager->f_config["DaemonModeForced"].toBool())
            throw Exception(tr("Daemon mode is already set"));
        f_daemonManager->f_config["DaemonModeForced"] = true;
    }

    void DaemonWorker::setMode(DaemonMode mode)
    {
        if(checkMode(mode))
        {
            lockMode();
            f_daemonManager->f_config["DaemonMode"] = (qulonglong)mode;
        }
    }

    bool DaemonWorker::checkMode(DaemonMode mode)
    {
        return ((f_daemonManager->f_config["ModeMask"].toULongLong() & mode) == mode);
    }

    void DaemonWorker::setManager(DaemonManager* man)
    {
        f_daemonManager = man;
    }

    int DaemonWorker::parseArg(int, char** argv)
    {
        QString curr = *argv;
        if(curr == "--help"    ){setMode(HCL_HELP    ); return 1;}
        if(curr == "--daemon"  ){setMode(HCL_DAEMON  ); return 1;}
        if(curr == "--nodaemon"){setMode(HCL_NODAEMON); return 1;}
        if(curr == "--stop"    ){setMode(HCL_STOP    ); return 1;}
        if(curr == "--restart" ){setMode(HCL_RESTART ); return 1;}
        return 0;
    }

    void DaemonWorker::exec(){}
    void DaemonWorker::help()
    {
        printf("\
HCL Daemonization module\
Help is not implemented in this daemon\
Please contact developer.");
    }
}

