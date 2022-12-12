#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_mainwindow.h>

namespace Ui {
class MatrixInput;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_continue_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
