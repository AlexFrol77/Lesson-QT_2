#ifndef CONNECTDB_H
#define CONNECTDB_H

#include <QWidget>
#include <QVector>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include "styleprog.h"

namespace Ui {
class ConnectDb;
}

class ConnectDb : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectDb(QWidget *parent = nullptr);
    ~ConnectDb();

    QVector<QString> getVecDataConnectDb();

private slots:
    void on_pb_dataConnect_clicked();

private:
    Ui::ConnectDb *ui;
    QVector<QString> dataConnect = {"", "", "", "", ""};
};

#endif // CONNECTDB_H
