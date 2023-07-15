#include "connectdb.h"
#include "ui_connectdb.h"

ConnectDb::ConnectDb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectDb)
{
    ui->setupUi(this);

    ui->le_dbName->setText("postgres");
    ui->le_dbHost->setText("127.0.0.1");
    ui->le_dbPort->setText("5432");
    ui->le_userName->setText("postgres");
    ui->le_userPass->setText("12345");

    this->setStyleSheet("background-color: #ddd;");
    ui->pb_dataConnect->setStyleSheet(StyleProg::getStyleButton());

    this->show();
}

ConnectDb::~ConnectDb()
{
    delete ui;
}

QVector<QString> ConnectDb::getVecDataConnectDb()
{
    return dataConnect;
}

void ConnectDb::on_pb_dataConnect_clicked()
{


    dataConnect[0] = ui->le_dbName->text();
    dataConnect[1] = ui->le_dbHost->text();
    dataConnect[2] = ui->le_dbPort->text();
    dataConnect[3] = ui->le_userName->text();
    dataConnect[4] = ui->le_userPass->text();
    this->close();
}

