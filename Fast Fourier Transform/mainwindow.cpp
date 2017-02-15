#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    graphicWidget = new GraphicWidget();
    centralWidget = new QWidget();
    tabWidget = new QTabWidget(centralWidget);

    tabWidget->setMinimumSize(600, 600);
    tabWidget->addTab(graphicWidget,"Usual graphic");
    tabWidget->addTab(new QWidget(),"Amplitude spectrum");
    tabWidget->addTab(new QWidget(),"Frequency range");
    tabWidget->addTab(new QWidget(),"Inverse transformation");

    this->setCentralWidget(centralWidget);
    this->setMinimumSize(600,600);
}

MainWindow::~MainWindow()
{

}
