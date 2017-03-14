#include "algorithm.h"

QVector<std::complex<qreal>> DFT(const QVector<qreal>& functionValues, const QVector<qreal>& argumentValues){
    QVector<std::complex<qreal>>* result = new QVector<std::complex<qreal>>();
    unsigned int size = functionValues.length();

    for (unsigned int k = 0; k < size; k++) {
        std::complex<qreal> sum = 0.0;

        for (unsigned int t = 0; t < size; t++) {
            double angle = 2 * M_PI * t * k / size;
            double realPart = argumentValues.at(t) * cos(angle) + functionValues.at(t) * sin(angle);
            double imaginePart = -argumentValues.at(t) * sin(angle) + functionValues.at(t) * cos(angle);

            sum += std::complex<qreal>(realPart,imaginePart);
        }
        result->insert(k, sum);
    }

    return *result;
}

QVector<qreal> function(const QVector<qreal>& argument){
    QVector<qreal>* functionValues = new QVector<qreal>();

    for(qint64 i = 0; i < argument.length(); i++){
        functionValues->append(qSin(argument.at(i)) + qCos(4.0f * argument.at(i)));
        qDebug() << functionValues->at(i);
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
