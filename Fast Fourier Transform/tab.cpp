#include "tab.h"

Tab::Tab(const QPair<QVector<qreal>, QVector<qreal>> &values, TabType type){
    this->values = new QVariant();
    this->values->setValue(values);
    this->plot = new QCustomPlot();
    this->mainLayout = new QVBoxLayout();

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

Tab::Tab(const QVector<std::complex<qreal> > &values, TabType type){

}

void Tab::general(){
    plot->addGraph();
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->xAxis->setRange(0, 10);
    plot->yAxis->setRange(-2, 2);
    Coordinates temp = this->values->value<Coordinates>();

    qint64 periodSize = getPeriod(temp.second);

    plot->graph(0)->setData(temp.first.mid(0, periodSize + 1), temp.second.mid(0, periodSize + 1));

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}

void Tab::amplitude(){

}

void Tab::frequency(){

}

void Tab::inverse(){

}
