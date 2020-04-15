#ifndef STOCKPERSOPISCINE_H
#define STOCKPERSOPISCINE_H

#include <QWidget>

namespace Ui {
class STOCKPersoPiscine;
}

class STOCKPersoPiscine : public QWidget
{
    Q_OBJECT

public:
    explicit STOCKPersoPiscine(QWidget *parent = nullptr);
    ~STOCKPersoPiscine();
    void afficher_stock(int a);
    void afficher_Commande();

private slots:
    void on_Abonne_clicked();

    void on_Cours_clicked();

    void on_Salaire_clicked();

    void on_Back_clicked();

    void on_TRICc_clicked();

    void on_TRID_clicked();

private:
    Ui::STOCKPersoPiscine *ui;
};

#endif // STOCKPERSOPISCINE_H
