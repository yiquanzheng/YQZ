#pragma once
#ifndef QDOCUMENT_H
#define QDOCUMENT_H
#include <QVector>
#include <QDebug>
/*
   单个软件环境信息类
*/
class SoftwareData
{
public:
	SoftwareData() {
	}
	~SoftwareData() {
	}
	void setData(SoftwareData *);
	void showData();
	//29维度的单个软件数据结构
	//任务环境信息
	QString taskID;          //任务种类  QString  任务名称
	int priority;           //任务优先级  int  {0,1,2}任务优先级

							//舰艇环境信息
	float missileX;         //导弹经度  float  [-180,180)  西经度为负
	float missileY;         //导弹纬度  float  [-90,90)    南纬度为负
	float missileSpeed;     //导弹速度  float 
	float missileD;         //导弹方向  float  [0,360)     导弹方向与正北方向顺时针夹角
	bool missileTag;       //导弹是否来袭，true代表来袭，false代表没有导弹来袭

	float shipX;            //舰艇经度  float  [-180,180)  西经度为负
	float shipY;            //舰艇纬度  float  [-90,90)    南纬度为负
	float shipSpeed;        //舰艇方向  float  [0,360)     导弹方向与正北方向顺时针夹角
	float shipD;            //舰艇速度  float
	float shipLength;       //舰艇长度  float

							//舱室环境信息
	QString cabinID;        //舱室编号  QString
	float cabinT;           //舱室温度  float   舱室的摄氏温度
	float cabinH;           //舱室湿度  float   舱室的相对湿度

							//主机环境信息
	QString hostID;         //主机编号  QString
	bool hostState = true;         //主机状态  bool    {true,false}表示在线或离线
	float hostComputeOR;    //主机计算资源占用比 float [0,1]
	float hostMemoryOR;     //主机内存资源占用比 float [0,1]
	float hostBandwidthOR;  //主机网络带宽占用比 float [0,1]
	float hostStorageOR;    //主机存储容量占用比 float [0,1]
	float hostMainboardT;   //主板温度  float  摄氏温度
	float hostCpuT;         //CPU温度   float  摄氏温度
	float hostHarddiskT;    //硬盘温度  float  摄氏温度

							//软件状态信息
	QString softwareID;          //软件编号 QString
	bool softwareHeartBeat = true;      //软件状态 bool  {true,false}表示软件运行与否
	float softwareComputeOR;     //软件占用主机计算资源比 float [0,1]
	float softwareMemoryOR;      //软件占用主机内存资源比 float [0,1]
	float softwareBandwidthOR;   //软件占用主机网络带宽比 float [0,1]
	float softwareStorageOR;     //软件占用主机存储容量比 float [0,1]
								 //一个主机的占用比=在主机上运行的各个软件占用比之和
								 //将一个虚拟机运行的软件的整体当成一个软件
};
/*
   正常数值定义类
*/
class NormalValue
{
public:
	NormalValue() {
	}
	~NormalValue() {
	}
	float cabinT;           //舱室温度  float   舱室的摄氏温度
	float cabinH;           //舱室湿度  float   舱室的相对湿度
	float hostComputeOR;    //主机计算资源占用比 float [0,1]
	float hostMemoryOR;     //主机内存资源占用比 float [0,1]
	float hostBandwidthOR;  //主机网络带宽占用比 float [0,1]
	float hostStorageOR;    //主机存储容量占用比 float [0,1]
	float hostMainboardT;   //主板温度  float  摄氏温度
	float hostCpuT;         //CPU温度   float  摄氏温度
	float hostHarddiskT;    //硬盘温度  float  摄氏温度
};
/*
  数值典型异常定义定义类
*/
class AbNormalValue
{
public:
	AbNormalValue() {
	}
	~AbNormalValue() {
	}
	float cabinT;           //舱室温度  float   舱室的摄氏温度
	float cabinH;           //舱室湿度  float   舱室的相对湿度
	float hostComputeOR;    //主机计算资源占用比 float [0,1]
	float hostMemoryOR;     //主机内存资源占用比 float [0,1]
	float hostBandwidthOR;  //主机网络带宽占用比 float [0,1]
	float hostStorageOR;    //主机存储容量占用比 float [0,1]
	float hostMainboardT;   //主板温度  float  摄氏温度
	float hostCpuT;         //CPU温度   float  摄氏温度
	float hostHarddiskT;    //硬盘温度  float  摄氏温度
};
/*
   错误产生设置数据类
*/
class FaultState
{
public:
	FaultState() {
	}
	~FaultState() {
	}
	QString ID;   //故障的影响舱室/主机/软件
	int fault_model;    //故障模式
	QString fault_model_name;   //故障模式名字
	int fault_func;     //故障产生函数
	QString fault_func_name;   //故障模式小类名字
	int time = 5;      //故障开始产生时间
};
/*
   舱室变化参数及相关历史数据类
*/
class CabinPar
{
public:
	CabinPar() {
	}
	~CabinPar() {
	}
	QString cabinID;
	QList<float> cabinH;             //舱室温度历史产生数据链表
	QList<float> cabinT;             //舱室湿度历史产生数据链表
	float cabinT_straight_k = 5;       //舱室温度直线上升的斜率
	float cabinT_square_k = 1;         //舱室温度二次上升的系数
	float cabinH_straight_k = 0.05;    //舱室湿度直线上升的斜率
	float cabinH_square_k = 0.01;      //舱室湿度二次上升的系数
};
/*
   主机变化参数及相关历史数据类
*/
class HostPar
{
public:
	HostPar() {
	}
	~HostPar() {
	}
	QString hostID;
	QList<bool> hostState;        //主机状态历史数据链表
	QList<float> hostMT;           //主板温度历史数据链表
	QList<float> hostCT;           //CPU温度历史数据链表
	QList<float> hostHT;           //硬盘温度历史数据链表
	QList<float> hostCOR;          //主机计算资源占用比历史数据链表
	QList<float> hostMOR;          //主机内存资源占用比历史数据链表
	QList<float> hostBOR;          //主机网络带宽占用比历史数据链表
	QList<float> hostSOR;          //主机存储容量占用比历史数据链表
	float hostMT_straight_k = 5;     //主板温度直线上升的斜率
	float hostMT_square_k = 1;       //主板温度二次上升的系数
	float hostCT_straight_k = 5;     //CPU温度直线上升的斜率
	float hostCT_square_k = 1;       //CPU温度二次上升的系数
	float hostHT_straight_k = 5;     //硬盘温度直线上升的斜率
	float hostHT_square_k = 1;       //硬盘温度二次上升的系数
	float hostCOR_straight_k = 0.05;      //主机计算资源占用比直线下降的斜率
	float hostCOR_square_k = 0.01;        //主机计算资源占用比二次下降的斜率

