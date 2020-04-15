#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "piscine.h"
#include "QTableWidgetItem"


namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    int p=0;
    int getID();
    void setID(int id);
    int getNumero_tel();
    void setNumero_tel(int numtel);
    QString getDate_de_naissance();
    void setDate_de_naissance(QString date_naissance);
    QString getAdresse();
    void setAdresse(QString adresse);
    QString getNom();
    void setNom(QString nom);
    QString getPrenom();
    void setPrenom(QString prenom);
    QString getEmail();
    void setEmail(QString email);
    QString getType();
    void setType(QString type);
    QString getMot_de_passe();
/*************************************************************************************************************************************************************************/
    void setMot_de_passe(QString mot_de_passe);
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
   // Admin(int idp,QString date_naissance,int numtel,QString adresse,QString nom,QString prenom,QString email,QString type,QString mot_de_passe);
   // Admin(const Admin &p);
    void ajouter_Personne(int ID,QString Nom,QString Prenom,int Numero_Tel,QString Type,QString Date_de_naissance,QString Email,QString Adresse,QString Mot_de_passe);
    void supprimer_Personne();
    void modifier_Personne(int ID,QString Nom,QString Prenom,int Numero_Tel,QString Type,QString Date_de_naissance,QString Email,QString Adresse);
    void afficher_Personne(int a);
    void afficher_PersonneA();
    void ajouter_Abonnement();
    void afficher_Abonnement();
    void modifier_Abonnement(int ID_Abonnement,QString Type,double Prix,QString Date_Fin,int Duree);
    void supprimer_Abonnement();

private slots:
    void on_Back_clicked();
    void on_BPiscine_clicked();

    void on_Ajouter_clicked();

    void on_Supp_clicked();

    void on_Modf_clicked();

    void on_AfficherP_itemClicked(QTableWidgetItem *i);

    void on_TRI_clicked();

    void on_TRI_2_clicked();

    void on_AjouterAb_clicked();

    void on_AfficherPA_itemClicked(QTableWidgetItem *i);

    void on_TRIC_clicked();

    void on_Supprimer_clicked();

    void on_Modifier_clicked();

    void on_AfficherA_itemClicked(QTableWidgetItem *i);

private:
    Ui::Admin *ui;
    int ID;
    QString Date_de_naissance;
    QString Mot_de_passe;
    int Numero_tel;
    QString Adresse;
    QString Nom;
    QString Prenom;
    QString Email;
    QString Type;
    /******************************/
    int ID_Abonnement;
    int Duree;
    QString Date_Debut;
    QString Date_Fin;
    float Prix;
    QString TypeA;
};

#endif // ADMIN_H
