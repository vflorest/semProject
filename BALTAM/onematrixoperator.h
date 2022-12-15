#ifndef ONEMATRIXOPERATOR_H
#define ONEMATRIXOPERATOR_H

#include <QDialog>
#include <QMessageBox>

#include "doublespinboxdelegate.h"
#include "resultview.h"

namespace Ui {
class OneMatrixOperator;
}

class OneMatrixOperator : public QDialog
{
    Q_OBJECT

public:
    explicit OneMatrixOperator(QWidget *parent = nullptr);

    ~OneMatrixOperator();

private slots:
    void on_diagButton_clicked();

    void on_transButton_clicked();

    void on_invButton_clicked();

    void on_backButton_clicked();

    void on_exitButton_clicked();

    void on_mspinBox_valueChanged(int arg1);

    void on_nspinBox_valueChanged(int arg1);

private:
    Ui::OneMatrixOperator *ui;
    QStandardItemModel *mModelA;
    QStandardItemModel *mModelRes;
    void setValueAt(QStandardItemModel *model, int xi, int xj, double value) const;
    void appendTo(QStandardItemModel *model, double value) const;
    double getValueAt(QStandardItemModel *model, int fila, int col) const;
    double **toDoublePointer(QStandardItemModel *model) const;
    double **createNewMatrix(int order) const;
    void inverseMatrix(double **a, double**ia, int order) const;
    void toModel(QStandardItemModel * model, double **a, int order) const;
    void deleteMatrix(double**a, int order) const;
    void getMinor(double **src, double **dest, int row, int col, int order) const;
    double calculateDeterminant(double **a, int order) const;
    int row_A, col_A;
};

#endif // ONEMATRIXOPERATOR_H
