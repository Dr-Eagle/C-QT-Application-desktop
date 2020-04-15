#include "pisc.h"
#include "ui_admin.h"
#include "admin.h"
#include "include.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    afficher_Personne(1);
    afficher_PersonneA();
    Abonnement *a=new Abonnement();
    a->afficher_Abonnement(2);
    afficher_Abonnement();
}

Admin::~Admin()
{
    delete ui;
}
/*************************************************************************************************************************************************************************************************/
int Admin :: getID()
{
    return  ID;
}
void Admin ::setID(int id)
{
    ID=id;
}
int Admin ::getNumero_tel()
{
    return Numero_tel;
}
void Admin ::setNumero_tel(int numtel)
{
    Numero_tel =numtel;
}
QString Admin ::getDate_de_naissance()
{
    return Date_de_naissance;
}
void Admin ::setDate_de_naissance(QString date_naissance)
{
    Date_de_naissance=date_naissance;
}
QString Admin ::getAdresse()
{
    return Adresse;
}
void Admin ::setAdresse(QString adresse)
{
    Adresse=adresse;
}
QString Admin ::getNom()
{
    return Nom;
}
void Admin ::setNom(QString nom)
{
    Nom=nom;
}
QString Admin ::getPrenom()
{
    return Prenom;
}
void Admin ::setPrenom(QString prenom)
{
    Prenom=prenom;
}
QString Admin ::getEmail()
{
    return Email;
}
void Admin ::setEmail(QString email)
{
    Email=email;
}
QString Admin ::getType()
{
    return Type;
}
void Admin ::setType(QString type)
{
    Type=type;
}
QString Admin ::getMot_de_passe()
{
    return Mot_de_passe;
}
void Admin ::setMot_de_passe(QString mot_de_passe)
{
    Mot_de_passe=mot_de_passe;
}
/********************************************************************************************************************************************************************************************/
void Admin::ajouter_Personne(int ID,QString Nom,QString Prenom,int Numero_tel,QString Type,QString Date_de_naissance,QString Email,QString Adresse,QString Mot_de_passe)
{
    QSqlQuery qry;
    qDebug()<< ID << Date_de_naissance <<Numero_tel <<Adresse << Nom << Prenom << Email<< Type << Mot_de_passe ;
   qry.prepare("INSERT INTO PERSONNE (ID,NOM,PRENOM,NUMERO,TYPE,DATE_DE_NAISSANCE,EMAIL,ADRESSE,MOT_DE_PASSE)"
                "VALUES(?,?,?,?,?,?,?,?,?)");
       qry.addBindValue(ID);
       qry.addBindValue(Nom);
       qry.addBindValue(Prenom);
       qry.addBindValue(Numero_tel);
       qry.addBindValue(Type);
       qry.addBindValue(Date_de_naissance);
       qry.addBindValue(Email);
       qry.addBindValue(Adresse);
       qry.addBindValue(Mot_de_passe);
       qDebug() <<qry.exec();
       QMessageBox msgBox;
       msgBox.setText("Personne a ete ajoute.");
       msgBox.exec();
       afficher_Personne(1);
       afficher_PersonneA();
}
void Admin::supprimer_Personne()
{
    QSqlQuery qry;
    int i=ui->AfficherP->currentRow();
    int id=ui->AfficherP->item(i,0)->text().toInt();
    qry.prepare("Delete from PERSONNE where ID=(?)");
    qry.addBindValue(id);
    qry.exec();
    qry.prepare("Delete from ABONNEMENT where ID_PERSONNE=(?)");
    qry.addBindValue(id);
    qry.exec();
    ui->AfficherP->removeRow(i);
    QMessageBox msg;
    msg.setText("Suppression effectué");
                msg.exec();
}
void Admin::modifier_Personne(int ID,QString Nom,QString Prenom,int Numero_Tel,QString Type,QString Date_de_naissance,QString Email,QString Adresse)
{
    QSqlQuery qry;
    qry.prepare("UPDATE PERSONNE set NOM=(?),PRENOM=(?),NUMERO=(?),TYPE=(?),DATE_DE_NAISSANCE=(?),EMAIL=(?),ADRESSE=(?) where ID=(?) ");
    qry.addBindValue(Nom);
    qry.addBindValue(Prenom);
    qry.addBindValue(Numero_Tel);
    qry.addBindValue(Type);
    qry.addBindValue(QDate::fromString(Date_de_naissance,"dd/MM/YYYY"));
    qry.addBindValue(Email);
    qry.addBindValue(Adresse);
    qry.addBindValue(ID);
    qDebug() << qry.exec();
    QMessageBox msg;
    msg.setText("Modification effectué");
    msg.exec();
    ui->AfficherP->clearContents();
    afficher_Personne(1);
}
void Admin::afficher_Personne(int a)
{
    if(a==1)
    {
        QSqlQuery qry;
       while(ui->AfficherP->rowCount()>0)
           {
               ui->AfficherP->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from PERSONNE ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherP->insertRow(c);
                   for (int j=0; j<9; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherP->setItem(c,j,item1);
                       int x=c;
                       ui->AfficherP->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
   else if (a==2)
    {
        QSqlQuery qry;
       while(ui->AfficherP->rowCount()>0)
           {
               ui->AfficherP->removeRow(0);
           }
        qDebug()<<"ok";
           qry.exec("select * from PERSONNE order by ID asc ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherP->insertRow(c);
                   for (int j=0; j<9; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherP->setItem(c,j,item1);
                       int x=c;
                       ui->AfficherP->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
    }
}
/***********************************************************************************************************************************************************************************************/
void Admin::afficher_PersonneA()
{

        QSqlQuery qry;
       while(ui->AfficherPA->rowCount()>0)
           {
               ui->AfficherPA->removeRow(0);

           }
        qDebug()<<"ok";
           qry.exec("select * from PERSONNE ");
               int c = -1;
               while (qry.next())
               {
                   c++;
                   ui->AfficherPA->insertRow(c);
                   for (int j=0; j<9; j++)
                   {
                       QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                       this->ui->AfficherPA->setItem(c,j,item1);
                       int x=c;
                       ui->AfficherP->item(x,0)->setBackgroundColor(Qt::blue);
                    }
                 }
               qDebug() <<"Fin";
}
void Admin::afficher_Abonnement()
{
    QSqlQuery qry;
   while(ui->AfficherA->rowCount()>0)
       {
           ui->AfficherA->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from ABONNEMENT");
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
void Admin::supprimer_Abonnement()
{
    QSqlQuery qry;
    int i=ui->AfficherA->currentRow();
    int id=ui->AfficherA->item(i,0)->text().toInt();
    qry.prepare("Delete from ABONNEMENT where ID_ABONNEMENT=(?)");
    qry.addBindValue(id);
    qry.exec();
    ui->AfficherA->removeRow(i);
    QMessageBox msg;
    msg.setText("Suppression effectué");
                msg.exec();
}

void Admin::modifier_Abonnement(int ID_Abonnement,QString Type,double Prix,QString Date_Fin,int Duree)
{
    QSqlQuery qry;
    qry.prepare("UPDATE ABONNEMENT set TYPE=(?),PRIX=(?),DATE_FIN=(?),DUREE=(?) where ID_ABONNEMENT=(?) ");
    qry.addBindValue(Type);
    qry.addBindValue(Prix);
    qry.addBindValue(QDate::fromString(Date_Fin,"dd/MM/YYYY"));
    qry.addBindValue(Duree);
    qry.addBindValue(ID_Abonnement);
    qDebug() << qry.exec();
    QMessageBox msg;
    msg.setText("Modification effectué");
    msg.exec();
    ui->AfficherA->clearContents();
    afficher_Abonnement();
}
/************************************************************************************************************************************************************************************************************/
void Admin::on_BPiscine_clicked()
{
    this->hide();
    Piscine *p=new Piscine;
    p->play_musicClick();
    p->show();

}

void Admin::on_Back_clicked()
{
    this->hide();
    Login *l=new Login;
    Piscine *p=new Piscine;
    p->play_musicClick();
    l->show();
}

void Admin::on_Ajouter_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    setID(ui->ID->text().toInt());
    setNom(ui->NomP->text());
    setPrenom(ui->PrenomP->text());
    setNumero_tel(ui->Numero->text().toInt());
    setType(ui->Type->text());
    setDate_de_naissance(ui->Date->text());
    setEmail(ui->Email->text());
    setAdresse(ui->Adresse->text());
    setMot_de_passe(ui->MDP->text());
    ajouter_Personne(getID(),getNom(),getPrenom(),getNumero_tel(),getType(),getDate_de_naissance(),getEmail(),getAdresse(),getMot_de_passe());
}

void Admin::on_Supp_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    if(ui->AfficherP->currentRow()!=-1)
    supprimer_Personne();
}

void Admin::on_Modf_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    modifier_Personne(ui->ID_2->text().toInt(),ui->NomP_2->text(),ui->PrenomP_2->text(),ui->num->text().toInt(),ui->type->text(),ui->date2->text(),ui->email->text(),ui->adresse->text());
}

void Admin::on_AfficherP_itemClicked(QTableWidgetItem *i)
{
    int j=ui->AfficherP->currentRow();
    QDate date=QDate::fromString(ui->AfficherP->item(j,5)->text(),"dd/MM/yyyy");
    setID(ui->AfficherP->item(j,0)->text().toInt());
    setNom(ui->AfficherP->item(j,1)->text());
    setPrenom(ui->AfficherP->item(j,2)->text());
    setNumero_tel(ui->AfficherP->item(j,3)->text().toInt());
    setType(ui->AfficherP->item(j,4)->text());
    setDate_de_naissance(ui->AfficherP->item(j,5)->text());
    setEmail(ui->AfficherP->item(j,6)->text());
    setAdresse(ui->AfficherP->item(j,7)->text());


    ui->ID_2->setText(ui->AfficherP->item(j,0)->text());
    ui->NomP_2->setText((ui->AfficherP->item(j,1)->text()));
    ui->PrenomP_2->setText((ui->AfficherP->item(j,2)->text()));
    ui->num->setText((ui->AfficherP->item(j,3)->text()));
    ui->type->setText((ui->AfficherP->item(j,4)->text()));
    ui->Date->setDate(date);
    ui->email->setText((ui->AfficherP->item(j,6)->text()));
    ui->adresse->setText((ui->AfficherP->item(j,7)->text()));
}

void Admin::on_TRI_clicked()
{
    afficher_Personne(2);
}
void Admin::on_AfficherPA_itemClicked(QTableWidgetItem *i)
{
    Abonnement *a=new Abonnement();
    int j=ui->AfficherPA->currentRow();
    a->setID_Abonne(ui->AfficherPA->item(j,0)->text().toInt());
}
void Admin::on_AjouterAb_clicked()
{
    if(ui->AfficherPA->currentRow()!=-1);
    {
        Abonnement *a=new Abonnement();
        Piscine *p=new Piscine;
        p->play_musicClick();
        a->setID_Abonnement(ui->IDA->text().toInt());
        a->setType(ui->comboBoxA->currentText());
        a->setPrix(ui->PrixA->text().toDouble());
        a->setDate_Fin(ui->DateFinA->text());
        a->setDuree(ui->DureeA->text().toInt());
        int j=ui->AfficherPA->currentRow();
        a->setID_Abonne(ui->AfficherPA->item(j,0)->text().toInt());
        a->ajouter_Abonnement(a->getID_Abonnement(),a->getType(),a->getPrix(),a->getDate_Fin(),a->getDuree(),a->getID_Abonne());
    }
}



void Admin::on_TRIC_clicked()
{
    Abonnement *a=new Abonnement();
    a->afficher_Abonnement(2);
}


void Admin::on_Supprimer_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    if(ui->AfficherA->currentRow()!=-1)
    supprimer_Abonnement();
}

void Admin::on_Modifier_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    modifier_Abonnement(ui->IDA_2->text().toInt(),ui->comboBoxA_2->currentText(),ui->PrixAB->text().toDouble(),ui->DateFinA_2->text(),ui->DureeA_2->text().toInt());

}
void Admin::on_TRI_2_clicked()
{

}
void Admin::on_AfficherA_itemClicked(QTableWidgetItem *i)
{
    Abonnement *a=new Abonnement();
    int j=ui->AfficherA->currentRow();
    QDate date=QDate::fromString(ui->AfficherA->item(j,4)->text(),"dd/MM/yyyy");
    a->setID_Abonnement(ui->AfficherA->item(j,0)->text().toInt());
    a->setType(ui->AfficherA->item(j,1)->text());
    a->setPrix(ui->AfficherA->item(j,2)->text().toDouble());
    a->setDate_Fin(ui->AfficherA->item(j,4)->text());
    a->setDuree(ui->AfficherA->item(j,5)->text().toInt());

    ui->IDA_2->setText(ui->AfficherA->item(j,0)->text());
    ui->comboBoxA_2->setCurrentText((ui->AfficherA->item(j,1)->text()));
    ui->PrixAB->setText((ui->AfficherA->item(j,2)->text()));
    ui->DateFinA_2->setDate(date);
    ui->DureeA_2->setText((ui->AfficherA->item(j,5)->text()));

}
