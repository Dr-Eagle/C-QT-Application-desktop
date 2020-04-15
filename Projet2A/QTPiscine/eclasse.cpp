#include "eclasse.h"
#include "ui_eclasse.h"
#include "pisc.h"

EClasse::EClasse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EClasse)
{
    ui->setupUi(this);
}

EClasse::~EClasse()
{
    delete ui;
}

void EClasse::on_Abonnement_clicked()
{
    this->hide();
    EAbonnement *ea=new EAbonnement();
    Piscine *p=new Piscine;
    p->play_musicClick();
    ea->show();
}

void EClasse::on_Notification_clicked()
{
    this->hide();
    ENotification *en=new ENotification();
    Piscine *p=new Piscine;
    p->play_musicClick();
    en->show();
}

void EClasse::on_Back_clicked()
{
    this->hide();
    Etudiant *etud=new Etudiant(0);
    Piscine *p=new Piscine;
    p->play_musicClick();
    etud->show();
}
