#include "GenerateData.h"
#include <QDebug>

GenerateData::GenerateData(QObject * parent) : QObject(parent)
{
	m_DataInstance = QDocument::getInstance();  //�Ѿ���������ݲ��������
	timer1 = new QTimer(this);
	//������ʱ������źź���Ӧ�Ĳۺ���
	connect(timer1, &QTimer::timeout, this, &GenerateData::changeData);
	timer1->setInterval(1000);//1��,��û��start
}

GenerateData::~GenerateData()
{

}

void GenerateData::simulation()
{
	timer1->stop();
	count = 0;
	m_ship = new ShipEnvironment(); //����һ����ͧ�࣬���Ҹ���ʼֵ
	//��ֵΪĬ�ϵ�����ֵ
	for (int i = 0; i < m_DataInstance->m_SoftWareData.size(); i++)
	{
		SoftwareData *temp = m_DataInstance->m_SoftWareData.at(i);
		temp->cabinT = m_DataInstance->m_NormalValue->cabinT;
		temp->cabinH = m_DataInstance->m_NormalValue->cabinH;
		temp->hostState = true;
		temp->hostComputeOR = m_DataInstance->m_NormalValue->hostComputeOR;
		temp->hostMemoryOR = m_DataInstance->m_NormalValue->hostMemoryOR;
		temp->hostBandwidthOR = m_DataInstance->m_NormalValue->hostBandwidthOR;
		temp->hostStorageOR = m_DataInstance->m_NormalValue->hostStorageOR;
		temp->hostMainboardT = m_DataInstance->m_NormalValue->hostMainboardT;
		temp->hostCpuT = m_DataInstance->m_NormalValue->hostCpuT;
		temp->hostHarddiskT = m_DataInstance->m_NormalValue->hostHarddiskT;
		temp->softwareHeartBeat = true;
		//���set��ȥ
		m_DataInstance->SetBysoftware(temp->softwareID,temp);
	}
	//Ϊ�������Դռ�ñȸ�ֵ��ÿ�������������ռ�ñȵ�ƽ����
	QVector<QString> hostIdVector = m_DataInstance->SelectAllhostID();
	for (int i = 0; i < hostIdVector.size(); i++)
	{
		QString hostId = hostIdVector.at(i);
		QVector<SoftwareData *> softWareVec = m_DataInstance->SelectByhostID(hostId);
		int size = softWareVec.size();
		for (int i = 0; i < size; i++)
		{
			softWareVec.at(i)->softwareComputeOR = softWareVec.at(i)->hostComputeOR / size;
			softWareVec.at(i)->softwareBandwidthOR = softWareVec.at(i)->hostBandwidthOR / size;
			softWareVec.at(i)->softwareMemoryOR = softWareVec.at(i)->hostMemoryOR / size;
			softWareVec.at(i)->softwareStorageOR = softWareVec.at(i)->hostStorageOR / size;

			//���set��ȥ
			m_DataInstance->SetBysoftware(softWareVec.at(i)->softwareID, softWareVec.at(i));
		}

	}
	/*
	for (int i = 0; i < m_DataInstance->m_SoftWareData.size(); i++)
	{
		m_DataInstance->m_SoftWareData.at(i)->showData();
	}
	*/
	clearDataList();
	timer1->start();//��ʼ��ʱ��
}

//ֱ������
float GenerateData::straightUp(float previous,float maxValue,float k){

	//previous������һ���ֵ
	float temp = previous + 1 * k;
	if (temp >= maxValue)
		temp = maxValue;
	return temp;
}

//ֱ���½�
float GenerateData::straightDown(float previous, float minValue, float k){
	//previous������һ���ֵ
	float temp = previous - 1 * k;
	if (temp <= minValue)
		temp = minValue;
	return temp;
}

//������������
float GenerateData::squareUp(float previous, float maxValue, float x,float k){
    //��һ�����һ������2(x-1)+1,����x��ʾʱ�䣬��1��ʼ
	float temp = previous + (2 * x + 1)*k;
	if (temp >= maxValue)
		temp = maxValue;
	return temp;
}

//Ծ�׺�����ֱ������0���߸�����num
float GenerateData::jumpFunction(float num){
	return num;
}

