#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    //qDebug()<<"MainWindow::MainWindow";
    //resize(1000,1000);
    hl  = new QHBoxLayout;
    //cb = new QCheckBox("отладка");

    hl->addStretch();
    //hl->addWidget(cb);
    pb = new QPushButton("Старт");
    pbC = new QPushButton("Стоп"); pbC->setEnabled(0);
    hl->addWidget(pb);
    hl->addWidget(pbC);
    vl = new QVBoxLayout;
    w = new Widget;

    //w->resize(600,600);
    w->setMinimumSize(400,400);
    vl->addWidget(w);
    vl->addLayout(hl);
    setLayout(vl);
    connect(pb,SIGNAL(clicked()),this,SLOT(startT()));
    connect(pbC,SIGNAL(clicked()),this,SLOT(stopT()));
    connect(&(w->TimerT),SIGNAL(timeout()),this,SLOT(t()));
    //connect(cb,SIGNAL(stateChanged(int)),this,SLOT(setCb(int)));

    restart();
    //qDebug()<<"MainWindow::MainWindow end";
}

MainWindow::~MainWindow()
{

}

void MainWindow::startT()
{
    //qDebug()<<"MainWindow::startT";
    pb->setEnabled(0);
    pbC->setEnabled(1);
    w->startT();
    //connect(w->t,SIGNAL(timeout()),this,SLOT(t()));
    //qDebug()<<"MainWindow::startT end";
}

void MainWindow::stopT()
{
    //qDebug()<<"MainWindow::stopT";
    pb->setEnabled(1);
    pbC->setEnabled(0);
    w->stopT();    w->d.restart(); w->update();
    //qDebug()<<"MainWindow::stopT end";
}

void MainWindow::restart()
{
    //qDebug()<<"MainWindow::restart";
    w->d.restart(); w->update();
    //qDebug()<<"re"<<w->d.N<<w->d.M<<w->d.W;
    //qDebug()<<"MainWindow::restart end";
}

void MainWindow::t()
{
    //qDebug()<<"MainWindow::t";
    //qDebug()<<"MainWindow::t end";
}

void MainWindow::setCb(int kl)
{
    //qDebug()<<"setCb";
    w->k=kl; //qDebug()<<kl;
    w->update();
    //qDebug()<<"setCb";
}

