#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket* socket;
    QByteArray data;

public slots:

    void socketReady();
    void socketDisconnection();

private slots:

    void on_pb_connectToSrver_clicked();
    void on_pb_sendMessage_clicked();
    void sendToServer(QString str);
    void on_le_setSend_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
