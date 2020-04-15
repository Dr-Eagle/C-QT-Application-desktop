#include "personnel.h"
#include "ui_personnel.h"

Personnel::Personnel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Personnel)
{
    ui->setupUi(this);
}

Personnel::~Personnel()
{
    delete ui;
}
