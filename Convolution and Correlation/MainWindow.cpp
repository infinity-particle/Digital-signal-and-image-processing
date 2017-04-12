#define _USE_MATH_DEFINES

#define COSINE_INDEX 4
#define SINE_INDEX 1
#define NUMBER_OF_POINTS 16

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<double> t(NUMBER_OF_POINTS);
    QVector<double> x(NUMBER_OF_POINTS);
    QVector<double> y(NUMBER_OF_POINTS);

    QVector<complex<double>>* resultZ;

    DiscreteFourierTransform *discreteTransform = new DiscreteFourierTransform();
    FastFourierTransform *fastTransform = new FastFourierTransform();
    Convolution *convolution = new Convolution();
    Correlation *correlation = new Correlation();

    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        t[i] = (8. * i / NUMBER_OF_POINTS);

        x[i] = cos(COSINE_INDEX * t[i]);
        y[i] = sin(SINE_INDEX * t[i]);
    }

    plotter(ui->sourceX, t, x, "t", "x");
    plotter(ui->sourceY, t, y, "t", "y");

    //plotter(ui->sourceXF, t, x, "t", "x");
    //plotter(ui->sourceYF, t, y, "t", "y");

    resultZ = convolution->execute(x, y, (*discreteTransform));
    plotter(ui->convolutionZ, t, *resultZ, "t", "z");

    ui->convolutionLabel->setText(QString("DFT. Additions: " + QString::number(discreteTransform->additionCounter)
                                       + " Multiplication: " + QString::number(discreteTransform->multiplyCounter)));

    resultZ = convolution->execute(x, y, (*fastTransform));
    plotter(ui->convolutionZF, t, *resultZ, "t", "z");

    ui->convolutionFLabel->setText(QString("FFT. Additions: " + QString::number(fastTransform->additionCounter)
                                       + " Multiplication: " + QString::number(fastTransform->multiplyCounter)));

    resultZ = correlation->execute(x, y, (*discreteTransform));
    plotter(ui->correlationZ, t, *resultZ, "t", "z");

    ui->correlationLabel->setText(QString("DFT. Additions: " + QString::number(discreteTransform->additionCounter)
                                       + " Multiplication: " + QString::number(discreteTransform->multiplyCounter)));

    resultZ = correlation->execute(x, y, (*fastTransform));
    plotter(ui->correlationZF, t, *resultZ, "t", "z");

    ui->correlationFLabel->setText(QString("FFT. Additions: " + QString::number(fastTransform->additionCounter)
                                       + " Multiplication: " + QString::number(fastTransform->multiplyCounter)));

    /* ui->timePlotD->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->timePlotD->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    ui->timePlotD->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->frequencyPlotD->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->frequencyPlotD->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    ui->frequencyPlotD->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4)); */
}

void MainWindow::plotter(QCustomPlot* plot, QVector<double> x, QVector<double> y, QString xLabel, QString yLabel)
{
    plot->addGraph();
    plot->graph(0)->setData(x, y);

    plot->xAxis->setLabel(xLabel);
    plot->yAxis->setLabel(yLabel);

    plot->xAxis->setRange(*min_element(x.constBegin(), x.constEnd()), *max_element(x.constBegin(), x.constEnd()));
    plot->yAxis->setRange(*min_element(y.constBegin(), y.constEnd()), *max_element(y.constBegin(), y.constEnd()));
    plot->replot();
}

void MainWindow::plotter(QCustomPlot* plot, QVector<double> x, QVector<complex<double>> y, QString xLabel, QString yLabel)
{
    QVector<double> *u;

    u = new QVector<double>(y.size());

    for (int i = 0;i<y.size();i++)
    {
        (*u)[i] = y[i].real();
    }

    plotter(plot, x, *u, xLabel, yLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}
