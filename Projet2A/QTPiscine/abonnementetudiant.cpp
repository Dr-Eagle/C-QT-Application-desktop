#include "abonnementetudiant.h"
#include "ui_abonnementetudiant.h"

AbonnementEtudiant::AbonnementEtudiant(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AbonnementEtudiant)
{
    ui->setupUi(this);
}

AbonnementEtudiant::~AbonnementEtudiant()
{
    delete ui;
}
