#include "onematrixoperator.h"
#include "ui_onematrixoperator.h"

OneMatrixOperator::OneMatrixOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OneMatrixOperator)
{
    ui->setupUi(this);
    this->setBaseSize(800, 500);
}

OneMatrixOperator::~OneMatrixOperator()
{
    delete ui;
}

void OneMatrixOperator::on_diagButton_clicked()
{
    QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
}


void OneMatrixOperator::on_transButton_clicked()
{
    QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
}


void OneMatrixOperator::on_invButton_clicked()
{
    QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
}


void OneMatrixOperator::on_backButton_clicked()
{
    this->close();
}


void OneMatrixOperator::on_exitButton_clicked()
{
    QApplication::quit();
}

