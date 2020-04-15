#include "pisc.h"
#include "ui_cours.h"
#include "cours.h"

Cours::Cours(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cours)
{
    ui->setupUi(this);
    afficher_Cours();
    afficher_Reservation();
}

Cours::~Cours()
{
    delete ui;
}
/*Cours::Cours()
{
    this->ID_Cours=0;
    this->Date_Cours="";
    this->Horaire_Cours="";
    this->NBR_Reservation=0;
}
Cours::Cours(int id_cours,QString date_cours,QString horaire,int nbr_reservation)
{
    this->ID_Cours=id_cours;
    this->Date_Cours=date_cours;
    this->Horaire_Cours=horaire;
    this->NBR_Reservation=nbr_reservation;
}
Cours::Cours(const Cours &c)
{
    this->ID_Cours=c.ID_Cours;
    this->Date_Cours=c.Date_Cours;
    this->Horaire_Cours=c.Horaire_Cours;
    this->NBR_Reservation=c.NBR_Reservation;
}*/
int Cours::getID_Cours()
{
    return ID_Cours;
}
void Cours::setID_Cours(int id_cours)
{
    ID_Cours=id_cours;
}
QString Cours::getDate_Cours()
{
    return Date_Cours;
}
void Cours::setDate_Cous(QString date_cours)
{
    Date_Cours=date_cours;
}
QString Cours ::getNom_du_cours()
{
    return Nom_du_cours;
}
void Cours:: setNom_du_cours(QString NomC)
{
    Nom_du_cours=NomC;

}
QString Cours::getHoraire_Cours()
{
    return  Horaire_Cours;
}
void Cours::setHoraire_Cours(QString horaire)
{
    Horaire_Cours=horaire;
}
int Cours::getNBR_Reservation()
{
    return NBR_Reservation;
}
void Cours::setNBR_Reservation(int nbr_reservation)
{
    NBR_Reservation=nbr_reservation;
}
/********************************************************************************************************************************************************************************************/
void Cours::ajouter_Cours(int ID,QString Nom_du_cours,QString Date_Cours,QString Horaire_Cours,int NBR_Reservation)
{
    QSqlQuery qry;
    qDebug()<< Date_Cours ;
    struct tm *timeinfo;
    time_t t=time(nullptr);
    char buffer[50];
    time(&t);
    timeinfo=localtime(&t);
    strftime(buffer,50,"%d/%m/%Y",timeinfo);
    qDebug()<< ID << Date_Cours << Nom_du_cours <<Horaire_Cours << NBR_Reservation ;
    qry.prepare("INSERT INTO COURS (ID,NOM_DU_COURS,DATE_DU_COURS,HORAIRE,NBR_RESERVATION)"
                "VALUES(?,?,?,?,?)");
       qry.addBindValue(ID);
       qry.addBindValue(Nom_du_cours);
       qry.addBindValue(Date_Cours);
       qry.addBindValue(Horaire_Cours);
       qry.addBindValue(NBR_Reservation);
       qDebug() <<qry.exec();
       QMessageBox msgBox;
       msgBox.setText("Cours a ete ajoute.");
       msgBox.exec();
       afficher_Cours();
}
void Cours::supprimer_Cours()
{
    QSqlQuery qry;
    int i=ui->AfficherCours->currentRow();
    int id=ui->AfficherCours->item(i,0)->text().toInt();
    qry.prepare("Delete from COURS where ID=(?)");
    qry.addBindValue(id);
    qry.exec();
    ui->AfficherCours->removeRow(i);
    QMessageBox msg;
    msg.setText("Suppression effectué");
                msg.exec();
}
void Cours::modifier_Cours(int ID,QString Nom_du_cours,QString Date_Cours,QString Horaire_Cours,int NBR_Reservation)
{
    QSqlQuery qry;
    qry.prepare("UPDATE Cours set NOM_DU_COURS=(?),DATE_DU_COURS=(?),HORAIRE=(?),NBR_RESERVATION=(?) where ID=(?) ");
    qry.addBindValue(Nom_du_cours);
    qry.addBindValue(QDate::fromString(Date_Cours,"dd/MM/YYYY"));
    qry.addBindValue(Horaire_Cours);
    qry.addBindValue(NBR_Reservation);
    qry.addBindValue(ID);
    qDebug() << qry.exec();
    QMessageBox msg;
    msg.setText("Modification effectué");
    msg.exec();
    ui->AfficherCours->clearContents();
    afficher_Cours();
}
void Cours::afficher_Cours()
{
    QSqlQuery qry;
   while(ui->AfficherCours->rowCount()>0)
       {
           ui->AfficherCours->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from COURS ");
           int c = -1;
           while (qry.next())
           {
               c++;
               ui->AfficherCours->insertRow(c);
               for (int j=0; j<5; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherCours->setItem(c,j,item1);
                   int x=c;
                   ui->AfficherCours->item(x,0)->setBackgroundColor(Qt::blue);
                }
             }
           qDebug() <<"Fin";
}
void Cours::afficher_Reservation()
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
                   this->ui->AfficherR->setItem(c,j,item1);
                   int x=c;
                   ui->AfficherR->item(x,0)->setBackgroundColor(Qt::yellow);
                  // ui->AfficherR->item(x,1)->setBackgroundColor(Qt::blue);
                }
             }
           qDebug() <<"Fin";
}
/*************************************************************************************************************************************************************************************************/
void Cours::on_Back_clicked()
{
    this->hide();
    Piscine *p=new Piscine;
    p->play_musicClick();
    p->show();
}

