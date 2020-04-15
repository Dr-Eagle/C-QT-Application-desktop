#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QWidget>
#include "enotification.h"
namespace Ui {
class Etudiant;
}

class Etudiant : public QWidget
{
    Q_OBJECT

public:
    int Getid() { return ID; }
    void Setid(int val) { ID = val; }
    QString nom,prenom;
/**********************************************************************************************************************************/
    explicit Etudiant(int id,QWidget *parent = nullptr);
    ~Etudiant();
    void afficher_ID(int id);

private slots:
    void on_Abonnement_clicked();

    void on_Classe_clicked();

    void on_Notification_clicked();

    void on_Back_clicked();

private:
    Ui::Etudiant *ui;
    int ID;
};

#endif // ETUDIANT_H
