#include "qtpiscine.h"
#include "ui_qtpiscine.h"
#include "pisc.h"

QTPiscine::QTPiscine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTPiscine)
{
    ui->setupUi(this);
}

QTPiscine::~QTPiscine()
{
    delete ui;
}
