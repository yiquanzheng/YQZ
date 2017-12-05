#include "SysControl.h"

SysControl::SysControl(QObject * parent) : QObject(parent)
{
	//ʵ�������������
	m_loadconfig = new LoadConfig();
	m_inwidget = new InterfaceWidget();
	m_gen = new GenerateData();
	m_DataInstance = QDocument::getInstance();  //�Ѿ���������ݲ��������
	//====================================
	m_dec = new Decision();
	//====================================
}

SysControl::~SysControl()
{
}

void SysControl::InitSys()
{
	//д��������桢���������ĳ�ʼ����
	m_loadconfig->init();
	m_inwidget->init();
	//д������������connect�ź�
	connect(m_inwidget, SIGNAL(startsim()), m_gen, SLOT(simulation()));
	connect(m_gen, SIGNAL(simover()), m_inwidget, SLOT(updateChartData()));
	//==================================
	connect(m_gen, SIGNAL(simover()), m_gen->publisher, SLOT(publishSoftwareState()));
	//==================================
}