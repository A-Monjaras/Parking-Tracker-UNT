/*
#include <QObject>
#include <QList>
#include <QWebSocketServer>
#include <QWebSocket>

class WebSocketServer : public QObject
{
    Q_OBJECT

public:
    explicit WebSocketServer(QObject *parent = nullptr);
    ~WebSocketServer();

    bool start(int port);
    void stop();

signals:
         // Define signals for broadcasting real-time updates
         // as per your application's requirements.

private slots:
    void onNewConnection();
    void processTextMessage(const QString &message);
    void socketDisconnected();

private:
    QWebSocketServer *m_webSocketServer;
    QList<QWebSocket *> m_clients;


} */
