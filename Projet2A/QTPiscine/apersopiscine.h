#ifndef APERSOPISCINE_H
#define APERSOPISCINE_H

#include <QWidget>

namespace Ui {
class APersoPiscine;
}

class APersoPiscine : public QWidget
{
    Q_OBJECT

public:
    explicit APersoPiscine(QWidget *parent = nullptr);
    ~APersoPiscine();
    void afficher_Abonnement();
    void afficher_Abonne();
    void rechercher_Abonne();
    void rechercher_Abonnement();
    void tri_asc_Abonne();
    void tri_desc_Abonne();
    void tri_asc_Abonnement();
    void tri_desc_Abonnement();

private slots:
    void on_Cours_clicked();

    void on_Salaire_clicked();

    void on_Stock_clicked();

    void on_Back_clicked();

    void on_Rechercher_clicked();

    void on_Recherche_clicked();

    void on_TriC_clicked();

    void on_TriD_clicked();

    void on_TriC_2_clicked();

    void on_TriD_2_clicked();

private:
    Ui::APersoPiscine *ui;
};

#endif // APERSOPISCINE_H
