#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plotter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_btnTamanhoDaMtariz_clicked();
    void on_btnPutBox_clicked();
    void on_btnCutBox_clicked();
    void on_btnPutElipsoid_clicked();
    void on_btnCutElipsoid_clicked();
    void on_btnPutSphere_clicked();
    void on_btnCutSphere_clicked();
    void on_btnMudaCor_clicked();
    void on_radioButtonSphere_clicked();
    void on_radioButtonBox_clicked();
    void on_radioButtonPut_clicked();
    void on_horizontalSliderZTela_valueChanged();

private:
    int matrizX,matrizY,matrizZ;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