	float hostMOR_straight_k = 0.05;      //主机内存资源占用比直线下降的斜率
	float hostMOR_square_k = 0.05;      //主机内存资源占用比直线下降的斜率

	float hostBOR_straight_k = 0.05;      //主机网络带宽占用比直线下降的斜率
	float hostBOR_square_k = 0.05;      //主机网络带宽占用比直线下降的斜率

	float hostSOR_straight_k = 0.05;      //主机存储容量占用比直线下降的斜率
	float hostSOR_square_k = 0.05;      //主机存储容量占用比直线下降的斜率
};
/*
   软件变化参数及相关历史数据类
*/
class SoftwarePar
{
public:
	SoftwarePar() {
	}
	~SoftwarePar() {
	}
	QString softwareID;
	QList<bool> softwareState;        //软件工作状态历史数据链表
	QList<float> softwareCOR;          //软件计算资源占用比历史数据链表
	QList<float> softwareMOR;          //软件内存资源占用比历史数据链表
	QList<float> softwareBOR;          //软件网络带宽占用比历史数据链表
	QList<float> softwareSOR;          //软件存储容量占用比历史数据链表
};

class QDocument
{
private:
	QDocument() {
		m_NormalValue = new NormalValue();
		m_AbNormalValue = new AbNormalValue();
	}
	static QDocument *m_DataInstance;
	class GC
	{
	public:
		~GC()
		{
			if (m_DataInstance != NULL)
			{
				delete m_DataInstance;
				m_DataInstance = NULL;
			}
		}
	};
	static GC gc;

public:
	static QDocument* getInstance() {
		return m_DataInstance;
	}
	QVector<SoftwareData *> m_SoftWareData;   //所有软件数据
	QVector<FaultState *>m_FaultStateData;    //故障数据
	NormalValue *m_NormalValue;               //正常值范围
	AbNormalValue *m_AbNormalValue;           //异常值范围

	QVector<CabinPar *>m_CabinPar;            //舱室的参数
	QVector<HostPar *>m_HostPar;              //主机的参数
	QVector<SoftwarePar *>m_SoftwarePar;      //软件的参数
	int TotalTime;                            //数据生成总时间

	//八个检索列表数据的方法，返回相应的列表
	QVector<QString> SelectHostIDBycabinID(QString);              //根据cabinID检索出来在舱室的主机
	QVector<QString> SelectsoftWareIDBycabinID(QString);          //根据cabinID检索出来在舱室的软件
	QVector<QString> SelectsoftWareIDByhostID(QString);           //根据hostID检索出来在主机的软件
	QVector<QString> SelectsoftWareIDBytaskID(QString);           //根据hostID检索出来在主机的软件

	QVector<QString> SelectAllcabinID();             //检索出来所有的舱室ID
	QVector<QString> SelectAllhostID();              //检索出来所有的主机ID
	QVector<QString> SelectAllsoftwareID();          //检索出来所有的软件ID
	QVector<QString> SelectAlltaskID();              //检索出来所有的排序任务ID

    //四个检索软件数据方法，返回相应的软件数据对象
	QVector<SoftwareData *> SelectBytaskID(QString);  //查找数据通过 任务ID 检索
	QVector<SoftwareData *> SelectBycabinID(QString); //查找数据通过 舱室ID 检索
	QVector<SoftwareData *> SelectByhostID(QString);  //查找数据通过 主机ID 检索
	SoftwareData * SelectBysoftwareID(QString);       //查找数据通过 软件ID 检索

	//三个检索变化参数方法,返回对象所在的下标
	int SelectCabinParBycabinID(QString);             //根据舱室ID检索舱室参数下标值，检索不到返回-1
	int SelectHostParByhostID(QString);           //根据主机ID检索主机参数下标值，检索不到返回-1
	int SelectSoftwareParBysoftwareID(QString);     //根据软件ID检索软件参数下标值，检索不到返回-1

	//一个设置软件数据方法
	void SetBysoftware(QString, SoftwareData *);     //通过 软件ID 去设置最新数据
};

#endif // QDOCUMENT_H
