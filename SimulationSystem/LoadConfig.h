#pragma once
// ��:   �����ļ�������
// ��;: ���ڼ��������ļ�����ʼ��ϵͳ������
// ����: ϵͳ��ʼ��ʱ�����init()����ִ��
#ifndef LoadConfig_H
#define LoadConfig_H
#include <QObject>
#include "QDocument.h"  //�����������ļ�
#include "QFile"
#include "QTextCodec"
#include "QDomDocument"
#include <QSettings>
#include <QMessageBox>
class LoadConfig : public QObject
{
	Q_OBJECT

public:
	LoadConfig(QObject * parent = Q_NULLPTR);
	~LoadConfig();
	void init();
	void readShipXML();     //��ȡ���������ļ�
	void readSettingIni();  //��ȡ��׼ֵ�쳣ֵ�����ļ�
	void createBaseData();  //��ʼ������
	void createBasePar();   //��ʼ������

private:
	QDocument *m_DataInstance;  //���ݲ��������
	QVector<QVector<QString>> SoftWareList;    //����б�

};

#endif // LoadConfig_H
