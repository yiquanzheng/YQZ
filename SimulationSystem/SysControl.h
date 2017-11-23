#pragma once
#ifndef SYSCONTROL_H
#define SYSCONTROL_H

#include "LoadConfig.h"
#include "InterfaceWidget.h"
#include "GenerateData.h"
class SysControl :public QObject
{
	Q_OBJECT
public:
	SysControl(QObject * parent = Q_NULLPTR);
	~SysControl();
	void InitSys();

public:
	LoadConfig *m_loadconfig;
	InterfaceWidget *m_inwidget;
	GenerateData *m_gen;
	QDocument *m_DataInstance;  //数据操作类对象
};

#endif // SYSCONTROL_H