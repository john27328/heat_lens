/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "grafwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLCDNumber *d1;
    QLabel *label_6;
    QLabel *label_5;
    QLCDNumber *w_x_2;
    QLabel *label_4;
    QLCDNumber *R;
    grafWidget *graf;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QSlider *d_Slider;
    QSlider *R_Slider;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *f_label;
    QSlider *f_Slider;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *f_doubleSpinBox;
    QCheckBox *f_minus;
    QCheckBox *f_inf;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QDoubleSpinBox *R1;
    QDoubleSpinBox *d;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *R1_min;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QDoubleSpinBox *R1_max;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QDoubleSpinBox *d_min;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_11;
    QDoubleSpinBox *d_max;
    QCheckBox *R_d;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QDoubleSpinBox *sdvig;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(952, 565);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 401, 441, 91));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        d1 = new QLCDNumber(layoutWidget);
        d1->setObjectName(QStringLiteral("d1"));

        gridLayout_2->addWidget(d1, 2, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setScaledContents(false);
        label_5->setWordWrap(true);

        gridLayout_2->addWidget(label_5, 1, 1, 1, 1);

        w_x_2 = new QLCDNumber(layoutWidget);
        w_x_2->setObjectName(QStringLiteral("w_x_2"));

        gridLayout_2->addWidget(w_x_2, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 0, 1, 1, 1);

        R = new QLCDNumber(layoutWidget);
        R->setObjectName(QStringLiteral("R"));

        gridLayout_2->addWidget(R, 0, 0, 1, 1);

        graf = new grafWidget(centralWidget);
        graf->setObjectName(QStringLiteral("graf"));
        graf->setGeometry(QRect(20, 10, 921, 301));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 490, 931, 66));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        d_Slider = new QSlider(layoutWidget1);
        d_Slider->setObjectName(QStringLiteral("d_Slider"));
        d_Slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(d_Slider, 1, 1, 1, 1);

        R_Slider = new QSlider(layoutWidget1);
        R_Slider->setObjectName(QStringLiteral("R_Slider"));
        R_Slider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(R_Slider, 0, 1, 1, 1);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 310, 921, 91));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        f_label = new QLabel(layoutWidget2);
        f_label->setObjectName(QStringLiteral("f_label"));
        f_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(f_label);

        f_Slider = new QSlider(layoutWidget2);
        f_Slider->setObjectName(QStringLiteral("f_Slider"));
        f_Slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(f_Slider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        f_doubleSpinBox = new QDoubleSpinBox(layoutWidget2);
        f_doubleSpinBox->setObjectName(QStringLiteral("f_doubleSpinBox"));

        horizontalLayout->addWidget(f_doubleSpinBox);

        f_minus = new QCheckBox(layoutWidget2);
        f_minus->setObjectName(QStringLiteral("f_minus"));

        horizontalLayout->addWidget(f_minus);

        f_inf = new QCheckBox(layoutWidget2);
        f_inf->setObjectName(QStringLiteral("f_inf"));

        horizontalLayout->addWidget(f_inf);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        R1 = new QDoubleSpinBox(layoutWidget2);
        R1->setObjectName(QStringLiteral("R1"));
        R1->setMinimum(-99999);
        R1->setMaximum(99999);
        R1->setValue(75.95);

        gridLayout->addWidget(R1, 1, 0, 1, 1);

        d = new QDoubleSpinBox(layoutWidget2);
        d->setObjectName(QStringLiteral("d"));
        d->setMinimum(-99999);
        d->setMaximum(99999);
        d->setValue(21.43);

        gridLayout->addWidget(d, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_7->addLayout(verticalLayout_2);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(100, 410, 401, 71));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        R1_min = new QDoubleSpinBox(layoutWidget3);
        R1_min->setObjectName(QStringLiteral("R1_min"));
        R1_min->setMinimum(0);
        R1_min->setMaximum(99999);
        R1_min->setValue(0);

        horizontalLayout_2->addWidget(R1_min);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        R1_max = new QDoubleSpinBox(layoutWidget3);
        R1_max->setObjectName(QStringLiteral("R1_max"));
        R1_max->setMinimum(-99999);
        R1_max->setMaximum(99999);
        R1_max->setValue(0);

        horizontalLayout_3->addWidget(R1_max);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_4->addWidget(label_10);

        d_min = new QDoubleSpinBox(layoutWidget3);
        d_min->setObjectName(QStringLiteral("d_min"));
        d_min->setMinimum(-99999);
        d_min->setMaximum(99999);

        horizontalLayout_4->addWidget(d_min);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_5->addWidget(label_11);

        d_max = new QDoubleSpinBox(layoutWidget3);
        d_max->setObjectName(QStringLiteral("d_max"));
        d_max->setMinimum(-99999);
        d_max->setMaximum(99999);

        horizontalLayout_5->addWidget(d_max);


        verticalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_4);

        R_d = new QCheckBox(centralWidget);
        R_d->setObjectName(QStringLiteral("R_d"));
        R_d->setEnabled(true);
        R_d->setGeometry(QRect(10, 450, 61, 31));
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 400, 75, 52));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        sdvig = new QDoubleSpinBox(layoutWidget4);
        sdvig->setObjectName(QStringLiteral("sdvig"));
        sdvig->setMinimum(-99.99);

        verticalLayout_5->addWidget(sdvig);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        graf->raise();
        R_d->raise();
