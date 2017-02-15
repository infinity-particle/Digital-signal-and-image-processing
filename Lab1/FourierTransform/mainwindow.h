#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTabWidget>
#include <qcustomplot.h>
#include <graphicwidget.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        QWidget *centralWidget;
        QTabWidget *tabWidget;
        GraphicWidget *graphicWidget;

};

#endif // MAINWINDOW_H
