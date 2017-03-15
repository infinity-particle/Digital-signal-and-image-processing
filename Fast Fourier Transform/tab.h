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

typedef QPair<QVector<qreal>, QVector<qreal>> Coordinates;
Q_DECLARE_METATYPE(Coordinates)

class Tab : public QWidget{
    Q_OBJECT

    public:
        Tab(const Coordinates& values, TabType type);
        Tab(const QVector<std::complex<qreal>>& values, TabType type);
    private:
        void general();
        void amplitude();
        void frequency();
        void inverse();

        QCustomPlot* plot;
        QVariant* values;
        QVBoxLayout* mainLayout;
};

#endif // TABWIDGET_H
