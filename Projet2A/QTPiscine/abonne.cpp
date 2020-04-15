#include "pisc.h"
#include "ui_abonne.h"
#include "abonne.h"

Abonne::Abonne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Abonne)
{
    ui->setupUi(this);
    Piscine *p=new Piscine;
    afficher_Abonne();
}

Abonne::~Abonne()
{
    delete ui;
}
/**********************************************************************************************************************************************************************************************/
void Abonne::afficher_Abonne()
{
    QSqlQuery qry;
    QSqlQuery qury;
    while(ui->AfficherA->rowCount()>0)
        {
            ui->AfficherA->removeRow(0);
        }
    int c = -1;
    qury.prepare("select ID_PERSONNE from ABONNEMENT where TYPE = 'Piscine' ");
    qury.exec();
        while ( qury.next() )
        {
            qry.prepare("select * from personne where id=(?)");
            qry.addBindValue(qury.value(0));
            qry.exec();
            qDebug()<<"ok";
           while (qry.next())
           {
               c++;
               ui->AfficherA->insertRow(c);
               for (int j=0; j<9; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherA->setItem(c,j,item1);
                   int x=c;
                   ui->AfficherA->item(x,0)->setBackgroundColor(Qt::blue);
                }
             }
           qDebug() <<"Fin";
        }
}
/********************************************************************************************************************************************************************************************/
void Abonne::on_Back_clicked()
{
    this->hide();
    Piscine *p=new Piscine;
    p->play_musicClick();
    p->show();
}

void Abonne::on_Abonnement_clicked()
{
    this->hide();
    Abonnement *ab=new Abonnement;
    Piscine *p=new Piscine;
    p->play_musicClick();
    ab->show();
}

void Abonne::on_Cours_clicked()
{
   this->hide();
   Cours *c=new Cours;
   Piscine *p=new Piscine;
   p->play_musicClick();
   c->show();
}

void Abonne::on_Stock_clicked()
{
   this->hide();
   Produit *pr=new Produit;
   Piscine *p=new Piscine;
   p->play_musicClick();
   pr->show();
}

void Abonne::on_Promotion_clicked()
{
    this->hide();
    Promotion *promo=new Promotion;
    Piscine *p=new Piscine;
    p->play_musicClick();
    promo->show();
}
