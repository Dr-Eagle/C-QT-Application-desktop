#ifndef ECLASSE_H
#define ECLASSE_H

#include <QWidget>

namespace Ui {
class EClasse;
}

class EClasse : public QWidget
{
    Q_OBJECT

public:
    explicit EClasse(QWidget *parent = nullptr);
    ~EClasse();

private slots:
    void on_Abonnement_clicked();

    void on_Notification_clicked();

    void on_Back_clicked();

private:
    Ui::EClasse *ui;
};

#endif // ECLASSE_H
