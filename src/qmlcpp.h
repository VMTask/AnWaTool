#ifndef QMLCPP_H
#define QMLCPP_H
#include <string>
#include <QObject>

class QmlCpp : public QObject
{
    Q_OBJECT
public:
    explicit QmlCpp(QObject *parent = nullptr);
    Q_INVOKABLE void OpenAdbCommandLine();
    Q_INVOKABLE std::string command_popen(const char *cmd);
    Q_INVOKABLE QString qstring_command_popen(QString command);
    Q_INVOKABLE void getAndroidDeviceStatus();
    Q_INVOKABLE void threadStart();
    Q_INVOKABLE QString getAndroidDeviceStatus_qstr();
    Q_INVOKABLE QString imageurl();
private:
    const char *cmd;
    QString command;
    bool connected_status;
signals:

};


#endif // QMLCPP_H
