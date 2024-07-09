#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString ip = ui->lineEdit->text();
    QString port = ui->lineEdit_2->text();
    socket->connectToHost(QHostAddress(ip),port.toShort());
    connect(socket,&QTcpSocket::connected,[this]()
            {
                QMessageBox::information(this,"Message","OK");
            });

    connect(socket,&QTcpSocket::disconnected,[this]()
            {
                QMessageBox::warning(this,"Message","Error");
            });
}


void MainWindow::on_pushButton_2_clicked()
{
    QByteArray s1 = ui->lineEdit_3->text().toUtf8();

    socket->write(s1);
}

