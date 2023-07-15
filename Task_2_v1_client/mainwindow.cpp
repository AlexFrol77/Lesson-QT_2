#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::socketReady()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_4);
    if (in.status() == QDataStream::Ok) {
        QString str;
        in >> str;
        ui->tb_showSendMsg->append(str);
    } else {
        ui->tb_showSendMsg->append("Ошибка чтения сообщения");
    }
}

void MainWindow::socketDisconnection()
{
    socket->deleteLater();
}

void MainWindow::on_pb_connectToSrver_clicked()
{
    socket->connectToHost("127.0.0.1", 5555);
}


void MainWindow::on_pb_sendMessage_clicked()
{
    sendToServer(ui->le_setSend->text());
}

void MainWindow::sendToServer(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << str;
    socket->write(data);
    ui->le_setSend->clear();
}


void MainWindow::on_le_setSend_returnPressed()
{
    sendToServer(ui->le_setSend->text());
}

