#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>

namespace Ui {
class Notification;
}

class Notification : public QWidget
{
    Q_OBJECT

public:
    explicit Notification(QWidget *parent = nullptr);
    ~Notification();
    void ajouter_Notification(int Code_Promotion,QString Date_Debut,QString Date_Fin,float Taux);
    void supprimer_Notification();
    void modifier_Notification(int Code_Promotion,QString Date_Debut,QString Date_Fin,float Taux);
    void afficher_Notification();

private:
    Ui::Notification *ui;
};

#endif // NOTIFICATION_H
