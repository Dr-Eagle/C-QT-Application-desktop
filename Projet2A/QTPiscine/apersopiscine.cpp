#include "apersopiscine.h"
#include "ui_apersopiscine.h"
#include "pisc.h"

APersoPiscine::APersoPiscine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::APersoPiscine)
{
    ui->setupUi(this);
    afficher_Abonnement();
    afficher_Abonne();

}

APersoPiscine::~APersoPiscine()
{
    delete ui;
}
/*******************************************************************************************************************************************************************************************/
void APersoPiscine::afficher_Abonnement()
{
    QSqlQuery qry;
   while(ui->AfficherAO->rowCount()>0)
       {
           ui->AfficherAO->removeRow(0);
       }
    qDebug()<<"ok";
       qry.exec("select * from ABONNEMENT where TYPE ='Piscine' ");
           int c = -1;
           while (qry.next())
           {
               c++;
               ui->AfficherAO->insertRow(c);
               for (int j=0; j<7; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->AfficherAO->setItem(c,j,item1);int x=c;
                   ui->AfficherAO->item(x,0)->setBackgroundColor(Qt::blue);
                }
             }
           qDebug() <<"Fin";
}
void APersoPiscine::afficher_Abonne()
{
    QSqlQuery qry;
    QSqlQuery qury;
    while(ui->Affichera->rowCount()>0)
        {
            ui->Affichera->removeRow(0);
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
               ui->Affichera->insertRow(c);
               for (int j=0; j<9; j++)
               {
                   QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
                   this->ui->Affichera->setItem(c,j,item1);
                   int x=c;
                   ui->Affichera->item(x,0)->setBackgroundColor(Qt::blue);
                }
             }
           qDebug() <<"Fin";
        }
}
void APersoPiscine::rechercher_Abonne()
{
    QString Type=ui->comboBox->currentText();
    QString Valeur=ui->Recher->text();
    QSqlQuery qry;
    if(Type=="ID")
    {
        qDebug()<<"1";
        qry.prepare("select * from PERSONNE where ID=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }
    else if(Type=="Nom")
    {
        qDebug()<<"2";
        qry.prepare("select * from PERSONNE where NOM=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }
    else if(Type=="Prenom")
    {
        qDebug()<<"3";
        qry.prepare("select * from PERSONNE where PRENOM=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }
    else if(Type=="Numero")
    {
        qDebug()<<"4";
        qry.prepare("select * from PERSONNE where NUMERO=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }

    while(ui->Affichera->rowCount()>0)
    {
        ui->Affichera->removeRow(0);
    }
    int c=-1;
    while(qry.next())
    {
        c++;
        ui->Affichera->insertRow(c);
        for(int j=0;j<9;j++)
        {
             QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
             this->ui->Affichera->setItem(c,j,item1);
              int x=c;
              ui->Affichera->item(x,0)->setBackgroundColor(Qt::blue);

        }
    }
    if(Valeur=="")
    {
        afficher_Abonne();
    }
}
void APersoPiscine::rechercher_Abonnement()
{
    QString Type=ui->comboBox_3->currentText();
    QString Valeur=ui->Recher_2->text();
    QSqlQuery qry;
    if(Type=="ID_Abonnement")
    {
        qDebug()<<"1";
        qry.prepare("select * from ABONNEMENT where ID_ABONNEMENT=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }
    else if(Type=="Type")
    {
        qDebug()<<"2";
        qry.prepare("select * from ABONNEMENT where TYPE=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }
    else if(Type=="Prix")
    {
        qDebug()<<"3";
        qry.prepare("select * from ABONNEMENT where PRIX=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }
    else if(Type=="Duree")
    {
        qDebug()<<"4";
        qry.prepare("select * from ABONNEMENT where DUREE=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }
    else if(Type=="ID_Personne")
    {
        qDebug()<<"5";
        qry.prepare("select * from ABONNEMENT where ID_PERSONNE=(?)");
        qry.addBindValue(Valeur);
        qDebug()<<qry.exec();
    }

    while(ui->AfficherAO->rowCount()>0)
    {
        ui->AfficherAO->removeRow(0);
    }
    int c=-1;
    while(qry.next())
    {
        c++;
        ui->AfficherAO->insertRow(c);
        for(int j=0;j<6;j++)
        {
             QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
             this->ui->AfficherAO->setItem(c,j,item1);
              int x=c;
             ui->AfficherAO->item(x,0)->setBackgroundColor(Qt::blue);

        }
    }
    if(Valeur=="")
    {
        afficher_Abonnement();
    }
}
void APersoPiscine::tri_asc_Abonne()
{
    QString type=ui->comboBox_2->currentText();
       QSqlQuery qry;
       if(type=="ID")
       {
           qDebug() <<"1";

           qry.exec("select * from PERSONNE  order by ID asc ");
       }
       else if (type=="Nom")
       {
           qDebug() <<"2";

           qry.exec("select * from PERSONNE order by NOM asc");

       }
       else if (type=="Prenom")
       {
           qDebug() <<"3";

           qry.exec("select * from PERSONNE order by PRENOM asc");

       }
       else if (type=="Numero Tel")
       {
           qDebug() <<"4";

           qry.exec("select * from PERSONNE order by NUMERO asc");

       }
       else if (type=="Date de naissance")
       {
           qDebug() <<"5";

           qry.exec("select * from PERSONNE order by DATE_DE_NAISSANCE asc");


       while(ui->Affichera->rowCount() > 0)
       {
           ui->Affichera->removeRow(0);
       }
       int c=-1;
       while(qry.next())
       {
           qDebug() <<"t";
           c++;
           ui->Affichera->insertRow(c);
           for (int j=0;j<9;j++)
           {
               QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
               this->ui->Affichera->setItem(c,j,item1);
               int x=c;
               ui->Affichera->item(x,0)->setBackgroundColor(Qt::blue);
           }
       }
   }
}
void APersoPiscine::tri_desc_Abonne()
{
    QString type=ui->comboBox_2->currentText();
       QSqlQuery qry;
       if(type=="ID")
       {
           qDebug() <<"1";

           qry.exec("select * from PERSONNE  order by ID desc ");
       }else if (type=="Nom")
       {
           qDebug() <<"2";

           qry.exec("select * from PERSONNE order by NOM desc");

       }else if (type=="Prenom")
       {
           qDebug() <<"3";

           qry.exec("select * from PERSONNE order by PRENOM desc");

       }else if (type=="Numero Tel")
       {
           qDebug() <<"4";

           qry.exec("select * from PERSONNE order by NUMERO desc");

       }else if (type=="Date de naissance")
       {
           qDebug() <<"5";

           qry.exec("select * from PERSONNE order by DATE_DE_NAISSANCE desc");


       while(ui->Affichera->rowCount() > 0)
       {
           ui->Affichera->removeRow(0);
       }
       int c=-1;
       while(qry.next())
       {
           qDebug() <<"t";
           c++;
           ui->Affichera->insertRow(c);
           for (int j=0;j<9;j++)
           {
               QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
               this->ui->Affichera->setItem(c,j,item1);
               int x=c;
              ui->Affichera->item(x,0)->setBackgroundColor(Qt::blue);
           }
       }
   }
}
void APersoPiscine::tri_asc_Abonnement()
{
    QString type=ui->comboBox_4->currentText();
    QSqlQuery qry;
   if(type=="ID_Abonnement")
   {
       qDebug() <<"1";

       qry.exec("select * from ABONNEMENT  where TYPE = 'Piscine' order by ID_ABONNEMENT asc ");
   }else if (type=="Date_Fin")
   {
       qDebug() <<"2";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by DATE_FIN asc");

   }else if (type=="Date_Debut")
   {
       qDebug() <<"3";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by DATE_DEBUT asc");

   }else if (type=="Type")
   {
       qDebug() <<"4";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by TYPE asc");

   }else if (type=="Prix")
   {
       qDebug() <<"5";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by PRIX asc");

    }
   else if (type=="Duree")
      {
          qDebug() <<"6";

          qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by DUREE asc");

       }
   else if (type=="ID_Personne")
      {
          qDebug() <<"7";

          qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by ID_PERSONNE asc");

       }
   while(ui->AfficherAO->rowCount() > 0)
   {
       ui->AfficherAO->removeRow(0);
   }
   int c=-1;
   while(qry.next())
   {
       qDebug() <<"t";
       c++;
       ui->AfficherAO->insertRow(c);
       for (int j=0;j<7;j++)
       {
           QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
           this->ui->AfficherAO->setItem(c,j,item1);
           int x=c;
          ui->AfficherAO->item(x,0)->setBackgroundColor(Qt::blue);
       }
   }

}
void APersoPiscine::tri_desc_Abonnement()
{
    QString type=ui->comboBox_4->currentText();
    QSqlQuery qry;
   if(type=="ID_Abonnement")
   {
       qDebug() <<"1";

       qry.exec("select * from ABONNEMENT  where TYPE = 'Piscine' order by ID_ABONNEMENT desc ");
   }else if (type=="Date_Fin")
   {
       qDebug() <<"2";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by DATE_FIN desc");

   }else if (type=="Date_Debut")
   {
       qDebug() <<"3";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by DATE_DEBUT desc");

   }else if (type=="Type")
   {
       qDebug() <<"4";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by TYPE desc");

   }else if (type=="Prix")
   {
       qDebug() <<"5";

       qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by PRIX desc");

    }
   else if (type=="Duree")
      {
          qDebug() <<"6";

          qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by DUREE desc");

       }
   else if (type=="ID_Personne")
      {
          qDebug() <<"7";

          qry.exec("select * from ABONNEMENT where TYPE = 'Piscine' order by ID_PERSONNE desc");

       }
   while(ui->AfficherAO->rowCount() > 0)
   {
       ui->AfficherAO->removeRow(0);
   }
   int c=-1;
   while(qry.next())
   {
       qDebug() <<"t";
       c++;
       ui->AfficherAO->insertRow(c);
       for (int j=0;j<7;j++)
       {
           QTableWidgetItem *item1 = new QTableWidgetItem(QString(qry.value(j).toString()));
           this->ui->AfficherAO->setItem(c,j,item1);
           int x=c;
          ui->AfficherAO->item(x,0)->setBackgroundColor(Qt::blue);
       }
   }
}
/***********************************************************************************************************************************************************************************************/
void APersoPiscine::on_TriC_clicked()
{
    tri_asc_Abonnement();
}

void APersoPiscine::on_TriD_clicked()
{
    tri_desc_Abonnement();
}

void APersoPiscine::on_TriC_2_clicked()
{
    tri_asc_Abonne();
}

void APersoPiscine::on_TriD_2_clicked()
{
    tri_desc_Abonne();
}
void APersoPiscine::on_Cours_clicked()
{
    this->hide();
    CPersoPiscine *c=new CPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    c->show();
}

void APersoPiscine::on_Salaire_clicked()
{
    this->hide();
    SPersoPiscine *s=new SPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    s->show();
}

void APersoPiscine::on_Stock_clicked()
{
    this->hide();
    STOCKPersoPiscine *sp= new STOCKPersoPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    sp->show();
}
void APersoPiscine::on_Back_clicked()
{
    this->hide();
    PersonnelPiscine *pe=new PersonnelPiscine();
    Piscine *p=new Piscine;
    p->play_musicClick();
    pe->show();
}
void APersoPiscine::on_Rechercher_clicked()
{
    rechercher_Abonne();
}
void APersoPiscine::on_Recherche_clicked()
{
    rechercher_Abonnement();
}
