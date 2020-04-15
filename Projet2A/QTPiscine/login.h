#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "admin.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    int Getid() { return ID; }
    void Setid(int val) { ID = val; }
    QString Getpassword() { return mdp; }
    void Setpassword(QString val) { mdp = val; }
    QString prenom,nom;
    int id;
    QString x="";
/*******************************************************************************************************************/
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool log();
    QString test_connexion();
    void redirect();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    int ID;
    QString mdp;
};

#endif // LOGIN_H