void GenerateData::changeData(){

	count++;//���������ģ�1���1
			//forѭ�����ı���ֵ����Ϊ����ģ��������
	for (int i = 0; i < m_DataInstance->m_FaultStateData.size(); i++)
	{
		//����쳣ģʽ�Ĳ���
		QString id = m_DataInstance->m_FaultStateData.at(i)->ID;
		int model = m_DataInstance->m_FaultStateData.at(i)->fault_model;
		int function = m_DataInstance->m_FaultStateData.at(i)->fault_func;
		//ǰ��ļ��������������ݣ�֮������쳣����
		if (count >= m_DataInstance->m_FaultStateData.at(i)->time)
		{
			switch (model)
			{
			case 1: {
				//�����¶����ߣ���ôid������ǲ���ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(id);
				//��õ�ǰ���ҵ��±�
				int idx = m_DataInstance->SelectCabinParBycabinID(id);
				//ѡ��ò��ҵĵ�һ������Ĳ����¶ȣ������ò��ҵ��¶�
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
					//ֱ������
					value = straightUp(temp->cabinT, m_DataInstance->m_AbNormalValue->cabinT,
						m_DataInstance->m_CabinPar.at(idx)->cabinT_straight_k);
					break;
				}
				case 1: {
					//��������
							value = squareUp(temp->cabinT, m_DataInstance->m_AbNormalValue->cabinT,
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_CabinPar.at(idx)->cabinT_square_k);
					break;
				}
				default:
					break;
				}
		
				//���ݲ���id,����ÿ����Ҫ�޸ĵ����,�����޸ĵ�ֵ�ǲ����¶�
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					temp->cabinT = value;
					//setһ��
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 2: {
				//����ʪ������,��ôid������ǲ���ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(id);
				//��õ�ǰ���ҵ��±�
				int idx = m_DataInstance->SelectCabinParBycabinID(id);
				//ѡ��ò��ҵĵ�һ������Ĳ���ʪ�ȣ������ò��ҵ�ʪ��
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//ֱ������
							value = straightUp(temp->cabinH, m_DataInstance->m_AbNormalValue->cabinH, 
								m_DataInstance->m_CabinPar.at(idx)->cabinH_straight_k);
							break;
				}
				case 1: {
							//��������
							value = squareUp(temp->cabinH, m_DataInstance->m_AbNormalValue->cabinH, 
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_CabinPar.at(idx)->cabinH_square_k);
							break;
				}
				default:
					break;
				}
				//���ݲ���id,����ÿ����Ҫ�޸ĵ����,�����޸ĵ�ֵ�ǲ���ʪ��
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->cabinH = value;
					//setһ��
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 3: {
				//��������ʧЧ ,��ôid�����������ID �������ǵ��޸������������״̬
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//Ծ�׺���
				float value = jumpFunction(0.0);//ֱ������0
				
				//��������id,����ÿ����Ҫ�޸ĵ����,�����޸ĵ�ֵ���������������Դռ�ñ�
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->hostComputeOR = value;
					temp->hostBandwidthOR = value;
					temp->hostMemoryOR = value;
					temp->hostStorageOR = value;

					temp->hostState = false;

					temp->softwareComputeOR = value;
					temp->softwareBandwidthOR = value;
					temp->softwareMemoryOR = value;
					temp->softwareStorageOR = value;

					temp->softwareHeartBeat = false;
					//setһ��
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 4: {
				//�������ʧЧ,��ôid����������ID���������ǵ��޸������״̬
				SoftwareData * softVec = m_DataInstance->SelectBysoftwareID(id);
				//�������id,�޸ĵ�ֵ���������Դռ�ñ�
				SoftwareData *temp = softVec;
				//Ծ�׺���
				float value = jumpFunction(0.0);//ֱ������0

				temp->softwareComputeOR = value;
				temp->softwareBandwidthOR = value;
				temp->softwareMemoryOR = value;
				temp->softwareStorageOR = value;

				temp->softwareHeartBeat = false;
				//���setһ��
				m_DataInstance->SetBysoftware(temp->softwareID, temp);
				break;
			}
			case 5: {
				//������Ϯ
				m_ship->missileDetected();
				break;
			}
			case 6: {
				//����cpu�¶�����,��ôid�����������ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//��ø��������±�
				int idx = m_DataInstance->SelectHostParByhostID(id);
				//�ø������ĵ�һ�����������cpu�¶ȣ���Ϊ����cpu�¶��������
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//ֱ������
							value = straightUp(temp->hostCpuT, m_DataInstance->m_AbNormalValue->hostCpuT,
								m_DataInstance->m_HostPar.at(idx)->hostCT_straight_k);
							break;
				}
				case 1: {
							//��������
							value = squareUp(temp->hostCpuT, m_DataInstance->m_AbNormalValue->hostCpuT, 
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostCT_square_k);
							break;
				}
				default:
					break;
				}

				//��������id,����ÿ����Ҫ�޸ĵ����,�����޸ĵ�ֵ������cpu�¶�
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->hostCpuT = value;
					//���setһ��
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 7: {
				//Ӳ���¶����ߣ���ôid�����������ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//��ø��������±�
				int idx = m_DataInstance->SelectHostParByhostID(id);
				//�ø������ĵ�һ�������Ӳ���¶ȣ���Ϊ����Ӳ���¶��������
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//ֱ������
							value = straightUp(temp->hostHarddiskT, m_DataInstance->m_AbNormalValue->hostHarddiskT, 
								m_DataInstance->m_HostPar.at(idx)->hostHT_straight_k);
							break;
				}
				case 1: {
							//��������
							value = squareUp(temp->hostHarddiskT, m_DataInstance->m_AbNormalValue->hostHarddiskT,
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostHT_square_k);
							break;
				}
				default:
					break;
				}

				//��������id,����ÿ����Ҫ�޸ĵ����,�����޸ĵ�ֵ������Ӳ���¶�
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->hostHarddiskT = value;
					//setһ��
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 8: {
				//�����¶�����,��ôid�����������ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//��ø��������±�
				int idx = m_DataInstance->SelectHostParByhostID(id);
				//�ø������ĵ�һ������������¶ȣ���Ϊ���������¶��������
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//ֱ������
							value = straightUp(temp->hostMainboardT, m_DataInstance->m_AbNormalValue->hostMainboardT, 
								m_DataInstance->m_HostPar.at(idx)->hostMT_straight_k);
							break;
				}
				case 1: {
							//��������
							float value = squareUp(temp->hostMainboardT, m_DataInstance->m_AbNormalValue->hostMainboardT,
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostMT_square_k);
							break;
				}
				default:
					break;
				}
				
				//��������id,����ÿ����Ҫ�޸ĵ����,�����޸ĵ�ֵ�����������¶�
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->hostMainboardT = value;
					//setһ��
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 9: {
				//����������Դ����,��ôid�����������ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//��ø��������±�
				int idx = m_DataInstance->SelectHostParByhostID(id);
				
				//������Ϊʱ�������Դռ�ñȣ�����ÿ������������Ϣ�ǲ�ͬ�ģ�������Ҫѭ��
				//�����ܼ򵥵İѵ�һ�������Ϣ���������е�
				//��������id,����ÿ����Ҫ�޸ĵ����,�����޸ĵ�ֵ�������Ͷ�Ӧ�������Դռ�ñ�
				int size = softVec.size();
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(i);
					float value = 0.0;
					float value1 = 0.0;
					float value2 = 0.0;
					float value3 = 0.0;
					switch (function)
					{
					case 0: {
						//ֱ������
						value = straightUp(temp->hostComputeOR, m_DataInstance->m_AbNormalValue->hostComputeOR,
							m_DataInstance->m_HostPar.at(idx)->hostCOR_straight_k);
						value1 = straightUp(temp->hostBandwidthOR, m_DataInstance->m_AbNormalValue->hostBandwidthOR, 
							m_DataInstance->m_HostPar.at(idx)->hostBOR_straight_k);
						value2 = straightUp(temp->hostMemoryOR, m_DataInstance->m_AbNormalValue->hostMemoryOR,
							m_DataInstance->m_HostPar.at(idx)->hostMOR_straight_k);
						value3 = straightUp(temp->hostStorageOR, m_DataInstance->m_AbNormalValue->hostStorageOR, 
							m_DataInstance->m_HostPar.at(idx)->hostSOR_straight_k);
						break;
					}
					case 1: {
						//��������
								value = squareUp(temp->hostComputeOR, m_DataInstance->m_AbNormalValue->hostComputeOR, 
									count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostCOR_square_k);
								value1 = squareUp(temp->hostBandwidthOR, m_DataInstance->m_AbNormalValue->hostBandwidthOR,
									count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostBOR_square_k);
								value2 = squareUp(temp->hostMemoryOR, m_DataInstance->m_AbNormalValue->hostMemoryOR,
									count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostMOR_square_k);
								value3 = squareUp(temp->hostStorageOR, m_DataInstance->m_AbNormalValue->hostStorageOR
									, count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostSOR_square_k);
						break;
					}
					default:
						break;
					}
					temp->hostComputeOR = value;
					temp->hostBandwidthOR = value1;
					temp->hostMemoryOR = value2;
					temp->hostStorageOR = value3;

					temp->softwareComputeOR = temp->hostComputeOR / size;
					temp->softwareBandwidthOR = temp->hostBandwidthOR / size;
					temp->softwareMemoryOR = temp->hostMemoryOR / size;
					temp->softwareStorageOR = temp->hostStorageOR / size;

					//setһ��
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 10: {
				//������
				break;
			}
			default:
				break;
			}
		}
	}

	//�����Ҫ����һ����������ݣ����뵽list����-----Ϊ����ʾͼ��
	addDataList();
	
	//���������Ϣ
	printMsg();

	if (count == m_DataInstance->TotalTime)
	//if (count == 10) 
		timer1->stop();
}

