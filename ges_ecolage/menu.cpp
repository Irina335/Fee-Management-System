#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    isconnected();
    load();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_student_btn_clicked()
{
    hide();
    student = new Student(this);
    student ->show();

}

void Menu::on_paiement_btn_clicked()
{
    hide();
    paiement = new Paiement(this);
    paiement ->show();
}

void Menu::on_Frais_btn_clicked()
{
    hide();
    fee = new Fee(this);
    fee ->show();
}

void Menu::load()
{
    QSqlQuery qry,qry_1,qry_2;
    qry.exec("SELECT COUNT(*) as cn  FROM student ");
    if (qry.exec()){
        while (qry.next()){
              ui->t_e->setText(qry.value(0).toString());
        }
    }

    qry_1.exec("SELECT COUNT(*) AS cn FROM paiement  ");
    if (qry_1.exec()){
        while (qry_1.next()){
              ui->t_p->setText(qry_1.value(0).toString());
        }
    }

    qry_2.exec("SELECT COUNT(*) AS cn FROM student where status=1  ");
        if (qry_2.exec()){
            while (qry_2.next()){
                  ui->t_ep->setText(qry_2.value(0).toString());
            }
}
}
