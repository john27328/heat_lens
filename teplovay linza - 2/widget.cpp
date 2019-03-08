#include "widget.h"
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //qDebug()<<"Widget";
    t=new QTimer;
    //resize(1000,1000);
    //qDebug()<<"Widget end";
    k=0;
    connect(t,SIGNAL(timeout()),this,SLOT(step()));
}

void Widget::paintEvent(QPaintEvent *)
{
    //qDebug()<<"paintEvent";
    //resize(1000,1000);
    QPainter paint(this);


    //qDebug()<<width()<<height();
    //const int N=100;
    int r,g,b;
    double A=(d.T_max-d.T_min)/510;
    double B=d.T_min/A+255;
    double w=width(), h=height(),wr=w/nKl,hr=h/nKl;
    for (int i=0;i<nKl+2;i++)
        for (int j=0;j<nKl+2;j++)
        {

            double x; //-255..255
            //qDebug()<<d.T_min<<T<<d.T_max;
            //double k_T=(d.T_max-d.T_min)/510;
            x=d.T1[i][j]/A-B;
            //qDebug()<<x;
            if(x<-255) x=-255;
            if(x>255) x=255;

            if(x<=0){
                r=g=255+x;
                //g=255+gradT(d.T1[i][j]);
                b=255;
            }
            else
            {
                r=255;
                g=b=255-x;
                //b=255-gradT(d.T1[i][j]);
            }
                //qDebug()<<r<<g<<b;
                paint.setPen(QColor(r,g,b));
                paint.setBrush(QColor(r,g,b));

            paint.drawRect(QRect(wr*i,hr*j,wr,hr));


            //paint.setPen(Qt::black);
            //paint.drawText(QRect(wr*i,hr*j,wr,hr),QString::number((int)(d.T(i,j)+.5)));

        }
    paint.setFont(QFont("Times", 25, QFont::Normal));
    paint.setPen(Qt::black);
    paint.drawText(0,h,QString::number((int)(d.n)));
    d.n=0;
    //qDebug()<<"paintEvent end";
}

int Widget::gradT(double T)
{
    double x; //-255..255
    //qDebug()<<d.T_min<<T<<d.T_max;
    //double k_T=(d.T_max-d.T_min)/510;
    x=(T-d.T_min)/(d.T_max-d.T_min)*510-255;
    //qDebug()<<x;
    if(x<-255) x=-255;
    if(x>255) x=255;
    return x;

}

void Widget::startT()
{
    //qDebug()<<"Widget::startT";
    //d.restart();
    t->start(2000);
    d.run();
    //qDebug()<<"Widget::startT end";

}

void Widget::stopT()
{
    //qDebug()<<"Widget::stopT";
    d.timer.stop();
    t->stop();
    //qDebug()<<"Widget::stopT end";
}

void Widget::step()
{
    //qDebug()<<"Widget::step";
    //for (int i=1;i<50;i++) d.step();
    update(); //qDebug()<<"update";
    //qDebug()<<d.n;

    //qDebug()<<"Widget::step end";
}

