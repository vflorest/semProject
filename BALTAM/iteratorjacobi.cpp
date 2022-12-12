#include "iteratorjacobi.h"
#include "ui_iteratorjacobi.h"


IteratorJacobi::IteratorJacobi(QWidget *parent, int n, QStandardItemModel *mModelA, QStandardItemModel *mModelb) :
    QDialog(parent),
    ui(new Ui::IteratorJacobi)
{
    ui->setupUi(this);
    QPixmap pix("/Users/vflores/OneDrive/USM/Semestre8/TEL102/proyecto/BALTAM/example_image.png");
    ui->matrizIteracion->setPixmap(pix.scaled(600, 300));
}

IteratorJacobi::~IteratorJacobi()
{
    delete ui;
}

//Matrix IteratorJacobi::get_Matrix(QStandardItemModel *graphicMatrix)
//{
//          int rows = graphicMatrix->rowCount();
//          int col = graphicMatrix->columnCount();
//          Matrix matrix = inicializa(rows, col);

//          for (int i = 0; i < rows; i++){
//                for (int j = 0; j < col; j++){
//                    matrix.datos[i][j] = graphicMatrix->item(i, j)->text().toInt();
//                }
//          }
//          return matrix;
//}



void IteratorJacobi::on_salirButton_2_clicked()
{
    QApplication::quit();
}
