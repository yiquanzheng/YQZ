#ifndef INTERFACEWDGET_H
#define INTERFACEWDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_InterfaceWidget.h"
#include "ModeSettingWidget.h"
#include "QDocument.h"  //�����������ļ�
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
	void initMenuBar();       //��ʼ���˵���
	void initparBox();        //��ʼ��������ѡ��
	void addmodel(int);       //��ӹ���ģʽ
	void removemodel(int);    //�Ƴ�����ģʽ
	void setAllChartView();
	QList<float> findData(int,QString);   //������ѡ��۲�Ĳ�����λ������ȡȫ������

public slots:
	void updateChartData();   //������ʾ������

private slots:
	//�˵����¼�
	void change_shipxml();   //���Ĵ��������ļ�
	void change_normalvalue();  //��������ֵ�����ļ�
	void change_abnormalvalue();  //�����쳣ֵ�����ļ�
	void exit();         //�˳�
	void run();          //����
	void run_chart();    //������ʾͼ��
	void maxwindows();   //��󻯴���
	void minwindows();   //��С������
	void openhelp();     //�򿪰���
	void contact();     //��ϵ����
	void right_reserve();  //��Ȩ����
	//��ť�¼�
	void openModeSetWidget();
	//�Ӵ����¼�
	void updateStateWidget();   //��ѡ״̬������
	//����ͼ�����¼�
	//����11
	void parBoxChange11();
	void showparlast11(const QString &);
	void setPosWidget11();
	void posBoxChange11();
	void showposlast11(const QString &);
	void drawchart11();
	//����12
	void parBoxChange12();
	void showparlast12(const QString &);
	void setPosWidget12();
	void posBoxChange12();
	void showposlast12(const QString &);
	void drawchart12();
	//����21
	void parBoxChange21();
	void showparlast21(const QString &);
	void setPosWidget21();
	void posBoxChange21();
	void showposlast21(const QString &);
	void drawchart21();
	//����22
	void parBoxChange22();
	void showparlast22(const QString &);
	void setPosWidget22();
	void posBoxChange22();
	void showposlast22(const QString &);
	void drawchart22();

signals:
	void startsim();    //������а���֮��������ź�

private:
	Ui::InterfaceWidgetClass ui;
	QDocument *m_DataInstance;  //���ݲ��������

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
