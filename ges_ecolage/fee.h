#ifndef FEE_H
#define FEE_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <conn.h>
#include <QStandardItemModel>
#include <QLineEdit>


namespace Ui {
class Fee;
}

class Fee : public QDialog
{
    Q_OBJECT

public:
    explicit Fee(QWidget *parent = 0);
    ~Fee();

private slots:
    void on_return_btn_clicked();

private:
    Ui::Fee *ui;


};

#endif // FEE_H
