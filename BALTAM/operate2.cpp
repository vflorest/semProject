#include "operate2.h"

Operate2::Operate2(QWidget *parent, ChoosingThemeMenu *m) :
    QDialog(parent),
    ui(new Ui::Operate2)
{
    ui->setupUi(this);
    this->setBaseSize(800, 500);
    menu = m;
    mModelA = new QStandardItemModel(this);
    mModelb = new QStandardItemModel(this);

    ui->matrixA->setModel(mModelA);
    ui->matrixb->setModel(mModelb);
    ui->matrixA->setItemDelegate(new DoubleSpinBoxDelegate(this));
    ui->matrixb->setItemDelegate(new DoubleSpinBoxDelegate(this));
}

Operate2::~Operate2()
{
    delete ui;
}



void Operate2::on_menuMetodosButton_clicked()
{
  this->close();
}


void Operate2::on_filasSpinBox_valueChanged(int arg1)
{
    mModelA->setRowCount(arg1);
    mModelb->setRowCount(arg1);
}


void Operate2::on_columnasSpinBox_valueChanged(int arg1)
{
    mModelA->setColumnCount(arg1);
    mModelb->setColumnCount(1);
}


void Operate2::on_salirButton_clicked()
{
    QApplication::quit();
}



