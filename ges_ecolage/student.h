#ifndef STUDENT_H
#define STUDENT_H

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
class Student;
}

class Student : public QDialog
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = 0);
    ~Student();

private slots:
    void on_pushButton_clicked();

    void on_Ajout_res_clicked();
    void show_student();
    void load_combo();
    void on_tableView_stu_activated(const QModelIndex &index);
    


    void on_Ajout_res_2_clicked();

    void on_btn_rech_clicked();

    void on_btn_rech_2_clicked();

private:
    Ui::Student *ui;
    QSqlDatabase database;
    QSqlQuery qry;
    QStandardItemModel *modele;
};

#endif // STUDENT_H
