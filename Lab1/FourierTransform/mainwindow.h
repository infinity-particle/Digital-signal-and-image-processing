#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QPen>
#include <QGraphicsScene>


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVBoxLayout *layout;
    QLabel *label;
    QGraphicsScene *scene;
    QPen *pen;
    QGraphicsView *view;
    QWidget *widget;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