#ifndef QT_NO_SHORTCUT
        label_7->setBuddy(R1);
        label_8->setBuddy(d);
        f_label->setBuddy(f_Slider);
        label_3->setBuddy(d);
        label_2->setBuddy(R1);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);
        QObject::connect(f_Slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(f_Slider_to_doubleSpinBox(int)));
        QObject::connect(f_doubleSpinBox, SIGNAL(valueChanged(double)), MainWindow, SLOT(f_doubleSpinBox_to_Slider(double)));
        QObject::connect(f_inf, SIGNAL(clicked(bool)), f_Slider, SLOT(setDisabled(bool)));
        QObject::connect(f_inf, SIGNAL(clicked(bool)), f_minus, SLOT(setDisabled(bool)));
        QObject::connect(f_inf, SIGNAL(clicked(bool)), f_doubleSpinBox, SLOT(setDisabled(bool)));
        QObject::connect(f_doubleSpinBox, SIGNAL(valueChanged(double)), MainWindow, SLOT(f_update()));
        QObject::connect(f_Slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(f_update()));
        QObject::connect(f_minus, SIGNAL(clicked()), MainWindow, SLOT(f_update()));
        QObject::connect(f_inf, SIGNAL(clicked()), MainWindow, SLOT(f_update()));
        QObject::connect(d, SIGNAL(valueChanged(double)), MainWindow, SLOT(f_update()));
        QObject::connect(R1, SIGNAL(valueChanged(double)), MainWindow, SLOT(f_update()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(add_f1()));
        QObject::connect(R_Slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(R_Slider_to_doubleSpinBox(int)));
        QObject::connect(R1, SIGNAL(valueChanged(double)), MainWindow, SLOT(R_doubleSpinBox_to_Slider(double)));
        QObject::connect(d_Slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(d_Slider_to_doubleSpinBox(int)));
        QObject::connect(d, SIGNAL(valueChanged(double)), MainWindow, SLOT(d_doubleSpinBox_to_Slider(double)));
        QObject::connect(R1_min, SIGNAL(valueChanged(double)), MainWindow, SLOT(R_sen_min_max()));
        QObject::connect(R1_max, SIGNAL(valueChanged(double)), MainWindow, SLOT(R_sen_min_max()));
        QObject::connect(d_min, SIGNAL(valueChanged(double)), MainWindow, SLOT(d_sen_min_max()));
        QObject::connect(d_max, SIGNAL(valueChanged(double)), MainWindow, SLOT(d_sen_min_max()));
        QObject::connect(sdvig, SIGNAL(valueChanged(double)), MainWindow, SLOT(f_update()));
        QObject::connect(R_d, SIGNAL(clicked()), MainWindow, SLOT(f_update()));
        QObject::connect(R_d, SIGNAL(clicked(bool)), d_Slider, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_6->setText(QApplication::translate("MainWindow", "d', \321\201\320\274", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\264\320\270\320\260\320\274\320\265\321\202\321\200 \320\277\321\217\321\202\320\275\320\260 \320\262 \320\277\320\265\321\200\320\265\321\200\320\265\321\202\321\217\320\266\320\272\320\265 n\320\277\320\276\321\201\320\273\320\265 \320\273\320\270\320\275\320\267\321\213 ,\320\274\320\274", 0));
        label_4->setText(QApplication::translate("MainWindow", "R' \321\215\320\272\320\262\320\270\320\262\320\260\320\273\320\265\320\275\321\202\320\275\320\276\320\265, \321\201\320\274", 0));
        label_7->setText(QApplication::translate("MainWindow", "R1, \321\201\320\274", 0));
        label_8->setText(QApplication::translate("MainWindow", "d, \321\201\320\274", 0));
        f_label->setText(QApplication::translate("MainWindow", "f, \320\274\320\274", 0));
        f_minus->setText(QApplication::translate("MainWindow", "\320\267\320\275\320\260\320\272 \320\273\320\270\320\275\320\267\321\213 \"-\"", 0));
        f_inf->setText(QApplication::translate("MainWindow", "\320\261\320\265\321\201\320\272\320\276\320\275\320\265\321\207\320\275\320\276\321\201\321\202\321\214", 0));
        label_3->setText(QApplication::translate("MainWindow", "d, \321\201\320\274", 0));
        label_2->setText(QApplication::translate("MainWindow", "R1, \321\201\320\274", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\276\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273 \321\201 \320\273\320\270\320\275\320\267\320\260\320\274\320\270", 0));
        label->setText(QApplication::translate("MainWindow", "R1 min", 0));
        label_9->setText(QApplication::translate("MainWindow", "R1 max", 0));
        label_10->setText(QApplication::translate("MainWindow", "d min", 0));
        label_11->setText(QApplication::translate("MainWindow", "d max", 0));
        R_d->setText(QApplication::translate("MainWindow", "R(d)", 0));
        label_12->setText(QApplication::translate("MainWindow", "\321\201\320\264\320\262\320\270\320\263", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