void GenerateData::clearDataList()//�����ʷ����list
{
	//�������еĲ��ң������ʷ����
	for (int cabin = 0; cabin < m_DataInstance->SelectAllcabinID().size(); cabin++) {

		QString cabinID = m_DataInstance->m_CabinPar.at(cabin)->cabinID;//�õ����ҵ�id
																		//Ȼ����ݲ���id�������е����������ֻ��Ҫѡȡ����һ�������cabinT��ֵ����Ϊ��Ӧ���ҵ�cabinT��ֵ
		QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(cabinID);
		if (softVec.size() > 0) { //��֤���������
			m_DataInstance->m_CabinPar.at(cabin)->cabinT.clear();
			m_DataInstance->m_CabinPar.at(cabin)->cabinH.clear();
		}
		else {
			qDebug() << "!!error!!dont have this cabin!!" << endl;
		}
	}

	//�������е������������ʷ����
	for (int host = 0; host < m_DataInstance->SelectAllhostID().size(); host++) {
		QString hostID = m_DataInstance->m_HostPar.at(host)->hostID;//�õ�����ID
																	//Ȼ���������id���Ҷ�Ӧ���������������ֻ��Ҫѡȡ����һ�������cabinT��ֵ����Ϊ��Ӧ������cabinT��ֵ
		QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(hostID);
		if (softVec.size() > 0) { //��֤���������
			m_DataInstance->m_HostPar.at(host)->hostState.clear();
			m_DataInstance->m_HostPar.at(host)->hostMT.clear();
			m_DataInstance->m_HostPar.at(host)->hostCT.clear();
			m_DataInstance->m_HostPar.at(host)->hostHT.clear();
			m_DataInstance->m_HostPar.at(host)->hostCOR.clear();
			m_DataInstance->m_HostPar.at(host)->hostMOR.clear();
			m_DataInstance->m_HostPar.at(host)->hostBOR.clear();
			m_DataInstance->m_HostPar.at(host)->hostSOR.clear();
		}
		else {
			qDebug() << "!!error!!dont have this host!!" << endl;
		}
	}

	//�������е�����������ʷ����
	for (int software = 0; software < m_DataInstance->SelectAllsoftwareID().size(); software++) {
		QString softwareID = m_DataInstance->m_SoftwarePar.at(software)->softwareID;//�õ����ID
																					//�������id�����ض�Ӧ�����
		SoftwareData *soft = m_DataInstance->SelectBysoftwareID(softwareID);
		if (soft != NULL) { //��֤�����
			m_DataInstance->m_SoftwarePar.at(software)->softwareState.clear();
			m_DataInstance->m_SoftwarePar.at(software)->softwareCOR.clear();
			m_DataInstance->m_SoftwarePar.at(software)->softwareMOR.clear();
			m_DataInstance->m_SoftwarePar.at(software)->softwareBOR.clear();
			m_DataInstance->m_SoftwarePar.at(software)->softwareSOR.clear();
		}
		else {
			qDebug() << "!!error!!dont have this software!!" << endl;
		}
	}
}

