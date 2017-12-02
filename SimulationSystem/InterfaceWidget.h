#ifndef INTERFACEWDGET_H
#define INTERFACEWDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_InterfaceWidget.h"
#include "ModeSettingWidget.h"
#include "QDocument.h"  //引入数据类文件
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QtCharts>
class InterfaceWidget : public QMainWindow
{
	Q_OBJECT

public:
	InterfaceWidget(QWidget *parent = 0);
	~InterfaceWidget();
	void init();

private:
	void initMenuBar();       //初始化菜单栏
	void initparBox();        //初始化参数可选框
	void addmodel(int);       //添加故障模式
	void removemodel(int);    //移除故障模式
	void setAllChartView();
	QList<float> findData(int,QString);   //根据所选择观察的参数及位置来获取全部数据

public slots:
	void updateChartData();   //更新显示的数据

private slots:
	//菜单栏事件
	void change_shipxml();   //更改船的配置文件
	void change_normalvalue();  //更改正常值配置文件
	void change_abnormalvalue();  //更改异常值配置文件
	void exit();         //退出
	void run();          //运行
	void run_chart();    //运行显示图表
	void maxwindows();   //最大化窗体
	void minwindows();   //最小化窗体
	void openhelp();     //打开帮助
	void contact();     //联系我们
	void right_reserve();  //版权所有
	//按钮事件
	void openModeSetWidget();
	//子窗体事件
	void updateStateWidget();   //已选状态栏更新
	//绘制图表窗体事件
	//窗体11
	void parBoxChange11();
	void showparlast11(const QString &);
	void setPosWidget11();
	void posBoxChange11();
	void showposlast11(const QString &);
	void drawchart11();
	//窗体12
	void parBoxChange12();
	void showparlast12(const QString &);
	void setPosWidget12();
	void posBoxChange12();
	void showposlast12(const QString &);
	void drawchart12();
	//窗体21
	void parBoxChange21();
	void showparlast21(const QString &);
	void setPosWidget21();
	void posBoxChange21();
	void showposlast21(const QString &);
	void drawchart21();
	//窗体22
	void parBoxChange22();
	void showparlast22(const QString &);
	void setPosWidget22();
	void posBoxChange22();
	void showposlast22(const QString &);
	void drawchart22();

signals:
	void startsim();    //点击运行按键之间的运行信号

private:
	Ui::InterfaceWidgetClass ui;
	QDocument *m_DataInstance;  //数据操作类对象

	QMenu *m_editMenu;
	QMenu *m_runMenu;
	QMenu *m_windowMenu;
	QMenu *m_helpMenu;

	QAction *m_edit_shipxml;
	QAction *m_edit_normal;
	QAction *m_edit_abnormal;
	QAction *m_edit_exit;
	QAction *m_run; 
	QAction *m_run_chart;
	QAction *m_maxwindow;
	QAction *m_minwindow;
	QAction *m_help_open;
	QAction *m_help_contract;
	QAction *m_help_right;

	QStandardItemModel *standardItemModel;

	QVector<FaultState *> faultStateList;
	int simtotaltime;
	QString parname[15];
	QVector<QString> posname11;
	QVector<QString> posname12;
	QVector<QString> posname21;
	QVector<QString> posname22;
	ModeSettingWidget *m_mswidget;

	QChartView *chartview11;
	QChartView *chartview12;
	QChartView *chartview21;
	QChartView *chartview22;
	QChart *chart11;
	QChart *chart12;
	QChart *chart21;
	QChart *chart22;
	QLineSeries * line11;
	QLineSeries * line12;
	QLineSeries * line21;
	QLineSeries * line22;
	QBarCategoryAxis *axisX11;
	QValueAxis *axisY11;
	QBarCategoryAxis *axisX12;
	QValueAxis *axisY12;
	QBarCategoryAxis *axisX21;
	QValueAxis *axisY21;
	QBarCategoryAxis *axisX22;
	QValueAxis *axisY22;

	QListWidget *pParListWidget11;
	QLineEdit *pParLineEdit11;
	QListWidget *pPosListWidget11;
	QLineEdit *pPosLineEdit11;
	QListWidget *pParListWidget12;
	QLineEdit *pParLineEdit12;
	QListWidget *pPosListWidget12;
	QLineEdit *pPosLineEdit12;
	QListWidget *pParListWidget21;
	QLineEdit *pParLineEdit21;
	QListWidget *pPosListWidget21;
	QLineEdit *pPosLineEdit21;
	QListWidget *pParListWidget22;
	QLineEdit *pParLineEdit22;
	QListWidget *pPosListWidget22;
	QLineEdit *pPosLineEdit22;

	int pParListId11 = 0;
	int pPosListId11 = 0;
	int pParListId12 = 1;
	int pPosListId12 = 0;
	int pParListId21 = 2;
	int pPosListId21 = 0;
	int pParListId22 = 10;
	int pPosListId22 = 0;

	QString pParSelect11 = "";
	QString pPosSelect11 = "";
	QString pParSelect12 = "";
	QString pPosSelect12 = "";
	QString pParSelect21 = "";
	QString pPosSelect21 = "";
	QString pParSelect22 = "";
	QString pPosSelect22 = "";

	int maxshow = 10;

};

#endif // INTERFACEWDGET_H
