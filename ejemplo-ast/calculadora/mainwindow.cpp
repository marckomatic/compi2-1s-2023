#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "parserctx.hpp"


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // añadimos el parser
    Proyecto1::ParserCtx analizador;

    analizador.Analizar(ui->textEdit->toPlainText().toStdString());
    this->ui->txtConsola->setPlainText(QString::fromStdString(analizador.Salida));

}

