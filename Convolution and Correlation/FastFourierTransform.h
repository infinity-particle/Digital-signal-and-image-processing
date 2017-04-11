#ifndef FASTFOURIERTRANSFORM_H
#define FASTFOURIERTRANSFORM_H

#include <QVector>
#include <complex>
#include <cmath>

using namespace std;

class FastFourierTransform
{
public:
    int additionCounter, multiplyCounter;

    FastFourierTransform();

    QVector<complex<double>>* transform(const QVector<complex<double>> &data);
    QVector<complex<double>>* directTransform(const QVector<complex<double> > &data);
    QVector<complex<double>>* directTransform(const QVector<double> &data);
    QVector<complex<double>>* inverseTransform(const QVector<complex<double>> &data);

    static QVector<double>* getAmplitude(const QVector<complex<double>> &numbers);
    static QVector<double>* getPhase(const QVector<complex<double>> &numbers);
};

#endif // FASTFOURIERTRANSFORM_H
