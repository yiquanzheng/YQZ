/********************************************************************************
** Form generated from reading UI file 'InterfaceWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEWIDGET_H
#define UI_INTERFACEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceWidgetClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *drawwidget;
    QGridLayout *gridLayout_2;
    QWidget *chart11;
    QVBoxLayout *verticalLayout_2;
    QWidget *selectwidget11;
    QGridLayout *gridLayout_4;
    QComboBox *parBox11;
    QSpacerItem *horizontalSpacer_14;
    QComboBox *posBox11;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *poslabel11;
    QLabel *parlabel11;
    QSpacerItem *horizontalSpacer;
    QWidget *chart12;
    QVBoxLayout *verticalLayout_3;
    QWidget *selectwidget12;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_20;
    QLabel *parlabel12;
    QComboBox *parBox12;
    QLabel *poslabel12;
    QComboBox *posBox12;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_21;
    QWidget *chart21;
    QVBoxLayout *verticalLayout_4;
    QWidget *selectwidget21;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_16;
    QLabel *poslabel21;
    QComboBox *parBox21;
    QLabel *parlabel21;
    QComboBox *posBox21;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_17;
    QWidget *chart22;
    QVBoxLayout *verticalLayout;
    QWidget *selectwidget22;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_19;
    QComboBox *parBox22;
    QComboBox *posBox22;
    QLabel *parlabel22;
    QLabel *poslabel22;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_22;
    QListView *modelistView;
    QWidget *bottonwidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *modesetbtn;
    QPushButton *startsimbtn;
    QSpacerItem *horizontalSpacer_13;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterfaceWidgetClass)
    {
        if (InterfaceWidgetClass->objectName().isEmpty())
            InterfaceWidgetClass->setObjectName(QStringLiteral("InterfaceWidgetClass"));
        InterfaceWidgetClass->resize(1245, 723);
        centralWidget = new QWidget(InterfaceWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        drawwidget = new QWidget(centralWidget);
        drawwidget->setObjectName(QStringLiteral("drawwidget"));
        sizePolicy.setHeightForWidth(drawwidget->sizePolicy().hasHeightForWidth());
        drawwidget->setSizePolicy(sizePolicy);
        drawwidget->setAutoFillBackground(false);
        drawwidget->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(drawwidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        chart11 = new QWidget(drawwidget);
        chart11->setObjectName(QStringLiteral("chart11"));
        chart11->setStyleSheet(QStringLiteral("background-color: rgb(221, 217, 255);"));
        verticalLayout_2 = new QVBoxLayout(chart11);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 3, -1, -1);
        selectwidget11 = new QWidget(chart11);
        selectwidget11->setObjectName(QStringLiteral("selectwidget11"));
        sizePolicy.setHeightForWidth(selectwidget11->sizePolicy().hasHeightForWidth());
        selectwidget11->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(selectwidget11);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(-1, 3, -1, 3);
        parBox11 = new QComboBox(selectwidget11);
        parBox11->setObjectName(QStringLiteral("parBox11"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(parBox11->sizePolicy().hasHeightForWidth());
        parBox11->setSizePolicy(sizePolicy1);
        parBox11->setMinimumSize(QSize(140, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        parBox11->setFont(font);

        gridLayout_4->addWidget(parBox11, 0, 3, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_14, 0, 0, 1, 1);

        posBox11 = new QComboBox(selectwidget11);
        posBox11->setObjectName(QStringLiteral("posBox11"));
        sizePolicy1.setHeightForWidth(posBox11->sizePolicy().hasHeightForWidth());
        posBox11->setSizePolicy(sizePolicy1);
        posBox11->setMinimumSize(QSize(90, 0));
        posBox11->setFont(font);

        gridLayout_4->addWidget(posBox11, 0, 6, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_15, 0, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 8, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_9, 0, 4, 1, 1);

        poslabel11 = new QLabel(selectwidget11);
        poslabel11->setObjectName(QStringLiteral("poslabel11"));
        sizePolicy.setHeightForWidth(poslabel11->sizePolicy().hasHeightForWidth());
        poslabel11->setSizePolicy(sizePolicy);
        poslabel11->setFont(font);
        poslabel11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(poslabel11, 0, 5, 1, 1);

        parlabel11 = new QLabel(selectwidget11);
        parlabel11->setObjectName(QStringLiteral("parlabel11"));
        sizePolicy.setHeightForWidth(parlabel11->sizePolicy().hasHeightForWidth());
        parlabel11->setSizePolicy(sizePolicy);
        parlabel11->setFont(font);
        parlabel11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(parlabel11, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 1);
        gridLayout_4->setColumnStretch(2, 1);
        gridLayout_4->setColumnStretch(3, 3);
        gridLayout_4->setColumnStretch(4, 1);
        gridLayout_4->setColumnStretch(5, 1);
        gridLayout_4->setColumnStretch(6, 1);
        gridLayout_4->setColumnStretch(7, 1);
        gridLayout_4->setColumnStretch(8, 1);

        verticalLayout_2->addWidget(selectwidget11);

        verticalLayout_2->setStretch(0, 1);

        gridLayout_2->addWidget(chart11, 0, 0, 1, 1);

        chart12 = new QWidget(drawwidget);
        chart12->setObjectName(QStringLiteral("chart12"));
        chart12->setStyleSheet(QStringLiteral("background-color: rgb(254, 255, 190);"));
        verticalLayout_3 = new QVBoxLayout(chart12);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 3, -1, -1);
        selectwidget12 = new QWidget(chart12);
        selectwidget12->setObjectName(QStringLiteral("selectwidget12"));
        sizePolicy.setHeightForWidth(selectwidget12->sizePolicy().hasHeightForWidth());
        selectwidget12->setSizePolicy(sizePolicy);
        selectwidget12->setStyleSheet(QStringLiteral(""));
        gridLayout_5 = new QGridLayout(selectwidget12);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 3, -1, 3);
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_20, 0, 1, 1, 1);

        parlabel12 = new QLabel(selectwidget12);
        parlabel12->setObjectName(QStringLiteral("parlabel12"));
        sizePolicy.setHeightForWidth(parlabel12->sizePolicy().hasHeightForWidth());
        parlabel12->setSizePolicy(sizePolicy);
        parlabel12->setFont(font);
        parlabel12->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(parlabel12, 0, 2, 1, 1);

        parBox12 = new QComboBox(selectwidget12);
        parBox12->setObjectName(QStringLiteral("parBox12"));
        sizePolicy1.setHeightForWidth(parBox12->sizePolicy().hasHeightForWidth());
        parBox12->setSizePolicy(sizePolicy1);
        parBox12->setMinimumSize(QSize(140, 0));
        parBox12->setFont(font);

        gridLayout_5->addWidget(parBox12, 0, 3, 1, 1);

        poslabel12 = new QLabel(selectwidget12);
        poslabel12->setObjectName(QStringLiteral("poslabel12"));
        sizePolicy.setHeightForWidth(poslabel12->sizePolicy().hasHeightForWidth());
        poslabel12->setSizePolicy(sizePolicy);
        poslabel12->setFont(font);
        poslabel12->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(poslabel12, 0, 5, 1, 1);

        posBox12 = new QComboBox(selectwidget12);
        posBox12->setObjectName(QStringLiteral("posBox12"));
        sizePolicy1.setHeightForWidth(posBox12->sizePolicy().hasHeightForWidth());
        posBox12->setSizePolicy(sizePolicy1);
        posBox12->setMinimumSize(QSize(90, 0));
        posBox12->setFont(font);

        gridLayout_5->addWidget(posBox12, 0, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 0, 8, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_10, 0, 4, 1, 1);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_21, 0, 7, 1, 1);

        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 1);
        gridLayout_5->setColumnStretch(2, 1);
        gridLayout_5->setColumnStretch(3, 3);
        gridLayout_5->setColumnStretch(4, 1);
        gridLayout_5->setColumnStretch(5, 1);
        gridLayout_5->setColumnStretch(6, 1);
        gridLayout_5->setColumnStretch(7, 1);
        gridLayout_5->setColumnStretch(8, 1);

        verticalLayout_3->addWidget(selectwidget12);

        verticalLayout_3->setStretch(0, 1);

        gridLayout_2->addWidget(chart12, 0, 1, 1, 1);

        chart21 = new QWidget(drawwidget);
        chart21->setObjectName(QStringLiteral("chart21"));
        chart21->setStyleSheet(QStringLiteral("background-color: rgb(255, 208, 233);"));
        verticalLayout_4 = new QVBoxLayout(chart21);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 3, -1, -1);
        selectwidget21 = new QWidget(chart21);
        selectwidget21->setObjectName(QStringLiteral("selectwidget21"));
        sizePolicy.setHeightForWidth(selectwidget21->sizePolicy().hasHeightForWidth());
        selectwidget21->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(selectwidget21);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 3, -1, 3);
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_16, 0, 1, 1, 1);

        poslabel21 = new QLabel(selectwidget21);
        poslabel21->setObjectName(QStringLiteral("poslabel21"));
        sizePolicy.setHeightForWidth(poslabel21->sizePolicy().hasHeightForWidth());
        poslabel21->setSizePolicy(sizePolicy);
        poslabel21->setFont(font);
        poslabel21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(poslabel21, 0, 5, 1, 1);

        parBox21 = new QComboBox(selectwidget21);
        parBox21->setObjectName(QStringLiteral("parBox21"));
        sizePolicy1.setHeightForWidth(parBox21->sizePolicy().hasHeightForWidth());
        parBox21->setSizePolicy(sizePolicy1);
        parBox21->setMinimumSize(QSize(140, 0));
        parBox21->setFont(font);

        gridLayout_3->addWidget(parBox21, 0, 3, 1, 1);

        parlabel21 = new QLabel(selectwidget21);
        parlabel21->setObjectName(QStringLiteral("parlabel21"));
        sizePolicy.setHeightForWidth(parlabel21->sizePolicy().hasHeightForWidth());
        parlabel21->setSizePolicy(sizePolicy);
        parlabel21->setFont(font);
        parlabel21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(parlabel21, 0, 2, 1, 1);

        posBox21 = new QComboBox(selectwidget21);
        posBox21->setObjectName(QStringLiteral("posBox21"));
        sizePolicy1.setHeightForWidth(posBox21->sizePolicy().hasHeightForWidth());
        posBox21->setSizePolicy(sizePolicy1);
        posBox21->setMinimumSize(QSize(90, 0));
        posBox21->setFont(font);

        gridLayout_3->addWidget(posBox21, 0, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 8, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 0, 4, 1, 1);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_17, 0, 7, 1, 1);

        gridLayout_3->setColumnStretch(0, 1);
        gridLayout_3->setColumnStretch(1, 1);
        gridLayout_3->setColumnStretch(2, 1);
        gridLayout_3->setColumnStretch(3, 3);
        gridLayout_3->setColumnStretch(4, 1);
        gridLayout_3->setColumnStretch(5, 1);
        gridLayout_3->setColumnStretch(6, 1);
        gridLayout_3->setColumnStretch(7, 1);
        gridLayout_3->setColumnStretch(8, 1);

        verticalLayout_4->addWidget(selectwidget21);

        verticalLayout_4->setStretch(0, 1);

        gridLayout_2->addWidget(chart21, 1, 0, 1, 1);

        chart22 = new QWidget(drawwidget);
        chart22->setObjectName(QStringLiteral("chart22"));
        chart22->setStyleSheet(QStringLiteral("background-color: rgb(208, 252, 255);"));
        verticalLayout = new QVBoxLayout(chart22);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 3, -1, -1);
        selectwidget22 = new QWidget(chart22);
        selectwidget22->setObjectName(QStringLiteral("selectwidget22"));
        sizePolicy.setHeightForWidth(selectwidget22->sizePolicy().hasHeightForWidth());
        selectwidget22->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(selectwidget22);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(-1, 3, -1, 3);
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_18, 0, 1, 1, 1);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_19, 0, 7, 1, 1);

        parBox22 = new QComboBox(selectwidget22);
        parBox22->setObjectName(QStringLiteral("parBox22"));
        sizePolicy1.setHeightForWidth(parBox22->sizePolicy().hasHeightForWidth());
        parBox22->setSizePolicy(sizePolicy1);
        parBox22->setMinimumSize(QSize(140, 0));
        parBox22->setFont(font);

        gridLayout_6->addWidget(parBox22, 0, 3, 1, 1);

        posBox22 = new QComboBox(selectwidget22);
        posBox22->setObjectName(QStringLiteral("posBox22"));
        sizePolicy1.setHeightForWidth(posBox22->sizePolicy().hasHeightForWidth());
        posBox22->setSizePolicy(sizePolicy1);
        posBox22->setMinimumSize(QSize(90, 0));
        posBox22->setFont(font);

        gridLayout_6->addWidget(posBox22, 0, 6, 1, 1);

        parlabel22 = new QLabel(selectwidget22);
        parlabel22->setObjectName(QStringLiteral("parlabel22"));
        sizePolicy.setHeightForWidth(parlabel22->sizePolicy().hasHeightForWidth());
        parlabel22->setSizePolicy(sizePolicy);
        parlabel22->setFont(font);
        parlabel22->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(parlabel22, 0, 2, 1, 1);

        poslabel22 = new QLabel(selectwidget22);
        poslabel22->setObjectName(QStringLiteral("poslabel22"));
        sizePolicy.setHeightForWidth(poslabel22->sizePolicy().hasHeightForWidth());
        poslabel22->setSizePolicy(sizePolicy);
        poslabel22->setFont(font);
        poslabel22->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(poslabel22, 0, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 0, 8, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_22, 0, 4, 1, 1);

        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 1);
        gridLayout_6->setColumnStretch(2, 1);
        gridLayout_6->setColumnStretch(3, 3);
        gridLayout_6->setColumnStretch(4, 1);
        gridLayout_6->setColumnStretch(5, 1);
        gridLayout_6->setColumnStretch(6, 1);
        gridLayout_6->setColumnStretch(7, 1);
        gridLayout_6->setColumnStretch(8, 1);

        verticalLayout->addWidget(selectwidget22);

        verticalLayout->setStretch(0, 1);

        gridLayout_2->addWidget(chart22, 1, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 1);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        gridLayout->addWidget(drawwidget, 0, 1, 2, 1);

        modelistView = new QListView(centralWidget);
        modelistView->setObjectName(QStringLiteral("modelistView"));

        gridLayout->addWidget(modelistView, 0, 0, 1, 1);

        bottonwidget = new QWidget(centralWidget);
        bottonwidget->setObjectName(QStringLiteral("bottonwidget"));
        sizePolicy.setHeightForWidth(bottonwidget->sizePolicy().hasHeightForWidth());
        bottonwidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(bottonwidget);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(18, 10, 18, 10);
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        modesetbtn = new QPushButton(bottonwidget);
        modesetbtn->setObjectName(QStringLiteral("modesetbtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(modesetbtn->sizePolicy().hasHeightForWidth());
        modesetbtn->setSizePolicy(sizePolicy2);
        modesetbtn->setFont(font);

        horizontalLayout_2->addWidget(modesetbtn);

        startsimbtn = new QPushButton(bottonwidget);
        startsimbtn->setObjectName(QStringLiteral("startsimbtn"));
        sizePolicy2.setHeightForWidth(startsimbtn->sizePolicy().hasHeightForWidth());
        startsimbtn->setSizePolicy(sizePolicy2);
        startsimbtn->setFont(font);

        horizontalLayout_2->addWidget(startsimbtn);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout->addWidget(bottonwidget, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 12);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 7);
        InterfaceWidgetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterfaceWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1245, 29));
        QFont font1;
        font1.setPointSize(10);
        menuBar->setFont(font1);
        menuBar->setFocusPolicy(Qt::ClickFocus);
        menuBar->setDefaultUp(false);
        InterfaceWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InterfaceWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InterfaceWidgetClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InterfaceWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InterfaceWidgetClass->setStatusBar(statusBar);

        retranslateUi(InterfaceWidgetClass);

        QMetaObject::connectSlotsByName(InterfaceWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *InterfaceWidgetClass)
    {
        InterfaceWidgetClass->setWindowTitle(QApplication::translate("InterfaceWidgetClass", "\347\216\257\345\242\203\345\217\230\345\214\226\344\273\277\347\234\237\347\263\273\347\273\237", Q_NULLPTR));
        poslabel11->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\344\275\215\347\275\256", Q_NULLPTR));
        parlabel11->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\345\217\202\346\225\260", Q_NULLPTR));
        parlabel12->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\345\217\202\346\225\260", Q_NULLPTR));
        poslabel12->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\344\275\215\347\275\256", Q_NULLPTR));
        poslabel21->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\344\275\215\347\275\256", Q_NULLPTR));
        parlabel21->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\345\217\202\346\225\260", Q_NULLPTR));
        parlabel22->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\345\217\202\346\225\260", Q_NULLPTR));
        poslabel22->setText(QApplication::translate("InterfaceWidgetClass", "\350\247\202\345\257\237\344\275\215\347\275\256", Q_NULLPTR));
        modesetbtn->setText(QApplication::translate("InterfaceWidgetClass", "\350\256\276\347\275\256\346\250\241\345\274\217", Q_NULLPTR));
        startsimbtn->setText(QApplication::translate("InterfaceWidgetClass", "\345\274\200\345\247\213\346\250\241\346\213\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InterfaceWidgetClass: public Ui_InterfaceWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEWIDGET_H
