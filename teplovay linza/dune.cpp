#include "dune.h"
#include <QDebug>
#include <time.h>

dune::dune()
{
    //qDebug()<<"dune";
    restart();
    //qDebug()<<"dune  end";
    C=100;Dt=0.05;l=0.2;k=2000;
    T_min=0;T_max=3000;
}


int dune::live(int i, int j)
{
    //qDebug()<<"live";
    return T0[i][j]==0;
}

void dune::step()
{
    //qDebug()<<"step";

    t+=Dt;n++;

    transfer();
    border();
    source();

    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++){
            T0[i][j]=T1[i][j];

        }
    //qDebug()<<"step end ";
}

void dune::restart()
{
    //qDebug()<<"restart";
    srand(time(NULL));

    t=0;n=0;

    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++)
            if(i>nKl/3 && i<nKl*2/3 && j>nKl/3 && j<nKl*2/3)
                T0[i][j]=T1[i][j]=3273;
            else
                T0[i][j]=T1[i][j]=300;


}


double dune::T(int i, int j)
{
    double x;
    if((i)>=0 && (i)<nKl && (j)>=0 && (j)<nKl)
        x=T0[i][j]-273;
    else
        x=0;
    return x;
}

void dune::sT1(int i, int j, double DT1)
{
    if((i)>=0 && (i)<nKl && (j)>=0 && (j)<nKl)
        T1[i][j]+=DT1;
}

void dune::transfer()
{
    //перераспределение тепла
    double DT;
    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++)
        {
            DT=k*l*T0[i][j]/C*Dt;
            sT1(i,j,-DT*N_d2_or_3d*2);
            sT1(i+1,j,DT);
            sT1(i-1,j,DT);
            sT1(i,j+1,DT);
            sT1(i,j-1,DT);
        }
}

void dune::border()
{
    for (int i=0;i<nKl;i++)
    {
        T1[i][0]=300;
        T1[i][nKl-1]=300;
        T1[0][i]=300;
        T1[nKl-1][i]=300;
    }

}

void dune::source()
{

}
