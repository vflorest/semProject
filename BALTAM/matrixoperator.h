#ifndef MATRIXOPERATOR_H
#define MATRIXOPERATOR_H

#include <QStandardItemModel>
#include <QDialog>

#include "iteratorjacobi.h"
#include "ui_metodojacobi.h"
#include "choosingthememenu.h"
#include "doublespinboxdelegate.h"

namespace Ui {
class MatrixOperator;
}

class MatrixOperator : public QDialog
{
    Q_OBJECT

public:
    explicit MatrixOperator(QWidget *parent = nullptr);
    ~MatrixOperator();

public slots:
    void on_menuMetodosButton_clicked();

    void on_filasSpinBox_valueChanged(int arg1);

    void on_columnasSpinBox_valueChanged(int arg1);

private slots:
    void on_salirButton_clicked();


private:
    Ui::MatrixOperator *ui;
    ChoosingThemeMenu *menu;
    QStandardItemModel *mModelA;
    QStandardItemModel *mModelb;
};

#endif // MATRIXOPERATOR_H
