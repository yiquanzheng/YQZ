#include "QDocument.h"

//数据设置方法
void SoftwareData::setData(SoftwareData *temp)
{
	taskID = temp->taskID;				       //任务种类
	priority = temp->priority;                 //任务优先级
	missileX = temp->missileX;                 //导弹经度
	missileY = temp->missileY;                 //导弹纬度
	missileSpeed = temp->missileSpeed;         //导弹速度
	missileD = temp->missileD;                 //导弹方向
	missileTag = temp->missileTag;             //导弹来袭标识
	shipX = temp->shipX;                       //舰艇经度
	shipY = temp->shipY;                       //舰艇纬度
	shipSpeed = temp->shipSpeed;               //舰艇方向
	shipD = temp->shipD;                       //舰艇速度
	shipLength = temp->shipLength;             //舰艇长度
	cabinID = temp->cabinID;                   //舱室编号
	cabinT = temp->cabinT;                     //舱室温度
	cabinH = temp->cabinH;                     //舱室湿度
	hostID = temp->hostID;                     //主机编号
	hostState = temp->hostState;               //主机状态
	hostComputeOR = temp->hostComputeOR;       //主机计算资源占用比
	hostMemoryOR = temp->hostMemoryOR;         //主机内存资源占用比
	hostBandwidthOR = temp->hostBandwidthOR;   //主机网络带宽占用比
	hostStorageOR = temp->hostStorageOR;       //主机存储容量占用比
	hostMainboardT = temp->hostMainboardT;     //主板温度
	hostCpuT = temp->hostCpuT;                 //CPU温度
	hostHarddiskT = temp->hostHarddiskT;       //硬盘温度
	softwareID = temp->softwareID;                  //软件编号
	softwareHeartBeat = temp->softwareHeartBeat;    //软件状态
	softwareComputeOR = temp->softwareComputeOR;    //软件占用主机计算资源比
	softwareMemoryOR = temp->softwareMemoryOR;      //软件占用主机内存资源比 
	softwareBandwidthOR = temp->softwareBandwidthOR;//软件占用主机网络带宽比
	softwareStorageOR = temp->softwareStorageOR;    //软件占用主机存储容量比
}

void SoftwareData::showData()
{
	qDebug() << "taskID:" + taskID;				       //任务种类
	qDebug() << "priority:" + QString::number(priority);                 //任务优先级
	qDebug() << "missileX:" + QString::number(missileX);                 //导弹经度
	qDebug() << "missileY:" + QString::number(missileY);                 //导弹纬度
	qDebug() << "missileSpeed:" + QString::number(missileSpeed);         //导弹速度
	qDebug() << "missileD:" + QString::number(missileD);                 //导弹方向
	qDebug() << "missileTag:" + QString::number(missileTag);           //导弹来袭标识
	qDebug() << "shipX:" + QString::number(shipX);                    //舰艇经度
	qDebug() << "shipY:" + QString::number(shipY);                       //舰艇纬度
	qDebug() << "shipSpeed:" + QString::number(shipSpeed);               //舰艇方向
	qDebug() << "shipD:" + QString::number(shipD);                     //舰艇速度
	qDebug() << "shipLength:" + QString::number(shipLength);             //舰艇长度
	qDebug() << "cabinID:" + cabinID;                 //舱室编号
	qDebug() << "cabinT:" + QString::number(cabinT);                     //舱室温度
	qDebug() << "cabinH:" + QString::number(cabinH);                     //舱室湿度
	qDebug() << "hostID:" + hostID;                     //主机编号
	qDebug() << "hostState:" + QString::number(hostState);              //主机状态
	qDebug() << "hostComputeOR:" + QString::number(hostComputeOR);      //主机计算资源占用比
	qDebug() << "hostMemoryOR:" + QString::number(hostMemoryOR);          //主机内存资源占用比
	qDebug() << "hostBandwidthOR:" + QString::number(hostBandwidthOR);   //主机网络带宽占用比
	qDebug() << "hostStorageOR:" + QString::number(hostStorageOR);       //主机存储容量占用比
	qDebug() << "hostMainboardT:" + QString::number(hostMainboardT);      //主板温度
	qDebug() << "hostCpuT:" + QString::number(hostCpuT);                 //CPU温度
	qDebug() << "hostHarddiskT:" + QString::number(hostHarddiskT);       //硬盘温度
	qDebug() << "softwareID:" + softwareID;                  //软件编号
	qDebug() << "softwareHeartBeat:" + QString::number(softwareHeartBeat);     //软件状态
	qDebug() << "softwareComputeOR:" + QString::number(softwareComputeOR);    //软件占用主机计算资源比
	qDebug() << "softwareMemoryOR:" + QString::number(softwareMemoryOR);     //软件占用主机内存资源比 
	qDebug() << "softwareBandwidthOR:" + QString::number(softwareBandwidthOR); //软件占用主机网络带宽比
	qDebug() << "softwareStorageOR:" + QString::number(softwareStorageOR);    //软件占用主机存储容量比
}

