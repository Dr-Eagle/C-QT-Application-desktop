#include "personnelpiscine.h"
#include "ui_personnelpiscine.h"
#include "pisc.h"

PersonnelPiscine::PersonnelPiscine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonnelPiscine)
{
    ui->setupUi(this);
}

PersonnelPiscine::~PersonnelPiscine()
{
    delete ui;
}
/********************************************************************************************************************************************************************************************/
void PersonnelPiscine::on_Abonne_clicked()
{
    this->hide();
    APersoPiscine *a=new APersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    a->show();
}

void PersonnelPiscine::on_Cours_clicked()
{
    this->hide();
    CPersoPiscine *c=new CPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    c->show();
}

void PersonnelPiscine::on_Salaire_clicked()
{
    this->hide();
    SPersoPiscine *s=new SPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    s->show();
}

void PersonnelPiscine::on_Stock_clicked()
{
    this->hide();
    STOCKPersoPiscine *stock=new STOCKPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    stock->show();
}

void PersonnelPiscine::on_Back_clicked()
{
    this->hide();
    Login *l=new Login();
    Piscine *p=new Piscine;
    p->play_musicClick();
    l->show();
}
