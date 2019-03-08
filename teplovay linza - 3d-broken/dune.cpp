#include "dune.h"
#include <qDebug>
#include <time.h>


dune::dune(): QThread()
{
    //qDebug()<<"dune";
    restart();

    Tmin=300;Tmax=5273;
    a=Kt*lm/Ct*dt;//упрощение рассчетов
    //qDebug()<<"dune  end"<<a;
}



void dune::step()
{
    //qDebug()<<"step";
    memcpy(T0, T1, sizeof(T1));

    t+=dt;n++;

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
 /********************************************************
        for (int i=0;i<nKlX+2;i++)
            for (int j=0;j<nKlY+2;j++)
                for (int k=0;k<nKlZ+1;k++)
                if(i>nKlX/3 && i<nKlX*2/3 && j>nKlY/3 && j<nKlY*2/3 && k>nKlZ/3 && k<nKlZ*2/3)
                    T0[i][j][k]=T1[i][j][k]=3273;
                else
                    T0[i][j][k]=T1[i][j][k]=300;
 ***********************************************************/

    for (int i=0;i<nKlX+2;i++)
        for (int j=0;j<nKlY+2;j++)
            for (int k=0;k<nKlZ+2;k++)
                T0[i][j][k]=T1[i][j][k]=TR;

}

void dune::run()
{
    connect(&timer, SIGNAL(timeout()), SLOT(step()));
    timer.start(1);

    exec();
}




void dune::transfer()
{
    //перераспределение тепла
    //qDebug()<<"transfer()";
    double DT;
    //int i1,j1;
    //qDebug()<<a;

    //qDebug()<<"T1[i][j][k]";


    for (int i=1;i<=nKlX;i++)
        for (int j=1;j<=nKlY;j++)
            for (int k=1;k<=nKlZ;k++)
            {

                //if (k==2 && i==20)//qDebug()<<j1<<j2;
                //if (j==j1 && i==1 && k==(nKlZ/2)) //qDebug()<<"T1["<<i<<"]["<<j<<"]["<<k<<"]"<<T1[i][j][k];
                //DT=k*l*T0[i][j]/C*Dt;

                DT=a*T0[i][j][k];
                T1[i][j][k]-=6.*DT;//4-двумерное пространство//6-трехмерное
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

    //qDebug()<<"border()";

    double A=(nKlX+1)/2.;
    //double AA=A*A;
    double B=(nKlX-1)/2.;
    double BB=B*B;
    int j1;
    int j2;
    double EE;
    double E;
    double D;
    for (int i=1;i<=nKlX;i++)
        for (int j=1;j<=nKlY;j++)
            for (int k=1;k<=nKlZ;k++)
            {
                //граница
                E=i-A; EE=E*E; D=sqrt(BB-EE);
                j1=(int)(A+D+.5);
                j2=(int)(A-D+.5);
                if (j>=j1 || j<=j2 || k==1 || k==nKlZ) T1[i][j][k]=TR;
            }


    /***тонкая граница****************************************************************
    double A=(nKlX+1)/2.;
    double AA=A*A;
    double B=(nKlX-1)/2.;
    double BB=B*B;
    int j1;
    int j2;
    double CC;
    double D;
    for (int i=1;i<=nKlX;i++)
        for(int k=1;k<=nKlZ;k++)
        {
            //            j1=nKlX/2.+0.5+sqrt((nKlX-1)*(nKlX-1)/4.-(i-nKlX/2.-.5)*(i-nKlX/2.-.5));
            //            j2=nKlX/2.+0.5-sqrt((nKlX-1)*(nKlX-1)/4.-(i-nKlX/2.-.5)*(i-nKlX/2.-.5));
            C=i-A; CC=C*C; D=sqrt(BB-CC);
            j1=(int)(A+D+.5);
            j2=(int)(A-D+.5);
//            //qDebug()<<"i = "<<i;
//            //qDebug()<<"j1 = "<<j1;
//            //qDebug()<<"j2 = "<<j2;
//            //qDebug()<<"D = "<<D;
            T1[i][j1][k]=3000;
            T1[i][j2][k]=3000;
            T1[j1][i][k]=3000;
            T1[j2][i][k]=3000;
        }
      *******************************************************************************************/

    /***тонкая граница старая************************************************************************
 *
    //qDebug()<<"i<<(int)((AA-(i-BB)*(i-BB)))<<(int)((AA-(i-BB)*(i-BB)));";
    double A=(nKlX+1)/2;
    double AA=(nKlX)*(nKlX)/4;
    double BB=nKlX/2+1./2.;
    double  j1,j2;
    for (int i=1;i<=nKlX;i++)
        for(int k=1;k<=nKlZ;k++)
        {
//            j1=nKlX/2.+0.5+sqrt((nKlX-1)*(nKlX-1)/4.-(i-nKlX/2.-.5)*(i-nKlX/2.-.5));
//            j2=nKlX/2.+0.5-sqrt((nKlX-1)*(nKlX-1)/4.-(i-nKlX/2.-.5)*(i-nKlX/2.-.5));
            j1=nKlX/2.+0.5+sqrt((nKlX-1)*(nKlX-1)/4.-(i-nKlX/2.-.5)*(i-nKlX/2.-.5));
            j2=nKlX/2.+0.5-sqrt((nKlX-1)*(nKlX-1)/4.-(i-nKlX/2.-.5)*(i-nKlX/2.-.5));
            T1[i][(int)(j1+.5)][k]=3000;
            T1[i][(int)(j2+.5)][k]=3000;
            T1[(int)(j1+.5)][i][k]=3000;
            T1[(int)(j2+.5)][i][k]=3000;
        }
****************************************************************************/



    /**коробка*************************************************************************
 *
    for (int i=0;i<nKlX+2;i++)
        for (int j=0;j<nKlY+2;j++)
        {
            //T1[0][i][j]=300;
            //T1[i][0][j]=300;
            T1[i][j][0]=3000;
            //T1[nKl+1][i][j]=300;
            //T1[i][nKl+1][j]=300;
            T1[i][j][nKlZ+1]=3000;
        }
    for (int i=0;i<nKlX+2;i++)
        for (int j=0;j<nKlZ+2;j++)
        {
            //T1[0][i][j]=300;
            T1[i][0][j]=3000;
            //T1[i][j][0]=300;
            //T1[nKl+1][i][j]=300;
            T1[i][nKlY+1][j]=3000;
            //T1[i][j][nKl+1]=300;
        }
    for (int i=0;i<nKlY+2;i++)
        for (int j=0;j<nKlZ+2;j++)
        {
            T1[0][i][j]=3000;
            //T1[i][0][j]=300;
            //T1[i][j][0]=300;
            T1[nKlX+1][i][j]=3000;
            //T1[i][nKl+1][j]=300;
            //T1[i][j][nKl+1]=300;
        }
*****************************************************************/
//qDebug()<<"border()end";

}




void dune::source()
{
    //qDebug()<<"source";
        for(int i=0;i<=nKlY+1;i++)
            T1[nKlX/2+1][i][(int)nKlZ/2+1]+=100;
}
