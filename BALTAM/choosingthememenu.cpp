#include "choosingthememenu.h"
#include "mainwindow.h"
#include "operate2.h"
#include "metodonewton.h"
#include "ui_choosingthememenu.h"

ChoosingThemeMenu::ChoosingThemeMenu(QWidget *parent, MainWindow *w)
    : QDialog(parent)
    , ui(new Ui::ChoosingThemeMenu)
{
  ui->setupUi(this);
  this->setFixedSize(800, 500);
  mainWindow = w;
}

ChoosingThemeMenu::~ChoosingThemeMenu()
{
    delete ui;
}


void ChoosingThemeMenu::on_menuPrincipalButton_clicked()
{
    this->close();
    mainWindow->show();
}


void ChoosingThemeMenu::on_salirButton_clicked()
{
    QApplication::quit();
}

