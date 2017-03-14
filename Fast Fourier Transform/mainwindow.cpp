#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget();
    tabWidget = new QTabWidget();

    qreal step = 0.001;
    qint64 vectorSize = 10/step;

    QVector<qreal> x(vectorSize), y(vectorSize);

    qDebug() << "Fill vectors...";
    x = fillWithStep(vectorSize, 0, step);
    y = function(x);
    qDebug() << "Done.";

    QPair<QVector<qreal>, QVector<qreal>> values;
    values.first = x;
    values.second = y;

    tabWidget->addTab(new Tab(values, GENERAL), "Source function");

    QVBoxLayout* main = new QVBoxLayout();
    main->addWidget(tabWidget);

    centralWidget->setLayout(main);
    this->setCentralWidget(centralWidget);
    this->setMinimumSize(600,600);
}

MainWindow::~MainWindow()
{

}
