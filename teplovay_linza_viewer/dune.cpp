#include "dune.h"
#include <QDebug>
#include <time.h>


dune::dune()//: QThread()
{
    //qDebug()<<"dune";
    load();
    //qDebug()<<"dune  end";

    T_min=300;T_max=350; t=0;//n=0;nn=0;nnn=0;

}

void dune::load()
{
    QFileDialog *FD=new QFileDialog;
    str =FD->getOpenFileName(0,"загрузка файла","./saveFile","*.bin");//qDebug()<<str;
    {
        file = new QFile(str);
        //Parametri p;

        //QList<ellement *> ellList=*ellListPtr;
        if(file->open(QFile::ReadOnly))
        {

            QDataStream strm(file);
            //strm.setRealNumberPrecision(8);
            strm >> R_mf >> L_mf >> nKlXf >> nKlYf >> nKlZf >> ltf >> TRf >> C_tf >> D_tf >> K_tf >> rhof >> mKlf >> Tkrf >> Tklf >> P0f;
            for(int i=1;i<=nKlX;i++)
                for(int j=1;j<=nKlY;j++)
                    for(int k=1;k<=nKlZ;k++)
                        strm>>T1[i][j][k];

            file->close(); delete file;
        }
    }
//    qDebug()<<R_mf<<L_mf<<nKlXf<<nKlYf<<nKlZf<<ltf<<TRf<<C_tf<<D_tf<<K_tf<<rhof<<mKlf<<Tkrf<<Tklf<<P0f;
//    str =FD->getOpenFileName(0,"загрузка файла","./saveFile","*.bin");//qDebug()<<str;
//    {
//        file = new QFile(str);
//        //Parametri p;

//        //QList<ellement *> ellList=*ellListPtr;
//        if(file->open(QFile::ReadOnly))
//        {

//            QDataStream strm(file);
//            //strm.setRealNumberPrecision(8);
//            strm >> R_mf >> L_mf >> nKlXf >> nKlYf >> nKlZf >> ltf >> TRf >> C_tf >> D_tf >> K_tf >> rhof >> mKlf >> Tkrf >> Tklf >> P0f;
//            for(int i=1;i<=nKlX;i++)
//                for(int j=1;j<=nKlY;j++)
//                    for(int k=1;k<=nKlZ;k++)
//                        strm>>T0[i][j][k];

//            file->close(); delete file;
//        }
//    }
//    str =FD->getSaveFileName(0,"сохранение файла","./saveFile","*.bin");//qDebug()<<str;
//    file = new QFile(str + ".csv");
//    if(file->open(QIODevice::WriteOnly))
//    {
//        QTextStream strm(file);
//        //QDataStream strm(file);
//        //strm.setRealNumberPrecision(8);
//        //strm << R_mf << L_mf << nKlXf << nKlYf << nKlZf << ltf << TRf << C_tf << D_tf << K_tf << rhof << mKlf << Tkrf << Tklf << P0f;
//        for(int i=1;i<=nKlX;i++)
//        {
//            for(int j=1;j<=nKlZ;j++)
//                strm<<T1[i][nKlY/2][j]<<"\t";
//            strm<<"\n";
//        }
//    }

//    file->close();
//    nnn++;
    //    delete file;
}

double dune::n(int i, int j, int k)
{
    return dn_dT*T1[i][j][k];
}




//void dune::step()
//{
//    //qDebug()<<"step";
//    memcpy(T0, T1, sizeof(T1));

//    t+=D_t;nn++;

//    transfer();
//    border();
//    source();
//    if (nn>999)
//    {
//        nn=0;
//        file = new QFile(str + " " + QString::number(nnn)+" t="+QString::number(t)+".bin");
//        if(file->open(QIODevice::WriteOnly))
//        {
//            //QTextStream strm(file);
//            QDataStream strm(file);
//            //strm.setRealNumberPrecision(8);
//            strm<<R_m<<L_m<<nKlX<<nKlY<<nKlZ<<lt<<TR<<C_t<<D_t<<K_t<<rho<<mKl<<Tkr<<Tkl<<P0;
//            for(int i=1;i<=nKlX;i++)
//                for(int j=1;j<nKlY;j++)
//                    for(int k=1;k<=nKlZ;k++)
//                        strm<<T1[i][j][k];
//        }

//            file->close();
//        nnn++;
//        delete file;
//    }


//n++;

//    //qDebug()<<"step end ";
//}

