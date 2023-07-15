#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbPost = new QSqlDatabase;
    this->setStyleSheet("background-color: #ddd;");
    ui->pb_dbConnect->setStyleSheet(StyleProg::getStyleButton());
    ui->pb_dbShowAll->setStyleSheet(StyleProg::getStyleButton());
    ui->pb_dbShowRow->setStyleSheet(StyleProg::getStyleButton());
    ui->pb_toolConnect->setStyleSheet(StyleProg::getStyleButton());
}

MainWindow::~MainWindow()
{
    delete dbPost;
    delete ui;
}

void MainWindow::queryBaseSelect(int num)
{
    if (ui->le_setNameTable->text() != "") {
        modelQuery = new QSqlQueryModel;
        modelQuery->setQuery("SELECT * FROM " + ui->le_setNameTable->text() + " WHERE id=" + QString::number(num));
        modelQuery->setHeaderData(0, Qt::Horizontal, "Номер id");
        modelQuery->setHeaderData(1, Qt::Horizontal, "Имя");
        modelQuery->setHeaderData(2, Qt::Horizontal, "Фамилия");
        modelQuery->setHeaderData(3, Qt::Horizontal, "Email");
        ui->tv_db->setModel(modelQuery);
        ui->tv_db->resizeRowsToContents();
        ui->tv_db->resizeColumnsToContents();
    } else {
        QMessageBox::information(this, "Предупреждение", "Введите имя таблицы");
    }
}

void MainWindow::queryBaseAll() {

    if (ui->le_setNameTable->text() != "") {
        query = new QSqlQuery;
        modelTab = new QSqlTableModel(this, *dbPost);
        modelTab->setTable(ui->le_setNameTable->text());
        modelTab->select();
        modelTab->setHeaderData(0, Qt::Horizontal, "Номер id");
        modelTab->setHeaderData(1, Qt::Horizontal, "Имя");
        modelTab->setHeaderData(2, Qt::Horizontal, "Фамилия");
        modelTab->setHeaderData(3, Qt::Horizontal, "Email");
        ui->tv_db->setModel(modelTab);
        ui->tv_db->resizeRowsToContents();
        ui->tv_db->resizeColumnsToContents();
    } else {
        QMessageBox::information(this, "Предупреждение", "Введите имя таблицы");
    }

}

void MainWindow::on_actionExit_triggered()
{
    dbPost->close();
    this->close();
}

void MainWindow::on_actionConnectToBase_triggered()
{
    addDataConnectDb();
}

void MainWindow::on_pb_dbConnect_clicked()
{
    addDataConnectDb();
}

void MainWindow::on_pb_dbShowAll_clicked()
{
    queryBaseAll();
}

void MainWindow::on_pb_dbShowRow_clicked()
{
    num = ui->sb_entryId->value();
    queryBaseSelect(num);
}


void MainWindow::on_pb_toolConnect_clicked()
{
    dataConnectDb  = new ConnectDb;

}

void MainWindow::addDataConnectDb()
{
    QVector<QString> dataVecConnectDb = dataConnectDb->getVecDataConnectDb();
    *dbPost = QSqlDatabase::addDatabase("QPSQL");
    dbPost->setDatabaseName(dataVecConnectDb[0]);
    dbPost->setHostName(dataVecConnectDb[1]);
    dbPost->setPort(dataVecConnectDb[2].toInt());
    dbPost->setUserName(dataVecConnectDb[3]);
    dbPost->setPassword(dataVecConnectDb[4]);

    if (dbPost->open()) {
        QMessageBox::information(this, "Connect Data Base", "Соединение прошло успешно");
        ui->statusbar->showMessage("Сonnection successful " + dbPost->databaseName());
        ui->lb_adressBase->setText("Имя базы: " + dbPost->databaseName() +
                                   " Ip адрес базы: " + dbPost->hostName() +
                                   " Имя пользователя: " + dbPost->userName());
        ui->pb_dbConnect->setEnabled(true);
    } else {
        QMessageBox::warning(this, "Connect Data Base", dbPost->lastError().text());
        ui->statusbar->showMessage("Connect: " + dbPost->lastError().text());
    }
}


void MainWindow::on_actionTool_connect_triggered()
{
    dataConnectDb  = new ConnectDb;
}


