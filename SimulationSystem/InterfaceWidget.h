#ifndef INTERFACEWDGET_H
#define INTERFACEWDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_InterfaceWidget.h"
#include "QDocument.h"  //引入数据类文件
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QStandardItemModel>
class InterfaceWidget : public QMainWindow
{
	Q_OBJECT

public:
	InterfaceWidget(QWidget *parent = 0);
	~InterfaceWidget();
	void init();

private:
	void initMenuBar();          //初始化菜单栏
	void initmodeltype();     //初始化模型类型
	void initSettingWidget();           //初始化下拉列表框内容
	void setmodelBox();       //设置模式复选框
	void setcabinBox();       //设置舱室复选框
	void sethostBox();        //设置主机复选框
	void setsoftwareBox();    //设置软件复选框
	void showSettingWidget();   //显示故障模式
	void updateStateWidget();   //已选状态栏更新

	void addmodel(int);       //添加故障模式
	void removemodel(int);    //移除故障模式


private slots:
    void faultModelSelected();      //模式选择复选框事件
	//box模式设置情况
	void modelChanged();     //改变模式相关选项
	void modeltextChanged(const QString &text);      //模式框内容更新
	void cabinChanged();     //改变舱室相关选项
	void cabintextChanged(const QString &text);      //舱室框内容更新
	void hostChanged();     //改变主机相关选项
	void hosttextChanged(const QString &text);       //主机框内容更新
	void softwareChanged();     //改变软件相关选项
	void softwaretextChanged(const QString &text);   //软件框内容更新
	//界面按钮事件
	void comfrim();   //点击确定按键
	void clear();     //点击清楚按键
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

signals:
	void startsim();    //点击运行按键之间的运行信号

private:
	Ui::InterfaceWidgetClass ui;
	QDocument *m_DataInstance;  //数据操作类对象

	QVector<QRadioButton *> ModelList;

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

	int m_Last_Faultmodel=1;

	QVector<QVector<QString>> modeltype;
	QString faultmodelname[10];

	QListWidget *pModelListWidget;
	QLineEdit *pModelLineEdit;
	QListWidget *pCabinListWidget;
	QLineEdit *pCabinLineEdit;
	QListWidget *pHostListWidget;
	QLineEdit *pHostLineEdit;
	QListWidget *pSoftwareListWidget;
	QLineEdit *pSoftwareLineEdit;

	//保留上一次的所选项目，不一定是点击确定之后的选项
	QString modelSelect[10] = {""};  //模式所选项
	QString cabinSelect[10] = {""};  //舱室所选项
	QString hostSelect[10] = {""};   //主机所选项
	QString softwareSelect[10] = {""};  //软件所选项

	QVector<FaultState *> faultStateList;

	QStandardItemModel *standardItemModel;

};

#endif // INTERFACEWDGET_H
