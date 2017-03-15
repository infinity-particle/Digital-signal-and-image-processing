#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPair>
#include <complex>
#include <QTabWidget>
#include <QVBoxLayout>
#include "qcustomplot.h"
#include "algorithm.h"

enum TabType{
    GENERAL,
    AMPLITUDE,
    FREQUENCY,
    INVERSE
};

#define NUMBER_OF_COUNTS 64

typedef QPair<QVector<qreal>, QVector<qreal>> Coordinates;
typedef QVector<std::complex<qreal>> FourierSeries;

Q_DECLARE_METATYPE(Coordinates)
Q_DECLARE_METATYPE(FourierSeries)

class Tab : public QWidget{
    Q_OBJECT

    public:
        Tab(const Coordinates& values, TabType type);
    private:
        void general();
        void amplitude();
        void frequency();
        void inverse();

        QCustomPlot* plot;
        Coordinates* values;
        qint64 periodSize;
        QVBoxLayout* mainLayout;
};

#endif // TABWIDGET_H
