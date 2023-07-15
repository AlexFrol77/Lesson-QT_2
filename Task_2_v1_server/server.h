#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDebug>

class Server : public QTcpServer
{
public:

    Server();

    QTcpSocket* socket;

private:

    QByteArray data;
    QVector<QTcpSocket*> socketVec;
    quint16 blockSize;

    void sendToClient(QString str);

public slots:

    void serverStart();
    void incomingConnection(qintptr socketDescriptor);
    void socketReady();
    void socketDisconection();

};

#endif // SERVER_H
