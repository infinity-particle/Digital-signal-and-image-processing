#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTabWidget>
#include <QDebug>
#include <QVector>
#include <qcustomplot.h>
#include "tab.h"
#include "algorithm.h"
#include "function.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        QWidget *centralWidget;
        QTabWidget *tabWidget;
};

#endif // MAINWINDOW_H
