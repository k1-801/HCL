#ifndef HCL_DAEMONWORKER_H
#define HCL_DAEMONWORKER_H


namespace Hcl {

class DaemonWorker : public QObject
{
    Q_OBJECT
public:
    explicit DaemonWorker(QObject *parent = 0);

signals:

public slots:
};

} // namespace Hcl

#endif // HCL_DAEMONWORKER_H
