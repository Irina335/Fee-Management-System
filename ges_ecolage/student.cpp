#include "student.h"
#include "ui_student.h"
#include "menu.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include<sstream>
using namespace std;

Menu *me;

Student::Student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    isconnected();
    show_student();
    load_combo();
    ui->status->hide();
    ui->tableView_paiement->setStyleSheet("QHeaderView::section { background-color:rgb(33, 47, 61); }");


}


Student::~Student()
{
    delete ui;
}

void Student::on_pushButton_clicked()
{
    hide();
    me = new Menu(this);
    me->show();
}
void Student::show_student()
{
    QSqlQueryModel *modal =  new QSqlQueryModel();
    QSqlQuery qry;
    qry.exec("SELECT student.id,nom,prenom,contact,level.nom_level FROM student INNER JOIN level ON level.id=student.id_level ORDER BY student.id ASC ");
    modal->setQuery(qry);
    ui->tableView_stu->setModel(modal);
}

void Student::on_Ajout_res_clicked()
{
    QString nom_s = ui->nom->text();
     QString prenom_s = ui->prenom-> text();
     QString contact_s = ui->contact-> text();
     int id = (ui->combo_level->currentIndex()) + 1;
     QSqlQuery qry;

     qry.prepare("INSERT INTO student (nom,prenom,contact,id_level)"
                 "VALUES ('"+nom_s+"','"+prenom_s+"','"+contact_s+"','"+QString::number(id)+"')");

     if (qry.exec()){
         QMessageBox::information(this, "Inserted","Data Inserted");
         show_student();
     }else{
          qDebug()<<qry.lastError().text();
     }
      qry.clear();
      ui->nom->clear();
      ui->prenom->clear();
      ui->contact->clear();
      ui->combo_level-> clear();

}



void Student::on_tableView_stu_activated(const QModelIndex &index)
{
    int res;
    int val = ui->tableView_stu->model()->data(index).toInt() ;
    QSqlQuery query,qry,qry_1,qry_update;
     query.exec("SELECT student.id,nom,prenom,contact,level.id,level.Frais FROM student"
                " INNER JOIN level on level.id=student.id_level where student.id='"+QString::number(val)+"'");
    if (query.exec()){
    while (query.next()){
        ui->id->setText(query.value(0).toString());
        ui->nom->setText(query.value(1).toString());
         ui->prenom ->setText(query.value(2).toString());
          ui->contact->setText(query.value(3).toString());
          ui->combo_level->setCurrentIndex(query.value(4).toInt());
          ui->f_p->setText(query.value(5).toString());
    }
    query.clear();
    }else{
       qDebug()<<query.lastError().text();
        }
    qry.exec("SELECT SUM(montant) As somme FROM paiement WHERE id_stu= '"+QString::number(val)+"' ");
    if (qry.exec()){
    while (qry.next()){
          ui->d_p->setText(qry.value(0).toString());
    }
    qry.clear();

    /*reste à payer*/

    res = (ui->f_p->text()).toInt() - (ui->d_p->text()).toInt();
    ui->rest->setText( QString::number(res));

    /*update student if reste à payer = frais à payer*/
    if ((ui->f_p->text())==(ui->d_p->text())){
    ui->status->show();
    qry_update.exec("UPDATE student SET status=1 WHERE id= '"+QString::number(val)+"' ");
    qry_update.clear();


    }else{
      ui->status->hide();
    }




    /*load historique paiement*/
    QSqlQueryModel *modal =  new QSqlQueryModel();
    qry_1.exec("SELECT id,date,description,montant FROM paiement WHERE id_stu= '"+QString::number(val)+"' ");
    modal->setQuery(qry_1);
    ui->tableView_paiement->setModel(modal);
    qry_1.clear();
}
}


void Student::load_combo()
{
    QSqlQueryModel *modal =  new QSqlQueryModel();
    QSqlQuery qry;
    qry.exec("SELECT nom_level FROM level");
    modal->setQuery(qry);

    ui->combo_level->setModel(modal);

}



void Student::on_Ajout_res_2_clicked()
{
    QString description = ui->description->text();
    QString montant = ui->montant->text();
     QString date = (ui->date->date()).toString("yyyy-MM-dd");
     QString id = ui->id->text();

     QSqlQuery qry;

     qry.prepare("INSERT INTO paiement (date,description,montant,id_stu)"
                 "VALUES ('"+date+"','"+description+"','"+montant+"','"+id+"')");

     if (qry.exec()){
         QMessageBox::information(this, "Inserted","Data Inserted");
     }else{
          qDebug()<<qry.lastError().text();
     }
      qry.clear();
      ui->description->clear();
      ui->montant->clear();
      ui->date->clear();
      ui->contact->clear();
      ui->nom->clear();
      ui->prenom->clear();
      ui->f_p->clear();
      ui->d_p->clear();
      ui->status->hide();
      ui->rest->clear();


}

void Student::on_btn_rech_clicked()
{
    QString val = ui->rech->text();
    QSqlQueryModel *modal =  new QSqlQueryModel();
    QSqlQuery qry;
    qry.exec("SELECT student.id,nom,prenom,contact,level.nom_level FROM student INNER JOIN level ON level.id=student.id_level WHERE nom='"+val+"'");
    modal->setQuery(qry);
    ui->tableView_stu->setModel(modal);
}

void Student::on_btn_rech_2_clicked()
{
    show_student();
     ui->rech->clear();

}
