#ifndef PRODUIT_H
#define PRODUIT_H
#include <QWidget>
#include "include.h"

namespace Ui {
class Produit;
}

class Produit : public QWidget
{

    Q_OBJECT

public:
    int getReference();
    void setReference(int ref);
    double getPrix_unitaire();
    void setPrix_unitaire(double prixu);
    QString getNom();
    void setNom(QString nomp);
    int getQuantite();
    void setQuantite(int quantite);
/*************************************************************************************************************************************/
    explicit Produit(QWidget *parent = nullptr);
    ~Produit();
  /* Produit();
   Produit(int ref,float prixu,QString nomp,int quantite);
   Produit(const Produit &prod);*/
    void ajouter_Produit(int Reference,double Prix_Unitaire,QString Nom_Produit,int Quantite);
    void supprimer_Produit();
    void modifier_Produit(int Reference,double Prix_Unitaire,QString Nom_Produit,int Quantite);
    void afficher_Stock();
    void afficher_Commande();

private slots:
    void on_AjouterProduit_clicked();

    void on_supprimer_clicked();


    void on_Afficher_itemClicked(QTableWidgetItem *i);

    void on_pushButton_11_clicked();

    void on_pushButton_6_clicked();

    void on_Back_clicked();

    void on_Abonne_clicked();

    void on_Abonnement_clicked();

    void on_Cours_clicked();

    void on_Promotion_clicked();

private:
    Ui::Produit *ui;
    int Reference;
    double Prix_Unitaire;
    QString Nom_Produit;
    int Quantite;


};

#endif // PRODUIT_H
