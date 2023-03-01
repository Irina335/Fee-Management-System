#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <conn.h>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QMainWindow>
#include "menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connexion_clicked();

private:
    Ui::MainWindow *ui;
    Menu *menu;
};

#endif // MAINWINDOW_H
