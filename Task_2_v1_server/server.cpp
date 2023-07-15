#include "server.h"

Server::Server()
{
    serverStart();
}

void Server::sendToClient(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << str;
    for (int i = 0; i < socketVec.size(); ++i) {
        socketVec[i]->write(data);
    }
}

void Server::serverStart()
{
    if (this->listen(QHostAddress::Any, 5555)) {
        qDebug() << "Сервер слушает";
    } else {
        qDebug() << "Сервер не слушает";
    }
    blockSize = 0;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconection()));

    qDebug()<<socketDescriptor<<" Соединение прошло успешно";
    qDebug()<<"Собшение о соединение отправленно клиенту";

    socketVec.push_back(socket);
}

void Server::socketReady()
{
    socket =(QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok) {
        QString str;
        in >> str;
        blockSize = 0;
        qDebug() << str;
        sendToClient(str);
    } else {
        qDebug() << "DataStream ошибка";
    }
}

void Server::socketDisconection()
{
    socket->deleteLater();
    qDebug() << "Отсоединение";
}
