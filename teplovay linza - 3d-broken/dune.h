#ifndef DUNEH
#define DUNEH

//#include <QtGui>
//#include <QApplication>
#include <QThread>
#include <QTimer>
#include <math.h>

#define Dmm    20.                                                          //диаметр в мм
#define Dm     (Dmm / 1000.)                                  //диаметр в м
#define Lmm    4.                                                            //толщина кристалла в мм
#define Lm     (Lmm / 1000.)                                             //диаметр в м


#define nKlX    150                                                         //число кубов
#define nKlY    nKlX
#define lm     (Dm / nKlX)                                                //размеры куба
#define nKlZ    ( Lmm / Dmm * nKlX + .5)
#define TR      300.                                                         // комнатная температура в кельвинах

#define Ct     100.                                                       //теплоемкость
#define dt      0.1                                                         //шаг
#define Kt       50000.                                                       //коэффициент теплопроводности

class dune :public QThread
{
Q_OBJECT
public:
    dune();
    //int live(int i,int j);

    void restart();
    void run();

    double Tmin;
    double Tmax;
    double t,n;
    QTimer timer;
    double a;
    double T0[nKlX+2][nKlY+2][(int)nKlZ+2]; //хранит температуру в кельвинах
    double T1[nKlX+2][nKlY+2][(int)nKlZ+2];
private:
    void transfer();
    void border();
    void source();
public slots:
    void step();

};

#endif // DUNEH
