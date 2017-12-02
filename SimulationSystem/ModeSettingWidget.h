#ifndef ModeSettingWidget_H
#define INTERFACEWDGET_H

#include <QWidget>
#include "ui_ModeSettingWidget.h"
#include "QDocument.h"  
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QStandardItemModel>
class ModeSettingWidget: public QWidget
{
	Q_OBJECT

public:
	ModeSettingWidget(QWidget *parent = Q_NULLPTR);
	~ModeSettingWidget();
	void init();
	void setshow(QVector<FaultState *>,int);
	//保留上一次的所选项目，不一定是点击确定之后的选项
	QString modelSelect[10] = { "" };  //模式所选项
	QString cabinSelect[10] = { "" };  //舱室所选项
	QString hostSelect[10] = { "" };   //主机所选项
	QString softwareSelect[10] = { "" };  //软件所选项
	QVector<FaultState *> faultStateList;
	int simtotaltime;

private:
	void initmodeltype();     //初始化模型类型
	void initSettingWidget();           //初始化下拉列表框内容
	void setmodelBox();       //设置模式复选框
	void setcabinBox();       //设置舱室复选框
	void sethostBox();        //设置主机复选框
	void setsoftwareBox();    //设置软件复选框
	void showSettingWidget();   //显示故障模式


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


signals:
	void updateMode();

private:
	Ui::ModeSettingWidget ui;
	QDocument *m_DataInstance;  //数据操作类对象

	QVector<QRadioButton *> ModelList;

	int m_Last_Faultmodel = 1;

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
	void closeEvent(QCloseEvent *event);
};

#endif // INTERFACEWDGET_H
