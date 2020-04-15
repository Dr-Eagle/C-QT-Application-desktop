#include "pisc.h"
#include "ui_login.h"
#include "include.h"
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
/*******************************************************************************************************************************************************************************************/
QString Login::test_connexion()
{
    QString mdp;
    int id;
    id=Getid();
    mdp=Getpassword();
    QSqlQuery qry;
    qDebug() << id ;
    qDebug() << mdp ;
    qry.prepare("select * from PERSONNE where ID=(?) and MOT_DE_PASSE=(?)");
    qry.addBindValue(id);
    qry.addBindValue(mdp);
    qDebug() << qry.exec() ;
    if(qry.next())
    {   this->nom=qry.value(1).toString();
        this->prenom=qry.value(2).toString();
        return qry.value(4).toString() ;}
    else
        return "";
}
bool Login::log()
{
    QMessageBox msg;
        this->Setpassword(ui->lineEdit_2->text());
        this->Setid(ui->ID->text().toInt());
        this->id=ui->ID->text().toInt();
        x=test_connexion();
        qDebug()<<x;
        if ( x!="" )
            {
            msg.setText("Connexion avec succès ! ");
            msg.exec();
            this->hide();
            return 1;
            }
        else
            {
            msg.setText("Connexion éronnée ! ");
            msg.exec();
            return 0;
            }
}
void Login::redirect()
{
    log();
 if(x=="ADMIN")
 {
     Admin *ad=new Admin;
     this->hide();
     ad->show();
 }
 else if(x=="ETUDIANT")
 {
    QSqlQuery qry;
    Etudiant *et=new Etudiant(Getid());
    et->Setid(Getid());
    et->show();

 }
 else if (x=="PersoPiscine")
 {
    PersonnelPiscine *pp =new PersonnelPiscine;
    pp->show();
 }
}
/************************************************************************************************************************************************************************************************/
void Login::on_pushButton_clicked()
{
    Piscine *p=new Piscine;
    p->play_musicClick();
    redirect();
}
