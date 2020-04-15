#ifndef COURS_H
#define COURS_H
#include <QWidget>
#include "include.h"

namespace Ui {
class Cours;
}

class Cours : public QWidget
{

    Q_OBJECT

public:
    int getID_Cours();
    void setID_Cours(int id_cours);
    QString getDate_Cours();
    void setDate_Cous(QString date_cours);
    QString getNom_du_cours();
    void setNom_du_cours(QString NomC);
    QString getHoraire_Cours();
    void setHoraire_Cours(QString horaire);
    int getNBR_Reservation();
    void setNBR_Reservation(int nbr_reservation);
/******************************************************************************************************************************************************************/
    explicit Cours(QWidget *parent = nullptr);
    ~Cours();
   /* Cours();
    Cours(int id_cours,QString date_cours,QString horaire,int nbr_reservation);
    Cours(const Cours &c);*/
    void ajouter_Cours(int ID,QString Nom_du_cours,QString Date_Cours,QString Horaire_Cours,int NBR_Reservation);
    void supprimer_Cours();
    void modifier_Cours(int ID,QString Nom_du_cours,QString Date_Cours,QString Horaire_Cours,int NBR_Reservation);
    void afficher_Cours();
    void afficher_Reservation();



private slots:
    void on_Back_clicked();

    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Enregistrer_clicked();

    void on_AfficherCours_itemClicked(QTableWidgetItem *i);

    void on_Abonne_clicked();

    void on_Abonnement_clicked();

    void on_Stock_clicked();

    void on_Promotion_clicked();

private:
    Ui::Cours *ui;
    int ID_Cours;
    QString Date_Cours;
    QString Nom_du_cours;
    QString Horaire_Cours;
    int NBR_Reservation;

};

#endif // COURS_H
