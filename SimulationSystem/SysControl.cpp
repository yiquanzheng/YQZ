#include "SysControl.h"

SysControl::SysControl(QObject * parent) : QObject(parent)
{
	//实例化操作类对象
	m_loadconfig = new LoadConfig();
	m_inwidget = new InterfaceWidget();
	m_gen = new GenerateData();
	m_DataInstance = QDocument::getInstance();  //已经获得了数据操作类对象
	//====================================
	m_dec = new Decision();
	//====================================
}

SysControl::~SysControl()
{
}

void SysControl::InitSys()
{
	//写入各个界面、操作类对象的初始化等
	m_loadconfig->init();
	m_inwidget->init();
	//写入各个操作类的connect信号
	connect(m_inwidget, SIGNAL(startsim()), m_gen, SLOT(simulation()));
	connect(m_gen, SIGNAL(simover()), m_inwidget, SLOT(updateChartData()));
	//==================================
	connect(m_gen, SIGNAL(simover()), m_gen->publisher, SLOT(publishSoftwareState()));
	//==================================
}