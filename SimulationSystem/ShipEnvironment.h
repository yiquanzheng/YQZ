#pragma once
#ifndef ShipEnvironment_H
#define ShipEnvironment_H

// 舰艇环境类
#include <QObject>
#include "QDocument.h"	// 引用数据类文件
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <random>

struct ShipEnv {
	float missileX;				// 导弹经度
	float missileY;				// 导弹纬度
	float missileSpeed;			// 导弹速度
	float missileD;				// 导弹方向
	bool missileTag;			// 导弹是否来袭
	float shipX;				// 舰艇经度
	float shipY;				// 舰艇纬度
	float shipSpeed;			// 舰艇速度
	float shipD;				// 舰艇方向
	float shipLength;			// 舰艇长度
};

class ShipEnvironment : public QObject
{
	Q_OBJECT

public:
	ShipEnvironment(QObject *parent = Q_NULLPTR);
	~ShipEnvironment();
	void init();			// 初始化，并将数据写入缓冲区

	void setShipEnv(ShipEnv shipEnv);
	ShipEnv getShipEnv();

	// 导弹来袭
	void missileDetected();

private:
	QDocument *m_DataInstance;	// 数据操作类对象
	struct ShipEnv m_shipEnv;

	void writeData();
	float straightMove(float previous, float k);
};

#endif