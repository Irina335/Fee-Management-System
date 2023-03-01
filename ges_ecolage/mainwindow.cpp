#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isconnected();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connexion_clicked()
{

    QString username = ui-> user -> text();
     QString password = ui-> mdp-> text();
     QSqlQuery qry;
     qry.exec("SELECT username,mdp FROM user WHERE username ='"+ username +"' AND mdp= '"+password+"'");

     if (!qry.exec()){
         QMessageBox::information(this, "Failed","Query Failed to execute");
         qDebug()<<qry.lastError().text();
     }else{
          while(qry.next()){
              QString usernameFromDB = qry.value(0).toString();
              QString mdpFromDB = qry.value(1).toString();

              if (usernameFromDB == username && mdpFromDB==password){

                  QMessageBox::information(this, "Success","Logged in successfully");
                  hide();
                  menu = new Menu(this);
                  menu->show();

              } else{
                  QMessageBox::information(this, "Failed","Check your information");
              }
       }



}
}
