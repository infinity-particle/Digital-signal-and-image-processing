#ifndef FUNCTION_H
#define FUNCTION_H

#include <QVector>
#include <complex>
#include "algorithm.h"

typedef qreal (*f)(qreal);

class Function{
    public:
        Function();
        Function(const QVector<qreal>& x, qreal (*f)(qreal));
        Function(const Function& f);
        qreal getMax(bool flag = true);
        QVector<qreal> getDiscretValues(qint64 step, bool flag = true);
        QVector<qreal> getX();
        QVector<qreal> getY();
        qint64 countPeriodSize();
        qint64 getPeriodSize();
        QVector<qreal> getPeriod();
    private:
        QVector<qreal>* x;
        QVector<qreal>* y;
        QVector<qreal>* period;
        qint64 periodSize;

};

#endif // FUNCTION_H