//八个检索列表数据的方法
QVector<QString> QDocument::SelectHostIDBycabinID(QString id)              //根据cabinID检索出来在舱室的主机
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->cabinID == id)
		{
			temp.append(m_SoftWareData.at(i)->hostID);
		}
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}

QVector<QString> QDocument::SelectsoftWareIDBycabinID(QString id)          //根据cabinID检索出来在舱室的软件
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->cabinID == id)
		{
			temp.append(m_SoftWareData.at(i)->softwareID);
		}
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}

QVector<QString> QDocument::SelectsoftWareIDByhostID(QString id)           //根据hostID检索出来在主机的软件
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->hostID == id)
		{
			temp.append(m_SoftWareData.at(i)->softwareID);
		}
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}

QVector<QString> QDocument::SelectsoftWareIDBytaskID(QString id)           //根据hostID检索出来在主机的软件
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->taskID == id)
		{
			temp.append(m_SoftWareData.at(i)->softwareID);
		}
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}

QVector<QString> QDocument::SelectAllcabinID()             //检索出来所有的舱室ID
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		temp.append(m_SoftWareData.at(i)->cabinID);
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}

QVector<QString> QDocument::SelectAllhostID()              //检索出来所有的主机ID
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		temp.append(m_SoftWareData.at(i)->hostID);
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}

QVector<QString> QDocument::SelectAllsoftwareID()         //检索出来所有的软件ID
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		temp.append(m_SoftWareData.at(i)->softwareID);
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}

QVector<QString> QDocument::SelectAlltaskID()             //检索出来所有的排序任务ID
{
	QVector<QString> temp;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		temp.append(m_SoftWareData.at(i)->taskID);
	}
	QVector<QString> returntemp;
	for (int i = 0; i < temp.size(); i++)
	{
		if (!returntemp.contains(temp.at(i)))
		{
			returntemp.append(temp.at(i));
		}
	}
	return returntemp;
}


//四个检索方法
QVector<SoftwareData *> QDocument::SelectBytaskID(QString id)  //查找数据通过 任务ID 检索
{
	QVector<SoftwareData *> returndata;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->taskID == id)
		{
			returndata.append(m_SoftWareData.at(i));
		}
	}
	return returndata;
}

QVector<SoftwareData *> QDocument::SelectBycabinID(QString id) //查找数据通过 舱室ID 检索
{
	QVector<SoftwareData *> returndata;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->cabinID == id)
		{
			returndata.append(m_SoftWareData.at(i));
		}
	}
	return returndata;
}

QVector<SoftwareData *> QDocument::SelectByhostID(QString id)  //查找数据通过 主机ID 检索
{
	QVector<SoftwareData *> returndata;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->hostID == id)
		{
			returndata.append(m_SoftWareData.at(i));
		}
	}
	return returndata;
}

SoftwareData * QDocument::SelectBysoftwareID(QString id) //查找数据通过 软件ID 检索
{
	SoftwareData * returndata;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->softwareID == id)
		{
			returndata = m_SoftWareData.at(i);
			break;
		}
	}
	return returndata;
}

//三个检索变化参数方法,返回所在的下标
int QDocument::SelectCabinParBycabinID(QString id)             //根据舱室ID检索舱室参数下标值，检索不到返回-1
{
	int index = -1;
	for (int i = 0; i < m_CabinPar.size(); i++)
	{
		if (m_CabinPar.at(i)->cabinID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int QDocument::SelectHostParByhostID(QString id)           //根据主机ID检索主机参数下标值，检索不到返回-1
{
	int index = -1;
	for (int i = 0; i < m_HostPar.size(); i++)
	{
		if (m_HostPar.at(i)->hostID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int QDocument::SelectSoftwareParBysoftwareID(QString id)     //根据软件ID检索软件参数下标值，检索不到返回-1
{
	int index = -1;
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->softwareID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}


//一个设置数据方法
void QDocument::SetBysoftware(QString id, SoftwareData *temp)     //通过 软件ID 去设置最新数据
{
	for (int i = 0; i < m_SoftWareData.size(); i++)
	{
		if (m_SoftWareData.at(i)->softwareID == id)
		{
			m_SoftWareData.at(i)->setData(temp);
			break;
		}
	}
}