void Cours::on_Ajouter_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    setID_Cours(ui->ID->text().toInt());
    setNom_du_cours(ui->NomC->text());
    setDate_Cous(ui->DateCours->text());
    setHoraire_Cours(ui->HoraireC->text());
    setNBR_Reservation(ui->NBRR->text().toInt());
    ajouter_Cours( getID_Cours(), getNom_du_cours(),getDate_Cours(),getHoraire_Cours(),getNBR_Reservation());
}

void Cours::on_Supprimer_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    if(ui->AfficherCours->currentRow()!=-1)
    supprimer_Cours();
}

void Cours::on_Enregistrer_clicked()
{
      Piscine *p=new Piscine;
      p->play_musicClick();
      modifier_Cours(ui->IDP_2->text().toInt(),ui->NomP_2->text(),ui->DateCours_2->text(),ui->Horaire->text(),ui->NBR->text().toInt());
}

void Cours::on_AfficherCours_itemClicked(QTableWidgetItem *i)
{
    int j=ui->AfficherCours->currentRow();
    QTime Horaire=QTime::fromString((ui->AfficherCours->item(j,3)->text()),"m'mm'hcarss");
    QDate date=QDate::fromString(ui->AfficherCours->item(j,2)->text(),"dd/MM/yyyy");
    setID_Cours(ui->AfficherCours->item(j,0)->text().toInt());
    setNom_du_cours(ui->AfficherCours->item(j,1)->text());
    setDate_Cous(ui->AfficherCours->item(j,2)->text());
    setHoraire_Cours(ui->AfficherCours->item(j,3)->text());
    setNBR_Reservation(ui->AfficherCours->item(j,4)->text().toInt());
    ui->IDP_2->setText(ui->AfficherCours->item(j,0)->text());
    ui->NomP_2->setText(ui->AfficherCours->item(j,1)->text());
    ui->DateCours_2->setDate(date);
    ui->Horaire->setTime(Horaire);
    ui->NBR->setText((ui->AfficherCours->item(j,4)->text()));

}

void Cours::on_Abonne_clicked()
{
   Piscine *p=new Piscine;
   p->play_musicClick();
   this->hide();
   Abonne *a=new Abonne;
   a->show();
}

void Cours::on_Abonnement_clicked()
{
    this->hide();
    Abonnement *ab=new Abonnement;
    Piscine *p=new Piscine;
    p->play_musicClick();
    ab->show();
}

void Cours::on_Stock_clicked()
{
   this->hide();
   Produit *pr=new Produit;
   Piscine *p=new Piscine;
   p->play_musicClick();
   pr->show();
}

void Cours::on_Promotion_clicked()
{
    this->hide();
    Promotion *promo=new Promotion;
    Piscine *p=new Piscine;
    p->play_musicClick();
    promo->show();
}
