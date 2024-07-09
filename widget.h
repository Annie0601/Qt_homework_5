#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Btw_login_clicked();

    void on_Btw_cancel_clicked();

private:
    Ui::Widget *ui;
    bool loggedIn; // Flag to track login status
    MainWindow mainWindow;
};
#endif // WIDGET_H
