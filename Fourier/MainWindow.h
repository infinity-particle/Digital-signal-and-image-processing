#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DiscreteFourierTransform.h"
#include "FastFourierTransform.h"
#include "QCustomPlot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void plotter(QCustomPlot*, QVector<double>, QVector<double>, QString, QString);
    void plotter(QCustomPlot*, QVector<double>, QVector<complex<double>>, QString, QString, bool, bool);
};

#endif // MAINWINDOW_H
