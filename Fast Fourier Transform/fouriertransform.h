#ifndef FOURIERTRANSFORM_H
#define FOURIERTRANSFORM_H

#include <QVector>
#include <complex>
#include <cmath>

enum TransformType{
    DIRECT_TRANSFORM,
    INVERSE_TRANSFORM
};

class FourierTransform{
    public:
        FourierTransform();
        FourierTransform(const QVector<qreal>& values);
        QVector<std::complex<qreal>> discretTransform(TransformType type = DIRECT_TRANSFORM);
        QVector<std::complex<qreal>> fastTransform(const QVector<std::complex<qreal>>& array, TransformType type = DIRECT_TRANSFORM);
    private:
        QVector<std::complex<qreal>>* values;
};

#endif // FOURIERTRANSFORM_H
