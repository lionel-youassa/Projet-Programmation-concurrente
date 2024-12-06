#include "mainwindow.h"
#include "../Projet-Programmation-concurrente/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/ui_mainwindow.h"

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
