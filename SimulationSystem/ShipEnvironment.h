#pragma once
#ifndef ShipEnvironment_H
#define ShipEnvironment_H

// ��ͧ������
#include <QObject>
#include "QDocument.h"	// �����������ļ�
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <random>

struct ShipEnv {
	float missileX;				// ��������
	float missileY;				// ����γ��
	float missileSpeed;			// �����ٶ�
	float missileD;				// ��������
	bool missileTag;			// �����Ƿ���Ϯ
	float shipX;				// ��ͧ����
	float shipY;				// ��ͧγ��
	float shipSpeed;			// ��ͧ�ٶ�
	float shipD;				// ��ͧ����
	float shipLength;			// ��ͧ����
};

class ShipEnvironment : public QObject
{
	Q_OBJECT

public:
	ShipEnvironment(QObject *parent = Q_NULLPTR);
	~ShipEnvironment();
	void init();			// ��ʼ������������д�뻺����

	void setShipEnv(ShipEnv shipEnv);
	ShipEnv getShipEnv();

	// ������Ϯ
	void missileDetected();

private:
	QDocument *m_DataInstance;	// ���ݲ��������
	struct ShipEnv m_shipEnv;

	void writeData();
	float straightMove(float previous, float k);
};

#endif