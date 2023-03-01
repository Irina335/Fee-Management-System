#include "paiement.h"
#include "ui_paiement.h"
#include "menu.h"

Menu *p_me;

Paiement::Paiement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paiement)
{
    ui->setupUi(this);
    isconnected();
    load_combo();
    QSqlQuery qry_1 ;
    QSqlQueryModel *modal =  new QSqlQueryModel();
    qry_1.exec("SELECT date,description,montant,student.nom,student.prenom,level.nom_level FROM paiement INNER JOIN student on student.id = paiement.id_stu LEFT JOIN level ON level.id=student.id_level");
    modal->setQuery(qry_1);
    ui->tableView->setModel(modal);
}

Paiement::~Paiement()
{
    delete ui;
}

void Paiement::on_return_btn_clicked()
{
    hide();
    p_me = new Menu(this);
    p_me->show();

}

void Paiement::on_enregistrer_clicked()
{
    QString description = ui->description->text();
    QString montant = ui->montant->text();
     QString date = (ui->dateEdit->date()).toString("yyyy-MM-dd");
     int id = (ui->combo_stu->currentIndex()) + 1;


     QSqlQuery qry;

     qry.prepare("INSERT INTO paiement (date,description,montant,id_stu)"
                 "VALUES ('"+date+"','"+description+"','"+montant+"','"+QString::number(id)+"')");

     if (qry.exec()){
         QMessageBox::information(this, "Inserted","Data Inserted");
     }else{
          qDebug()<<qry.lastError().text();
     }
      qry.clear();
      ui->description->clear();
      ui->montant->clear();
      ui->dateEdit->clear();
      ui->combo_stu-> clear();
      QSqlQuery qry_1 ;
      QSqlQueryModel *modal =  new QSqlQueryModel();
      qry_1.exec("SELECT date,description,montant,student.nom,student.prenom,level.nom_level FROM paiement INNER JOIN student on student.id = paiement.id_stu LEFT JOIN level ON level.id=student.id_level");
      modal->setQuery(qry_1);
      ui->tableView->setModel(modal);

}
void Paiement::load_combo()
{
    QSqlQueryModel *modal =  new QSqlQueryModel();
    QSqlQuery qry ;
    qry.exec("SELECT nom FROM student");
    modal->setQuery(qry);
    ui->combo_stu->setModel(modal);






}
