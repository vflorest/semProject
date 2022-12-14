#include "resultview.h"
#include "ui_resultview.h"

ResultView::ResultView(QWidget *parent,  QStandardItemModel *mModelRes) :
    QDialog(parent),
    ui(new Ui::ResultView)
{
    ui->setupUi(this);
    this->setBaseSize(800, 500);
    ui->resMatrix->setModel(mModelRes);
    ui->resMatrix->setItemDelegate(new DoubleSpinBoxDelegate(this));
}

ResultView::~ResultView()
{
    delete ui;
}

void ResultView::on_exitButton_clicked()
{
    QApplication::quit();
}


void ResultView::on_backButton_clicked()
{
    this->close();
}

