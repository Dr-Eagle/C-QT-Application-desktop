#ifndef INCLUDE_H
#define INCLUDE_H
#include "iostream"
#include "QSqlQuery"
#include "QSqlDatabase"
#include "QDebug"
#include "string.h"
#include "ctime"
#include "QDate"
#include "QTableWidgetItem"
#include <QMediaPlayer>
#include "QMessageBox"
#include "string"
#include "admin.h"
#include "piscine.h"
#include "login.h"
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>
class include
{
public:
    include();
    Admin *ad = new Admin();
    Login *log = new Login();
    Piscine *p = new Piscine();
};

#endif // INCLUDE_H
