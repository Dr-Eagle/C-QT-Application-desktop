#ifndef PISCINE_H
#define PISCINE_H

#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class Piscine;
}

class Piscine : public QWidget
{
    Q_OBJECT

public:
    explicit Piscine(QWidget *parent = nullptr);
    ~Piscine();
    void play_musicBackground();
    void play_musicClick();

private slots:
    void on_Stock_clicked();

    void on_Promotion_clicked();

    void on_Cours_clicked();

    void on_Abonnement_clicked();

    void on_Abonne_clicked();

    void on_Back_clicked();

private:
    Ui::Piscine *ui;
    QMediaPlayer *musicB=new QMediaPlayer();
    QMediaPlayer *musicC=new QMediaPlayer();
};

#endif // PISCINE_H
