#pragma once
#ifndef GenerateData_H
#define GenerateData_H

#include <QObject>
#include "QDocument.h"  //引入数据类文件
#include "ShipEnvironment.h" //引入舰艇类
#include <QVector>
#include <QTimer>
#include <QDateTime>


class GenerateData :public QObject
{
	Q_OBJECT

public:
	GenerateData(QObject * parent = Q_NULLPTR);
	~GenerateData();

	int count;//用于计数
	float straightUp(float previous,float maxValue,float k);//直线上升
	float straightDown(float previous, float minValue, float k);//直线下降
	float squareUp(float previous,float maxValue,float x,float k);//二次函数上升
	float jumpFunction(float num);//跃阶函数
	void changeData();//改变生成的数据
	void addDataList();//保存历史数据到list,用于生产图像
	void clearDataList();//清除历史数据list
	void printMsg();//输出测试信息

public slots:
	void simulation();//初始化为正常值

signals:
	void simover();    //执行完成

private:
	QDocument *m_DataInstance;  //数据操作类对象
	QTimer *timer1;//一个1秒一次的定时器
	ShipEnvironment *m_ship; //舰艇
};

#endif