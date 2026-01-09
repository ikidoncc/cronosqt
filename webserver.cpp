#include "webserver.h"

WebServer::WebServer(QObject *parent)
    : QTcpServer(parent)
{
    listen(QHostAddress::Any, 8080);
}

void WebServer::incomingConnection(qintptr handle)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(handle);

    QString html =
        R"(
HTTP/1.1 200 OK
Content-Type: text/html

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<style>
body {
    margin: 0;
    background: transparent;
}
#timer {
    font-size: 64px;
    color: white;
    font-family: Arial;
    font-weight: bold;
}
</style>
</head>
<body>
<div id="timer">00:00:00</div>

<script>
let ws = new WebSocket("ws://localhost:8080");

ws.onmessage = function(event) {
    document.getElementById("timer").textContent = event.data;
};
</script>

</body>
</html>
)";

    socket->write(html.toUtf8());
    socket->disconnectFromHost();
}
