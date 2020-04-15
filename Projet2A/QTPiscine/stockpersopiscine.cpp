#include "stockpersopiscine.h"
#include "ui_stockpersopiscine.h"
#include "pisc.h"
#include "include.h"


STOCKPersoPiscine::STOCKPersoPiscine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::STOCKPersoPiscine)
{
    ui->setupUi(this);
    afficher_stock(1);
    afficher_Commande();
}

STOCKPersoPiscine::~STOCKPersoPiscine()
{
    delete ui;
}
/********************************************************************************************************************************************************************************************/
void STOCKPersoPiscine::afficher_stock(int a)
{
    if(a==1)
    {
        QSqlQuery qry;
       while(ui->Afficherp->rowCount()>0)
           {
               ui->Afficherp->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from Produit ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->Afficherp->insertRow(c);
                   for (int j=0; j<4; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->Afficherp->setItem(c,j,item1);
                       int x=c;
                       ui->Afficherp->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
    else if(a==2)
    {
        QSqlQuery qry;
       while(ui->Afficherp->rowCount()>0)
           {
               ui->Afficherp->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from Produit order by REFERENCE asc ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->Afficherp->insertRow(c);
                   for (int j=0; j<4; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->Afficherp->setItem(c,j,item1);
                       int x=c;
                       ui->Afficherp->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
    else if(a==3)
    {
        QSqlQuery qry;
       while(ui->Afficherp->rowCount()>0)
           {
               ui->Afficherp->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from Produit order by REFERENCE desc ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->Afficherp->insertRow(c);
                   for (int j=0; j<4; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->Afficherp->setItem(c,j,item1);
                       int x=c;
                       ui->Afficherp->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
}
void STOCKPersoPiscine::afficher_Commande()
{
    QSqlQuery qry;
   while(ui->AfficherC->rowCount()>0)
       {
           ui->AfficherC->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from COMMANDE ");
           int c = -1;
           while (qry.next())
           {
               c++;
               ui->AfficherC->insertRow(c);
               for (int j=0; j<3; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherC->setItem(c,j,item1);
                   int x=c;
                   ui->AfficherC->item(x,0)->setBackgroundColor(Qt::yellow);

                }
             }
           qDebug() <<"Fin";
}
/********************************************************************************************************************************************************************************************/
void STOCKPersoPiscine::on_TRICc_clicked()
{
    afficher_stock(2);
}
void STOCKPersoPiscine::on_TRID_clicked()
{
    afficher_stock(3);
}
void STOCKPersoPiscine::on_Abonne_clicked()
{
    this->hide();
    APersoPiscine *a=new APersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    a->show();
}
void STOCKPersoPiscine::on_Cours_clicked()
{
    this->hide();
    CPersoPiscine *c=new  CPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    c->show();
}
void STOCKPersoPiscine::on_Salaire_clicked()
{
    this->hide();
    SPersoPiscine *s=new SPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    s->show();
}
void STOCKPersoPiscine::on_Back_clicked()
{
    this->hide();
    PersonnelPiscine *pe=new PersonnelPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    pe->show();
}
