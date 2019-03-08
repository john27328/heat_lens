#include "grafwidget.h"

grafWidget::grafWidget(QWidget *parent) :
    QWidget(parent)
{
    X_min=13.5; Y_min=27; X_max=20; Y_max=100;
    x_0=140, y_0=60; //нижний левый угол графика относительно нижнего левого края поля
    x_1=20,  y_1=50;//верхний правый угол графика
    x_2=5, y_2=5;//выступание сетки за края графика
    y_3=5; //отступ названия графика от верхней границы окна
    y_4=5; //отсуп названия графика от верхней границы графика
    y_5=5; //отступ название оси у от левого края окна
    y_6=100; //отступ название оси у от левого края графика
    y_7=5;//отступ название оси x от нижнего края окна
    y_8=20;//отступ название оси x от нижнего края графика

    DX=X_max-X_min; DY=Y_max - Y_min;
    N_Graf=0;
    setMinimumSize(300,300);
    nameX = "ось x";
    nameY = "ось y";
    nameGraf = "график";
}

void grafWidget::paintEvent(QPaintEvent *)
{
    painter = new QPainter(this);
    w=width(), h=height();
    //qDebug()<<"0";
    if (N_Graf!=0) extremes();
    plotingArea();
    if (N_Graf!=0) plotGraf();
    plotNames();
    //qDebug()<<"4";
    delete painter;
    //qDebug()<<"5";
}

double grafWidget::x(double X)
{
    return (X-X_min)/(X_max-X_min)*(w-x_0-x_1)+x_0;
}

double grafWidget::y(double Y)
{
    return h-(Y-Y_min)/(Y_max-Y_min)*(h-y_0-y_1)-y_0;
}

QPointF grafWidget::XY_to_xy(QPointF point_XY)
{
    QPointF point;
    point.setX(x(point_XY.x()));
    point.setY(y(point_XY.y()));
    return point;
}

void grafWidget::plotingArea() //рисую сетку
{
    //ниже магия, с помощью которой подбираю красивый шаг для сетки
    double Dx_d=DX, Dy_d=DY;
    while (fabs(Dx_d)<10) {
        Dx_d=Dx_d*10;
    }
    while (fabs(Dy_d)<10){
        Dy_d=Dy_d*10;
    }
    while (fabs(Dx_d)>100) {
        Dx_d=Dx_d/10;
    }
    while (fabs(Dy_d)>100){
        Dy_d=Dy_d/10;
    }

    double dx_d,dy_d;
    if(Dx_d<20) dx_d=2;
    else
        if (Dx_d<50) dx_d=5;
        else dx_d=10;

    if(Dy_d<20) dy_d=2;
    else
        if (Dy_d<50) dy_d=5;
        else dy_d=10;
    double dX,dY;
    //вот такой шаг будет
    dX=DX/Dx_d*dx_d;
    dY=DY/Dy_d*dy_d;

    //определяю начальное значение сетки
    double nX,X0;
    nX=(int)(X_min/dX);
    if(X_min<0) nX--;
    X0=(nX+1)*dX;
    double X_sd=X0-X_min;
    if (X_sd==dX) X_sd=0;
    //qDebug()<<"X_sd"<<X_sd;

    double nY,Y0;
    nY=(int)(Y_min/dY);
    if(Y_min<0) nY--;
    Y0=(nY+1)*dY;
    double Y_sd=Y0-Y_min;
    if (Y_sd==dY) Y_sd=0;

    //далее начинаю рисовать
    //рисую белый фон для графика
    QBrush brush(Qt::white);
    painter->fillRect(0,0,w,h,brush);

    //рисую оси
    painter->setPen(QPen(Qt::black,3));
    painter->setRenderHint(QPainter::Antialiasing,true);
    painter->drawLine(QPoint(x(X_min)-x_2,y(Y_min)),QPoint(x(X_max)+x_2,y(Y_min)));
    painter->drawLine(QPoint(x(X_min),y(Y_min)+y_2),QPoint(x(X_min),y(Y_max)-y_2));

    //qDebug()<<"1";
//    if(X_min*X_max <= 0){
//        painter->drawLine(QPoint(x(X_min)-5,y(0)),QPoint(x(X_max),y(0)));
//    }
//    else{
//        painter->drawLine(QPoint(x(X_min)-5,y(Y_min)),QPoint(x(X_max),y(Y_min)));
//    }
//    if(Y_min*Y_max <= 0){
//        painter->drawLine(QPoint(x(0),y(Y_min)+5),QPoint(x(0),y(Y_max)));
//    }
//    else{
//        painter->drawLine(QPoint(x(X_min),y(Y_min)+5),QPoint(x(X_min),y(Y_max)));
//    }
    //qDebug()<<"2";
    //painter->drawLine(QPoint(x_0,h-y_0+5),QPoint(x_0,0));
    
    
    //рисую сетку
    painter->setPen(QPen(Qt::black,1));
    painter->setFont(QFont("Times", 11, QFont::Normal));
    for (double X=X_min+X_sd;X<=X_max;X+=dX)
    {
        painter->drawLine(QPoint(x(X),y(Y_min)+y_2),QPoint(x(X),y(Y_max)-y_2));
        painter->drawText(QRect(x(X)-5,y(Y_min)+5,95,14),QString::number(X));
    }

    painter->setPen(QPen(Qt::black,1));
    for (double Y=Y_min+Y_sd;Y<=Y_max;Y+=dY)
    {
        painter->drawLine(QPoint(x(X_min)-x_2,y(Y)),QPoint(x(X_max)+x_2,y(Y)));
        painter->drawText(QRect(x(X_min)-98,y(Y)-10,90,15),Qt::AlignRight,QString::number(Y));

    }

    double X;
    for (X = X_min + X_sd; X>X_min; X-=dX/5.);
    painter->setPen(QPen(Qt::gray,1,Qt::DashLine));
    for (X+=dX/5.;X<=X_max;X+=dX/5.)
    {
        painter->drawLine(QPoint(x(X),y(Y_min)+y_2),QPoint(x(X),y(Y_max)-y_2));
    }

    double Y;
    for (Y = Y_min + Y_sd; Y>Y_min; Y-=dY/5.);
    painter->setPen(QPen(Qt::gray,1,Qt::DashLine));
    for (Y+=dY/5.;Y<=Y_max;Y+=dY/5.)
    {
        painter->drawLine(QPoint(x(X_min)-x_2,y(Y)),QPoint(x(X_max)+x_2,y(Y)));
    }

}

