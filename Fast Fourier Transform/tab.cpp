#include "tab.h"

Tab::Tab(const Coordinates& values, TabType type){
    this->values = new Coordinates(values);
    this->plot = new QCustomPlot();
    this->mainLayout = new QVBoxLayout();

    this->periodSize = getPeriod(this->values->second);

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
    plot->xAxis->setRange(0, 10);
    plot->yAxis->setRange(-2, 2);
    plot->graph(0)->setData(values->first.mid(0, periodSize + 1), values->second.mid(0, periodSize + 1));

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}

void Tab::amplitude(){
    FourierSeries array;
    qint64 step = periodSize/NUMBER_OF_COUNTS;

    QVector<qreal> discreted;
    for(qint64 i = step; i < periodSize + 1; i += step){
        discreted.push_back(this->values->second.mid(0, periodSize + 1).at(i));
    }

    array = discreteFourierTransform(discreted);

    QVector<qreal> amplitudes;
    QVector<qreal> indices;

    for(qint64 i = 0; i < array.length(); i++){
        amplitudes.push_back(qSqrt(qPow(array.at(i).real(),2) + qPow(array.at(i).imag(),2)));
        indices.push_back(i);
        qDebug() << "Index: " << indices.at(i) << " Amplitude: " << amplitudes.at(i);
    }

    plot->addGraph();
    plot->xAxis->setRange(0, NUMBER_OF_COUNTS);
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
    FourierSeries array;
    qint64 step = periodSize/NUMBER_OF_COUNTS;

    QVector<qreal> discreted;
    for(qint64 i = step; i < periodSize + 1; i += step){
        discreted.push_back(this->values->second.mid(0, periodSize + 1).at(i));
    }

    array = discreteFourierTransform(discreted);

    QVector<qreal> phases;
    QVector<qreal> indices;

    for(qint64 i = 0; i < array.length(); i++){
        phases.push_back(qRadiansToDegrees(qAtan(array.at(i).imag() / qSqrt(qPow(array.at(i).real(),2) + qPow(array.at(i).imag(),2)))));
        indices.push_back(i);
    }

    plot->addGraph();
    plot->xAxis->setRange(0, NUMBER_OF_COUNTS);
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
    FourierSeries array;
    qint64 step = periodSize/NUMBER_OF_COUNTS;

    QVector<qreal> discreted, x;
    qint64 index = 0;
    for(qint64 i = step; i < periodSize + 1; i += step){
        discreted.push_back(this->values->second.mid(0, periodSize + 1).at(i));
        x.push_back(index);
        index++;
    }

    array = discreteFourierTransform(discreted);

    QVector<qreal> source = inverseDiscreteDourierTransform(array);
    qDebug() << "Length: " << source.length();
    for(qint64 i = 0; i < source.length(); i++){
        qDebug() << source.at(i);
    }

    plot->addGraph();
    plot->xAxis->setRange(0, 17);
    plot->yAxis->setRange(-2, 2);
    plot->graph(0)->setAntialiased(true);


    plot->graph(0)->setName("Inverse Discrete Fourier Transform");
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    plot->graph(0)->setData(x, source);

    plot->legend->setVisible(true);
    plot->replot();

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}
