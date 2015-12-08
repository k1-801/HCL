#pragma once

#ifndef HCL_DAEMONWORKER_HPP
#define HCL_DAEMONWORKER_HPP

/**
  * This file is a part of Haont Common Library (HCL) [Daemon module]
  *
  * @project HCL
  * @author k1-801
  */

// Qt
#include <QObject>

namespace Hcl
{
    class DaemonWorker;
}

// HCL
#include "DaemonManager.hpp"
#include "DaemonMode.hpp"

namespace Hcl
{
    class DaemonWorker : public QObject
    {
        Q_OBJECT

        protected:
            DaemonManager* f_daemonManager;
            bool checkMode(DaemonMode);
            void lockMode();
            void setMode(DaemonMode);

        public:
            explicit DaemonWorker();
            virtual ~DaemonWorker();

            static QString& getName();
            void setManager(DaemonManager*);
            virtual void help();
            virtual int parseArg(int, char**);

        signals:
            void stop(int);

        public slots:
            virtual void exec();
    };
}

#endif // HCL_DAEMONWORKER_HPP
