#include "matrixoperator.h"
#include "ui_matrixoperator.h"
#include "choosingthememenu.h"

MatrixOperator::MatrixOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixOperator)
{
    ui->setupUi(this);
    this->setBaseSize(800, 500);
    mModelA = new QStandardItemModel(this);
    mModelb = new QStandardItemModel(this);

    ui->matrixA->setModel(mModelA);
    ui->matrixB->setModel(mModelb);
    ui->matrixA->setItemDelegate(new DoubleSpinBoxDelegate(this));
    ui->matrixB->setItemDelegate(new DoubleSpinBoxDelegate(this));
}

MatrixOperator::~MatrixOperator()
{
    delete ui;
}

void MatrixOperator::on_menuMetodosButton_clicked()
{
  this->close();
}


void MatrixOperator::on_filasSpinBox_valueChanged(int arg1)
{
    mModelA->setRowCount(arg1);
    mModelb->setRowCount(arg1);
}


void MatrixOperator::on_columnasSpinBox_valueChanged(int arg1)
{
    mModelA->setColumnCount(arg1);
    mModelb->setColumnCount(1);
}


void MatrixOperator::on_salirButton_clicked()
{
    QApplication::quit();
}

