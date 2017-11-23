#ifndef INTERFACEWDGET_H
#define INTERFACEWDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_InterfaceWidget.h"
#include "QDocument.h"  //�����������ļ�
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
	void initMenuBar();          //��ʼ���˵���
	void initmodeltype();     //��ʼ��ģ������
	void initSettingWidget();           //��ʼ�������б������
	void setmodelBox();       //����ģʽ��ѡ��
	void setcabinBox();       //���ò��Ҹ�ѡ��
	void sethostBox();        //����������ѡ��
	void setsoftwareBox();    //���������ѡ��
	void showSettingWidget();   //��ʾ����ģʽ
	void updateStateWidget();   //��ѡ״̬������

	void addmodel(int);       //��ӹ���ģʽ
	void removemodel(int);    //�Ƴ�����ģʽ


private slots:
    void faultModelSelected();      //ģʽѡ��ѡ���¼�
	//boxģʽ�������
	void modelChanged();     //�ı�ģʽ���ѡ��
	void modeltextChanged(const QString &text);      //ģʽ�����ݸ���
	void cabinChanged();     //�ı�������ѡ��
	void cabintextChanged(const QString &text);      //���ҿ����ݸ���
	void hostChanged();     //�ı��������ѡ��
	void hosttextChanged(const QString &text);       //���������ݸ���
	void softwareChanged();     //�ı�������ѡ��
	void softwaretextChanged(const QString &text);   //��������ݸ���
	//���水ť�¼�
	void comfrim();   //���ȷ������
	void clear();     //����������
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

signals:
	void startsim();    //������а���֮��������ź�

private:
	Ui::InterfaceWidgetClass ui;
	QDocument *m_DataInstance;  //���ݲ��������

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

	//������һ�ε���ѡ��Ŀ����һ���ǵ��ȷ��֮���ѡ��
	QString modelSelect[10] = {""};  //ģʽ��ѡ��
	QString cabinSelect[10] = {""};  //������ѡ��
	QString hostSelect[10] = {""};   //������ѡ��
	QString softwareSelect[10] = {""};  //�����ѡ��

	QVector<FaultState *> faultStateList;

	QStandardItemModel *standardItemModel;

};

#endif // INTERFACEWDGET_H
