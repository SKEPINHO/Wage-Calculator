#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->doublespin_mzda, &QDoubleSpinBox::valueChanged, this, &MainWindow::vypocetMzdy);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vypocetMzdy()
{
    double Dan = ui->doublespin_mzda->value() * 0.15;
    ui->label_danV->setText(QString::number(Dan) + " CZK");

    double Socialni = ui->doublespin_mzda->value() * 0.071;
    ui->label_socV->setText(QString::number(Socialni) + " CZK");

    double Zdravotni = ui->doublespin_mzda->value() * 0.045;
    ui->label_zdraV->setText(QString::number(Zdravotni) + " CZK");

    double result = ui->doublespin_mzda->value() - Dan - Socialni - Zdravotni;
    ui->label_vysledek->setText(QString::number(result) + " CZK");




}