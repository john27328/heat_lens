#ifndef DUNE_H
#define DUNE_H

//#include <QtGui>
//#include <QApplication>
#include <QThread>
#include <QTimer>
#include <math.h>


#include <QFile>
#include <QDataStream>
#include <QString>
#include <QFileDialog>

//a=K_t*lt*D_t/C_t/mKl;
//m=rho*V=rho*lt^3;
//DT=a*T0[i][j][k];
//K=K*Вт/м/К*м*с/(Дж/кг/К)/кг
//K=K*Вт/м/К*м*с/Дж*кг*К/кг
//K=кг*К/кг

#define R 20. //в мм
#define L 4.  //в мм
#define R_m (R/1000.)  //в м
#define L_m (L/1000.) //в м



#define nKlX 200
#define nKlY nKlX
#define lt (R/nKlX/1000.) //размеры куба в м


#define nKlZ ((int)(L*nKlX/R+.5))

#define TR 300.  // комнатная температура в кельвинах
#define C_t 339.//теплоемкость//удельная теплоемкость 339Дж/кг/К
#define D_t 0.0001 //шаг в с
#define K_t 19. //коэффициент теплопроводности//19 Вт/м/К
#define rho 5.27 //плотность 5.27 гр/см^3
#define mKl (rho/1000.*(lt*100)*(lt*100)*(lt*100))

#define Tkr .2 // коэффициент пропускания кристалла
#define Tkl (pow(Tkr,1./nKlZ)) // коэффициент пропускания клетки
#define P0 700 //падающая мощность

class dune :public QThread
{
Q_OBJECT
public:
    dune();
    //int live(int i,int j);

    void restart();
    void run();
    //double l_t; //размеры куба
    //double D_t; //шаг
    //double K_t;  //коэффициент теплопроводности
    //double C;
    double T_min;
    double T_max;
    double t;
    int n,nn,nnn;
    QTimer timer;
    double a;
    double T0[nKlX+2][nKlY+2][nKlZ+2]; //хранит температуру в кельвинах
    double T1[nKlX+2][nKlY+2][nKlZ+2];
    void border(int i0, int j0, int k0, int i, int j, int k, double dT);
    QString str;
    QFile *file;
private:
    void transfer();
    void border();
    void source();
public slots:
    void step();

};

#endif // DUNE_H