void GenerateData::addDataList(){
	//�������еĲ��ң�������ʷ����
	for (int cabin = 0; cabin < m_DataInstance->SelectAllcabinID().size(); cabin++){

		QString cabinID = m_DataInstance->m_CabinPar.at(cabin)->cabinID;//�õ����ҵ�id
		//Ȼ����ݲ���id�������е����������ֻ��Ҫѡȡ����һ�������cabinT��ֵ����Ϊ��Ӧ���ҵ�cabinT��ֵ
		QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(cabinID);
		if (softVec.size() > 0) { //��֤���������
			  //�����Ӧʱ�����ʷֵ
			m_DataInstance->m_CabinPar.at(cabin)->cabinT.append(softVec.at(0)->cabinT);
			m_DataInstance->m_CabinPar.at(cabin)->cabinH.append(softVec.at(0)->cabinH);
		}
		else{
			qDebug() << "!!error!!dont have this cabin!!" << endl;
		}

	}

	//�������е�������������ʷ����
	for (int host = 0; host < m_DataInstance->SelectAllhostID().size(); host++){
		QString hostID = m_DataInstance->m_HostPar.at(host)->hostID;//�õ�����ID
		//Ȼ���������id���Ҷ�Ӧ���������������ֻ��Ҫѡȡ����һ�������cabinT��ֵ����Ϊ��Ӧ������cabinT��ֵ
		QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(hostID);
		if (softVec.size() > 0) { //��֤���������
            //�����Ӧʱ�����ʷֵ
			m_DataInstance->m_HostPar.at(host)->hostState.append(softVec.at(0)->hostState);
			m_DataInstance->m_HostPar.at(host)->hostMT.append(softVec.at(0)->hostMainboardT);
			m_DataInstance->m_HostPar.at(host)->hostCT.append(softVec.at(0)->hostCpuT);
			m_DataInstance->m_HostPar.at(host)->hostHT.append(softVec.at(0)->hostHarddiskT);
			m_DataInstance->m_HostPar.at(host)->hostCOR.append(softVec.at(0)->hostComputeOR);
			m_DataInstance->m_HostPar.at(host)->hostMOR.append(softVec.at(0)->hostMemoryOR);
			m_DataInstance->m_HostPar.at(host)->hostBOR.append(softVec.at(0)->hostBandwidthOR);
			m_DataInstance->m_HostPar.at(host)->hostSOR.append(softVec.at(0)->hostStorageOR);
		}
		else{
			qDebug() << "!!error!!dont have this host!!" << endl;
		}
	}

	//�������е������������ʷ����
	for (int software = 0; software < m_DataInstance->SelectAllsoftwareID().size(); software++){
		QString softwareID = m_DataInstance->m_SoftwarePar.at(software)->softwareID;//�õ����ID
		//�������id�����ض�Ӧ�����
		SoftwareData *soft = m_DataInstance->SelectBysoftwareID(softwareID);
		if (soft != NULL) { //��֤�����
            //�����Ӧʱ�����ʷֵ
			m_DataInstance->m_SoftwarePar.at(software)->softwareState.append(soft->softwareStorageOR);
			m_DataInstance->m_SoftwarePar.at(software)->softwareCOR.append(soft->softwareComputeOR);
			m_DataInstance->m_SoftwarePar.at(software)->softwareMOR.append(soft->softwareMemoryOR);
			m_DataInstance->m_SoftwarePar.at(software)->softwareBOR.append(soft->softwareBandwidthOR);
			m_DataInstance->m_SoftwarePar.at(software)->softwareSOR.append(soft->softwareStorageOR);
		}
		else{
			qDebug() << "!!error!!dont have this software!!" << endl;
		}
	}
}

