#pragma once
#ifndef QDOCUMENT_H
#define QDOCUMENT_H
#include <QVector>
#include <QDebug>
/*
   �������������Ϣ��
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
	//29ά�ȵĵ���������ݽṹ
	//���񻷾���Ϣ
	QString taskID;          //��������  QString  ��������
	int priority;           //�������ȼ�  int  {0,1,2}�������ȼ�

							//��ͧ������Ϣ
	float missileX;         //��������  float  [-180,180)  ������Ϊ��
	float missileY;         //����γ��  float  [-90,90)    ��γ��Ϊ��
	float missileSpeed;     //�����ٶ�  float 
	float missileD;         //��������  float  [0,360)     ������������������˳ʱ��н�
	bool missileTag;       //�����Ƿ���Ϯ��true������Ϯ��false����û�е�����Ϯ

	float shipX;            //��ͧ����  float  [-180,180)  ������Ϊ��
	float shipY;            //��ͧγ��  float  [-90,90)    ��γ��Ϊ��
	float shipSpeed;        //��ͧ����  float  [0,360)     ������������������˳ʱ��н�
	float shipD;            //��ͧ�ٶ�  float
	float shipLength;       //��ͧ����  float

							//���һ�����Ϣ
	QString cabinID;        //���ұ��  QString
	float cabinT;           //�����¶�  float   ���ҵ������¶�
	float cabinH;           //����ʪ��  float   ���ҵ����ʪ��

							//����������Ϣ
	QString hostID;         //�������  QString
	bool hostState = true;         //����״̬  bool    {true,false}��ʾ���߻�����
	float hostComputeOR;    //����������Դռ�ñ� float [0,1]
	float hostMemoryOR;     //�����ڴ���Դռ�ñ� float [0,1]
	float hostBandwidthOR;  //�����������ռ�ñ� float [0,1]
	float hostStorageOR;    //�����洢����ռ�ñ� float [0,1]
	float hostMainboardT;   //�����¶�  float  �����¶�
	float hostCpuT;         //CPU�¶�   float  �����¶�
	float hostHarddiskT;    //Ӳ���¶�  float  �����¶�

							//���״̬��Ϣ
	QString softwareID;          //������ QString
	bool softwareHeartBeat = true;      //���״̬ bool  {true,false}��ʾ����������
	float softwareComputeOR;     //���ռ������������Դ�� float [0,1]
	float softwareMemoryOR;      //���ռ�������ڴ���Դ�� float [0,1]
	float softwareBandwidthOR;   //���ռ�������������� float [0,1]
	float softwareStorageOR;     //���ռ�������洢������ float [0,1]
								 //һ��������ռ�ñ�=�����������еĸ������ռ�ñ�֮��
								 //��һ����������е���������嵱��һ�����
};
/*
   ������ֵ������
*/
class NormalValue
{
public:
	NormalValue() {
	}
	~NormalValue() {
	}
	float cabinT;           //�����¶�  float   ���ҵ������¶�
	float cabinH;           //����ʪ��  float   ���ҵ����ʪ��
	float hostComputeOR;    //����������Դռ�ñ� float [0,1]
	float hostMemoryOR;     //�����ڴ���Դռ�ñ� float [0,1]
	float hostBandwidthOR;  //�����������ռ�ñ� float [0,1]
	float hostStorageOR;    //�����洢����ռ�ñ� float [0,1]
	float hostMainboardT;   //�����¶�  float  �����¶�
	float hostCpuT;         //CPU�¶�   float  �����¶�
	float hostHarddiskT;    //Ӳ���¶�  float  �����¶�
};
/*
  ��ֵ�����쳣���嶨����
*/
class AbNormalValue
{
public:
	AbNormalValue() {
	}
	~AbNormalValue() {
	}
	float cabinT;           //�����¶�  float   ���ҵ������¶�
	float cabinH;           //����ʪ��  float   ���ҵ����ʪ��
	float hostComputeOR;    //����������Դռ�ñ� float [0,1]
	float hostMemoryOR;     //�����ڴ���Դռ�ñ� float [0,1]
	float hostBandwidthOR;  //�����������ռ�ñ� float [0,1]
	float hostStorageOR;    //�����洢����ռ�ñ� float [0,1]
	float hostMainboardT;   //�����¶�  float  �����¶�
	float hostCpuT;         //CPU�¶�   float  �����¶�
	float hostHarddiskT;    //Ӳ���¶�  float  �����¶�
};
/*
   �����������������
*/
class FaultState
{
public:
	FaultState() {
	}
	~FaultState() {
	}
	QString ID;   //���ϵ�Ӱ�����/����/���
	int fault_model;    //����ģʽ
	QString fault_model_name;   //����ģʽ����
	int fault_func;     //���ϲ�������
	QString fault_func_name;   //����ģʽС������
	int time = 5;      //���Ͽ�ʼ����ʱ��
};
/*
   ���ұ仯�����������ʷ������
*/
class CabinPar
{
public:
	CabinPar() {
	}
	~CabinPar() {
	}
	QString cabinID;
	QList<float> cabinH;             //�����¶���ʷ������������
	QList<float> cabinT;             //����ʪ����ʷ������������
	float cabinT_straight_k = 5;       //�����¶�ֱ��������б��
	float cabinT_square_k = 1;         //�����¶ȶ���������ϵ��
	float cabinH_straight_k = 0.05;    //����ʪ��ֱ��������б��
	float cabinH_square_k = 0.01;      //����ʪ�ȶ���������ϵ��
};
/*
   �����仯�����������ʷ������
*/
class HostPar
{
public:
	HostPar() {
	}
	~HostPar() {
	}
	QString hostID;
	QList<bool> hostState;        //����״̬��ʷ��������
	QList<float> hostMT;           //�����¶���ʷ��������
	QList<float> hostCT;           //CPU�¶���ʷ��������
	QList<float> hostHT;           //Ӳ���¶���ʷ��������
	QList<float> hostCOR;          //����������Դռ�ñ���ʷ��������
	QList<float> hostMOR;          //�����ڴ���Դռ�ñ���ʷ��������
	QList<float> hostBOR;          //�����������ռ�ñ���ʷ��������
	QList<float> hostSOR;          //�����洢����ռ�ñ���ʷ��������
	float hostMT_straight_k = 5;     //�����¶�ֱ��������б��
	float hostMT_square_k = 1;       //�����¶ȶ���������ϵ��
	float hostCT_straight_k = 5;     //CPU�¶�ֱ��������б��
	float hostCT_square_k = 1;       //CPU�¶ȶ���������ϵ��
	float hostHT_straight_k = 5;     //Ӳ���¶�ֱ��������б��
	float hostHT_square_k = 1;       //Ӳ���¶ȶ���������ϵ��
	float hostCOR_straight_k = 0.05;      //����������Դռ�ñ�ֱ���½���б��
	float hostCOR_square_k = 0.01;        //����������Դռ�ñȶ����½���б��

