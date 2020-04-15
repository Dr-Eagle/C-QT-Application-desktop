#include "pisc.h"
#include "ui_promotion.h"
#include "include.h"
#include "promotion.h"

Promotion::Promotion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Promotion)
{
    ui->setupUi(this);
    afficher_Promotion();
}

Promotion::~Promotion()
{
    delete ui;
}
/*Promotion::Promotion()
{
    this->Code_Promotion=0;
    this->Date_Debut="";
    this->Date_Fin="";
    this->Taux=0;
}
Promotion::Promotion(int code,QString dated,QString datef,float taux)
{
    this->Code_Promotion=code;
    this->Date_Debut=dated;
    this->Date_Fin=datef;
    this->Taux=taux;

}
Promotion::Promotion(const Promotion &pr)
{
    this->Code_Promotion=pr.Code_Promotion;
    this->Date_Debut=pr.Date_Debut;
    this->Date_Fin=pr.Date_Fin;
    this->Taux=pr.Taux;
}*/
/*******************************************************************************************************************************************************************************************/
int Promotion::getCode_Promotion()
{
    return Code_Promotion;
}
void Promotion::setCode_Promotion(int code)
{
    Code_Promotion=code;
}
QString Promotion::getDate_Fin()
{
    return  Date_Fin;
}
void Promotion::setDate_Fin(QString datef)
{
    Date_Fin=datef;
}
int Promotion ::getTaux()
{
    return Taux;
}
void Promotion::setTaux(int taux)
{
    Taux=taux;
}
/************************************************************************************************************************************************************************************************/
void Promotion::afficher_Promotion()
{
    QSqlQuery qry;
   while(ui->Afficher->rowCount()>0)
       {
           ui->Afficher->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from PROMOTION ");
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
void Promotion:: ajouter_Promotion(int Code_Promotion,QString Date_Fin,int Taux)
{
    QSqlQuery qry;
    qDebug()<< Date_Fin ;
    struct tm *timeinfo;

    time_t t=time(nullptr);
    char buffer[50];
    time(&t);
    timeinfo=localtime(&t);
    strftime(buffer,50,"%d/%m/%Y",timeinfo);
    qDebug()<< Code_Promotion << Taux << Date_Fin <<buffer ;
    qry.prepare("INSERT INTO PROMOTION (CODE,DATE_FIN,TAUX,DATE_DEBUT)"
                "VALUES(?,?,?,?)");
       qry.addBindValue(Code_Promotion);
       qry.addBindValue(Date_Fin);
       qry.addBindValue(Taux);
      qry.addBindValue(buffer);
       qDebug() <<qry.exec();
       QMessageBox msgBox;
       msgBox.setText("Promotion a ete ajoute.");
       msgBox.exec();
       afficher_Promotion();
}
void Promotion:: supprimer_Promotion()
{
    QSqlQuery qry;
    int i=ui->Afficher->currentRow();
    int id=ui->Afficher->item(i,0)->text().toInt();
    qry.prepare("Delete from PROMOTION where CODE=(?)");
    qry.addBindValue(id);
    qry.exec();
    ui->Afficher->removeRow(i);
    QMessageBox msg;
    msg.setText("Suppression effectué");
                msg.exec();
}

void Promotion:: modifier_Promotion(int Code_Promotion,QString Date_Fin,int Taux)
{
    //QDate::fromString(Date_Fin,"dd/MM/YYYY")

    QSqlQuery qry;
    qry.prepare("UPDATE PROMOTION set DATE_FIN=(?),TAUX=(?) where CODE=(?) ");
    qry.addBindValue(ui->modf_datef->text());
    qry.addBindValue(Taux);
    qry.addBindValue(Code_Promotion);
    qDebug() << qry.exec();
    QMessageBox msg;
    msg.setText("Modification effectué");
    msg.exec();
    ui->Afficher->clearContents();
    afficher_Promotion();
}
/******************************************************************************************************************************************************************************************/
void Promotion::on_Ajouter_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    setCode_Promotion(ui->Code->text().toInt());
    setDate_Fin(ui->Date_Fin->text());
    setTaux(ui->Taux->text().toInt());
    ajouter_Promotion( getCode_Promotion(), getDate_Fin(), getTaux());
}

void Promotion::on_Supprimer_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    if(ui->Afficher->currentRow()!=-1)
    supprimer_Promotion();
}

void Promotion::on_Enregistrer_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    modifier_Promotion(ui->modf_code->text().toInt(),ui->modf_datef->text(),ui->modf_taux->text().toInt());
}

void Promotion::on_Afficher_itemClicked(QTableWidgetItem *i)
{
    int j=ui->Afficher->currentRow();
    QDate date;

    setCode_Promotion(ui->Afficher->item(j,0)->text().toInt());
    setDate_Fin(ui->Afficher->item(j,1)->text());
    setTaux(ui->Afficher->item(j,2)->text().toInt());
    ui->modf_code->setText(ui->Afficher->item(j,0)->text());
    ui->modf_datef->setDate(date.fromString(ui->Afficher->item(j,1)->text(),"dd/MM/yyyy"));
    ui->modf_taux->setText((ui->Afficher->item(j,2)->text()));
}

void Promotion::on_Back_clicked()
{
    this->hide();
    Piscine *p=new Piscine;
    p->play_musicClick();
    p->show();
}

void Promotion::on_Abonne_clicked()
{
    this->hide();
    Abonne *a =new Abonne;
    Piscine *p=new Piscine;
    p->play_musicClick();
    a->show();
}

void Promotion::on_Abonnement_clicked()
{
    this->hide();
    Abonnement *ab =new Abonnement;
    Piscine *p=new Piscine;
    p->play_musicClick();
    ab->show();
}

void Promotion::on_Cours_clicked()
{
    this->hide();
    Cours *c =new Cours;
    Piscine *p=new Piscine;
    p->play_musicClick();
    c->show();
}

void Promotion::on_Stock_clicked()
{
    this->hide();
    Produit *pr = new Produit;
    Piscine *p=new Piscine;
    p->play_musicClick();
    pr->show();
}
