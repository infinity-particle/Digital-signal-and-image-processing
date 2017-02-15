#include <graphicwidget.h>

GraphicWidget::GraphicWidget()
{
    mainLayout = new QVBoxLayout();
    plotButton = new QPushButton("Plot!");
    customPlot = new QCustomPlot();

    leftLimitInput = new QLineEdit();
    rightLimitInput = new QLineEdit();
    stepInput = new QLineEdit();

    leftLimitInput->setText("-10");
    rightLimitInput->setText("10");
    stepInput->setText("0.001");

    QHBoxLayout* limitLayout = new QHBoxLayout();

    limitLayout->addWidget(new QLabel("Left limit: "));
    limitLayout->addWidget(leftLimitInput);
    limitLayout->addWidget(new QLabel("Right limit: "));
    limitLayout->addWidget(rightLimitInput);
    limitLayout->addWidget(new QLabel("Step: "));
    limitLayout->addWidget(stepInput);

    connect(plotButton,SIGNAL(clicked(bool)),this,SLOT(drawThePlot()));

    mainLayout->addWidget(customPlot);
    mainLayout->addLayout(limitLayout);
    mainLayout->addWidget(plotButton);

    setLayout(mainLayout);
}

void GraphicWidget::drawThePlot()
{
    qreal leftLimit = leftLimitInput->text().toDouble();
    qreal rightLimit = rightLimitInput->text().toDouble();
    qreal step = stepInput->text().toDouble();

    qreal size = (qFabs(leftLimit) + qFabs(rightLimit)) / step;
    qDebug() << "Left limit = " << leftLimit;
    qDebug() << "Right limit = " << rightLimit;
    qDebug() << "Step = " << step;
    qDebug() << "Size = " << size;
    QVector<qreal> x(size),y(size);

    for(int i = 0; i < size; i++){
        x[i] = leftLimit + qreal(i) * step;
        qDebug() << x.at(i);
        y[i] = sin(x[i]) + cos(4.0f * x[i]);
    }

    customPlot->addGraph();
    customPlot->graph(0)->setData(x,y);
    customPlot->graph(0)->setAntialiased(true);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(leftLimit,rightLimit);
    customPlot->yAxis->setRange(*std::min_element(y.constBegin(),y.constEnd()),*std::max_element(y.constBegin(),y.constEnd()));
    customPlot->replot();
}

GraphicWidget::~GraphicWidget()
{

}
