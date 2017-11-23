#include "QDocument.h"

//�������÷���
void SoftwareData::setData(SoftwareData *temp)
{
	taskID = temp->taskID;				       //��������
	priority = temp->priority;                 //�������ȼ�
	missileX = temp->missileX;                 //��������
	missileY = temp->missileY;                 //����γ��
	missileSpeed = temp->missileSpeed;         //�����ٶ�
	missileD = temp->missileD;                 //��������
	missileTag = temp->missileTag;             //������Ϯ��ʶ
	shipX = temp->shipX;                       //��ͧ����
	shipY = temp->shipY;                       //��ͧγ��
	shipSpeed = temp->shipSpeed;               //��ͧ����
	shipD = temp->shipD;                       //��ͧ�ٶ�
	shipLength = temp->shipLength;             //��ͧ����
	cabinID = temp->cabinID;                   //���ұ��
	cabinT = temp->cabinT;                     //�����¶�
	cabinH = temp->cabinH;                     //����ʪ��
	hostID = temp->hostID;                     //�������
	hostState = temp->hostState;               //����״̬
	hostComputeOR = temp->hostComputeOR;       //����������Դռ�ñ�
	hostMemoryOR = temp->hostMemoryOR;         //�����ڴ���Դռ�ñ�
	hostBandwidthOR = temp->hostBandwidthOR;   //�����������ռ�ñ�
	hostStorageOR = temp->hostStorageOR;       //�����洢����ռ�ñ�
	hostMainboardT = temp->hostMainboardT;     //�����¶�
	hostCpuT = temp->hostCpuT;                 //CPU�¶�
	hostHarddiskT = temp->hostHarddiskT;       //Ӳ���¶�
	softwareID = temp->softwareID;                  //������
	softwareHeartBeat = temp->softwareHeartBeat;    //���״̬
	softwareComputeOR = temp->softwareComputeOR;    //���ռ������������Դ��
	softwareMemoryOR = temp->softwareMemoryOR;      //���ռ�������ڴ���Դ�� 
	softwareBandwidthOR = temp->softwareBandwidthOR;//���ռ��������������
	softwareStorageOR = temp->softwareStorageOR;    //���ռ�������洢������
}

void SoftwareData::showData()
{
	qDebug() << "taskID:" + taskID;				       //��������
	qDebug() << "priority:" + QString::number(priority);                 //�������ȼ�
	qDebug() << "missileX:" + QString::number(missileX);                 //��������
	qDebug() << "missileY:" + QString::number(missileY);                 //����γ��
	qDebug() << "missileSpeed:" + QString::number(missileSpeed);         //�����ٶ�
	qDebug() << "missileD:" + QString::number(missileD);                 //��������
	qDebug() << "missileTag:" + QString::number(missileTag);           //������Ϯ��ʶ
	qDebug() << "shipX:" + QString::number(shipX);                    //��ͧ����
	qDebug() << "shipY:" + QString::number(shipY);                       //��ͧγ��
	qDebug() << "shipSpeed:" + QString::number(shipSpeed);               //��ͧ����
	qDebug() << "shipD:" + QString::number(shipD);                     //��ͧ�ٶ�
	qDebug() << "shipLength:" + QString::number(shipLength);             //��ͧ����
	qDebug() << "cabinID:" + cabinID;                 //���ұ��
	qDebug() << "cabinT:" + QString::number(cabinT);                     //�����¶�
	qDebug() << "cabinH:" + QString::number(cabinH);                     //����ʪ��
	qDebug() << "hostID:" + hostID;                     //�������
	qDebug() << "hostState:" + QString::number(hostState);              //����״̬
	qDebug() << "hostComputeOR:" + QString::number(hostComputeOR);      //����������Դռ�ñ�
	qDebug() << "hostMemoryOR:" + QString::number(hostMemoryOR);          //�����ڴ���Դռ�ñ�
	qDebug() << "hostBandwidthOR:" + QString::number(hostBandwidthOR);   //�����������ռ�ñ�
	qDebug() << "hostStorageOR:" + QString::number(hostStorageOR);       //�����洢����ռ�ñ�
	qDebug() << "hostMainboardT:" + QString::number(hostMainboardT);      //�����¶�
	qDebug() << "hostCpuT:" + QString::number(hostCpuT);                 //CPU�¶�
	qDebug() << "hostHarddiskT:" + QString::number(hostHarddiskT);       //Ӳ���¶�
	qDebug() << "softwareID:" + softwareID;                  //������
	qDebug() << "softwareHeartBeat:" + QString::number(softwareHeartBeat);     //���״̬
	qDebug() << "softwareComputeOR:" + QString::number(softwareComputeOR);    //���ռ������������Դ��
	qDebug() << "softwareMemoryOR:" + QString::number(softwareMemoryOR);     //���ռ�������ڴ���Դ�� 
	qDebug() << "softwareBandwidthOR:" + QString::number(softwareBandwidthOR); //���ռ��������������
	qDebug() << "softwareStorageOR:" + QString::number(softwareStorageOR);    //���ռ�������洢������
}

//�˸������б����ݵķ���
QVector<QString> QDocument::SelectHostIDBycabinID(QString id)              //����cabinID���������ڲ��ҵ�����
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

QVector<QString> QDocument::SelectsoftWareIDBycabinID(QString id)          //����cabinID���������ڲ��ҵ����
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

QVector<QString> QDocument::SelectsoftWareIDByhostID(QString id)           //����hostID�������������������
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

QVector<QString> QDocument::SelectsoftWareIDBytaskID(QString id)           //����hostID�������������������
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

QVector<QString> QDocument::SelectAllcabinID()             //�����������еĲ���ID
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

QVector<QString> QDocument::SelectAllhostID()              //�����������е�����ID
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

QVector<QString> QDocument::SelectAllsoftwareID()         //�����������е����ID
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

QVector<QString> QDocument::SelectAlltaskID()             //�����������е���������ID
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


//�ĸ���������
QVector<SoftwareData *> QDocument::SelectBytaskID(QString id)  //��������ͨ�� ����ID ����
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

QVector<SoftwareData *> QDocument::SelectBycabinID(QString id) //��������ͨ�� ����ID ����
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

QVector<SoftwareData *> QDocument::SelectByhostID(QString id)  //��������ͨ�� ����ID ����
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

SoftwareData * QDocument::SelectBysoftwareID(QString id) //��������ͨ�� ���ID ����
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

//���������仯��������,�������ڵ��±�
int QDocument::SelectCabinParBycabinID(QString id)             //���ݲ���ID�������Ҳ����±�ֵ��������������-1
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

int QDocument::SelectHostParByhostID(QString id)           //��������ID�������������±�ֵ��������������-1
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

int QDocument::SelectSoftwareParBysoftwareID(QString id)     //�������ID������������±�ֵ��������������-1
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


//һ���������ݷ���
void QDocument::SetBysoftware(QString id, SoftwareData *temp)     //ͨ�� ���ID ȥ������������
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