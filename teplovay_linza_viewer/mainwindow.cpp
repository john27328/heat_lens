#include "mainwindow.h"
//#include "widget.h"


MWindow::MWindow(QWidget *parent)
    : QWidget(parent)
{
    //qDebug()<<"MainWindow::MainWindow";
    //resize(1000,1000);
    hl  = new QHBoxLayout;
    //cb = new QCheckBox("отладка");

    //hl->addStretch();
    //hl->addWidget(cb);
    //pb = new QPushButton("Старт");
    //pbC = new QPushButton("Стоп"); pbC->setEnabled(0);
    //hl->addWidget(pb);
    //hl->addWidget(pbC);
    vl = new QVBoxLayout;
    w = new Widget(this);
    slX = new QSlider(Qt::Horizontal);
    slX->setRange(1,nKlX);
    slZ = new QSlider(Qt::Horizontal);
    slZ->setRange(1,nKlZ);
    hl->addWidget(slX);
    hl->addWidget(slZ);
    //w->resize(600,600);
    w->setMinimumSize(800,400);
    vl->addWidget(w);
    vl->addLayout(hl);
    setLayout(vl);
    connect(slX,SIGNAL(valueChanged(int)),SLOT(restart()));
    connect(slZ,SIGNAL(valueChanged(int)),SLOT(restart()));

//    connect(pb,SIGNAL(clicked()),this,SLOT(startT()));
//    connect(pbC,SIGNAL(clicked()),this,SLOT(stopT()));
//    connect(w->t,SIGNAL(timeout()),this,SLOT(t()));
    //connect(cb,SIGNAL(stateChanged(int)),this,SLOT(setCb(int)));

    //restart();
    //qDebug()<<"MainWindow::MainWindow end";
}

MWindow::~MWindow()
{

}


//void MainWindow::startT()
//{
//    //qDebug()<<"MainWindow::startT";
//    pb->setEnabled(0);
//    pbC->setEnabled(1);
//    w->startT();
//    //connect(w->t,SIGNAL(timeout()),this,SLOT(t()));
//    //qDebug()<<"MainWindow::startT end";
//}

//void MainWindow::stopT()
//{
//    //qDebug()<<"MainWindow::stopT";
//    pb->setEnabled(1);
//    pbC->setEnabled(0);
//    w->stopT();    w->d.restart(); w->update();
//    //qDebug()<<"MainWindow::stopT end";
//}

void MWindow::restart()
{
    //qDebug()<<"MainWindow::restart";
    w->KlX=slX->value();
    w->KlZ=slZ->value();
    w->update();
    //qDebug()<<"re"<<w->d.N<<w->d.M<<w->d.W;
    //qDebug()<<"MainWindow::restart end";
}

//void MainWindow::t()
//{
//    //qDebug()<<"MainWindow::t";
//    //qDebug()<<"MainWindow::t end";
//}

//void MainWindow::setCb(int kl)
//{
//    //qDebug()<<"setCb";
//    w->k=kl; qDebug()<<kl;
//    w->update();
//    //qDebug()<<"setCb";
//}

