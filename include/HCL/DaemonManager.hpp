#pragma once

#ifndef HCL_DAEMONMANAGER_HPP
#define HCL_DAEMONMANAGER_HPP

/**
 * This file is a part of Haont Common Library
 * It contains a DaemonManager class definition
 *
 * DaemonManager is a class providing daemonization routines
 * Uses DBus for daemon controlling
 *
 * Usage:
 * #include <HCL/DaemonManager.hpp>
 */

// Qt
#include <QCoreApplication>
#include <QMap>
#include <QObject>
#include <QString>
#include <QStringList>
#include <QThread>
#include <QVariant>
#include <QPair>

namespace Hcl
{
    class DaemonManager;
}

// HCL
#include "DaemonMode.hpp"
#include "DaemonWorker.hpp"

namespace Hcl
{
    class DaemonManager : public QObject
    {
        Q_OBJECT

        private:
            int    f_argc;
            char** f_argv;
            int    f_result;

            DaemonWorker*     f_daemonWorker;
            QThread           f_daemonThread;
            QCoreApplication* f_qCoreApplication;

            bool daemonize();
            void defaultConfig();
            void parseArgs(int, char**);

        public:
            QMap<QString, QVariant> f_config;

            explicit DaemonManager(int, char**, DaemonWorker*);
            virtual ~DaemonManager();

            int exec();
    };
}

#endif // HCL_DEAMONMANAGER_HPP
