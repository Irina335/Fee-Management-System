#ifndef MENU_H
#define MENU_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <conn.h>
#include <QStandardItemModel>
#include <QLineEdit>
#include "student.h"
#include "paiement.h"
#include "fee.h"

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_student_btn_clicked();

    void on_paiement_btn_clicked();

    void on_Frais_btn_clicked();
    void load();

private:
    Ui::Menu *ui;
    Student *student;
    Paiement *paiement;
    Fee *fee;

};

#endif // MENU_H
