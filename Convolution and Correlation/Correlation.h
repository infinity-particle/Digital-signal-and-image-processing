#ifndef CORRELATION_H
#define CORRELATION_H

#include <QVector>
#include <complex>

#include "DiscreteFourierTransform.h"
#include "FastFourierTransform.h"

using namespace std;

class Correlation
{
public:
    Correlation();
    QVector<complex<double> > *execute(const QVector<complex<double> > &first, const QVector<complex<double> > &second, DiscreteFourierTransform &transform);
    QVector<complex<double> > *execute(const QVector<double> &first, const QVector<double> &second, DiscreteFourierTransform &transform);

    QVector<complex<double> > *execute(const QVector<complex<double> > &first, const QVector<complex<double> > &second, FastFourierTransform &transform);
    QVector<complex<double> > *execute(const QVector<double> &first, const QVector<double> &second, FastFourierTransform &transform);
};

#endif // CORRELATION_H
