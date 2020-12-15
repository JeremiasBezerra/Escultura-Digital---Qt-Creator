#include "plotter.h"
#include "mainwindow.h"
#include "sculptor.h"
#include <cmath>
#include <iostream>
#include <QPainter>
#include <QMouseEvent>
#include <QBrush>
#include <QPen>
#include <vector>

using namespace std;

Plotter::Plotter(QWidget *parent) : QWidget(parent)
{
    matrizCriada = false;
    matrizX = 1;
    matrizY = 1;
    matrizZ = 1;
    ZAtual = 0;
    selectedButton = 1;
}


void Plotter::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);

    painter.setBrush(brush);

    painter.setPen(pen);

    painter.drawRect(0,0,width(),height());

    if(matrizCriada){
        for(int j = 0;j<matrizY;j++){
            for(int k = 0;k<matrizX;k++){
                brush.setColor(QColor(255,255,255));
                painter.setBrush(brush);
                if(matriz->getIsOn(k,j,ZAtual)){
                    vector<int> cores = matriz->getColor(k,j,ZAtual);
                    brush.setColor(QColor(cores[0],cores[1],cores[2]));
                    painter.setBrush(brush);
                    painter.drawRect(sizeRectX*k,sizeRectY*j,sizeRectX,sizeRectY);
                }
                else{
                    painter.drawRect(sizeRectX*k,sizeRectY*j,sizeRectX,sizeRectY);
                    painter.drawLine(sizeRectX*k,sizeRectY*j,sizeRectX*(k+1),sizeRectY*(j+1));
                }
            }
        }
    }
    else{
        brush.setColor(QColor(255,255,255));
        painter.setBrush(brush);
        painter.drawRect(0,0,width(),height());
    }
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    XAtual = event->x()/sizeRectX;
    YAtual = event->y()/sizeRectY;
    if(event->button() == Qt::LeftButton && selectedButton == 1){
        this->putVoxel();
    }
    if(event->button() == Qt::RightButton){
        this->cutVoxel();
    }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        XRelease = event->x()/sizeRectX;
        YRelease = event->y()/sizeRectY;
        if(XRelease != XAtual || YRelease != YAtual){
            if(selectedButton == 2){
                this->putBox(XRelease,YRelease,ZAtual);
            }
            if(selectedButton == 3){
                double raio = sqrt(pow(XRelease-XAtual,2) + pow(YRelease-YAtual,2));
                this->putSphere(raio);
            }
        }
    }
}

void Plotter::setZAtual(int z)
{
    ZAtual = z;
    repaint();
}

void Plotter::setSizeMatriz(int x, int y, int z)
{
    matrizX = x;
    matrizY = y;
    matrizZ = z;
    matriz = new Sculptor(x,y,z);
    matrizCriada = true;
    sizeRectX = width()/matrizX;
    sizeRectY = height()/matrizY;

    repaint();
}

void Plotter::setRGBA(int r, int g, int b, int a)
{
    if(matrizCriada){
        matriz->setColor(r,g,b,a);
    }
}

void Plotter::setRadioButton(int x)
{
    selectedButton = x;
}

void Plotter::putVoxel()
{
    if(matrizCriada){
        matriz->putVoxel(XAtual,YAtual,ZAtual);
        repaint();
    }
}

void Plotter::cutVoxel()
{
    if(matrizCriada){
        matriz->cutVoxel(XAtual,YAtual,ZAtual);
        repaint();
    }
}

void Plotter::putBox(int x1, int y1, int z1)
{
    if(matrizCriada){
        matriz->putBox(XAtual,YAtual,ZAtual,x1,y1,z1);
        repaint();
    }
}

void Plotter::cutBox(int x1, int y1, int z1)
{
    if(matrizCriada){
        matriz->cutBox(XAtual,YAtual,ZAtual,x1,y1,z1);
        repaint();
    }
}

void Plotter::putSphere(int r)
{
    if(matrizCriada){
        matriz->putSphere(XAtual,YAtual,ZAtual,r);
        repaint();
    }
}

void Plotter::cutSphere(int r)
{
    if(matrizCriada){
        matriz->cutSphere(XAtual,YAtual,ZAtual,r);
        repaint();
    }
}

void Plotter::putEllipsoid(int rx, int ry, int rz)
{
    if(matrizCriada){
        matriz->putEllipsoid(XAtual,YAtual,ZAtual,rx,ry,rz);
        repaint();
    }
}

void Plotter::cutEllipsoid(int rx, int ry, int rz)
{
    if(matrizCriada){
        matriz->cutEllipsoid(XAtual,YAtual,ZAtual,rx,ry,rz);
        repaint();
    }
}
