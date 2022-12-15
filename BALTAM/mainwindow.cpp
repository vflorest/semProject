#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "choosingthememenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_continue_button_clicked()
{
    ChoosingThemeMenu choosingTheme(nullptr, this);
    choosingTheme.setModal(true);
    choosingTheme.exec();
}
