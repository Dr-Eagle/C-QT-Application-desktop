#include "qtpiscine.h"
#include "pisc.h"
#include <QDebug>
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "enotification.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Youssef");//inserer nom de l'utilisateur
    db.setPassword("123456");//inserer mot de passe de cet utilisateur
    if (db.open())
    qDebug()<<true;
    else
    qDebug()<<false;
/*************************************************************************************************************************************************/
    Piscine *p =new Piscine();
    p->play_musicBackground();
   /* QMediaPlayer *Intro =new QMediaPlayer();
    QVideoWidget *vw =new QVideoWidget();
    Intro->setVideoOutput(vw);
    Intro->setMedia(QUrl("qrc:/Sound/Intro.mpg"));
    vw->setGeometry(100,100,800,600);
    vw->show();
    Intro->play();
    qDebug() << Intro->state();*/
/*****************************************************************************************************************************************************/


    Login *l = new Login;
    l->show();
    return a.exec();


}
