#ifndef ENOTIFICATION_H
#define ENOTIFICATION_H

#include <QWidget>
#include "include.h"
namespace Ui {
class ENotification;
}

class ENotification : public QWidget
{
    Q_OBJECT

public:
    explicit ENotification(QWidget *parent = nullptr);
    ~ENotification();
    explicit ENotification( const QString &user, const QString &pass,const QString &host, int port = 465, int timeout = 30000 );
    void sendMail( const QString &from, const QString &to,
                   const QString &subject, const QString &body );

signals:
    void status( const QString &);


private slots:
    void on_Classe_clicked();

    void on_Abonnement_clicked();

    void on_Back_clicked();
    void stateChanged(QAbstractSocket::SocketState socketState);
    void errorReceived(QAbstractSocket::SocketError socketError);
    void disconnected();
    void connected();
    void readyRead();
private:
    Ui::ENotification *ui;
    int timeout;
    QString message;
    QTextStream *t;
    QSslSocket *socket;
    QString from;
    QString rcpt;
    QString response;
    QString user;
    QString pass;
    QString host;
    int port;
    enum states{Tls, HandShake ,Auth,User,Pass,Rcpt,Mail,Data,Init,Body,Quit,Close};
    int state;
};

#endif // ENOTIFICATION_H
