#include "ui_produit.h"
#include "include.h"
#include "pisc.h"
#include "produit.h"


Produit::Produit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Produit)
{
    ui->setupUi(this);
    afficher_Stock();
    afficher_Commande();
}

Produit::~Produit()
{
    delete ui;
}
/**********************************************************************************************************************************************************************************************/
/*Produit::Produit()
{
    this->Reference=0;
    this->Nom_Produit="";
    this->Prix_Unitaire=0;
    this->Quantite=0;
}
Produit::Produit(int ref,float prixu,QString nomp,int quantite)
{
    this->Reference=ref;
    this->Nom_Produit=nomp;
    this->Prix_Unitaire=prixu;
    this->Quantite=quantite;
}

Produit::Produit(const Produit &prod)
{

    this->Reference=prod.Reference;
    this->Nom_Produit=prod.Nom_Produit;
    this->Prix_Unitaire=prod.Prix_Unitaire;
    this->Quantite=prod.Quantite;
}*/
/**********************************************************************************************************************************************************************************************************/
int Produit::getReference()
{
    return Reference;
}
void Produit::setReference(int ref)
{
    Reference=ref;
}
QString Produit::getNom()
{
    return Nom_Produit;
}
void Produit::setNom(QString nomp)
{
    Nom_Produit=nomp;
}
double Produit::getPrix_unitaire()
{
    return Prix_Unitaire;
}
void Produit::setPrix_unitaire(double prixu)
{
    Prix_Unitaire=prixu;
}
int Produit::getQuantite()
{
    return Quantite;
}
void Produit::setQuantite(int quantite)
{
    Quantite=quantite;
}
/********************************************************************************************************************************************************************************************************/
void Produit::ajouter_Produit(int Reference,double Prix_Unitaire,QString Nom_Produit,int Quantite)
{
     QSqlQuery qry;
     qDebug()<< Reference << Prix_Unitaire << Nom_Produit << Quantite ;
    qry.prepare("INSERT INTO PRODUIT (REFERENCE,PRIX_UNITAIRE,NOM_PRODUIT,QUANTITE)"
                 "VALUES(?,?,?,?)");
        qry.addBindValue(Reference);
        qry.addBindValue(Prix_Unitaire);
        qry.addBindValue(Nom_Produit);
        qry.addBindValue(Quantite);
        qDebug() <<qry.exec();
        QMessageBox msgBox;
        msgBox.setText("Le Produit a ete ajoute.");
        msgBox.exec();
        afficher_Stock();
}
void Produit::afficher_Stock()
{
     QSqlQuery qry;
    while(ui->Afficher->rowCount()>0)
        {
            ui->Afficher->removeRow(0);
        }
     qDebug()<<"ok";
        qry.exec("select * from Produit ");
            int c = -1;
            while (qry.next())
            {
                c++;
                ui->Afficher->insertRow(c);
                for (int j=0; j<4; j++)
                {
                    QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                    this->ui->Afficher->setItem(c,j,item1);
                    int x=c;
                    ui->Afficher->item(x,0)->setBackgroundColor(Qt::blue);
                 }
              }
            qDebug() <<"Fin";
}
void Produit::modifier_Produit(int Reference,double Prix_Unitaire,QString Nom_Produit,int Quantite)
{
    QSqlQuery qry;
    qry.prepare("UPDATE PRODUIT set PRIX_UNITAIRE=(?),NOM_PRODUIT=(?),QUANTITE=(?) where REFERENCE=(?) ");
    qry.addBindValue(Prix_Unitaire);
    qry.addBindValue(Nom_Produit);
    qry.addBindValue(Quantite);
    qry.addBindValue(Reference);
    qDebug() << qry.exec();
    QMessageBox msg;
    msg.setText("Modification effectué");
    msg.exec();
    ui->Afficher->clearContents();
    afficher_Stock();

}
void Produit::afficher_Commande()
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
                   ui->AfficherC->item(x,0)->setBackgroundColor(Qt::blue);

                }
             }
           qDebug() <<"Fin";
}

void Produit::supprimer_Produit()
{
    QSqlQuery qry;
    int i=ui->Afficher->currentRow();
                int id=ui->Afficher->item(i,0)->text().toInt();
                qry.prepare("Delete from PRODUIT where REFERENCE=(?)");
                qry.addBindValue(id);
                qry.exec();
                ui->Afficher->removeRow(i);
                QMessageBox msg;
                msg.setText("Suppression effectué");
                msg.exec();
}
/*******************************************************************************************************************************************************************************************/
void Produit::on_AjouterProduit_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    setReference(ui->Reference->text().toInt());
    setPrix_unitaire(ui->Prix_u->text().toDouble());
    setNom(ui->Nom_Produit->text());
    setQuantite(ui->quantite->text().toInt());
    ajouter_Produit( getReference(), getPrix_unitaire(), getNom(), getQuantite());
}

void Produit::on_supprimer_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();

    if(ui->Afficher->currentRow()!=-1)
    supprimer_Produit();
}
void Produit::on_Afficher_itemClicked(QTableWidgetItem *i)
{
    int j=ui->Afficher->currentRow();
    setNom(ui->Afficher->item(j,1)->text());
    setReference(ui->Afficher->item(j,0)->text().toInt());
    setPrix_unitaire(ui->Afficher->item(j,3)->text().toDouble());
    setQuantite(ui->Afficher->item(j,2)->text().toInt());
    ui->modif_ref->setText(ui->Afficher->item(j,0)->text());
    ui->modif_nom->setText(ui->Afficher->item(j,2)->text());
    ui->modif_prix->setText((ui->Afficher->item(j,1)->text()));
    ui->modif_qte->setText(ui->Afficher->item(j,3)->text());
}
void Produit::on_pushButton_11_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();

    modifier_Produit( ui->modif_ref->text().toInt(),ui->modif_prix->text().toDouble(),ui->modif_nom->text(),ui->modif_qte->text().toInt());
}
void Produit::on_pushButton_6_clicked()
{
    this->hide();
    Promotion *promo=new Promotion;
    Piscine *p=new Piscine;
    p->play_musicClick();
    promo->show();
}

void Produit::on_Back_clicked()
{
    this->hide();
    Piscine *p=new Piscine;
    p->play_musicClick();
    p->show();
}

void Produit::on_Abonne_clicked()
{
    this->hide();
    Abonne *a =new Abonne;
    Piscine *p=new Piscine;
    p->play_musicClick();
    a->show();
}

void Produit::on_Abonnement_clicked()
{
    this->hide();
    Abonnement *ab =new Abonnement;
    Piscine *p=new Piscine;
    p->play_musicClick();
    ab->show();
}

void Produit::on_Cours_clicked()
{
    this->hide();
    Cours *c =new Cours;
    Piscine *p=new Piscine;
    p->play_musicClick();
    c->show();
}

void Produit::on_Promotion_clicked()
{
    this->hide();
    Promotion *promo =new Promotion;
    Piscine *p=new Piscine;
    p->play_musicClick();
    promo->show();
}
