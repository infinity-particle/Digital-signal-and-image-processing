#ifndef GRAPHICWIDGET_H
#define GRAPHICWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <qcustomplot.h>
#include <QLabel>
#include <QLineEdit>
#include <algorithm>

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
        QLineEdit* leftLimitInput;
        QLineEdit* rightLimitInput;
        QLineEdit* stepInput;
        QCustomPlot* customPlot;
};

#endif // GRAPHICWIDGET_H
