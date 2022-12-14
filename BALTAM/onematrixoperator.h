#ifndef ONEMATRIXOPERATOR_H
#define ONEMATRIXOPERATOR_H

#include <QDialog>
#include <QMessageBox>

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

private:
    Ui::OneMatrixOperator *ui;
};

#endif // ONEMATRIXOPERATOR_H
