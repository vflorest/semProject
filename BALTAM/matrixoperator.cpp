#include "matrixoperator.h"
#include "ui_matrixoperator.h"

MatrixOperator::MatrixOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatrixOperator)
{
    ui->setupUi(this);
    this->setBaseSize(800, 500);
    mModelA = new QStandardItemModel(this);
    mModelB = new QStandardItemModel(this);
    mModelRes = new QStandardItemModel(this);
    row_A = 0;
    col_A = 0;
    row_B = 0;
    col_B = 0;

    ui->matrixA->setModel(mModelA);
    ui->matrixB->setModel(mModelB);
    ui->matrixA->setItemDelegate(new DoubleSpinBoxDelegate(this));
    ui->matrixB->setItemDelegate(new DoubleSpinBoxDelegate(this));
}

MatrixOperator::~MatrixOperator()
{
    delete ui;
}


void MatrixOperator::on_exitButton_clicked()
{
    QApplication::quit();
}


void MatrixOperator::on_mSpinBoxA_valueChanged(int arg1)
{
    if(arg1>row_A){
        row_A+=1;
    }else{
        row_A-=1;
    }
    mModelA->setRowCount(arg1);
}


void MatrixOperator::on_nSpinBoxA_valueChanged(int arg1)
{
    if(arg1>col_A){
        col_A+=1;
    }else{
        col_A-=1;
    }
    mModelA->setColumnCount(arg1);
}

void MatrixOperator::on_mSpinBoxB_valueChanged(int arg1)
{
    if(arg1>row_B){
        row_B+=1;
    }else{
        row_B-=1;
    }
    mModelB->setRowCount(arg1);
}


void MatrixOperator::on_nSpinBoxB_valueChanged(int arg1)
{
    if(arg1>col_B){
        col_B+=1;
    }else{
        col_B-=1;
    }
    mModelB->setColumnCount(arg1);
}


void MatrixOperator::on_backButton_clicked()
{
    this->close();
}


void MatrixOperator::on_sumButton_clicked()
{
    if (row_A != row_B || col_A != col_B){
        QMessageBox::about(this, "Row or Column dismatch!", "Asegura que las matrices tengan los mismos parámetros para poder sumarlas.");
    }else{
        QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
        mModelRes->clear();
        mModelRes->setRowCount(row_A);
        mModelRes->setColumnCount(col_A);
        for(int xi=0; xi<row_A;xi++){
            for(int ji=0; ji<col_A;ji++){
                const double aij = getValueAt(mModelA, xi, ji);
                const double bij = getValueAt(mModelB, xi, ji);
                const double rij = aij + bij;
                mModelRes->setItem(xi, ji, new QStandardItem(QString::number(rij)));
            }
        }
        ResultView resView(nullptr, mModelRes);
        resView.setModal(true);
        resView.exec();
    }
}


double MatrixOperator::getValueAt(QStandardItemModel *model, int fila, int col) const{
    auto item = model ->item(fila, col);
    if(!item){
        return 0.0;
    }
    return item->text().toDouble();

}


void MatrixOperator::on_sustButton_clicked()
{
    if (row_A != row_B || col_A != col_B){
        QMessageBox::about(this, "Row or Column dismatch!", "Asegura que las matrices tengan los mismos parámetros para poder restarlas.");
    }else{
        QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
    }

}

void MatrixOperator::on_multButton_clicked()
{
    QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
}


