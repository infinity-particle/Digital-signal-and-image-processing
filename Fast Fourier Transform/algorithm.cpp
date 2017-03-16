#include "algorithm.h"

qreal function(qreal argument){
    return qSin(argument.at(i)) + qCos(4.0f * argument.at(i));
}

QVector<qreal> fillWithStep(qint64 size, qreal startValue, qreal step){
    QVector<qreal> array;
    for(qint64 i = 0; i < size; i++){
        array.append(startValue);
        startValue += step;
    }
    return array;
}

qreal roundWithPrecision(qreal number, qint64 precision){
    QString numberString = QString::number(number);

    return numberString.left(numberString.indexOf(".") + precision + 1).toDouble();
}

bool compareWithEpsilon(qreal first, qreal second){
    const qreal epsilon = 0.0001;
    qreal diff = qAbs(first - second);
    if(diff <= epsilon){
        return true;
    }else{
        return false;
    }
}

QVector<std::complex<qreal>> toComplex(const QVector<qreal> &first, const QVector<qreal> &second){
    QVector<std::complex<qreal>>* result = new QVector<std::complex<qreal>>();

    if(first.length() != second.length()){
        return *result;
    }

    for(qint64 i = 0; i < first.length(); i++){
        result->append(std::complex<qreal>(first.at(i), second.at(i)));
    }

    return *result;
}


