#include "websocketserver.h"

WebSocketServer::WebSocketServer(QObject *parent)
    : QObject(parent)
{
    server = new QWebSocketServer("CronosWebSocket",
                                  QWebSocketServer::NonSecureMode,
                                  this);

    server->listen(QHostAddress::Any, 8080);

    connect(server, &QWebSocketServer::newConnection,
            this, &WebSocketServer::onNewConnection);
}

void WebSocketServer::onNewConnection()
{
    QWebSocket *client = server->nextPendingConnection();
    clients.append(client);

    connect(client, &QWebSocket::disconnected,
            this, &WebSocketServer::onClientDisconnected);
}

void WebSocketServer::onClientDisconnected()
{
    QWebSocket *client = qobject_cast<QWebSocket*>(sender());
    clients.removeAll(client);
    client->deleteLater();
}

void WebSocketServer::broadcast(const QString &message)
{
    for (QWebSocket *c : clients)
    {
        c->sendTextMessage(message);
    }
}
