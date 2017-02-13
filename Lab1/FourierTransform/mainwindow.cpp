#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget();
    layout = new QVBoxLayout();
    label = new QLabel("Тут должны быть графики, формулы и т.д.");
    layout->addWidget(label);
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{

}
