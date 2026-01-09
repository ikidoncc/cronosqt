#ifndef WEBSOCKETSERVER_H
#define WEBSOCKETSERVER_H

#include <QObject>
#include <QWebSocketServer>
#include <QWebSocket>
#include <QList>

class WebSocketServer : public QObject
{
    Q_OBJECT

public:
    explicit WebSocketServer(QObject *parent = nullptr);
    void broadcast(const QString &message);

private slots:
    void onNewConnection();
    void onClientDisconnected();

private:
    QWebSocketServer *server;
    QList<QWebSocket*> clients;
};

#endif // WEBSOCKETSERVER_H
