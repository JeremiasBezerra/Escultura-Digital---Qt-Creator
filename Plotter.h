#ifndef PLOTTER_H
#define PLOTTER_H

#include "sculptor.h"
#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
public:explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void on_pushButton_clicked();
    void putVoxel();
    void cutVoxel();
    void putBox(int x1, int y1, int z1);
    void cutBox(int x1, int y1, int z1);
    void putSphere(int r);
    void cutSphere(int r);
    void putEllipsoid(int rx, int ry, int rz);
    void cutEllipsoid(int rx, int ry, int rz);
    void setRGBA(int r, int g, int b, int a);
    void setZAtual(int z);
    void setRadioButton(int x);
signals:
    void posAtualMouse(int x,int y);

public slots:
    void setSizeMatriz(int x, int y, int z);

private:
    bool matrizCriada;
    Sculptor *matriz;
    int matrizX, matrizY, matrizZ, XAtual,YAtual,ZAtual,XRelease,YRelease,sizeRectX,sizeRectY,selectedButton;
};

#endif // PLOTTER_H