	float hostMOR_straight_k = 0.05;      //�����ڴ���Դռ�ñ�ֱ���½���б��
	float hostMOR_square_k = 0.05;      //�����ڴ���Դռ�ñ�ֱ���½���б��

	float hostBOR_straight_k = 0.05;      //�����������ռ�ñ�ֱ���½���б��
	float hostBOR_square_k = 0.05;      //�����������ռ�ñ�ֱ���½���б��

	float hostSOR_straight_k = 0.05;      //�����洢����ռ�ñ�ֱ���½���б��
	float hostSOR_square_k = 0.05;      //�����洢����ռ�ñ�ֱ���½���б��
};
/*
   ����仯�����������ʷ������
*/
class SoftwarePar
{
public:
	SoftwarePar() {
	}
	~SoftwarePar() {
	}
	QString softwareID;
	QList<bool> softwareState;        //�������״̬��ʷ��������
	QList<float> softwareCOR;          //���������Դռ�ñ���ʷ��������
	QList<float> softwareMOR;          //����ڴ���Դռ�ñ���ʷ��������
	QList<float> softwareBOR;          //����������ռ�ñ���ʷ��������
	QList<float> softwareSOR;          //����洢����ռ�ñ���ʷ��������
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
	QVector<SoftwareData *> m_SoftWareData;   //�����������
	QVector<FaultState *>m_FaultStateData;    //��������
	NormalValue *m_NormalValue;               //����ֵ��Χ
	AbNormalValue *m_AbNormalValue;           //�쳣ֵ��Χ

	QVector<CabinPar *>m_CabinPar;            //���ҵĲ���
	QVector<HostPar *>m_HostPar;              //�����Ĳ���
	QVector<SoftwarePar *>m_SoftwarePar;      //����Ĳ���
	int TotalTime;                            //����������ʱ��

	//�˸������б����ݵķ�����������Ӧ���б�
	QVector<QString> SelectHostIDBycabinID(QString);              //����cabinID���������ڲ��ҵ�����
	QVector<QString> SelectsoftWareIDBycabinID(QString);          //����cabinID���������ڲ��ҵ����
	QVector<QString> SelectsoftWareIDByhostID(QString);           //����hostID�������������������
	QVector<QString> SelectsoftWareIDBytaskID(QString);           //����hostID�������������������

	QVector<QString> SelectAllcabinID();             //�����������еĲ���ID
	QVector<QString> SelectAllhostID();              //�����������е�����ID
	QVector<QString> SelectAllsoftwareID();          //�����������е����ID
	QVector<QString> SelectAlltaskID();              //�����������е���������ID

    //�ĸ�����������ݷ�����������Ӧ��������ݶ���
	QVector<SoftwareData *> SelectBytaskID(QString);  //��������ͨ�� ����ID ����
	QVector<SoftwareData *> SelectBycabinID(QString); //��������ͨ�� ����ID ����
	QVector<SoftwareData *> SelectByhostID(QString);  //��������ͨ�� ����ID ����
	SoftwareData * SelectBysoftwareID(QString);       //��������ͨ�� ���ID ����

	//���������仯��������,���ض������ڵ��±�
	int SelectCabinParBycabinID(QString);             //���ݲ���ID�������Ҳ����±�ֵ��������������-1
	int SelectHostParByhostID(QString);           //��������ID�������������±�ֵ��������������-1
	int SelectSoftwareParBysoftwareID(QString);     //�������ID������������±�ֵ��������������-1

	//һ������������ݷ���
	void SetBysoftware(QString, SoftwareData *);     //ͨ�� ���ID ȥ������������
};

#endif // QDOCUMENT_H
