#ifndef ABONNE_H
#define ABONNE_H

#include <QWidget>

namespace Ui {
class Abonne;
}

class Abonne : public QWidget
{
    Q_OBJECT

public:
    explicit Abonne(QWidget *parent = nullptr);
    ~Abonne();
    void afficher_Abonne();


private slots:
    void on_Back_clicked();

    void on_Abonnement_clicked();

    void on_Cours_clicked();

    void on_Stock_clicked();

    void on_Promotion_clicked();

private:
    Ui::Abonne *ui;

};

#endif // ABONNE_H
