#ifndef DUNE_H
#define DUNE_H

#define nKl 300
#define N_d2_or_3d 2 //размерность задачи
class dune
{

public:
    dune();
    int live(int i,int j);
    void step();
    void restart();
    void run();
    double l; //размеры куба
    double Dt; //шаг
    double k;  //коэффициент теплопроводности
    double C;
    double T_min;
    double T_max;
    double t,n;
    double T(int i, int j); //возвращает температуру ячейки в цельсиях
    void sT1(int i, int j,double dT1);  //прирост
private:
    double T0[nKl][nKl]; //хранит температуру в кельвинах
    double T1[nKl][nKl];
    void transfer();
    void border();
    void source();


};

#endif // DUNE_H
