#include "Correlation.h"

Correlation::Correlation()
{

}

QVector<complex<double> > *Correlation::execute(const QVector<complex<double> > &first, const QVector<complex<double> > &second, DiscreteFourierTransform &transform)
{
    QVector<complex<double>> *cx = transform.directTransform(first);
    QVector<complex<double>> *cy = transform.directTransform(second);
    QVector<complex<double>> *c = new QVector<complex<double>>(first.size());

    for (int i = 0; i<first.size(); i++)
    {
        (*c)[i] = complex<double>((*cx)[i].real(), -((*cx)[i].imag())) * (*cy)[i];
        transform.additionCounter++;
        transform.multiplyCounter++;
    }

    QVector<complex<double>> *x = transform.inverseTransform((*c));
    delete c;
    return x;
}

QVector<complex<double> > *Correlation::execute(const QVector<double> &first, const QVector<double> &second, DiscreteFourierTransform &transform)
{
    QVector<complex<double>> u(first.size());
    QVector<complex<double>> y(first.size());
    for (int i = 0;i<first.size();i++)
    {
        u[i] = complex<double>(first[i], 0);
        y[i] = complex<double>(second[i], 0);
    }
    return execute(u, y, transform);
}

QVector<complex<double> > *Correlation::execute(const QVector<complex<double> > &first, const QVector<complex<double> > &second, FastFourierTransform &transform)
{
    QVector<complex<double>> *cx = transform.directTransform(first);
    QVector<complex<double>> *cy = transform.directTransform(second);
    QVector<complex<double>> *c = new QVector<complex<double>>(first.size());
    for (int i = 0; i<first.size(); i++)
    {
        (*c)[i] = complex<double>((*cx)[i].real(), -((*cx)[i].imag())) * (*cy)[i];
        transform.additionCounter++;
        transform.multiplyCounter++;
    }
    QVector<complex<double>> *x = transform.inverseTransform((*c));
    delete c;
    return x;
}

QVector<complex<double> > *Correlation::execute(const QVector<double> &first, const QVector<double> &second, FastFourierTransform &transform)
{
    QVector<complex<double>> u(first.size());
    QVector<complex<double>> y(first.size());
    for (int i = 0;i<first.size();i++)
    {
        u[i] = complex<double>(first[i], 0);
        y[i] = complex<double>(second[i], 0);
    }
    return execute(u, y, transform);
}

