#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QPen>
#include <QGraphicsScene>
#include "qcustomplot.h"
#include <QDebug>

#define RANGE 10


class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void drawThePlot();

    private:
        QVBoxLayout *mainLayout;
        QWidget *centralWidget;
        QPushButton* plotButton;
        QCustomPlot* customPlot;
};

#endif // MAINWINDOW_H
