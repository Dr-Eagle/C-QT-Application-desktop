#include "eabonnement.h"
#include "ui_eabonnement.h"
#include "pisc.h"
#include "enotification.h"

EAbonnement::EAbonnement(int id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EAbonnement)
{
    ui->setupUi(this);
    qDebug() << id << "eabonne";
    Setid(id);
    afficher_Abonnement();
    afficher_Cours();
    afficher_Stock();
}
EAbonnement::EAbonnement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EAbonnement)
{
    ui->setupUi(this);
    afficher_Abonnement();
    afficher_Cours();
    afficher_Stock();
}
EAbonnement::~EAbonnement()
{
    delete ui;
}
/*********************************************************************************************************************************************************************************************/
void EAbonnement::afficher_Cours()
{
    QSqlQuery qry;
   while(ui->AfficherCo->rowCount()>0)
       {
           ui->AfficherCo->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from COURS ");
           int c = -1;
           while (qry.next())
           {
               c++;
               ui->AfficherCo->insertRow(c);
               for (int j=0; j<5; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherCo->setItem(c,j,item1);
                   int x=c;
                   ui->AfficherCo->item(x,0)->setBackgroundColor(Qt::yellow);
                }
             }
           qDebug() <<"Fin";
}
void EAbonnement ::afficher_Stock()
{
    QSqlQuery qry;
   while(ui->AfficherST->rowCount()>0)
       {
           ui->AfficherST->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from Produit ");
           int c = -1;
           while (qry.next())
           {
               c++;
               ui->AfficherST->insertRow(c);
               for (int j=0; j<4; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherST->setItem(c,j,item1);
                   int x=c;
                   ui->AfficherST->item(x,0)->setBackgroundColor(Qt::blue);
                }
             }
           qDebug() <<"Fin";
}
void EAbonnement::reserver_Cours()
{
     ENotification *en=new ENotification("smartsmartup@gmail.com","smartup123","smtp.gmail.com");
     connect(en, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
     QSqlQuery qry,qury;
     if(ui->AfficherCo->currentRow()>=0)
     {
         if (ui->AfficherCo->item(ui->AfficherCo->currentRow(),4)->text().toInt() < 1)
              {
                  QMessageBox msgBox;
                  msgBox.setText("Nous sommes désolé mais le cours n'est plus disponible .");
                  msgBox.exec();
              }
         else
         {struct tm *timeinfo;
         time_t t=time(nullptr);
         char buffer[50];
         time(&t);
         timeinfo=localtime(&t);
         strftime(buffer,50,"%d/%m/%Y",timeinfo);
        qry.prepare("UPDATE COURS set NBR_RESERVATION=NBR_RESERVATION-1 where ID=(?);");
        qry.addBindValue(ui->AfficherCo->item(ui->AfficherCo->currentRow(),0)->text().toInt());
        qDebug()<<qry.exec();
        qury.prepare("INSERT INTO RESERVATION_COURS (ID_PERSONNE, ID_COURS , DATE_RESERVATION) VALUES(?,?,?) ; ");
        qury.addBindValue(this->Getid());
        qury.addBindValue(ui->AfficherCo->item(ui->AfficherCo->currentRow(),0)->text().toInt());
        qury.addBindValue(buffer);
        qDebug() << qury.exec();
        QMessageBox msgBox;
        msgBox.setText("Reservation a ete ajoute.");
        msgBox.exec();
        const QString body = "Vous avez effectué la réservation du cours " + ui->AfficherCo->item(ui->AfficherCo->currentRow(),1)->text() + " qui va etre déroulé le " + ui->AfficherCo->item(ui->AfficherCo->currentRow(),2)->text() + ' ' + ui->AfficherCo->item(ui->AfficherCo->currentRow(),3)->text();
        qDebug() << body ;
        qDebug() << "connexion mail khatfét" ;
        en->sendMail("smartsmartup@gmail.com", "youssef.darderi@esprit.tn" , "Confirmation de la réservation du cours " + ui->AfficherCo->item(ui->AfficherCo->currentRow(),1)->text() , "Vous avez effectué la réservation du cours " + ui->AfficherCo->item(ui->AfficherCo->currentRow(),1)->text() + " qui va etre déroulé le " +  ui->AfficherCo->item(ui->AfficherCo->currentRow(),2)->text() +  "\n Horaire : " + ui->AfficherCo->item(ui->AfficherCo->currentRow(),3)->text()  );
        afficher_Cours();}
     }
}

void EAbonnement::commander_Produit()
{
     ENotification *en=new ENotification("smartsmartup@gmail.com","smartup123","smtp.gmail.com");
     connect(en, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
     QSqlQuery qry,qury;
     if(ui->AfficherST->currentRow()>=0)
     {
         if (ui->AfficherST->item(ui->AfficherST->currentRow(),3)->text().toInt() < 1)
              {
                  QMessageBox msgBox;
                  msgBox.setText("Nous sommes désolé mais le produit demandé n'est plus disponible .");
                  msgBox.exec();
              }
         else
         {struct tm *timeinfo;
         time_t t=time(nullptr);
         char buffer[50];
         time(&t);
         timeinfo=localtime(&t);
         strftime(buffer,50,"%d/%m/%Y",timeinfo);
        qry.prepare("UPDATE PRODUIT set QUANTITE=QUANTITE-1 where REFERENCE=(?);");
        qry.addBindValue(ui->AfficherST->item(ui->AfficherST->currentRow(),0)->text().toInt());
        qDebug()<<qry.exec();
        qury.prepare("INSERT INTO COMMANDE (ID_PERSONNE, ID_PRODUIT , DATE_COMMANDE) VALUES(?,?,?) ; ");
        qury.addBindValue(this->Getid());
        qury.addBindValue(ui->AfficherST->item(ui->AfficherST->currentRow(),0)->text().toInt());
        qury.addBindValue(buffer);
        qDebug() << qury.exec();
        QMessageBox msgBox;
        msgBox.setText("Commande a ete ajoute.");
        msgBox.exec();
        const QString body = "Vous avez effectué la commande du produit " + ui->AfficherST->item(ui->AfficherST->currentRow(),2)->text() + "\n prix : " + ui->AfficherST->item(ui->AfficherST->currentRow(),1)->text();
        qDebug() << body ;
        qDebug() << "connexion mail khatfét" ;
        en->sendMail("smartsmartup@gmail.com", "youssef.darderi@esprit.tn" , "Confirmation de la commande du produit " + ui->AfficherST->item(ui->AfficherST->currentRow(),2)->text() , body);
        afficher_Stock();}
     }
}
void EAbonnement::afficher_Abonnement()
{
    QSqlQuery qry;
    while(ui->AfficherA->rowCount()>0)
       {
           ui->AfficherA->removeRow(0);
       }
    qDebug()<<"ok";
       qry.prepare("select * from ABONNEMENT where ID_PERSONNE=(?);");
       qry.addBindValue(this->Getid());
       qDebug() << Getid() << "ekher wahda ";
       qDebug() << qry.exec();
           int c = -1;
           while (qry.next())
           {
               c++;
               ui->AfficherA->insertRow(c);
               for (int j=0; j<7; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherA->setItem(c,j,item1);
                   int x=c;
                   ui->AfficherA->item(x,0)->setBackgroundColor(Qt::blue);
                }
             }
           qDebug() <<"Fin";
}
/***********************************************************************************************************************************************************************************************/
void EAbonnement::on_Commander_clicked()
{
    commander_Produit();
}
void EAbonnement::on_Classe_clicked()
{
    this->hide();
    EClasse *ec=new EClasse();
    Piscine *p=new Piscine;
    p->play_musicClick();
    ec->show();
}

void EAbonnement::on_Notification_clicked()
{
    this->hide();
    ENotification *en=new ENotification();
    Piscine *p=new Piscine;
    p->play_musicClick();
    en->show();
}

void EAbonnement::on_Back_clicked()
{
    this->hide();
    Etudiant *etud=new Etudiant(Getid());
    Piscine *p=new Piscine;
    p->play_musicClick();
    etud->show();
}
void EAbonnement::on_Reserver_clicked()
{
    reserver_Cours();
}
