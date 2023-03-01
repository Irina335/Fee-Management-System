#ifndef PAIEMENT_H
#define PAIEMENT_H

#include <QDialog>

namespace Ui {
class Paiement;
}

class Paiement : public QDialog
{
    Q_OBJECT

public:
    explicit Paiement(QWidget *parent = 0);
    ~Paiement();

private slots:
    void on_return_btn_clicked();

    void on_enregistrer_clicked();
    void load_combo();

private:
    Ui::Paiement *ui;
};

#endif // PAIEMENT_H
