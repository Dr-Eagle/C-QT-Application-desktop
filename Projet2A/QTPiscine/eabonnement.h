#ifndef EABONNEMENT_H
#define EABONNEMENT_H

#include <QWidget>

namespace Ui {
class EAbonnement;
}

class EAbonnement : public QWidget
{
    Q_OBJECT

public:
    int Getid() { return ID; }
    void Setid(int val) { ID = val; }
/*************************************************************************************************************************************************************************/
    explicit EAbonnement(int id,QWidget *parent = nullptr);
     explicit EAbonnement(QWidget *parent = nullptr);
    ~EAbonnement();    
    void afficher_Cours();
    void afficher_Stock();
    void afficher_Abonnement();
    void reserver_Cours();
    void commander_Produit();


private slots:
    void on_Classe_clicked();

    void on_Notification_clicked();

    void on_Back_clicked();

    void on_Reserver_clicked();

    void on_Commander_clicked();

private:
    int ID;
    Ui::EAbonnement *ui;
};

#endif // EABONNEMENT_H
