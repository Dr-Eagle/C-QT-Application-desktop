#ifndef CPERSOPISCINE_H
#define CPERSOPISCINE_H

#include <QWidget>

namespace Ui {
class CPersoPiscine;
}

class CPersoPiscine : public QWidget
{
    Q_OBJECT

public:
    explicit CPersoPiscine(QWidget *parent = nullptr);
    ~CPersoPiscine();
    void afficher_cours(int a);
    void afficher_Reservation();

private slots:
    void on_Abonne_clicked();

    void on_Salaire_clicked();

    void on_Stock_clicked();

    void on_Back_clicked();

    void on_TRIC_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CPersoPiscine *ui;
};

#endif // CPERSOPISCINE_H
