#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget();
    tabWidget = new QTabWidget();

    qreal step = 0.01;
    qint64 vectorSize = 10/step;

    QVector<qreal> x(vectorSize);

    x = fillWithStep(vectorSize, 0, step);

    Function f(x);

    tabWidget->addTab(new Tab(values, GENERAL), "Source");
    tabWidget->addTab(new Tab(values, AMPLITUDE), "Amplitude");
    tabWidget->addTab(new Tab(values, FREQUENCY), "Frequency");
    tabWidget->addTab(new Tab(values, INVERSE), "Inverse");

    QVBoxLayout* main = new QVBoxLayout();
    main->addWidget(tabWidget);

    centralWidget->setLayout(main);
    this->setCentralWidget(centralWidget);
    this->setMinimumSize(600,600);
}

MainWindow::~MainWindow()
{

}
