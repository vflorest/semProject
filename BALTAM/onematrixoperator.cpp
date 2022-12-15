#include "onematrixoperator.h"
#include "ui_onematrixoperator.h"

OneMatrixOperator::OneMatrixOperator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OneMatrixOperator)
{
    ui->setupUi(this);
    this->setBaseSize(800, 500);

    row_A = 0;
    col_A = 0;

    mModelA = new QStandardItemModel(this);
    mModelRes = new QStandardItemModel(this);

    ui->matrixA->setModel(mModelA);
    ui->matrixA->setItemDelegate(new DoubleSpinBoxDelegate(this));

}

OneMatrixOperator::~OneMatrixOperator()
{
    delete ui;
}

double OneMatrixOperator::getValueAt(QStandardItemModel *model, int fila, int col) const{
    auto item = model ->item(fila, col);
    if(!item){
        return 0.0;
    }
    return item->text().toDouble();

}

double **OneMatrixOperator::toDoublePointer(QStandardItemModel *model) const
{
    const int orden = model->rowCount();
    double **a = new double*[orden];
    for(int xi = 0; xi<orden; xi++){
        a[xi] = new double[orden];
        for(int xj=0; xj<orden;xj++){
            a[xi][xj] = getValueAt(model, xi, xj);
        }
    }
    return a;
}

void OneMatrixOperator::setValueAt(QStandardItemModel  *model, int xi, int  xj, double value) const{
    if(!model->item(xi,  xj)){
        model->setItem(xi, xj, new QStandardItem(QString::number(value)));
    }else{
        model->item(xi, xj)->setText(QString::number(value));
    }

}

void OneMatrixOperator::appendTo(QStandardItemModel *model, double value) const
{
    const int rowCount = model->rowCount();
    const int colCount = model->columnCount();
    for(int xi=0;xi<rowCount; xi++){
        for(int xj=0;xj<colCount;xj++){
            if(!model->item(xi, xj)){
                model->setItem(xi, xj, new QStandardItem(QString::number(value)));
                return;
            }
        }
    }
}


double **OneMatrixOperator::createNewMatrix(int order) const
{
    double **a = new double*[order];
    for(int xi=0; xi<order; xi++){
        a[xi] = new double[order];
    }
    return a;
}

void OneMatrixOperator::inverseMatrix(double **a, double**ia, int order) const
{
    double det= 1.0/calculateDeterminant(a, order);
    double *temp = new double[(order-1)*(order-1)];
    double **minor  = new double*[order-1];
    for(int  xi=0; xi<order;  xi++){
        minor[xi] = temp+(xi*(order-1)) ;
    }
    for(int xj=0; xj<order; xj++){
        for(int xi=0;xi<order;xi++){
            getMinor(a, minor, xj, xi, order);
            ia[xi][xj] = det *calculateDeterminant(minor, order-1);
            if((xi+xj)%2 == 1){
                ia[xi][xj] = -ia[xi][xj];
            }
        }
    }
    delete[] temp;
    delete minor;
}

void OneMatrixOperator::toModel(QStandardItemModel *model, double **a, int order) const
{
    for(int xi=0;xi<order;xi++){
        for(int xj=0; xj<order; xj++){
            setValueAt(model, xi, xj, a[xi][xj]);
        }
    }
}

void OneMatrixOperator::deleteMatrix(double **a, int order) const
{
    for(int xi=0; xi<order; xi++){
        delete[] a[xi];
    }
    delete[] a;
}

void OneMatrixOperator::getMinor(double **src, double **dest, int row, int col, int order) const
{
    int colCount = 0;
    int rowCount = 0;
    for(int xi=0; xi<order;  xi++){
        if(xi!=row){
            colCount=0;
            for(int xj=0;  xj<order; xj++){
                if(xj!=col){
                    dest[rowCount][colCount]  = src[xi][xj];
                    colCount++;
                }
            }
            rowCount++;
        }
    }
}

double OneMatrixOperator::calculateDeterminant(double **a, int order) const
{
    if(order==1){
        return a[0][0];
    }
    double det=0.0;
    double **minor =new double*[order];
    for(int  xi=0; xi<order; xi++){
        minor[xi] = new double[order-1];
    }
    for(int xi=0; xi<order; xi++){
        getMinor(a, minor, 0, xi, order);
        det += (xi%2 == 1 ? -1.0 : 1.0 ) * a[0][xi] * calculateDeterminant(
                    minor, order-1);
    }
    for(int xi=0; xi<order-1; xi++){
        delete[] minor;
        return det;
    }
}


void OneMatrixOperator::on_diagButton_clicked()
{
    //QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
    const int rowCountA = mModelA->rowCount();
    const int colCountA = mModelA->columnCount();

    mModelRes->clear();
    mModelRes->setRowCount(mModelA->rowCount());
    mModelRes->setColumnCount(mModelA->columnCount());
    for(int xj=0;xj<col_A;xj++){
        for(int xi=0;xi<row_A;xi++){
            if(xi==xj){
                appendTo(mModelRes, getValueAt(mModelA, xi, xj));
            }else{
                appendTo(mModelRes, 0.0);
            }

        }
    }
    ResultView resView(nullptr, mModelRes);
    resView.setModal(true);
    resView.exec();
}


void OneMatrixOperator::on_transButton_clicked()
{
    //QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
    const int rowCountA = mModelA->rowCount();
    const int colCountA = mModelA->columnCount();


    mModelRes->clear();
    mModelRes->setRowCount(mModelA->rowCount());
    mModelRes->setColumnCount(mModelA->columnCount());
    for(int xj=0;xj<col_A;xj++){
        for(int xi=0;xi<row_A;xi++){
            appendTo(mModelRes, getValueAt(mModelA, xi, xj));
        }
    }
    ResultView resView(nullptr, mModelRes);
    resView.setModal(true);
    resView.exec();

}






void OneMatrixOperator::on_invButton_clicked()
{
    if(col_A==row_A){
        mModelRes->clear();
        const int orden = mModelA->rowCount();
        double **a = toDoublePointer(mModelA);
        double **ia = createNewMatrix(orden);
        inverseMatrix(a, ia, orden);
        toModel(mModelRes, ia, orden);

        ResultView resView(nullptr, mModelRes);
        resView.setModal(true);
        resView.exec();
    }else{
        QMessageBox::about(this, "Not implemented yet.", "Estamos trabajando para ud.");
    }

}


void OneMatrixOperator::on_backButton_clicked()
{
    close();
}


void OneMatrixOperator::on_exitButton_clicked()
{
    QApplication::quit();
}


void OneMatrixOperator::on_mspinBox_valueChanged(int arg1)
{
    if(arg1>row_A){
        row_A+=1;
    }else{
        row_A-=1;
    }
    mModelA->setRowCount(arg1);
}


void OneMatrixOperator::on_nspinBox_valueChanged(int arg1)
{
    if(arg1>col_A){
        col_A+=1;
    }else{
        col_A-=1;
    }
    mModelA->setColumnCount(arg1);
}

