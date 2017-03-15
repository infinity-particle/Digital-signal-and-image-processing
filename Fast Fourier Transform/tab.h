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

#define NUMBER_OF_COUNTS 16

typedef QPair<QVector<qreal>, QVector<qreal>> Coordinates;
typedef QVector<std::complex<qreal>> FourierSeries;

Q_DECLARE_METATYPE(Coordinates)
Q_DECLARE_METATYPE(FourierSeries)

class Tab : public QWidget{
    Q_OBJECT

    public:
        Tab(const QPair<QVector<qreal>, QVector<qreal>>& sourceValues, TabType type);
    private:
        void general();
        void amplitude();
        void frequency();
        void inverse();

        QCustomPlot* plot;

        QPair<QVector<qreal>, QVector<qreal>>* values;
        QPair<QVector<qreal>, QVector<qreal>>* period;
        QPair<QVector<qreal>, QVector<qreal>>* discretValues;

        QVector<std::complex<qreal>>* DFTValues;
        QVector<std::complex<qreal>>* FFTValues;

        qint64 periodSize;
        QVBoxLayout* mainLayout;
};

#endif // TABWIDGET_H
