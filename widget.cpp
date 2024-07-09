#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Btw_login_clicked()
{
    QString username = ui->lineEdit_account->text();
    QString password = ui->lineEdit_password->text();

    if (username == "admin" && password == "1234") {
        loggedIn = true;
        close(); // Close the login dialog
        mainWindow.show();
    } else {
        //emit loginFailed(); // Emit loginFailed signal
        ui->label_warning->setText("<font color='red'>Account or password error!</font>");
        ui->label_warning->setVisible(true); // Show error label
    }
}


void Widget::on_Btw_cancel_clicked()
{
    this->close();
}

