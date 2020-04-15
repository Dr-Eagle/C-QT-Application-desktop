#ifndef PROMOTION_H
#define PROMOTION_H
#include "include.h"
#include <QWidget>

namespace Ui {
class Promotion;
}

class Promotion : public QWidget
{

    Q_OBJECT

public:
    int getCode_Promotion();
    void setCode_Promotion(int code);
    QString getDate_Fin();
    void setDate_Fin(QString datef);
    int getTaux();
    void setTaux(int taux);
/************************************************************************************************************************************************************************/
    explicit Promotion(QWidget *parent = nullptr);
    ~Promotion();
  /*  Promotion();
    Promotion(int code,QString dated,QString datef,float taux);
    Promotion(const Promotion &pr);*/
    void ajouter_Promotion(int Code_Promotion,QString Date_Fin,int Taux);
    void supprimer_Promotion();
    void modifier_Promotion(int Code_Promotion,QString Date_Fin,int Taux);
    void afficher_Promotion();


private slots:
    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Enregistrer_clicked();

    void on_Afficher_itemClicked(QTableWidgetItem *item);

    void on_Back_clicked();

    void on_Abonne_clicked();

    void on_Abonnement_clicked();

    void on_Cours_clicked();

    void on_Stock_clicked();

private:
    Ui::Promotion *ui;
    int Code_Promotion;
    QString Date_Fin;
    int Taux;

};

#endif // PROMOTION_H