void GenerateData::printMsg(){
	//��ȡϵͳ���ڵ�ʱ��
	QDateTime time = QDateTime::currentDateTime();
	//����ϵͳʱ����ʾ��ʽ
	QString qstr = time.toString("yyyy-MM-dd hh:mm:ss");
	qDebug() << "************************" << qstr << "*********************" << endl;

	qDebug() << count << "  " << m_DataInstance->m_SoftWareData.at(0)->cabinT;
	qDebug() << count << "  " << m_DataInstance->m_SoftWareData.at(4)->cabinH;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->cabinH;

	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostMainboardT;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostHarddiskT;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostCpuT;

	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostState;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostComputeOR;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostBandwidthOR;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostMemoryOR;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->hostStorageOR;


	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->softwareHeartBeat;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->softwareComputeOR;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->softwareBandwidthOR;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->softwareMemoryOR;
	//qDebug() << m_DataInstance->m_SoftWareData.at(0)->softwareStorageOR;
	//��ʾ������Ϣ
	//m_DataInstance->m_SoftWareData.at(0)->showData();

	//��ʾһ��ĳһ���б����Ϣ
	qDebug() << "..........list start...........";
	for (int i = 0; i < m_DataInstance->m_CabinPar.at(0)->cabinT.size(); i++){
		qDebug() << m_DataInstance->m_CabinPar.at(0)->cabinT.at(i);
	}
	qDebug() << "...........list end..........";
}