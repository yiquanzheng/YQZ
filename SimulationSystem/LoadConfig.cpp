#include "LoadConfig.h"
#include <iostream>
using namespace std;
LoadConfig::LoadConfig(QObject * parent) : QObject(parent)
{
	m_DataInstance = QDocument::getInstance();  //已经获得了数据操作类对象
}


LoadConfig::~LoadConfig()
{
}

void LoadConfig::init()
{
	/*
	外部接口，读取配置文件
	*/
	readShipXML();
	readSettingIni();
	createBaseData();
	createBasePar();
}

void LoadConfig::readShipXML()
{
	//读取舱室配置表
	//同时需要进行创建基本软件数据信息
	QFile file("Config/Ship.xml");
	QDomDocument document;
	QString error;
	int row = 0, column = 0;
	if (!document.setContent(&file, false, &error, &row, &column))
	{
		QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row and column") + QString::number(row, 10) + QString(",") + QString::number(column, 10));
		return;
	}
	if (document.isNull())
	{
		QMessageBox::information(NULL, QString("title"), QString("document is null!"));
		return;
	}
	QDomElement root = document.documentElement();
	if (root.hasAttribute("Ship"))
	{
		QString name = root.attributeNode("Ship").value();
	}
	QDomElement software = root.firstChildElement();
	if (software.isNull())
		return;
	SoftWareList.clear();
	QDomNodeList list = root.childNodes();
	int count = list.count();
	for (int i = 0; i<count;i++)
	{
		QDomNode dom_node = list.item(i);
		QDomElement element = dom_node.toElement();
		QDomNodeList child_list = element.childNodes();
		int child_count = child_list.count();
		QVector<QString> Value;
		for (int j = 0; j<child_count;j++)
		{
			QDomNode child_dom_node = child_list.item(j);
			QDomElement child_element = child_dom_node.toElement();
			QString child_tag_name = child_element.tagName();
			QString child__tag_value = child_element.text();
			Value.append(child__tag_value);
		}
		SoftWareList.append(Value);
	}
}

void LoadConfig::readSettingIni()
{
	//读取正常值与异常值设定表
	QSettings settings("Config/valueSetting.ini", QSettings::IniFormat);
	if (settings.contains("NormalValue/cabinT"))
	{
		m_DataInstance->m_NormalValue->cabinT = settings.value("NormalValue/cabinT").toFloat();
	}
	if (settings.contains("NormalValue/cabinH"))
	{
		m_DataInstance->m_NormalValue->cabinH = settings.value("NormalValue/cabinH").toFloat();
	}
	if (settings.contains("NormalValue/hostComputeOR"))
	{
		m_DataInstance->m_NormalValue->hostComputeOR = settings.value("NormalValue/hostComputeOR").toFloat();
	}
	if (settings.contains("NormalValue/hostMemoryOR"))
	{
		m_DataInstance->m_NormalValue->hostMemoryOR = settings.value("NormalValue/hostMemoryOR").toFloat();
	}
	if (settings.contains("NormalValue/hostBandwidthOR"))
	{
		m_DataInstance->m_NormalValue->hostBandwidthOR = settings.value("NormalValue/hostBandwidthOR").toFloat();
	}
	if (settings.contains("NormalValue/hostStorageOR"))
	{
		m_DataInstance->m_NormalValue->hostStorageOR = settings.value("NormalValue/hostStorageOR").toFloat();
	}
	if (settings.contains("NormalValue/hostMainboardT"))
	{
		m_DataInstance->m_NormalValue->hostMainboardT = settings.value("NormalValue/hostMainboardT").toFloat();
	}
	if (settings.contains("NormalValue/hostCpuT"))
	{
		m_DataInstance->m_NormalValue->hostCpuT = settings.value("NormalValue/hostCpuT").toFloat();
	}
	if (settings.contains("NormalValue/hostHarddiskT"))
	{
		m_DataInstance->m_NormalValue->hostHarddiskT = settings.value("NormalValue/hostHarddiskT").toFloat();
	}

	if (settings.contains("AbNormalValue/cabinT"))
	{
		m_DataInstance->m_AbNormalValue->cabinT = settings.value("AbNormalValue/cabinT").toFloat();
	}
	if (settings.contains("AbNormalValue/cabinH"))
	{
		m_DataInstance->m_AbNormalValue->cabinH = settings.value("AbNormalValue/cabinH").toFloat();
	}
	if (settings.contains("AbNormalValue/hostComputeOR"))
	{
		m_DataInstance->m_AbNormalValue->hostComputeOR = settings.value("AbNormalValue/hostComputeOR").toFloat();
	}
	if (settings.contains("AbNormalValue/hostMemoryOR"))
	{
		m_DataInstance->m_AbNormalValue->hostMemoryOR = settings.value("AbNormalValue/hostMemoryOR").toFloat();
	}
	if (settings.contains("AbNormalValue/hostBandwidthOR"))
	{
		m_DataInstance->m_AbNormalValue->hostBandwidthOR = settings.value("AbNormalValue/hostBandwidthOR").toFloat();
	}
	if (settings.contains("AbNormalValue/hostStorageOR"))
	{
		m_DataInstance->m_AbNormalValue->hostStorageOR = settings.value("AbNormalValue/hostStorageOR").toFloat();
	}
	if (settings.contains("AbNormalValue/hostMainboardT"))
	{
		m_DataInstance->m_AbNormalValue->hostMainboardT = settings.value("AbNormalValue/hostMainboardT").toFloat();
	}
	if (settings.contains("AbNormalValue/hostCpuT"))
	{
		m_DataInstance->m_AbNormalValue->hostCpuT = settings.value("AbNormalValue/hostCpuT").toFloat();
	}
	if (settings.contains("AbNormalValue/hostHarddiskT"))
	{
		m_DataInstance->m_AbNormalValue->hostHarddiskT = settings.value("AbNormalValue/hostHarddiskT").toFloat();
	}
}

void LoadConfig::createBaseData()
{
	//初始化参数
	m_DataInstance->m_SoftWareData.clear();
	for (int i = 0; i < SoftWareList.size(); i++)
	{
		SoftwareData *temp = new SoftwareData();
		temp->cabinID = SoftWareList.at(i).at(0);
		temp->hostID = SoftWareList.at(i).at(2);
		temp->softwareID = SoftWareList.at(i).at(3);
		temp->taskID = SoftWareList.at(i).at(4);
		temp->priority = SoftWareList.at(i).at(5).toInt();
		m_DataInstance->m_SoftWareData.append(temp);
	}
}

void LoadConfig::createBasePar()   //初始化参数
{
	for (int cabinid = 0; cabinid < m_DataInstance->SelectAllcabinID().size(); cabinid++)
	{
		CabinPar *temp = new CabinPar();
		temp->cabinID = m_DataInstance->SelectAllcabinID().at(cabinid);
		m_DataInstance->m_CabinPar.append(temp);
	}
	for (int hostid = 0; hostid < m_DataInstance->SelectAllhostID().size(); hostid++)
	{
		HostPar *temp = new HostPar();
		temp->hostID = m_DataInstance->SelectAllhostID().at(hostid);
		m_DataInstance->m_HostPar.append(temp);
	}
	for (int softwareid = 0; softwareid < m_DataInstance->SelectAllsoftwareID().size(); softwareid++)
	{
		SoftwarePar *temp = new SoftwarePar();
		temp->softwareID = m_DataInstance->SelectAllsoftwareID().at(softwareid);
		m_DataInstance->m_SoftwarePar.append(temp);
	}
}