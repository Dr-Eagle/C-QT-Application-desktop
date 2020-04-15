#include "etudiant.h"
#include "ui_etudiant.h"
#include "pisc.h"


Etudiant::Etudiant(int id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Etudiant)
{
    ui->setupUi(this);
    Setid(id);
    afficher_ID(id);
}

Etudiant::~Etudiant()
{
    delete ui;
}
/***********************************************************************************************************************************************************************************************/
void Etudiant::afficher_ID(int id)
{
    QSqlQuery qry;
    qry.prepare("select * from PERSONNE where ID=(?)");
    qry.addBindValue(id);
    qDebug() << qry.exec();
    qDebug() << qry.next();
    qDebug() << qry.value(1).toString() <<  ' ' << qry.value(2).toString() ;
    ui->Esmy->setText(qry.value(1).toString() + ' ' + qry.value(2).toString());
}
/******************************************************************************************************************************************************************************************************/
void Etudiant::on_Abonnement_clicked()
{
    this->hide();
    Piscine *p=new Piscine;
    p->play_musicClick();
    EAbonnement *eab=new EAbonnement(Getid());
    eab->Setid(this->Getid());
    qDebug() << eab->Getid() << "EAB ID";
    eab->show();
}

void Etudiant::on_Classe_clicked()
{
    this->hide();
    EClasse *ecl=new EClasse;
    Piscine *p=new Piscine;
    p->play_musicClick();
    ecl->show();
}

void Etudiant::on_Notification_clicked()
{
    this->hide();
    ENotification *enotif=new ENotification;
    Piscine *p=new Piscine;
    p->play_musicClick();
    enotif->show();
}



void Etudiant::on_Back_clicked()
{
    this->hide();
    Login *l=new Login();
    Piscine *p=new Piscine;
    p->play_musicClick();
    l->show();
}
