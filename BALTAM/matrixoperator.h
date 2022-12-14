#ifndef MATRIXOPERATOR_H
#define MATRIXOPERATOR_H

#include <QStandardItemModel>
#include <QDialog>
#include <QMessageBox>

#include "doublespinboxdelegate.h"
#include "resultview.h"


namespace Ui {
class MatrixOperator;
}

class MatrixOperator : public QDialog
{
    Q_OBJECT

public:
    explicit MatrixOperator(QWidget *parent = nullptr);
    double getValueAt(QStandardItemModel *model, int fila, int col) const;
    ~MatrixOperator();

public slots:
    void on_exitButton_clicked();

    void on_mSpinBoxA_valueChanged(int arg1);

    void on_nSpinBoxA_valueChanged(int arg1);

    void on_backButton_clicked();

    void on_mSpinBoxB_valueChanged(int arg1);

    void on_nSpinBoxB_valueChanged(int arg1);

    void on_sumButton_clicked();

    void on_sustButton_clicked();

    void on_multButton_clicked();

private:
    Ui::MatrixOperator *ui;
    QStandardItemModel *mModelA;
    QStandardItemModel *mModelB;
    QStandardItemModel *mModelRes;
    int row_A, col_A, row_B, col_B;
};

#endif // MATRIXOPERATOR_H
