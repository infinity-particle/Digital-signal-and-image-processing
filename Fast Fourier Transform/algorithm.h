#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <complex>
#include <cmath>
#include <QVector>
#include <QDebug>
#include <QtMath>

QVector<std::complex<qreal>> discreteFourierTransform(const QVector<qreal>& functionValues);
QVector<qreal> inverseDiscreteDourierTransform(const QVector<std::complex<qreal>>& values);
QVector<std::complex<qreal>> fastFourierTransform(const QVector<qreal>& functionValues);


QVector<qreal> function(const QVector<qreal>& argument);
QVector<qreal> fillWithStep(qint64 size, qreal startValue, qreal step);
qreal getMax(const QVector<qreal>& array);
qint64 getPeriod(const QVector<qreal>& array);
qreal roundWithPrecision(qreal number, qint64 precision = 3);
bool compareWithEpsilon(qreal first, qreal second);

#endif // ALGORITHM_H
