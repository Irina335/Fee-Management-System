#include "fee.h"
#include "ui_fee.h"
#include "menu.h"


Menu *F_me;
Fee::Fee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fee)
{
    ui->setupUi(this);
    isconnected();
    QSqlQueryModel *modal =  new QSqlQueryModel();
    QSqlQuery qry ;
    qry.exec("SELECT * FROM level");
    modal->setQuery(qry);
    ui->tableView->setModel(modal);

}

Fee::~Fee()
{
    delete ui;
}

void Fee::on_return_btn_clicked()
{
  hide();
  F_me = new Menu(this) ;
  F_me->show();
}