void grafWidget::extremes()
{
    for(int i=0; i<grafSourceList.size();i++)
    {
        //qDebug()<<i<<grafSourceList[i];
        nPoint= (grafSourceList[i]->iList < grafSourceList[i]->n || grafSourceList[i]->n == 0)
                ? grafSourceList[i]->iList
                : grafSourceList[i]->n;
        if(i==0)
        {
            X_min=grafSourceList[i]->xyList[1].x();
            X_max=grafSourceList[i]->xyList[1].x();
            Y_min=grafSourceList[i]->xyList[1].y();
            Y_max=grafSourceList[i]->xyList[1].y();
        }
        for(int j=0;j<nPoint;j++)
        {
            if (grafSourceList[i]->xyList[j].x()<X_min) X_min=grafSourceList[i]->xyList[j].x();
            if (grafSourceList[i]->xyList[j].x()>X_max) X_max=grafSourceList[i]->xyList[j].x();
            if (grafSourceList[i]->xyList[j].y()<Y_min) Y_min=grafSourceList[i]->xyList[j].y();
            if (grafSourceList[i]->xyList[j].y()>Y_max) Y_max=grafSourceList[i]->xyList[j].y();
        }
    }


    DX=X_max-X_min, DY=Y_max-Y_min;

    //qDebug()<<X_max<<X_min<<Y_max<<Y_min;
    if (DX==0 && X_max==0) X_max=1;
    if (DX==0 && X_max>0) X_min=0;
    if (DX==0 && X_max<0) X_max=0;
    if (DY==0 && Y_max==0) Y_max=1;
    if (DY==0 && Y_max>0) Y_min=0;
    if (DY==0 && Y_max<0) Y_max=0;
    DX=X_max-X_min, DY=Y_max-Y_min;

    X_max+=DX*0.05;
    Y_max+=DY*0.05;
    if (X_min!=0) X_min-=DX*0.05;
    if (Y_min!=0) Y_min-=DY*0.05;
    DX=X_max-X_min, DY=Y_max-Y_min;

}

void grafWidget::plotGraf()
{
    //рисую график
    //qDebug()<<"plotGraf()";
    QPolygonF polygon;
    for(int i=0; i<grafSourceList.size();i++)
    {
        //qDebug()<<i<<grafSourceList[i];
        nPoint= (grafSourceList[i]->iList < grafSourceList[i]->n || grafSourceList[i]->n == 0)
                ? grafSourceList[i]->iList
                : grafSourceList[i]->n;
        //qDebug()<<nPoint;
        painter->setPen(grafSourceList[i]->pen);
        polygon.clear();
        for(int j=0;j<nPoint;j++)
        {
            //qDebug()<<grafSourceList[i]->xyList[j]<<point_xy(grafSourceList[i]->xyList[j]);
            polygon<<XY_to_xy(grafSourceList[i]->xyList[j]);
        }

        painter->drawPolyline(polygon);
    }
}

void grafWidget::plotNames()
{
    painter->setPen(QPen(Qt::black,1));//x_0,y_1-y_4,x_1
    painter->setFont(QFont("Times", 25, QFont::Normal));
    painter->drawText(QRect(QPoint(x_0,y_4),QPoint(w-x_1,y_1-y_4)),Qt::AlignCenter,nameGraf);
    painter->save();
    painter->translate(0,h);painter->rotate(-90);
    painter->setFont(QFont("Times", 20, QFont::Normal));
    painter->drawText(QRect(QPoint(y_0,y_5),QPoint(h-y_1,x_0-y_6)),Qt::AlignHCenter|Qt::AlignBottom,nameY);
    painter->restore();
    painter->setFont(QFont("Times", 20, QFont::Normal));
    painter->drawText(QRect(QPoint(x_0,h-y_0+y_8),QPoint(w-x_1,h-y_7)),Qt::AlignHCenter|Qt::AlignTop,nameX);

}

void grafWidget::addListPoint(grafSource *sourcePTR)
{
    grafSourceList<<sourcePTR;
    N_Graf++;
}
