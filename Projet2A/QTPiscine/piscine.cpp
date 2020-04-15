#include "pisc.h"
#include "ui_piscine.h"
#include "include.h"
#include <QApplication>


Piscine::Piscine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Piscine)
{
    ui->setupUi(this);
}

Piscine::~Piscine()
{
    delete ui;
}
/***************************************************************************************************************************************************************************************/
void Piscine ::play_musicBackground()
{
    musicB=new QMediaPlayer();
    musicB->setMedia(QUrl("qrc:/Sound/Beautiful Light Music - easy smooth inspirational - long playlist by relaxdaily Ocean Breeze.mp3"));
    musicB->setVolume(25);
    musicB->play();
}
void Piscine ::play_musicClick()
{
    musicC=new QMediaPlayer();
    musicC->setMedia(QUrl("qrc:/Sound/Click.mp3"));
    musicC->setVolume(200);
    musicC->play();
}
/******************************************************************************************************************************************************************************************/
void Piscine::on_Stock_clicked()
{
    play_musicClick();
    this->hide();
    Produit *p = new Produit;
    p->show();
}
void Piscine::on_Promotion_clicked()
{
    play_musicClick();
    this->hide();
    Promotion *promo =new Promotion;
    promo->show();
}

void Piscine::on_Cours_clicked()
{
    play_musicClick();
    this->hide();
    Cours *c =new Cours;
    c->show();
}

void Piscine::on_Abonnement_clicked()
{
    play_musicClick();
    this->hide();
    Abonnement *ab =new Abonnement;
    ab->show();
}

void Piscine::on_Abonne_clicked()
{
    play_musicClick();
    this->hide();
    Abonne *a =new Abonne;
    a->show();
}

void Piscine::on_Back_clicked()
{
    play_musicClick();
    this->hide();
    Admin *ad =new Admin;
    ad->show();
}


