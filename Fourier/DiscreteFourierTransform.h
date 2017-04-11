#ifndef DISCRETEFOURIERTRANSFORM_H
#define DISCRETEFOURIERTRANSFORM_H

#include <QVector>
#include <complex>
#include <cmath>

using namespace std;

class DiscreteFourierTransform
{
public:
    int additionCounter, multiplyCounter;
    DiscreteFourierTransform();
    QVector<complex<double>>* directTransform(const QVector<complex<double> > &data);
    QVector<complex<double>>* directTransform(const QVector<double> &data);
    QVector<complex<double>>* inverseTransform(const QVector<complex<double>> &data);

    static QVector<double>* getAmplitude(const QVector<complex<double>> &numbers);
    static QVector<double>* getPhase(const QVector<complex<double>> &numbers);
};

#endif // DISCRETEFOURIERTRANSFORM_H
