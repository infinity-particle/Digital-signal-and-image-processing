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

  /*  qreal max = *std::max_element(temp.second.begin(), temp.second.end());
    qDebug() << "Max element: " << max;
    qint64 startIndex = temp.second.indexOf(max);
    qint64 endIndex = temp.second.indexOf(max, startIndex + 1);
    qint64 periodSize = endIndex - startIndex;

    qDebug() << "Start index: " << startIndex;
    qDebug() << "End index: " << endIndex;
    qDebug() << "Period size: " << periodSize;
    qDebug() << "Last index of max element:" << temp.second.lastIndexOf(max);

    QPair<QVector<qreal>, QVector<qreal>> period;
    for(qint64 i = 0; i < periodSize; i++){
        period.first.push_back(temp.first.at(i));
        period.second.push_back(temp.second.at(i));
    }

    plot->graph(0)->setData(period.first,period.second);*/

    plot->graph(0)->setData(temp.first, temp.second);

    this->mainLayout->addWidget(plot);
    this->setLayout(mainLayout);
}

void Tab::amplitude(){

}

void Tab::frequency(){

}

void Tab::inverse(){

}
