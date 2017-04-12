#include "FastFourierTransform.h"

FastFourierTransform::FastFourierTransform()
{
    additionCounter = 0;
    multiplyCounter = 0;
}

QVector<complex<double>> *FastFourierTransform::transform(const QVector<std::complex<double>> &data)
{
    /*if (data.size() == 1)
    {
        QVector<complex<double>> *vector = new QVector<complex<double>>(1);
        (*vector)[0] = data[0];
        return vector;
    }

    QVector<complex<double>> even(data.size()/2);
    QVector<complex<double>> odd(data.size()/2);

    for (int i = 0; i < data.size(); i++)
    {
        if (!(i % 2))
        {
            even[i/2] = data[i];
        }
        else
        {
            odd[i/2] = data[i];
        }
    }

    QVector<complex<double>> *yEven = transform(even);
    QVector<complex<double>> *yOdd = transform(odd);

    complex<double> e(exp(1.0), 0);
    complex<double> wn = pow(e, -2. * complex<double>(0,1) * M_PI / static_cast<double>(data.size()));
    complex<double> w(1, 0);

    multiplyCounter += 4;

    QVector<complex<double>> *y = new QVector<complex<double>>(data.size());

    for (int i = 0; i < data.size()/2; i++)
    {
        (*y)[i] = ((*yEven)[i] + (w * (*yOdd)[i]));
        (*y)[i + data.size()/2] = ((*yEven)[i] - (w * (*yOdd)[i]));

        w = w * wn;
        multiplyCounter += 3;
        additionCounter += 2;
    }

    return y;*/
    if (data.size() == 1)
        {
            QVector<std::complex<double>> *vector = new QVector<std::complex<double>>(1);
            (*vector)[0] = data[0];
            return vector;
        }
        QVector<std::complex<double>> b(data.size()/2);
        QVector<std::complex<double>> c(data.size()/2);

        std::complex<double> e(exp(1.0), 0);
        complex<double> wn = pow(e, -2. * complex<double>(0,1) * M_PI / static_cast<double>(data.size()));
        std::complex<double> w(1, 0);

         multiplyCounter += 4;

        for (int i = 0;i<data.size()/2;i++)
        {
            b[i] = data[i] + data[i + data.size()/2];
            c[i] = w * (data[i] - data[i + data.size()/2]);
            w = w * wn;
            multiplyCounter += 3;
            additionCounter += 2;
        }

        QVector<std::complex<double>> *nb = transform(b);
        QVector<std::complex<double>> *nc = transform(c);
        QVector<std::complex<double>> *y = new QVector<std::complex<double>>(data.size());
        for (int i = 0;i<data.size()/2;i++)
        {
            (*y)[2*i] = (*nb)[i];
            (*y)[2*i+1] = (*nc)[i];
        }
        delete nb;
        delete nc;
        return y;
}

QVector<std::complex<double> > *FastFourierTransform::directTransform(const QVector<complex<double> > &data)
{
    additionCounter = 0;
    multiplyCounter = 0;

    QVector<complex<double>> *y = transform(data);

    for (int i = 0; i < data.size(); i++)
    {
        (*y)[i] /= static_cast<double>(data.size());
        multiplyCounter += 1;
    }

    return y;
}

QVector<std::complex<double> > *FastFourierTransform::directTransform(const QVector<double> &data)
{
    QVector<complex<double>> u(data.size());

    for (int i = 0; i < data.size(); i++)
    {
        u[i] = complex<double>(data[i], 0);
    }

    return directTransform(u);
}

QVector<complex<double>> * FastFourierTransform::inverseTransform(const QVector<complex<double>> &data)
{
    QVector<complex<double>> *result = new QVector<complex<double>>(data.size());

    complex<double> e(exp(1.0), 0);

    for(int m = 0; m < data.size(); m++)
    {
        complex<double> w = pow(e, -2. * complex<double>(0,1) * M_PI / static_cast<double>(data.size()));

        complex<double> sum(0,0);
        for(int k = 0; k < data.size(); k++)
        {
            sum += data[k] * pow(w, -1 * k * m);
        }

        (*result)[m]= sum;
    }
    return result;
}

