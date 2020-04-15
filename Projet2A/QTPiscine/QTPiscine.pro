#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T18:53:01
#
#-------------------------------------------------

QT       += core gui\
         multimedia
QT += multimediawidgets
QT+=sql
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTPiscine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
        main.cpp \
        qtpiscine.cpp \
    login.cpp \
    admin.cpp \
    piscine.cpp \
    abonne.cpp \
    abonnement.cpp \
    produit.cpp \
    cours.cpp \
    promotion.cpp \
    include.cpp \
    etudiant.cpp \
    personnelpiscine.cpp \
    eabonnement.cpp \
    eclasse.cpp \
    enotification.cpp \
    apersopiscine.cpp \
    cpersopiscine.cpp \
    spersopiscine.cpp \
    stockpersopiscine.cpp

HEADERS += \
        qtpiscine.h \
    login.h \
    admin.h \
    piscine.h \
    abonne.h \
    abonnement.h \
    produit.h \
    cours.h \
    promotion.h \
    personne.h \
    include.h \
    pisc.h \
    etudiant.h \
    personnelpiscine.h \
    eabonnement.h \
    eclasse.h \
    enotification.h \
    apersopiscine.h \
    cpersopiscine.h \
    spersopiscine.h \
    stockpersopiscine.h

FORMS += \
        qtpiscine.ui \
    login.ui \
    admin.ui \
    piscine.ui \
    abonne.ui \
    abonnement.ui \
    produit.ui \
    cours.ui \
    promotion.ui \
    etudiant.ui \
    personnelpiscine.ui \
    eabonnement.ui \
    eclasse.ui \
    enotification.ui \
    apersopiscine.ui \
    cpersopiscine.ui \
    spersopiscine.ui \
    stockpersopiscine.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sound.qrc
