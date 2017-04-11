#define _USE_MATH_DEFINES
#define NUMBER_OF_POINTS 16
#define COSINE_INDEX 4
#define SINE_INDEX 1

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<double> t0(NUMBER_OF_POINTS);
    QVector<double> u0(NUMBER_OF_POINTS);

    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        t0[i] = (8. * i / NUMBER_OF_POINTS);
        u0[i] = cos(COSINE_INDEX * t0[i]) + sin(SINE_INDEX * t0[i]);
    }

    DiscreteFourierTransform *discreteTransform = new DiscreteFourierTransform();
    FastFourierTransform *fastTransform = new FastFourierTransform();

    QVector<complex<double>> *data = discreteTransform->directTransform(u0);
    QVector<complex<double>> *original = discreteTransform->inverseTransform(*data);

    plotter(ui->sourcePlotD, t0, u0, "t", "u");
    plotter(ui->timePlotD, t0, *data, "f", "u", true, false);
    plotter(ui->frequencyPlotD, t0, *data, "f", "phi", false, false);
    plotter(ui->originalPlotD, t0, *original, "t", "u", false, true);

    ui->timePlotD->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->timePlotD->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    ui->timePlotD->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->frequencyPlotD->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->frequencyPlotD->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    ui->frequencyPlotD->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->discreteLabel->setText(QString("Additions: " + QString::number(discreteTransform->additionCounter)
                                       + " Multiply: " + QString::number(discreteTransform->multiplyCounter)));

    QVector<complex<double>> *dataF = fastTransform->directTransform(u0);
    QVector<complex<double>> *originalF = fastTransform->inverseTransform(*data);

    plotter(ui->sourcePlotF, t0, u0, "t", "u");
    plotter(ui->timePlotF, t0, *dataF, "f", "u", true, false);
    plotter(ui->frequencyPlotF, t0, *dataF, "f", "phi", false, false);
    plotter(ui->originalPlotF, t0, *originalF, "t", "u", false, true);

    ui->timePlotF->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->timePlotF->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    ui->timePlotF->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->frequencyPlotF->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->frequencyPlotF->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    ui->frequencyPlotF->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    ui->fftLabel->setText(QString("Additions: " + QString::number(fastTransform->additionCounter)
                                       + " Multiply: " + QString::number(fastTransform->multiplyCounter)));
}

void MainWindow::plotter(QCustomPlot* plot, QVector<double> x, QVector<double> y, QString xLabel, QString yLabel)
{
    plot->addGraph();
    plot->graph(0)->setData(x, y);

    plot->xAxis->setLabel(xLabel);
    plot->yAxis->setLabel(yLabel);

    plot->xAxis->setRange(*min_element(x.constBegin(), x.constEnd()), *max_element(x.constBegin(), x.constEnd()) + 1);
    plot->yAxis->setRange(*min_element(y.constBegin(), y.constEnd()), *max_element(y.constBegin(), y.constEnd()) + 1);
    plot->replot();
}

void MainWindow::plotter(QCustomPlot* plot, QVector<double> x, QVector<complex<double>> y, QString xLabel, QString yLabel, bool amplitude, bool real)
{
    QVector<double> *u;

    if (real)
    {
        u = new QVector<double>(y.size());

        for (int i = 0;i<y.size();i++)
        {
            (*u)[i] = y[i].real();
        }
    }
    else if (amplitude)
    {
        u = DiscreteFourierTransform::getAmplitude(y);
    }
    else
    {
        u = DiscreteFourierTransform::getPhase(y);
    }

    plotter(plot, x, *u, xLabel, yLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}
