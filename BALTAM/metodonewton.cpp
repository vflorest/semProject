#include "iteratornewton.h"
#include "metodonewton.h"
#include "ui_metodonewton.h"

MetodoNewton::MetodoNewton(QWidget *parent, ChoosingThemeMenu *m) :
    QDialog(parent),
    ui(new Ui::MetodoNewton)
{
    ui->setupUi(this);
    menu = m;
    this->setBaseSize(800, 500);
}

MetodoNewton::~MetodoNewton()
{
    delete ui;
}

void MetodoNewton::on_menuMetodosButton_clicked()
{
    this->close();
}


void MetodoNewton::on_salirButton_clicked()
{
    QApplication::quit();
}



void MetodoNewton::on_resButton_clicked()
{
    IteratorNewton iter(nullptr, this);
    iter.setModal(true);
    iter.exec();
}

