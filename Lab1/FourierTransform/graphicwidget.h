#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <qcustomplot.h>
#include <QLabel>

class GraphicWidget : public QWidget{

    Q_OBJECT

    public:
        GraphicWidget();
        ~GraphicWidget();

    private slots:
        void drawThePlot();

    private:
        QVBoxLayout *mainLayout;
        QWidget *centralWidget;
        QPushButton* plotButton;
        QCustomPlot* customPlot;
};

#endif // GRAPHICWIDGET_H
