#include "DiscreteFourierTransform.h"
#include <math.h>

DiscreteFourierTransform::DiscreteFourierTransform()
{
    additionCounter = 0;
    multiplyCounter = 0;
}

QVector<complex<double>>* DiscreteFourierTransform::directTransform(const QVector<complex<double>> &data)
{
    additionCounter = 0;
    multiplyCounter = 0;

    QVector<complex<double>> *result = new QVector<complex<double>>(data.size());

    complex<double> e(exp(1.0), 0);

    for(int k = 0; k < data.size(); k++)
    {
        /* W = e^(-2*pi*i/N) */
        complex<double> w = pow(e, -2. * complex<double>(0,1) * M_PI / static_cast<double>(data.size()));

        multiplyCounter += 4;

        complex<double> sum(0,0);

        for(int m = 0; m<data.size(); m++)
        {
            sum += data[m] * pow(w, k * m);
            additionCounter += 1;
            multiplyCounter += 2;
        }

        (*result)[k]= sum / static_cast<double>(data.size());
        multiplyCounter += 1;
    }
    return result;
}

QVector<complex<double>>* DiscreteFourierTransform::directTransform(const QVector<double> &data)
{
    QVector<complex<double>> u(data.size());

    for (int i = 0; i<data.size(); i++)
    {
        u[i] = complex<double>(data[i], 0);
    }

    return directTransform(u);
}

QVector<complex<double>>* DiscreteFourierTransform::inverseTransform(const QVector<std::complex<double>> &data)
{
    QVector<std::complex<double>> *result = new QVector<std::complex<double>>(data.size());

    std::complex<double> e(exp(1.0), 0);

    for(int m = 0;m<data.size();m++)
    {
        std::complex<double> w = std::pow(e, -2. * std::complex<double>(0,1) * M_PI / static_cast<double>(data.size())); //W=e^(-2*pi*i/N)

        std::complex<double> summ(0,0);

        for(int k = 0;k<data.size();k++)
        {
            summ += data[k] * std::pow(w, -1 * k * m);
        }
        (*result)[m]= summ;
    }
    return result;
}

QVector<double>* DiscreteFourierTransform::getAmplitude(const QVector<std::complex<double>> &numbers)
{
    QVector<double> *result = new QVector<double>(numbers.size());

    for (int i=0;i<numbers.size();i++) {
        (*result)[i] = sqrt(pow(numbers[i].real(), 2) + pow(numbers[i].imag(), 2));
    }
    return result;
}

QVector<double> * DiscreteFourierTransform::getPhase(const QVector<std::complex<double>> & numbers)
{
    QVector<double> *result = new QVector<double>(numbers.size());
    for (int i=0;i<numbers.size();i++) {
        (*result)[i] = atan(numbers[i].imag() / numbers[i].real());
    }
    return result;
}

