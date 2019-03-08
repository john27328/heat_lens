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
    QPen pen1(QColor(0,0,0));
    QBrush brush1(QColor(0,0,0));

    //qDebug()<<width()<<height();
    //const int N=100;
    int r,g,b;
    double w=width(), h=height(),wr=w/nKl,hr=h/nKl;
    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++)
        {

            if(gradT(d.T(i,j))<=0){
                r=255+gradT(d.T(i,j));
                g=255+gradT(d.T(i,j));
                b=255;
            }
            else
            {
                r=255;
                g=255-gradT(d.T(i,j));
                b=255-gradT(d.T(i,j));
            }
                paint.setPen(QColor(r,g,b));
                paint.setBrush(QColor(r,g,b));

            paint.drawRect(QRect(wr*i,hr*j,wr,hr));


            //paint.setPen(Qt::black);
            //paint.drawText(QRect(wr*i,hr*j,wr,hr),QString::number((int)(d.T(i,j)+.5)));

        }
    //qDebug()<<"paintEvent end";
}

int Widget::gradT(double T)
{
    double x; //-255..255
    double k_T=(d.T_max-d.T_min)/510;
    x=(T-d.T_min)/(d.T_max-d.T_min)*510-255;
    if(x<-255) x=-255;
    if(x>255) x=255;
    return x;
}

void Widget::startT()
{
    //qDebug()<<"Widget::startT";
    //d.restart();
    t->start(1000);

    //qDebug()<<"Widget::startT end";

}

void Widget::stopT()
{
    //qDebug()<<"Widget::stopT";
    t->stop();
    //qDebug()<<"Widget::stopT end";
}

void Widget::step()
{
    //qDebug()<<"Widget::step";
    for (int i=1;i<50;i++) d.step();
    update();
    //qDebug()<<"Widget::step end";
}

