#include "widget.h"
#include <QSize>
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <qDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    qDebug()<<"Widget";

    //resize(1000,1000);
    //qDebug()<<"Widget end"<<t;
    k=0;
    connect(&TimerT,SIGNAL(timeout()),this,SLOT(step()));
    qDebug()<<"Widget end";
}

void Widget::paintEvent(QPaintEvent *)
{
    //qDebug()<<"paintEvent";
    //resize(1000,1000);
    QPainter paint(this);


    //qDebug()<<width()<<height();
    //const int N=100;
    int r,g,b;
    double A=1020/(d.Tmax-d.Tmin);
    double B=d.Tmin*A+510;
    int NN=nKlZ/2;
    double w=width(), h=height(),wr=w/(nKlX+2),hr=h/(nKlY+2);
    for (int i=0;i<=nKlX+1;i++)
        for (int j=0;j<=nKlY+1;j++)
        {

            double x; //-255..255
            //x=(T-d.Tmin)/(d.Tmax-d.Tmin)*1020-510;
            //qDebug()<<d.Tmin<<T<<d.Tmax;
            //double kT=(d.Tmax-d.Tmin)/510;
            x=d.T1[i][j][NN]*A-B;
            //qDebug()<<x;

            if(x>=-510 && x<-255)
            {
                r=g=0;
                b=510+x;
            }
            if(x>=-255 && x<0)
            {
                g=0;
                b=255;
                r=255+x;
            }
            if(x>=0 && x<255)
            {
                g=0;
                b=255-x;
                r=255;
            }
            if(x>=255 && x<=510)
            {
                g=x-255;
                b=x-255;
                r=255;
            }
            if(x<-510)
            {
                g=0;
                b=0;
                r=0;
            }
            if(x>510)
            {
                g=255;
                b=255;
                r=255;
            }
//            if(x<=0){
//                r=g=255+x;
//                //g=255+gradT(d.T1[i][j]);
//                b=255;
//            }
//            else
//            {
//                r=255;
//                g=b=255-x;
//                //b=255-gradT(d.T1[i][j]);
//            }
//                //qDebug()<<r<<g<<b;
                paint.setPen(QColor(r,g,b));
                paint.setBrush(QColor(r,g,b));

            paint.drawRect(QRect(wr*(i),hr*(j),wr,hr));


            //paint.setPen(Qt::black);
            //paint.drawText(QRect(wr*i,hr*j,wr,hr),QString::number((int)(d.T(i,j)+.5)));

        }

    paint.setFont(QFont("Times", 25, QFont::Normal));
    paint.setPen(Qt::green);
    paint.drawText(10,h-10,"fps: "+QString::number((int)(d.n)) + "; t=" + QString::number(d.t));
    d.n=0;
    //qDebug()<<"paintEvent end";
}

int Widget::gradT(double T)
{
    double x; //-255..255
    //qDebug()<<d.Tmin<<T<<d.Tmax;
    //double kT=(d.Tmax-d.Tmin)/510;
    x=(T-d.Tmin)/(d.Tmax-d.Tmin)*1020-510;
    //qDebug()<<x;
    if(x<-255) x=-255;
    if(x>255) x=255;
    return x;

}

void Widget::startT()
{
    qDebug()<<"Widget::startT";

    //d.restart();
    TimerT.start(1000);
    d.run();
    qDebug()<<"Widget::startT end";

}

void Widget::stopT()
{
    //qDebug()<<"Widget::stopT"<<t;
    d.timer.stop();
    TimerT.stop();
    //qDebug()<<"Widget::stopT end"<<t;
}

void Widget::step()
{
    //qDebug()<<"Widget::step";
    //for (int i=1;i<50;i++) d.step();
    update(); //qDebug()<<"update";
    //qDebug()<<d.n;

    //qDebug()<<"Widget::step end";
}

