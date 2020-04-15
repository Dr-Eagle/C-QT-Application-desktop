#ifndef ABONNEMENT_H
#define ABONNEMENT_H

#include <QWidget>

namespace Ui {
class Abonnement;
}

class Abonnement : public QWidget
{

    Q_OBJECT

public:
    int getID_Abonnement();
    void setID_Abonnement(int id_abonnement);
    int getDuree();
    void setDuree(int duree);
    int getID_Abonne();
    void setID_Abonne(int ID_abonne);
    QString getType();
    void setType(QString type);
    QString getDate_Debut();
    void setDate_Debut(QString dated);
    QString getDate_Fin();
    void setDate_Fin(QString datef);
    double getPrix();
    void setPrix(double prix);
/*************************************************************************************************************************************************/
    explicit Abonnement(QWidget *parent = nullptr);
   /* Abonnement();
    Abonnement(int id_abonnement,int duree,QString dated,QString datef,float prix);
    Abonnement(const Abonnement &a);*/
    ~Abonnement();
    void ajouter_Abonnement(int ID_Anonnement,QString Type,double Prix,QString Date_Fin,int Duree,int ID_Abonne);
    void supprimer_Abonnement();
    void modifier_Abonnement();
    void afficher_Abonnement(int a);



private slots:
    void on_Back_clicked();

    void on_Cours_clicked();

    void on_Stock_clicked();

    void on_Promotion_clicked();

    void on_Abonne_clicked();

private:
    Ui::Abonnement *ui;
    int ID_Abonnement;
    QString Type;
    double Prix;
    QString Date_Debut;
    QString Date_Fin;
    int Duree;
    int ID_Abonne;

};

#endif // ABONNEMENT_H
