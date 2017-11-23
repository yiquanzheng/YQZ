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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceWidgetClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_10;
    QWidget *settingwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *errorsettingwidget;
    QGridLayout *gridLayout;
    QComboBox *hostBox;
    QComboBox *softwareBox;
    QComboBox *cabinBox;
    QLabel *errorhostlabel;
    QLabel *errorsoftwarelabel;
    QComboBox *modelBox;
    QLabel *errorcabinlabel;
    QLabel *errormodellabel;
    QWidget *timesettingwidget;
    QGridLayout *gridLayout_2;
    QLabel *simtimelabel;
    QSpinBox *totalTime;
    QLabel *errortimelabel;
    QSpinBox *errorBeginTime;
    QWidget *comfrimwidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *comfrim;
    QPushButton *clear;
    QListView *listView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterfaceWidgetClass)
    {
        if (InterfaceWidgetClass->objectName().isEmpty())
            InterfaceWidgetClass->setObjectName(QStringLiteral("InterfaceWidgetClass"));
        InterfaceWidgetClass->resize(815, 467);
        centralWidget = new QWidget(InterfaceWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 7, -1, 5);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, 5);
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        sizePolicy.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy);
        radioButton->setFocusPolicy(Qt::ClickFocus);
        radioButton->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        sizePolicy.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy);
        radioButton_2->setFocusPolicy(Qt::ClickFocus);
        radioButton_2->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        sizePolicy.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy);
        radioButton_3->setFocusPolicy(Qt::ClickFocus);
        radioButton_3->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        sizePolicy.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy);
        radioButton_4->setFocusPolicy(Qt::ClickFocus);
        radioButton_4->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        sizePolicy.setHeightForWidth(radioButton_5->sizePolicy().hasHeightForWidth());
        radioButton_5->setSizePolicy(sizePolicy);
        radioButton_5->setFocusPolicy(Qt::ClickFocus);
        radioButton_5->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_5);

        radioButton_6 = new QRadioButton(groupBox);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        sizePolicy.setHeightForWidth(radioButton_6->sizePolicy().hasHeightForWidth());
        radioButton_6->setSizePolicy(sizePolicy);
        radioButton_6->setFocusPolicy(Qt::ClickFocus);
        radioButton_6->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_6);

        radioButton_7 = new QRadioButton(groupBox);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));
        sizePolicy.setHeightForWidth(radioButton_7->sizePolicy().hasHeightForWidth());
        radioButton_7->setSizePolicy(sizePolicy);
        radioButton_7->setFocusPolicy(Qt::ClickFocus);
        radioButton_7->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_7);

        radioButton_8 = new QRadioButton(groupBox);
        radioButton_8->setObjectName(QStringLiteral("radioButton_8"));
        sizePolicy.setHeightForWidth(radioButton_8->sizePolicy().hasHeightForWidth());
        radioButton_8->setSizePolicy(sizePolicy);
        radioButton_8->setFocusPolicy(Qt::ClickFocus);
        radioButton_8->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_8);

        radioButton_9 = new QRadioButton(groupBox);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        sizePolicy.setHeightForWidth(radioButton_9->sizePolicy().hasHeightForWidth());
        radioButton_9->setSizePolicy(sizePolicy);
        radioButton_9->setFocusPolicy(Qt::ClickFocus);
        radioButton_9->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_9);

        radioButton_10 = new QRadioButton(groupBox);
        radioButton_10->setObjectName(QStringLiteral("radioButton_10"));
        sizePolicy.setHeightForWidth(radioButton_10->sizePolicy().hasHeightForWidth());
        radioButton_10->setSizePolicy(sizePolicy);
        radioButton_10->setFocusPolicy(Qt::ClickFocus);
        radioButton_10->setContextMenuPolicy(Qt::ActionsContextMenu);

        verticalLayout->addWidget(radioButton_10);


        horizontalLayout_2->addWidget(groupBox);

        settingwidget = new QWidget(centralWidget);
        settingwidget->setObjectName(QStringLiteral("settingwidget"));
        sizePolicy.setHeightForWidth(settingwidget->sizePolicy().hasHeightForWidth());
        settingwidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(settingwidget);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        errorsettingwidget = new QWidget(settingwidget);
        errorsettingwidget->setObjectName(QStringLiteral("errorsettingwidget"));
        sizePolicy.setHeightForWidth(errorsettingwidget->sizePolicy().hasHeightForWidth());
        errorsettingwidget->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        errorsettingwidget->setFont(font1);
        gridLayout = new QGridLayout(errorsettingwidget);
        gridLayout->setSpacing(15);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        hostBox = new QComboBox(errorsettingwidget);
        hostBox->setObjectName(QStringLiteral("hostBox"));
        sizePolicy.setHeightForWidth(hostBox->sizePolicy().hasHeightForWidth());
        hostBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(hostBox, 5, 1, 1, 2);

        softwareBox = new QComboBox(errorsettingwidget);
        softwareBox->setObjectName(QStringLiteral("softwareBox"));
        sizePolicy.setHeightForWidth(softwareBox->sizePolicy().hasHeightForWidth());
        softwareBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(softwareBox, 6, 1, 1, 2);

        cabinBox = new QComboBox(errorsettingwidget);
        cabinBox->setObjectName(QStringLiteral("cabinBox"));
        sizePolicy.setHeightForWidth(cabinBox->sizePolicy().hasHeightForWidth());
        cabinBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(cabinBox, 3, 1, 1, 2);

        errorhostlabel = new QLabel(errorsettingwidget);
        errorhostlabel->setObjectName(QStringLiteral("errorhostlabel"));
        sizePolicy.setHeightForWidth(errorhostlabel->sizePolicy().hasHeightForWidth());
        errorhostlabel->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(9);
        errorhostlabel->setFont(font2);

        gridLayout->addWidget(errorhostlabel, 5, 0, 1, 1);

        errorsoftwarelabel = new QLabel(errorsettingwidget);
        errorsoftwarelabel->setObjectName(QStringLiteral("errorsoftwarelabel"));
        sizePolicy.setHeightForWidth(errorsoftwarelabel->sizePolicy().hasHeightForWidth());
        errorsoftwarelabel->setSizePolicy(sizePolicy);
        errorsoftwarelabel->setFont(font2);

        gridLayout->addWidget(errorsoftwarelabel, 6, 0, 1, 1);

        modelBox = new QComboBox(errorsettingwidget);
        modelBox->setObjectName(QStringLiteral("modelBox"));
        sizePolicy.setHeightForWidth(modelBox->sizePolicy().hasHeightForWidth());
        modelBox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(modelBox, 1, 1, 1, 2);

        errorcabinlabel = new QLabel(errorsettingwidget);
        errorcabinlabel->setObjectName(QStringLiteral("errorcabinlabel"));
        sizePolicy.setHeightForWidth(errorcabinlabel->sizePolicy().hasHeightForWidth());
        errorcabinlabel->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        errorcabinlabel->setFont(font3);

        gridLayout->addWidget(errorcabinlabel, 3, 0, 1, 1);

        errormodellabel = new QLabel(errorsettingwidget);
        errormodellabel->setObjectName(QStringLiteral("errormodellabel"));
        sizePolicy.setHeightForWidth(errormodellabel->sizePolicy().hasHeightForWidth());
        errormodellabel->setSizePolicy(sizePolicy);
        errormodellabel->setFont(font3);

        gridLayout->addWidget(errormodellabel, 1, 0, 1, 1);


        verticalLayout_2->addWidget(errorsettingwidget);

        timesettingwidget = new QWidget(settingwidget);
        timesettingwidget->setObjectName(QStringLiteral("timesettingwidget"));
        sizePolicy.setHeightForWidth(timesettingwidget->sizePolicy().hasHeightForWidth());
        timesettingwidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(timesettingwidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(7);
        gridLayout_2->setVerticalSpacing(15);
        gridLayout_2->setContentsMargins(15, 5, 15, 5);
        simtimelabel = new QLabel(timesettingwidget);
        simtimelabel->setObjectName(QStringLiteral("simtimelabel"));
        sizePolicy.setHeightForWidth(simtimelabel->sizePolicy().hasHeightForWidth());
        simtimelabel->setSizePolicy(sizePolicy);
        simtimelabel->setFont(font3);

        gridLayout_2->addWidget(simtimelabel, 0, 0, 1, 1);

        totalTime = new QSpinBox(timesettingwidget);
        totalTime->setObjectName(QStringLiteral("totalTime"));
        sizePolicy.setHeightForWidth(totalTime->sizePolicy().hasHeightForWidth());
        totalTime->setSizePolicy(sizePolicy);
        totalTime->setMinimum(1);
        totalTime->setValue(30);

        gridLayout_2->addWidget(totalTime, 0, 1, 1, 1);

        errortimelabel = new QLabel(timesettingwidget);
        errortimelabel->setObjectName(QStringLiteral("errortimelabel"));
        sizePolicy.setHeightForWidth(errortimelabel->sizePolicy().hasHeightForWidth());
        errortimelabel->setSizePolicy(sizePolicy);
        errortimelabel->setFont(font3);

        gridLayout_2->addWidget(errortimelabel, 1, 0, 1, 1);

        errorBeginTime = new QSpinBox(timesettingwidget);
        errorBeginTime->setObjectName(QStringLiteral("errorBeginTime"));
        sizePolicy.setHeightForWidth(errorBeginTime->sizePolicy().hasHeightForWidth());
        errorBeginTime->setSizePolicy(sizePolicy);
        errorBeginTime->setValue(10);

        gridLayout_2->addWidget(errorBeginTime, 1, 1, 1, 1);


        verticalLayout_2->addWidget(timesettingwidget);

        comfrimwidget = new QWidget(settingwidget);
        comfrimwidget->setObjectName(QStringLiteral("comfrimwidget"));
        sizePolicy.setHeightForWidth(comfrimwidget->sizePolicy().hasHeightForWidth());
        comfrimwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(comfrimwidget);
        horizontalLayout->setSpacing(15);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(30, 2, 30, 2);
        comfrim = new QPushButton(comfrimwidget);
        comfrim->setObjectName(QStringLiteral("comfrim"));
        sizePolicy.setHeightForWidth(comfrim->sizePolicy().hasHeightForWidth());
        comfrim->setSizePolicy(sizePolicy);
        comfrim->setFont(font1);

        horizontalLayout->addWidget(comfrim);

        clear = new QPushButton(comfrimwidget);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy);
        clear->setFont(font1);

        horizontalLayout->addWidget(clear);


        verticalLayout_2->addWidget(comfrimwidget);


        horizontalLayout_2->addWidget(settingwidget);

        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));

        horizontalLayout_2->addWidget(listView);

        InterfaceWidgetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterfaceWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 815, 29));
        QFont font4;
        font4.setPointSize(10);
        menuBar->setFont(font4);
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
        groupBox->setTitle(QApplication::translate("InterfaceWidgetClass", "\344\273\277\347\234\237\346\250\241\345\274\217", Q_NULLPTR));
        radioButton->setText(QApplication::translate("InterfaceWidgetClass", "\350\210\261\345\256\244\346\270\251\345\272\246\345\215\207\351\253\230", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("InterfaceWidgetClass", "\350\210\261\345\256\244\346\271\277\345\272\246\345\215\207\351\253\230", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("InterfaceWidgetClass", "\344\270\273\346\234\272\350\277\220\350\241\214\345\244\261\346\225\210", Q_NULLPTR));
        radioButton_4->setText(QApplication::translate("InterfaceWidgetClass", "\350\275\257\344\273\266\350\277\220\350\241\214\345\244\261\346\225\210", Q_NULLPTR));
        radioButton_5->setText(QApplication::translate("InterfaceWidgetClass", "\345\257\274\345\274\271\346\235\245\350\242\255", Q_NULLPTR));
        radioButton_6->setText(QApplication::translate("InterfaceWidgetClass", "\344\270\273\346\234\272CPU\346\270\251\345\272\246\345\215\207\351\253\230", Q_NULLPTR));
        radioButton_7->setText(QApplication::translate("InterfaceWidgetClass", "\344\270\273\346\234\272\347\241\254\347\233\230\346\270\251\345\272\246\345\215\207\351\253\230", Q_NULLPTR));
        radioButton_8->setText(QApplication::translate("InterfaceWidgetClass", "\344\270\273\346\234\272\344\270\273\346\235\277\346\270\251\345\272\246\345\215\207\351\253\230", Q_NULLPTR));
        radioButton_9->setText(QApplication::translate("InterfaceWidgetClass", "\344\270\273\346\234\272\345\217\257\347\224\250\350\265\204\346\272\220\345\207\217\345\260\221", Q_NULLPTR));
        radioButton_10->setText(QApplication::translate("InterfaceWidgetClass", "\344\273\273\345\212\241\344\274\230\345\205\210\347\272\247\345\217\230\346\233\264", Q_NULLPTR));
        errorhostlabel->setText(QApplication::translate("InterfaceWidgetClass", "\351\200\211\346\213\251\346\225\205\351\232\234\344\270\273\346\234\272", Q_NULLPTR));
        errorsoftwarelabel->setText(QApplication::translate("InterfaceWidgetClass", "\351\200\211\346\213\251\346\225\205\351\232\234\350\275\257\344\273\266", Q_NULLPTR));
        errorcabinlabel->setText(QApplication::translate("InterfaceWidgetClass", "\351\200\211\346\213\251\346\225\205\351\232\234\350\210\261\345\256\244", Q_NULLPTR));
        errormodellabel->setText(QApplication::translate("InterfaceWidgetClass", "\351\200\211\346\213\251\346\225\205\351\232\234\347\261\273\345\236\213", Q_NULLPTR));
        simtimelabel->setText(QApplication::translate("InterfaceWidgetClass", "\346\250\241\346\213\237\350\256\276\345\256\232\346\227\266\351\227\264", Q_NULLPTR));
        errortimelabel->setText(QApplication::translate("InterfaceWidgetClass", "\346\225\205\351\232\234\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        comfrim->setText(QApplication::translate("InterfaceWidgetClass", "\347\241\256\345\256\232", Q_NULLPTR));
        clear->setText(QApplication::translate("InterfaceWidgetClass", "\346\270\205\351\231\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InterfaceWidgetClass: public Ui_InterfaceWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEWIDGET_H
