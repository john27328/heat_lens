#ifndef GRAFWIDGET_H
#define GRAFWIDGET_H

#include <QWidget>

#include <QPainter>
#include <QPointer>
#include "grafsource.h"
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QDebug>
#include <cmath>
#include <QPolygon>
#include <QPolygonF>
#include <QString>
#include <QPainterPath>

class grafWidget : public QWidget
{
    Q_OBJECT
public:
    explicit grafWidget(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent*);
    double X_min, X_max, Y_min, Y_max;
    double w, h;
    double x_0, y_0;
    double x_1, y_1;
    double x_2, y_2;
    double y_3, y_4, y_5, y_6, y_7, y_8;
    double DX, DY;
    double x(double X);
    double y(double Y);
    int N_Graf;
    QPointF XY_to_xy(QPointF point_XY);
    int nPoint;
    void extremes();
    void plotingArea();
    void plotGraf();
    void plotNames();
    QString nameX;
    QString nameY;
    QString nameGraf;
    //void recalculation_of_coordinates_x();
    //void recalculation_of_coordinates_x();
    //void range_XY();
    //void axis();
    //QPainter *painter;
    QPainter *painter;
    //grafSource source;
    void addListPoint(grafSource *sourcePTR);
    QList<grafSource*> grafSourceList;



signals:

public slots:

};

#endif // GRAFWIDGET_H
