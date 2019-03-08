#include "dune.h"
#include <QDebug>
#include <time.h>


dune::dune(): QThread()
{
    //qDebug()<<"dune";
    restart();
    //qDebug()<<"dune  end";
    C=100;Dt=0.01;l=0.2;K=1000;
    T_min=300;T_max=3273;
    a=K*l/C*Dt;//упрощение рассчетов

}



void dune::step()
{
    //qDebug()<<"step";
    memcpy(T0, T1, sizeof(T1));
    //qDebug()<<"memcpy ok";
    /************************
    for (int i=0;i<nKl;i++)
        for (int j=0;j<nKl;j++){
            T0[i][j]=T1[i][j];

        }
    ***********************/

    t+=Dt;n++;

    transfer();
    border();
    source();





    //qDebug()<<"step end ";
}

void dune::restart()
{
    //qDebug()<<"restart";
    srand(time(NULL));

    t=0;n=0;

//    for (int i=0;i<nKl+2;i++)
//        for (int j=0;j<nKl+2;j++)
//            for (int k=0;k<nKl+1;k++)
//            if(i>nKl/3 && i<nKl*2/3 && j>nKl/3 && j<nKl*2/3 && k>nKl/3 && k<nKl*2/3)
//                T0[i][j][k]=T1[i][j][k]=3273;
//            else
//                T0[i][j][k]=T1[i][j][k]=300;

        for (int i=0;i<nKl+2;i++)
            for (int j=0;j<nKl+2;j++)
                for (int k=0;k<nKl+1;k++)
                    T0[i][j][k]=T1[i][j][k]=300;


}

void dune::run()
{
    connect(&timer, SIGNAL(timeout()), SLOT(step()));
    timer.start(1);

    exec();
}




//void dune::transfer()
//{
//    //перераспределение тепла
//    double DT;
//    //qDebug()<<a;
//    for (int i=0;i<nKl;i++)
//        for (int j=0;j<nKl;j++)
//        {
//            //DT=k*l*T0[i][j]/C*Dt;
//            DT=a*T0[i][j];
//            sT1(i,j,-4*DT);//4-двумерное пространство//6-трехмерное
//            sT1(i+1,j,DT);
//            sT1(i-1,j,DT);
//            sT1(i,j+1,DT);
//            sT1(i,j-1,DT);
//        }
//}

void dune::transfer()
{
    //перераспределение тепла
    //qDebug()<<"transfer()";
    double DT;
    //int i1,j1;
    //qDebug()<<a;
    for (int i=1;i<=nKl;i++)
        for (int j=1;j<=nKl;j++)
            for (int k=1;k<=nKl;k++)
            {
                //DT=k*l*T0[i][j]/C*Dt;
                DT=a*T0[i][j][k];
                T1[i][j][k]-=6*DT;//4-двумерное пространство//6-трехмерное
                T1[i+1][j][k]+=DT;
                T1[i-1][j][k]+=DT;
                T1[i][j+1][k]+=DT;
                T1[i][j-1][k]+=DT;
                T1[i][j][k+1]+=DT;
                T1[i][j][k-1]+=DT;
            }
    //qDebug()<<"transfer() end";
}

void dune::border()
{
    for (int i=0;i<nKl+2;i++)
        for (int j=0;j<nKl;j++)
        {
            T1[0][i][j]=300;
            T1[i][0][j]=300;
            T1[i][j][0]=300;
            T1[nKl+1][i][j]=300;
            T1[i][nKl+1][j]=300;
            T1[i][j][nKl+1]=300;

        }

}


void dune::source()
{
 //       qDebug()<<"source";
    for(int i=1;i<=nKl;i++)
        T1[nKl/2][i][nKl/2]+=273;
}
