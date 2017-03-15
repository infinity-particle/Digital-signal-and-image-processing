#include "tab.h"

Tab::Tab(const QPair<QVector<qreal>, QVector<qreal>>& sourceValues, TabType type){
    this->plot = new QCustomPlot();
    this->mainLayout = new QVBoxLayout();

    values = new QPair<QVector<qreal>, QVector<qreal>>(sourceValues.first, sourceValues.second);
    periodSize = getPeriod(values->second);

    qint64 step = periodSize/NUMBER_OF_COUNTS;

    period = new QPair<QVector<qreal>, QVector<qreal>>(values->first.mid(0, periodSize + 1), values->second.mid(0, periodSize + 1));

    discretValues = new QPair<QVector<qreal>, QVector<qreal>>();
    discretValues->first = getDiscretValues(period->first, step);
    discretValues->second = getDiscretValues(period->second, step);

    DFTValues = new QVector<std::complex<qreal>>(discreteFourierTransform(discretValues->second));
    FFTValues = new QVector<std::complex<qreal>>();

    switch(type){
        case GENERAL: {
            this->general();
        }break;

        case AMPLITUDE: {
            this->amplitude();
        }break;

        case FREQUENCY: {
            this->frequency();
        }break;

        case INVERSE:{
            this->inverse();
        }break;
    };
}

void Tab::general(){
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->xAxis->setRange(0, 7);
    plot->yAxis->setRange(-2, 2);
    plot->graph(0)->setData(period->first, period->second);

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}

void Tab::amplitude(){
    QVector<qreal> amplitudes;
    QVector<qreal> indices;

    for(qint64 i = 0; i < this->DFTValues->length(); i++){
        amplitudes.push_back(qSqrt(qPow(this->DFTValues->at(i).real(),2) +
                                   qPow(this->DFTValues->at(i).imag(),2)));
        indices.push_back(i);
    }

    plot->addGraph();
    plot->xAxis->setRange(0, NUMBER_OF_COUNTS + 1);
    plot->yAxis->setRange(0, 9);

    plot->graph(0)->setName("Discrete Fourier Transform");
    plot->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    plot->graph(0)->setData(indices, amplitudes);
    plot->legend->setVisible(true);

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}

void Tab::frequency(){
    QVector<qreal> phases;
    QVector<qreal> indices;

    for(qint64 i = 0; i < this->DFTValues->length(); i++){
        phases.push_back(qRadiansToDegrees(qAtan(this->DFTValues->at(i).imag() /
                                                 qSqrt(qPow(this->DFTValues->at(i).real(),2) +
                                                       qPow(this->DFTValues->at(i).imag(),2)))));
        indices.push_back(i);
    }

    plot->addGraph();
    plot->xAxis->setRange(0, NUMBER_OF_COUNTS + 1);
    plot->yAxis->setRange(-100, 100);

    plot->graph(0)->setName("Discrete Fourier Transform");

    plot->graph(0)->setLineStyle(QCPGraph::lsImpulse);
    plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

    plot->graph(0)->setData(indices, phases);
    plot->legend->setVisible(true);

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}

void Tab::inverse(){
    QVector<qreal> source = inverseDiscreteFourierTransform(*this->DFTValues);
    QVector<qreal> index;
    qint64 step = periodSize/NUMBER_OF_COUNTS;
    for(qint64 i = 0; i < this->period->first.length(); i += step){
        index.push_back(this->period->first.at(i));
    }

    plot->addGraph();
    plot->xAxis->setRange(0, 7);
    plot->yAxis->setRange(-2, 2);
    plot->graph(0)->setAntialiased(true);


    plot->graph(0)->setName("Inverse Discrete Fourier Transform");
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    plot->graph(0)->setData(index, source);

    plot->legend->setVisible(true);
    plot->replot();

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}
