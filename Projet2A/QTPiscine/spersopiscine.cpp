#include "spersopiscine.h"
#include "ui_spersopiscine.h"
#include "pisc.h"

SPersoPiscine::SPersoPiscine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SPersoPiscine)
{
    ui->setupUi(this);
}

SPersoPiscine::~SPersoPiscine()
{
    delete ui;
}

void SPersoPiscine::on_Abonne_clicked()
{
    this->hide();
    APersoPiscine *a=new APersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    a->show();
}

void SPersoPiscine::on_Cours_clicked()
{
    this->hide();
    CPersoPiscine *c=new CPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    c->show();
}

void SPersoPiscine::on_Stock_clicked()
{
    this->hide();
    STOCKPersoPiscine *stock=new STOCKPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    stock->show();
}

void SPersoPiscine::on_Back_clicked()
{
    this->hide();
   PersonnelPiscine *pe=new PersonnelPiscine();
   Piscine *p=new Piscine;
   p->play_musicClick();
   pe->show();
}
