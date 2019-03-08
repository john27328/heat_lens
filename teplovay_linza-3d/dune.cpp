#include "dune.h"
#include <QDebug>
#include <time.h>
//#include <omp.h>


dune::dune(): QThread()
{
    //omp_set_dynamic(0);      // запретить библиотеке openmp менять число потоков во время исполнения
    //omp_set_num_threads(4); // установить число потоков в 10

    //qDebug()<<"dune";
    restart();
    //qDebug()<<"dune  end";

    T_min=300;T_max=350; t=0;n=0;nn=0;nnn=0;

    a=K_t*lt/C_t*D_t/mKl;//упрощение рассчетов
    qDebug()<<"mKl"<<mKl<<"lt"<<lt<<"nKlZ"<<nKlZ<<"a"<<a<<"Tkl"<<Tkl;
    qDebug()<<"m = "<<mKl*nKlX*nKlY*nKlZ*1000<<"гр";
    qDebug()<<"m = "<<2*2*0.4*rho<<"гр";
    //QFileDialog *FD=new QFileDialog;
    //str =FD->getSaveFileName(0,"сохранение файла","./saveFile","*.bin");//qDebug()<<str;

//    QFile file("file.txt");
//    QString str = "This is a test";
//    if (file.open(QIODevice::WriteOnly)) {
//        QTextStream stream(&file);
//        stream << str.toUpper(); // Запишет THIS IS A TEST
//        file.close();
//        if (stream.status() != QTextStream::Ok) {
//            qDebug() << "Ошибка записи файла";
//        }
//    }
}



