#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    widget = new QWidget();
    layout = new QVBoxLayout();
    label = new QLabel("Тут должны быть графики, формулы и т.д.");
    pen = new QPen(Qt::green);
    scene = new QGraphicsScene();
    scene->addLine(0, 90, 180, 90, *pen);
    scene->addLine(90, 0, 90, 180, *pen);

    view = new QGraphicsView();
    view->setScene(scene);
    layout->addWidget(label);
    layout->addWidget(view);
    widget->setLayout(layout);
    this->setCentralWidget(widget);
    double x[2];
    double y[2];
    x[0]=y[0] = x[1] = y[1] = 0;
    pen->setColor(Qt::red);
    for(double i=-5;i<5;i+=0.5)
    {
        x[0] = x[1];
        y[0] =4*x[0]*x[0]-20;
        x[1] = i;
        y[1] = 4*x[1]*x[1]-20;
        if(i!=-5)
         scene->addLine(x[0]+90, 90-y[0], x[1]+90, 90-y[1], *pen);
    }

}

MainWindow::~MainWindow()
{

}
