#include "algorithm.h"

QVector<std::complex<qreal>> discreteFourierTransform(const QVector<qreal>& functionValues){
    QVector<std::complex<qreal>>* result = new QVector<std::complex<qreal>>();
    unsigned int size = functionValues.length();

    for (unsigned int m = 0; m < size; m++) {
        std::complex<qreal> sum = 0.0;

        for (unsigned int n = 0; n < size; n++) {
            double angle = 2 * M_PI * n * m / size;
            double realPart = functionValues.at(n) * cos(angle);
            double imaginePart = -functionValues.at(n) * sin(angle);

            sum += std::complex<qreal>(realPart,imaginePart);
        }
        result->push_back(sum);
    }

    return *result;
}

QVector<qreal> inverseDiscreteDourierTransform(const QVector<std::complex<qreal> > &values){
    QVector<qreal>* result = new QVector<qreal>();
    qint64 size = values.length();

    for (qint64 n = 0; n < size; n++) {
        qreal sum = 0.0;

        for (qint64 m = 0; m < size; m++) {
            qreal angle = 2 * M_PI * n * m / size;
            qreal realPart = values.at(m).real() * qCos(angle) - values.at(m).imag() * qSin(angle);

            sum += realPart;
        }
        result->push_back(sum/size);
    }

    return *result;
}

QVector<std::complex<qreal>> fastFourierTransform(const QVector<qreal> &functionValues){

}

QVector<qreal> function(const QVector<qreal>& argument){
    QVector<qreal>* functionValues = new QVector<qreal>();

    for(qint64 i = 0; i < argument.length(); i++){
        functionValues->append(qSin(argument.at(i)) + qCos(4.0f * argument.at(i)));
    }

    return *functionValues;
}

QVector<qreal> fillWithStep(qint64 size, qreal startValue, qreal step){
    QVector<qreal> array;
    for(qint64 i = 0; i < size; i++){
        array.append(startValue);
        startValue += step;
    }
    return array;
}

qreal getMax(const QVector<qreal> &array){
    qreal max = array.at(0);
    for(qint64 i = 1; i < array.length(); i++){
        if(array.at(i) > max){
            max = array.at(i);
        }
    }
    return max;
}

qint64 getPeriod(const QVector<qreal> &array){
    qreal max = getMax(array);

    qint64 startIndex = 0, endIndex = 0, count = 0;
    for(qint64 i = 0; i < array.length(); i++){
        if(compareWithEpsilon(roundWithPrecision(array.at(i),4), roundWithPrecision(max, 4))){
            if(count == 0){
                startIndex = i;
                count++;
            }else{
                if(count == 1){
                    endIndex = i;
                    break;
                }
            }
        }
    }
    return endIndex - startIndex;
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
