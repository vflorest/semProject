#ifndef CHOOSINGTHEMEMENU_H
#define CHOOSINGTHEMEMENU_H

#include "mainwindow.h"


#include <QDialog>

namespace Ui {
class ChoosingThemeMenu;
}

class ChoosingThemeMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ChoosingThemeMenu(QWidget *parent = nullptr, MainWindow *mainWindow=nullptr);
    ~ChoosingThemeMenu();

public slots:

    void on_menuPrincipalButton_clicked();


private slots:

    void on_salirButton_clicked();

private:
    Ui::ChoosingThemeMenu *ui;
    MainWindow *mainWindow;
};

#endif // CHOOSINGTHEMEMENU_H
