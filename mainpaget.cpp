#include "mainpaget.h"
#include "ui_mainpaget.h"

mainpaget::mainpaget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainpaget)
{
    ui->setupUi(this);
}

mainpaget::~mainpaget()
{
    delete ui;
}
