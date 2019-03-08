#ifndef DUNE_H
#define DUNE_H

//#include <QtGui>
//#include <QApplication>
#include <QThread>
#include <QTimer>

#define nKl 300
#define N_d2_or_3d 2 //размерность задачи
class dune :public QThread
{
Q_OBJECT
public:
    dune();
    int live(int i,int j);

    void restart();
    void run();
    double l; //размеры куба
    double Dt; //шаг
    double k;  //коэффициент теплопроводности
    double C;
    double T_min;
    double T_max;
    double t,n;
    QTimer timer;
    double a;
    double T(int i, int j); //возвращает температуру ячейки в цельсиях
    void sT1(int i, int j,double dT1);  //прирост
    double T0[nKl+2][nKl+2]; //хранит температуру в кельвинах
    double T1[nKl+2][nKl+2];
private:
    void transfer();
    void border();
    void source();
public slots:
    void step();

};

#endif // DUNE_H
