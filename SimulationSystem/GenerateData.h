#pragma once
#ifndef GenerateData_H
#define GenerateData_H

#include <QObject>
#include "QDocument.h"  //�����������ļ�
#include "ShipEnvironment.h" //���뽢ͧ��
#include <QVector>
#include <QTimer>
#include <QDateTime>


class GenerateData :public QObject
{
	Q_OBJECT

public:
	GenerateData(QObject * parent = Q_NULLPTR);
	~GenerateData();

	int count;//���ڼ���
	float straightUp(float previous,float maxValue,float k);//ֱ������
	float straightDown(float previous, float minValue, float k);//ֱ���½�
	float squareUp(float previous,float maxValue,float x,float k);//���κ�������
	float jumpFunction(float num);//Ծ�׺���
	void changeData();//�ı����ɵ�����
	void addDataList();//������ʷ���ݵ�list,��������ͼ��
	void clearDataList();//�����ʷ����list
	void printMsg();//���������Ϣ

public slots:
	void simulation();//��ʼ��Ϊ����ֵ

signals:
	void simover();    //ִ�����

private:
	QDocument *m_DataInstance;  //���ݲ��������
	QTimer *timer1;//һ��1��һ�εĶ�ʱ��
	ShipEnvironment *m_ship; //��ͧ
};

#endif