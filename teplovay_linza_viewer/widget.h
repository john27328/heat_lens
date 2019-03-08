#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "dune.h"
#include <QTimer>
//#include <mainwindow.h>
#include "grafwidget.h"
//#include "grafsource.h"


class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    dune d;
    virtual void paintEvent(QPaintEvent*);
    QTimer *t;
    int k;
    int KlX,KlZ;
    grafSource *source;
    grafWidget *graf;

protected:
    //virtual void timerEvent(QTimerEvent *);
private:
    int gradT(double T);

signals:

public slots:
    void startT();
    void stopT();
    void step();

};

#endif // WIDGET_H
