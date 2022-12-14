#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <QDialog>
#include <QStandardItemModel>
#include "doublespinboxdelegate.h"


namespace Ui {
class ResultView;
}

class ResultView : public QDialog
{
    Q_OBJECT

public:
    explicit ResultView(QWidget *parent = nullptr, QStandardItemModel *mModelRes=nullptr);
    ~ResultView();

private slots:
    void on_exitButton_clicked();

    void on_backButton_clicked();

private:
    Ui::ResultView *ui;
    QStandardItemModel *resModel;
};

#endif // RESULTVIEW_H
