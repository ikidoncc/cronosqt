#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class WebServer : public QTcpServer
{
public:
    explicit WebServer(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr handle) override;
};

#endif
