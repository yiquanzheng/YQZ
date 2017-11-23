#pragma once
// 类:   配置文件加载类
// 用途: 用于加载配置文件，初始化系统与数据
// 调用: 系统初始化时候调用init()方法执行
#ifndef LoadConfig_H
#define LoadConfig_H
#include <QObject>
#include "QDocument.h"  //引入数据类文件
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
	void readShipXML();     //读取船的配置文件
	void readSettingIni();  //读取标准值异常值配置文件
	void createBaseData();  //初始化数据
	void createBasePar();   //初始化参数

private:
	QDocument *m_DataInstance;  //数据操作类对象
	QVector<QVector<QString>> SoftWareList;    //软件列表

};

#endif // LoadConfig_H