void dune::step()
{
    //qDebug()<<"step";
    memcpy(T0, T1, sizeof(T1));

    t+=D_t;nn++;

    transfer();
    border();
    source();
    if (nn*0>99)
    {
        nn=0;
        file = new QFile(str + " " + QString::number(nnn)+" t="+QString::number(t)+".bin");
        if(file->open(QIODevice::WriteOnly))
        {
            //QTextStream strm(file);
            QDataStream strm(file);
            //strm.setRealNumberPrecision(8);
            strm<<R_m<<L_m<<nKlX<<nKlY<<nKlZ<<lt<<TR<<C_t<<D_t<<K_t<<rho<<mKl<<Tkr<<Tkl<<P0;
            for(int i=1;i<=nKlX;i++)
                for(int j=1;j<=nKlY;j++)
                    for(int k=1;k<=nKlZ;k++)
                        strm<<T1[i][j][k];
        }

            file->close();
        nnn++;
        delete file;
    }


n++;

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
                    T0[i][j][k]=T1[i][j][k]=100000;
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

void dune::border(int i0, int j0, int k0, int i, int j, int k, double dT)
{
    double A=(nKlX+1)/2.;
    //double AA=A*A;
    double B=(nKlX)/2.;
    double BB=B*B;
    double EE;
    double E;
    double D;
    double DD;
    double EE0;
    double E0;
    double D0;
    double DD0;
    E=i-A; EE=E*E; D=j-A; DD=D*D;
    E0=i0-A; EE0=E0*E0; D0=j0-A; DD0=D0*D0;
    if (EE0+DD0-BB<=0 && k0>=1 && k0<=nKlZ)
    {
        if (EE+DD-BB<=0 && k>=1 && k<=nKlZ)
        {
            T1[i0][j0][k0]-=dT;
            T1[i][j][k]+=dT;
        }
        else
        {
            // если теплоизоляция, то пусто
            T1[i0][j0][k0]-=dT; //если термостат
        }
    }
    else
    {
        if (EE+DD-BB<=0 && k>=1 && k<=nKlZ)
        {
            T1[i][j][k]+=dT;
        }
        else
        {
            // если теплоизоляция, то пусто
            //T1[i0][j0][k0]-=dT; //если термостат
        }
    }
}





//универсальный, но медленный метод((
//void dune::transfer()
//{
//    //перераспределение тепла
//    //qDebug()<<"transfer()";
//    double DT;

//    for (int i=0;i<=nKlX+1;i++)
//        for (int j=0;j<=nKlY+1;j++)
//        {
//            for (int k=0;k<=nKlZ+1;k++)
//            {
//                DT=a*T0[i][j][k];
//                border(i,j,k,i+1,j,k,DT);
//                border(i,j,k,i-1,j,k,DT);
//                border(i,j,k,i,j+1,k,DT);
//                border(i,j,k,i,j-1,k,DT);
//                border(i,j,k,i,j,k+1,DT);
//                border(i,j,k,i,j,k-1,DT);
//            }
//        }
//}


void dune::transfer()
{
    //перераспределение тепла
    //qDebug()<<"transfer()";
    double DT;
    //#pragma omp parallel for shared(T0,T1) private(i,j,k)
    for (int i=1;i<=nKlX;i++)
        for (int j=1;j<=nKlY;j++)
        {
            for (int k=1;k<=nKlZ;k++)
            {
                DT=a*T0[i][j][k];
                T1[i][j][k]-=6.*DT;//4-двумерное пространство//6-трехмерное
                T1[i+1][j][k]+=DT;
                T1[i-1][j][k]+=DT;
                T1[i][j+1][k]+=DT;
                T1[i][j-1][k]+=DT;
                T1[i][j][k+1]+=DT;
                T1[i][j][k-1]+=DT;
            }
        }
}

void dune::source()
{
    //qDebug()<<"source";
    double P=P0;
    for (int i=1;i<=nKlX;i++)
        for (int j=1;j<=nKlY;j++)
        {
            for (int k=1;k<=nKlZ;k++){
                    T1[i][j][k]+=P/nKlX/nKlY/nKlZ*D_t/C_t/mKl;
                }
            //P=P*Tkl;
        }
        //qDebug()<<P;
}

//void dune::transfer()
//{
//    //перераспределение тепла
//    //qDebug()<<"transfer()";
//    double DT;
//    //int i1,j1;
//    //qDebug()<<a;

//    //qDebug()<<"T1[i][j][k]";
//    double A=(nKlX+1)/2.;
//    //double AA=A*A;
//    double B=(nKlX)/2.;
//    double BB=B*B;
//    double EE;
//    double E;
//    double D;
//    double DD;
//    double F=(nKlX-2)/2.;
//    double FF=F*F;
//    for (int i=1;i<=nKlX;i++)
//        for (int j=1;j<=nKlY;j++)
//        {
//            E=i-A; EE=E*E; D=j-A; DD=D*D;
//            if (EE+DD-BB<=0)
//            {//qDebug()<<i<<j;
//                if (EE+DD-FF<=0)
//                {

//                    for (int k=2;k<nKlZ;k++)
//                    {
//                        DT=a*T0[i][j][k];
//                        T1[i][j][k]-=6.*DT;//4-двумерное пространство//6-трехмерное
//                        T1[i+1][j][k]+=DT;
//                        T1[i-1][j][k]+=DT;
//                        T1[i][j+1][k]+=DT;
//                        T1[i][j-1][k]+=DT;
//                        T1[i][j][k+1]+=DT;
//                        T1[i][j][k-1]+=DT;
//                    }
//                }
//                else
//                {
//                    //тут определяю граничные условия

//                    for (int k=2;k<nKlZ;k++)
//                    {
//                        DT=a*T0[i][j][k];
//                        border(i,j,k,i+1,j,k,DT);
//                        border(i,j,k,i-1,j,k,DT);
//                        border(i,j,k,i,j+1,k,DT);
//                        border(i,j,k,i,j-1,k,DT);
//                        border(i,j,k,i,j,k+1,DT);
//                        border(i,j,k,i,j,k-1,DT);
//                    }

//                }
//            }
//        }
//}

void dune::border()
{

    //qDebug()<<"i<<(int)((AA-(i-BB)*(i-BB)))<<(int)((AA-(i-BB)*(i-BB)));";

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
//            qDebug()<<"i = "<<i;
//            qDebug()<<"j1 = "<<j1;
//            qDebug()<<"j2 = "<<j2;
//            qDebug()<<"D = "<<D;
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
}
