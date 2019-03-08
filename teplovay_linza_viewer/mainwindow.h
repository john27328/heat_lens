#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "widget.h"

#include <QMainWindow>
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QCheckBox>
#include <QSlider>
//#define N 100


class MWindow : public QWidget
{
    Q_OBJECT

public:
    MWindow(QWidget *parent = 0);
    ~MWindow();
    QHBoxLayout *hl;
    QPushButton *pb;
    QPushButton *pbC;
    QVBoxLayout *vl;
    Widget *w;
    QSlider *slX;
    QSlider *slZ;
    //QCheckBox *cb;
public slots:
//    void startT();
//    void stopT();
    void restart();
//    void t();
//    void setCb(int k);
};

#endif // MAINWINDOW_H
