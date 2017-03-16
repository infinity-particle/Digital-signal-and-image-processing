#include "fouriertransform.h"

FourierTransform::FourierTransform(){
    this->values = nullptr;
}

FourierTransform::FourierTransform(const QVector<qreal> &values){
    this->values = new QVector<std::complex<qreal>>();
    for(qint64 i = 0; i < values.length(); i++){
        this->values->append(std::complex<qreal>(values.at(i), 0.0));
    }
}

QVector<std::complex<qreal>> FourierTransform::discretTransform(TransformType type){
    QVector<std::complex<qreal>>* result = new QVector<std::complex<qreal>>();
    qint64 size = this->values->length();

    for (qint64 m = 0; m < size; m++) {
        std::complex<qreal> sum = 0.0;
        for (qint64 n = 0; n < size; n++) {
            qreal angle = 2 * M_PI * n * m / size;
            qreal realPart, imaginePart;
            if(type == DIRECT_TRANSFORM){
                realPart = this->values->at(n) * cos(angle);
                imaginePart = -this->values->at(n) * sin(angle);
            }else if(type == INVERSE_TRANSFORM){
                realPart = this->values->at(m).real() * qCos(angle) -
                        this->values->at(m).imag() * qSin(angle);
                imaginePart = 0.0;
            }

            sum += std::complex<qreal>(realPart,imaginePart);
        }
        if(type == DIRECT_TRANSFORM){
            result->push_back(sum);
        }else if(type == INVERSE_TRANSFORM){
            result->push_back(sum/size);
        }
    }
    return *result;
}

QVector<std::complex<qreal>> FourierTransform::fastTransform(const QVector<std::complex<qreal>>& array, TransformType type){
    qint64 N = array->length();

    if (N <= 1){
        QVector<std::complex<qreal>> *vector = new QVector<std::complex<qreal>>();
        vector->push_back(array.first());
        return *vector;
    }

    QVector<std::complex<qreal>> b(N/2);
    QVector<std::complex<qreal>> c(N/2);

    std::complex<qreal> wN;
    if(type){
        wN = std::complex<qreal>(qCos(2 * M_PI/N), qSin(2 * M_PI/N));
    }else{
        wN = std::complex<qreal>(qCos(2 * M_PI/N), -qSin(2 * M_PI/N));
    }
    std::complex<qreal> w(1, 0);

    for (qint64 i = 0; i < N/2; i++){
        b.replace(i,this->array->at(i) + this->array->at(i + N/2));
        c.replace(i,this->array->at(i) - this->array->at(i + N/2));
        w = w * wN;
    }

    QVector<std::complex<qreal>> nb = fastTransform(b, type);
    QVector<std::complex<qreal>> nc = fastTransform(c, type);
    QVector<std::complex<qreal>> y(N);

    for (int i = 0; i < N/2; i++) {
        y[2*i] = nb[i];
        y[2*i+1] = nc[i];
    }
    return y;
}
