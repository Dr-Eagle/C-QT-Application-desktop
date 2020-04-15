#include "cpersopiscine.h"
#include "ui_cpersopiscine.h"
#include "pisc.h"

CPersoPiscine::CPersoPiscine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CPersoPiscine)
{
    ui->setupUi(this);
    afficher_cours(1);
    afficher_Reservation();
}

CPersoPiscine::~CPersoPiscine()
{
    delete ui;
}
/*******************************************************************************************************************************************************************************************/
void CPersoPiscine::afficher_cours(int a)
{
    if(a==1)
    {
        QSqlQuery qry;
       while(ui->AfficherC->rowCount()>0)
           {
               ui->AfficherC->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from COURS ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherC->insertRow(c);
                   for (int j=0; j<5; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherC->setItem(c,j,item1);
                       int x=c;
                       ui->AfficherC->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
    else if(a==2)
    {
        QSqlQuery qry;
       while(ui->AfficherC->rowCount()>0)
           {
               ui->AfficherC->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from COURS order by ID asc ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherC->insertRow(c);
                   for (int j=0; j<5; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherC->setItem(c,j,item1);
                       int x=c;
                       ui->AfficherC->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
    else if(a==3)
    {
        QSqlQuery qry;
       while(ui->AfficherC->rowCount()>0)
           {
               ui->AfficherC->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from COURS order by ID desc ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherC->insertRow(c);
                   for (int j=0; j<5; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherC->setItem(c,j,item1);
                       int x=c;
                       ui->AfficherC->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
                      qDebug() <<"Fin";
    }
}
void CPersoPiscine::afficher_Reservation()
{
    QSqlQuery qry;
   while(ui->AfficherR->rowCount()>0)
       {
           ui->AfficherR->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from RESERVATION_COURS ");
           int c = -1;
           while (qry.next())
           {
               c++;
               ui->AfficherR->insertRow(c);
               for (int j=0; j<3; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherR->setItem(c,j,item1);int x=c;
                   ui->AfficherR->item(x,0)->setBackgroundColor(Qt::yellow);

                }
             }
           qDebug() <<"Fin";
}
/*********************************************************************************************************************************************************************************************/

void CPersoPiscine::on_TRIC_clicked()
{
    afficher_cours(2);
}

void CPersoPiscine::on_pushButton_2_clicked()
{
    afficher_cours(3);
}
void CPersoPiscine::on_Abonne_clicked()
{
    this->hide();
    APersoPiscine *a=new APersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    a->show();
}

void CPersoPiscine::on_Salaire_clicked()
{
    this->hide();
    SPersoPiscine *s=new SPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    s->show();
}

void CPersoPiscine::on_Stock_clicked()
{
    this->hide();
    STOCKPersoPiscine *stock=new STOCKPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    stock->show();
}

void CPersoPiscine::on_Back_clicked()
{
    this->hide();
    PersonnelPiscine *pe=new PersonnelPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    pe->show();
}
