#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include "connectdb.h"
#include "styleprog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void queryBaseAll();
    void queryBaseSelect(int num);

private slots:

    void on_actionExit_triggered();
    void on_actionConnectToBase_triggered();
    void on_pb_dbConnect_clicked();
    void on_pb_dbShowAll_clicked();
    void on_pb_dbShowRow_clicked();
    void on_pb_toolConnect_clicked();
    void addDataConnectDb();
    void on_actionTool_connect_triggered();


private:

    Ui::MainWindow *ui;
    QSqlDatabase* dbPost;
    QSqlQuery* query;
    QSqlTableModel* modelTab;
    QSqlQueryModel* modelQuery;
    ConnectDb* dataConnectDb;
    int num = 1;


};
#endif // MAINWINDOW_H
