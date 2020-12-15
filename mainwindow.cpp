#include "plotter.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QIntValidator>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     matrizX = 1;
     matrizY = 1;
     matrizZ = 1;

    ui->tamanhoDaMatrizX->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->tamanhoDaMatrizY->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->tamanhoDaMatrizZ->QLineEdit::setValidator( new QIntValidator(0, 400, this));

    ui->boxX->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->boxY->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->boxZ->QLineEdit::setValidator( new QIntValidator(0, 400, this));

    ui->elipsoidX->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->elipsoidY->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->elipsoidZ->QLineEdit::setValidator( new QIntValidator(0, 400, this));

    ui->raioSphere->QLineEdit::setValidator( new QIntValidator(0, 400, this));

    ui->mudaCorR->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->mudaCorG->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->mudaCorB->QLineEdit::setValidator( new QIntValidator(0, 400, this));
    ui->mudaCorA->QLineEdit::setValidator( new QIntValidator(0, 400, this));

   ui->horizontalSliderZTela->QSlider::setMaximum(0);


}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnTamanhoDaMtariz_clicked()
{
    matrizX = ui->tamanhoDaMatrizX->text().toInt();
    matrizY = ui->tamanhoDaMatrizY->text().toInt();
    matrizZ = ui->tamanhoDaMatrizZ->text().toInt();


}



void MainWindow::on_btnPutBox_clicked()
{
    int x1,y1,z1;

    x1 = ui->boxX->text().toInt();
    y1 = ui->boxY->text().toInt();
    z1 = ui->boxZ->text().toInt();

    ui->plotter->putBox(x1,y1,z1);
}


void MainWindow::on_btnCutBox_clicked()
{
    int x1,y1,z1;

    x1 = ui->boxX->text().toInt();
    y1 = ui->boxY->text().toInt();
    z1 = ui->boxZ->text().toInt();

    ui->plotter->cutBox(x1,y1,z1);
}


void MainWindow::on_btnPutElipsoid_clicked()
{
    int rx,ry,rz;

    rx = ui->elipsoidX->text().toInt();
    ry = ui->elipsoidY->text().toInt();
    rz = ui->elipsoidZ->text().toInt();

    ui->plotter->putEllipsoid(rx,ry,rz);
}

void MainWindow::on_btnCutElipsoid_clicked()
{
    int rx,ry,rz;

    rx = ui->elipsoidX->text().toInt();
    ry = ui->elipsoidY->text().toInt();
    rz = ui->elipsoidZ->text().toInt();

    ui->plotter->cutEllipsoid(rx,ry,rz);
}

void MainWindow::on_btnPutSphere_clicked()
{
    int r;

    r = ui->raioSphere->text().toInt();

    ui->plotter->putSphere(r);
}

void MainWindow::on_btnCutSphere_clicked()
{
    int r;

    r = ui->raioSphere->text().toInt();

    ui->plotter->cutSphere(r);
}


void MainWindow::on_btnMudaCor_clicked()
{
    int r,g,b,a=100;

    r = ui->mudaCorR->text().toInt();
    g = ui->mudaCorG->text().toInt();
    b = ui->mudaCorB->text().toInt();
    a = ui->mudaCorA->text().toInt();

    ui->plotter->setRGBA(r,g,b,a);
}


void MainWindow::on_radioButtonPut_clicked()
{
    ui->plotter->setRadioButton(1);
}

void MainWindow::on_radioButtonBox_clicked()
{
    ui->plotter->setRadioButton(2);
}

void MainWindow::on_radioButtonSphere_clicked()
{
    ui->plotter->setRadioButton(3);
}


void MainWindow::on_horizontalSliderZTela_valueChanged()
{
    ui->plotter->setZAtual(ui->horizontalSliderZTela->value());
}
