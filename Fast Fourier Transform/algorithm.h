#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <complex>
#include <cmath>
#include <QVector>
#include <QDebug>
#include <QtMath>

qreal function(qreal argument);
QVector<qreal> fillWithStep(qint64 size, qreal startValue, qreal step);
qreal roundWithPrecision(qreal number, qint64 precision = 3);
bool compareWithEpsilon(qreal first, qreal second);
QVector<std::complex<qreal>> toComplex(const QVector<qreal>& first, const QVector<qreal>& second);

#endif // ALGORITHM_H
