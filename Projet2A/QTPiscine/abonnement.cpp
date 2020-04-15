#include "pisc.h"
#include "ui_abonnement.h"
#include "abonnement.h"


Abonnement::Abonnement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Abonnement)
{
    ui->setupUi(this);
    afficher_Abonnement(1);
}

Abonnement::~Abonnement()
{
    delete ui;
}
/*Abonnement::Abonnement()
{
    this->ID_Abonnement=0;
    this->Duree=0;
    this->Date_Debut="";
    this->Date_Fin="";
    this->Prix=0;
}
Abonnement::Abonnement(int id_abonnement,int duree,QString dated,QString datef,float prix)
{
    this->ID_Abonnement=id_abonnement;
    this->Duree=duree;
    this->Date_Debut=dated;
    this->Date_Fin=datef;
    this->Prix=prix;
}
Abonnement::Abonnement(const Abonnement &a)
{
    this->ID_Abonnement=a.ID_Abonnement;
    this->Duree=a.Duree;
    this->Date_Debut=a.Date_Debut;
    this->Date_Fin=a.Date_Fin;
    this->Prix=a.Prix;
}
*/
/********************************************************************************************************************************************************************************************/
int Abonnement::getID_Abonnement()
{
    return ID_Abonnement;
}
void Abonnement::setID_Abonnement(int id_abonnement)
{
    ID_Abonnement=id_abonnement;
}
QString Abonnement::getType()
{
    return Type;
}
void Abonnement::setType(QString type)
{
    Type=type;
}
int Abonnement::getID_Abonne()
{
    return ID_Abonne;
}
void Abonnement::setID_Abonne(int ID_abonne)
{
    ID_Abonne=ID_abonne;
}
int Abonnement::getDuree()
{
    return Duree;
}
void Abonnement::setDuree(int duree)
{
    Duree=duree;
}
QString Abonnement::getDate_Debut()
{
    return Date_Debut;
}
void Abonnement::setDate_Debut(QString dated)
{
    Date_Debut=dated;
}
QString Abonnement::getDate_Fin()
{
    return  Date_Fin;
}
void Abonnement::setDate_Fin(QString datef)
{
    Date_Fin=datef;
}
double Abonnement::getPrix()
{
    return Prix;
}
void Abonnement::setPrix(double prix)
{
    Prix=prix;
}
/*********************************************************************************************************************************************************************************************/
void Abonnement::ajouter_Abonnement(int ID_Anonnement,QString Type,double Prix,QString Date_Fin,int Duree,int ID_Abonne)
{
    QSqlQuery qry;
    struct tm *timeinfo;

    time_t t=time(nullptr);
    char buffer[50];
    time(&t);
    timeinfo=localtime(&t);
    strftime(buffer,50,"%d/%m/%Y",timeinfo);
    qDebug()<< ID_Anonnement <<Type <<Prix<<Date_Debut<<Date_Fin<<Duree<<ID_Abonne;
    qry.prepare("INSERT INTO ABONNEMENT (ID_ABONNEMENT,TYPE,PRIX,DATE_DEBUT,DATE_FIN,DUREE,ID_PERSONNE)"
                "VALUES(?,?,?,?,?,?,?)");
       qry.addBindValue(ID_Anonnement);
       qry.addBindValue(Type);
       qry.addBindValue(Prix);
       qry.addBindValue(buffer);
       qry.addBindValue(Date_Fin);
       qry.addBindValue(Duree);
       qry.addBindValue(ID_Abonne);
       qDebug() <<qry.exec();
       QMessageBox msgBox;
       msgBox.setText("Abonnement a ete ajoute.");
       msgBox.exec();
       afficher_Abonnement(1);
}
void Abonnement::afficher_Abonnement(int a)
{
    if (a==1)
    {
        QSqlQuery qry;
       while(ui->AfficherAB->rowCount()>0)
           {
               ui->AfficherAB->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from ABONNEMENT where TYPE ='Piscine' ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherAB->insertRow(c);
                   for (int j=0; j<7; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherAB->setItem(c,j,item1);
                       int x=c;
                       ui->AfficherAB->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
    else if (a==2)
    {
        QSqlQuery qry;
       while(ui->AfficherAB->rowCount()>0)
           {
               ui->AfficherAB->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from ABONNEMENT where TYPE ='Piscine' order by ID_ABONNEMENT asc ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherAB->insertRow(c);
                   for (int j=0; j<7; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherAB->setItem(c,j,item1);int x=c;
                       ui->AfficherAB->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }

}
void Abonnement::supprimer_Abonnement()
{
    QSqlQuery qry;
    int i=ui->AfficherAB->currentRow();
    int id=ui->AfficherAB->item(i,0)->text().toInt();
    qry.prepare("Delete from ABONNEMENT where ID_ABONNEMENT=(?)");
    qry.addBindValue(id);
    qry.exec();
    ui->AfficherAB->removeRow(i);
    QMessageBox msg;
    msg.setText("Suppression effectué");
                msg.exec();
}
/***************************************************************************************************************************************************************************************/
void Abonnement::on_Back_clicked()
{
    this->hide();
    Piscine *p=new Piscine;
    p->play_musicClick();
    p->show();
}

void Abonnement::on_Cours_clicked()
{
   this->hide();
   Cours *c=new Cours;
   Piscine *p=new Piscine;
   p->play_musicClick();
   c->show();
}

void Abonnement::on_Stock_clicked()
{
   this->hide();
   Produit *pr=new Produit;
   Piscine *p=new Piscine;
   p->play_musicClick();
   pr->show();
}

void Abonnement::on_Promotion_clicked()
{

    this->hide();
    Promotion *promo=new Promotion;
    Piscine *p=new Piscine;
    p->play_musicClick();
    promo->show();


}

void Abonnement::on_Abonne_clicked()
{

   this->hide();
   Abonne *n=new Abonne;
   Piscine *p=new Piscine;
   p->play_musicClick();
   n->show();

}
