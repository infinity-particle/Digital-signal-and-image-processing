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
#include "function.h"

enum TabType{
    GENERAL,
    AMPLITUDE,
    PHASE,
    INVERSE
};

#define NUMBER_OF_COUNTS 16

class Tab : public QWidget{
    Q_OBJECT

    public:
        Tab(const Function& f, TabType type);

    private:
        void general();
        void amplitude();
        void frequency();
        void inverse();

        QCustomPlot* plot;
        Function* f;
        QVBoxLayout* mainLayout;
};

#endif // TABWIDGET_H
