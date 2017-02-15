#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    graphicWidget = new GraphicWidget();
    centralWidget = new QWidget();
    tabWidget = new QTabWidget();

    //tabWidget->setMinimumSize(600, 600);
    tabWidget->addTab(graphicWidget,"Usual graphic");
    tabWidget->addTab(new QWidget(),"Amplitude spectrum");
    tabWidget->addTab(new QWidget(),"Frequency range");
    tabWidget->addTab(new QWidget(),"Inverse transformation");

    QVBoxLayout* main = new QVBoxLayout();
    main->addWidget(tabWidget);

    centralWidget->setLayout(main);
    this->setCentralWidget(centralWidget);
    this->setMinimumSize(600,600);
}

MainWindow::~MainWindow()
{

}
