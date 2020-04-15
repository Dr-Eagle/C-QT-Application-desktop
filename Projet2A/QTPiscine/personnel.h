#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QWidget>

namespace Ui {
class Personnel;
}

class Personnel : public QWidget
{
    Q_OBJECT

public:
    explicit Personnel(QWidget *parent = nullptr);
    ~Personnel();
    void ajouter_Personnel(int Code_Promotion,QString Date_Debut,QString Date_Fin,float Taux);
    void supprimer_Personnel();
    void modifier_Personnel(int Code_Promotion,QString Date_Debut,QString Date_Fin,float Taux);
    void afficher_Personnel();
    bool payer_Personnel();

private:
    Ui::Personnel *ui;
};

#endif // PERSONNEL_H
