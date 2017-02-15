#include <graphicwidget.h>

GraphicWidget::GraphicWidget()
{
    mainLayout = new QVBoxLayout();
    plotButton = new QPushButton("Plot!");
    customPlot = new QCustomPlot();

    connect(plotButton,SIGNAL(clicked(bool)),this,SLOT(drawThePlot()));

    mainLayout->addWidget(customPlot);
    mainLayout->addWidget(plotButton);

    setLayout(mainLayout);
}

void GraphicWidget::drawThePlot()
{
    double K = -10.0;
    double step = 0.01;
    QVector<double> x(2000),y(2000);

    for(int i = 0; i < 2000; i++)
    {
        x[i] = K + i * step;
        qDebug() << x[i];
        y[i] = sin(x[i]) + cos(4 * x[i]);
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x,y);
    customPlot->graph(0)->setAntialiased(true);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(-10,10);
    customPlot->yAxis->setRange(-2,2);
    customPlot->replot();
}

GraphicWidget::~GraphicWidget()
{

}
