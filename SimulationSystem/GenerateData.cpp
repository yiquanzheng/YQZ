#include "GenerateData.h"
#include <QDebug>

GenerateData::GenerateData(QObject * parent) : QObject(parent)
{
	m_DataInstance = QDocument::getInstance();  //已经获得了数据操作类对象
	timer1 = new QTimer(this);
	//关联定时器溢出信号和相应的槽函数
	connect(timer1, &QTimer::timeout, this, &GenerateData::changeData);
	timer1->setInterval(1000);//1秒,还没有start

	srand((unsigned)time(NULL));

	//==================================
	publisher = new Publisher();
	m_participant = DDSTheParticipantFactory->create_participant(0, DDS_PARTICIPANT_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);	// 创建域参与者
	publisher->startupParticipant(m_participant);		// 启动DDS服务，实例化DDS实体
	//==================================
}

GenerateData::~GenerateData()
{

}

void GenerateData::simulation()
{
	timer1->stop();
	count = 0;
	m_ship = new ShipEnvironment(); //定义一个舰艇类，并且赋初始值

									//先产生舱室的温度、湿度，在分配到每个舱室下的所有软件
	QVector<QString> cabinIdVector = m_DataInstance->SelectAllcabinID();
	//遍历所有舱室
	for (int i = 0; i < cabinIdVector.size(); i++) {
		QString cabinId = cabinIdVector.at(i);
		//获得舱室的配置值
		float normal_cabinT = m_DataInstance->m_NormalValue->cabinT;
		float normal_cabinH = m_DataInstance->m_NormalValue->cabinH;
		//假设所有舱室正常值都一样
		//float cabinT = normal_cabinT;
		//float cabinH = normal_cabinH;

		/*
		或者正常值是波动的随机值
		*/
		float cabinT = int(rand() % (8)) + (normal_cabinT - 4);                  //    35+/-4
		float cabinH = float(rand() % (40)) / 100.0 + (normal_cabinH - 0.2);     //   0.5+/-0.2

																				 //赋值给舱室里的所有软件
		QVector<SoftwareData *> softWareVec = m_DataInstance->SelectBycabinID(cabinId);
		for (int j = 0; j < softWareVec.size(); j++) {

			softWareVec.at(j)->cabinT = cabinT;
			softWareVec.at(j)->cabinH = cabinH;

			//最后set回去
			m_DataInstance->SetBysoftware(softWareVec.at(j)->softwareID, softWareVec.at(j));
		}
	}

	//先生成随机的主机资源占用比，然后为软件的资源占用比赋值，每个软件等于所属主机资源占用比的平均数
	QVector<QString> hostIdVector = m_DataInstance->SelectAllhostID();
	//遍历所有的主机
	for (int i = 0; i < hostIdVector.size(); i++)
	{
		QString hostId = hostIdVector.at(i);

		//获得主机温度的配置值
		float normal_hostMainboardT = m_DataInstance->m_NormalValue->hostMainboardT;
		float normal_hostCpuT = m_DataInstance->m_NormalValue->hostCpuT;
		float normal_hostHarddiskT = m_DataInstance->m_NormalValue->hostHarddiskT;
		//假设所有主机正常值都一样
		//float hostMainboardT = normal_hostMainboardT;
		//float hostCpuT = normal_hostCpuT;
		//float hostHarddiskT = normal_hostHarddiskT;

		/*
		或者正常值是波动的随机值
		*/
		float hostMainboardT = int(rand() % (8)) + (normal_hostMainboardT - 4);                  //    35+/-4
		float hostCpuT = int(rand() % (8)) + (normal_hostCpuT - 4);                              //    35+/-4
		float hostHarddiskT = int(rand() % (8)) + (normal_hostHarddiskT - 4);                    //    35+/-4

																								 //主机状态
		bool hostState = true;
		//软件心跳
		bool softwareHeartBeat = true;

		//产生随机的主机资源占用比
		float gap = 0.2;
		float normal = 0.0;
		//主机计算资源
		normal = m_DataInstance->m_NormalValue->hostComputeOR;
		float hostComputeOR = float(rand() % (40)) / 100.0 + (normal - gap); //(0.01-0.40之间) + 0.3
																			 //主机存储资源
		normal = m_DataInstance->m_NormalValue->hostMemoryOR;
		float hostMemoryOR = float(rand() % (40)) / 100.0 + (normal - gap);
		//主机网络资源
		normal = m_DataInstance->m_NormalValue->hostBandwidthOR;
		float hostBandwidthOR = float(rand() % (40)) / 100.0 + (normal - gap);
		//主机存储资源
		normal = m_DataInstance->m_NormalValue->hostStorageOR;
		float hostStorageOR = float(rand() % (40)) / 100.0 + (normal - gap);

		//接下来平均到 主机 下的所有软件
		QVector<SoftwareData *> softWareVec = m_DataInstance->SelectByhostID(hostId);
		int size = softWareVec.size();
		for (int j = 0; j < size; j++)
		{
			//随机的主机占用资源，直接赋值
			softWareVec.at(j)->hostComputeOR = hostComputeOR;
			softWareVec.at(j)->hostBandwidthOR = hostBandwidthOR;
			softWareVec.at(j)->hostMemoryOR = hostMemoryOR;
			softWareVec.at(j)->hostStorageOR = hostStorageOR;
			//主机温度
			softWareVec.at(j)->hostCpuT = hostCpuT;
			softWareVec.at(j)->hostHarddiskT = hostHarddiskT;
			softWareVec.at(j)->hostMainboardT = hostMainboardT;
			//主机状态和软件心跳
			softWareVec.at(j)->hostState = hostState;
			softWareVec.at(j)->softwareHeartBeat = softwareHeartBeat;
			//软件的占用资源，求平均
			softWareVec.at(j)->softwareComputeOR = hostComputeOR / size;
			softWareVec.at(j)->softwareBandwidthOR = hostBandwidthOR / size;
			softWareVec.at(j)->softwareMemoryOR = hostMemoryOR / size;
			softWareVec.at(j)->softwareStorageOR = hostStorageOR / size;

			//最后set回去
			m_DataInstance->SetBysoftware(softWareVec.at(j)->softwareID, softWareVec.at(j));
		}

	}
	/*
	for (int i = 0; i < m_DataInstance->m_SoftWareData.size(); i++)
	{
	m_DataInstance->m_SoftWareData.at(i)->showData();
	}
	*/
	clearDataList();//清空列表
	timer1->start();//开始定时器
}

//直线上升
float GenerateData::straightUp(float previous,float maxValue,float k){

	//previous等于上一秒的值
	float temp = previous + 1 * k;
	if (temp >= maxValue)
		temp = maxValue;
	return temp;
}

//直线下降
float GenerateData::straightDown(float previous, float minValue, float k){
	//previous等于上一秒的值
	float temp = previous - 1 * k;
	if (temp <= minValue)
		temp = minValue;
	return temp;
}

//二次上升函数
float GenerateData::squareUp(float previous, float maxValue, float x,float k){
    //下一秒比上一秒增加2(x-1)+1,其中x表示时间，从1开始
	float temp = previous + (2 * x + 1)*k;
	if (temp >= maxValue)
		temp = maxValue;
	return temp;
}

//跃阶函数，直接跳到0或者给定的num
float GenerateData::jumpFunction(float num){
	return num;
}

void GenerateData::changeData(){

	count++;//用来计数的，1秒加1
			//for循环来改变多个值，因为可以模拟多个故障
	for (int i = 0; i < m_DataInstance->m_FaultStateData.size(); i++)
	{
		//获得异常模式的参数
		QString id = m_DataInstance->m_FaultStateData.at(i)->ID;
		int model = m_DataInstance->m_FaultStateData.at(i)->fault_model;
		int function = m_DataInstance->m_FaultStateData.at(i)->fault_func;
		//前面的几秒钟是正常数据，之后才是异常数据
		if (count >= m_DataInstance->m_FaultStateData.at(i)->time)
		{
			switch (model)
			{
			case 1: {
				//舱室温度升高，那么id代表的是舱室ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(id);
				//获得当前舱室的下标
				int idx = m_DataInstance->SelectCabinParBycabinID(id);
				//选择该舱室的第一个软件的舱室温度，则代表该舱室的温度
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
					//直线上升
					value = straightUp(temp->cabinT, m_DataInstance->m_AbNormalValue->cabinT,
						m_DataInstance->m_CabinPar.at(idx)->cabinT_straight_k);
					break;
				}
				case 1: {
					//二次上升
							value = squareUp(temp->cabinT, m_DataInstance->m_AbNormalValue->cabinT,
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_CabinPar.at(idx)->cabinT_square_k);
					break;
				}
				default:
					break;
				}
		
				//根据舱室id,遍历每个需要修改的软件,而且修改的值是舱室温度
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					temp->cabinT = value;
					//set一下
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 2: {
				//舱室湿度升高,那么id代表的是舱室ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(id);
				//获得当前舱室的下标
				int idx = m_DataInstance->SelectCabinParBycabinID(id);
				//选择该舱室的第一个软件的舱室湿度，则代表该舱室的湿度
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//直线上升
							value = straightUp(temp->cabinH, m_DataInstance->m_AbNormalValue->cabinH, 
								m_DataInstance->m_CabinPar.at(idx)->cabinH_straight_k);
							break;
				}
				case 1: {
							//二次上升
							value = squareUp(temp->cabinH, m_DataInstance->m_AbNormalValue->cabinH, 
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_CabinPar.at(idx)->cabinH_square_k);
							break;
				}
				default:
					break;
				}
				//根据舱室id,遍历每个需要修改的软件,而且修改的值是舱室湿度
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->cabinH = value;
					//set一下
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 3: {
				//主机运行失效 ,那么id代表的是主机ID ！！！记得修改主机和软件的状态
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//跃阶函数
				float value = jumpFunction(0.0);//直接跳到0
				
				//根据主机id,遍历每个需要修改的软件,而且修改的值是主机和软件的资源占用比
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
					//set一下
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 4: {
				//软件运行失效,那么id代表的是软件ID！！！！记得修改软件的状态
				SoftwareData * softVec = m_DataInstance->SelectBysoftwareID(id);
				//根据软件id,修改的值是软件的资源占用比
				SoftwareData *temp = softVec;
				//跃阶函数
				float value = jumpFunction(0.0);//直接跳到0

				temp->softwareComputeOR = value;
				temp->softwareBandwidthOR = value;
				temp->softwareMemoryOR = value;
				temp->softwareStorageOR = value;

				temp->softwareHeartBeat = false;
				//最后set一下
				m_DataInstance->SetBysoftware(temp->softwareID, temp);
				break;
			}
			case 5: {
				//导弹来袭
				m_ship->missileDetected();
				break;
			}
			case 6: {
				//主机cpu温度升高,那么id代表的是主机ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//获得该主机的下标
				int idx = m_DataInstance->SelectHostParByhostID(id);
				//用该主机的第一个软件的主机cpu温度，作为主机cpu温度这个属性
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//直线上升
							value = straightUp(temp->hostCpuT, m_DataInstance->m_AbNormalValue->hostCpuT,
								m_DataInstance->m_HostPar.at(idx)->hostCT_straight_k);
							break;
				}
				case 1: {
							//二次上升
							value = squareUp(temp->hostCpuT, m_DataInstance->m_AbNormalValue->hostCpuT, 
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostCT_square_k);
							break;
				}
				default:
					break;
				}

				//根据主机id,遍历每个需要修改的软件,而且修改的值是主机cpu温度
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->hostCpuT = value;
					//最后set一下
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 7: {
				//硬盘温度升高，那么id代表的是主机ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//获得该主机的下标
				int idx = m_DataInstance->SelectHostParByhostID(id);
				//用该主机的第一个软件的硬盘温度，作为主机硬盘温度这个属性
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//直线上升
							value = straightUp(temp->hostHarddiskT, m_DataInstance->m_AbNormalValue->hostHarddiskT, 
								m_DataInstance->m_HostPar.at(idx)->hostHT_straight_k);
							break;
				}
				case 1: {
							//二次上升
							value = squareUp(temp->hostHarddiskT, m_DataInstance->m_AbNormalValue->hostHarddiskT,
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostHT_square_k);
							break;
				}
				default:
					break;
				}

				//根据主机id,遍历每个需要修改的软件,而且修改的值是主机硬盘温度
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->hostHarddiskT = value;
					//set一下
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 8: {
				//主板温度升高,那么id代表的是主机ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//获得该主机的下标
				int idx = m_DataInstance->SelectHostParByhostID(id);
				//用该主机的第一个软件的主板温度，作为主机主板温度这个属性
				SoftwareData *temp = softVec.at(0);
				float value = 0.0;
				switch (function)
				{
				case 0: {
							//直线上升
							value = straightUp(temp->hostMainboardT, m_DataInstance->m_AbNormalValue->hostMainboardT, 
								m_DataInstance->m_HostPar.at(idx)->hostMT_straight_k);
							break;
				}
				case 1: {
							//二次上升
							float value = squareUp(temp->hostMainboardT, m_DataInstance->m_AbNormalValue->hostMainboardT,
								count - m_DataInstance->m_FaultStateData.at(i)->time, m_DataInstance->m_HostPar.at(idx)->hostMT_square_k);
							break;
				}
				default:
					break;
				}
				
				//根据主机id,遍历每个需要修改的软件,而且修改的值是主机主板温度
				for (int j = 0; j < softVec.size(); j++)
				{
					SoftwareData *temp = softVec.at(j);
					
					temp->hostMainboardT = value;
					//set一下
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 9: {
				//主机可用资源减少,那么id代表的是主机ID
				QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(id);
				//获得该主机的下标
				int idx = m_DataInstance->SelectHostParByhostID(id);
				
				//这里因为时软件的资源占用比，所以每个软件本身的信息是不同的，所以需要循环
				//而不能简单的把第一个软件信息，代表所有的
				//根据主机id,遍历每个需要修改的软件,而且修改的值是主机和对应的软件资源占用比
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
						//直线上升
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
						//二次上升
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

					//set一下
					m_DataInstance->SetBysoftware(temp->softwareID, temp);
				}
				break;
			}
			case 10: {
				//任务变更
				break;
			}
			default:
				break;
			}
		}
	}

	//最后，需要将这一秒产生的数据，放入到list里面-----为了显示图像
	addDataList();
	
	//输出测试信息
	//printMsg();

	if (count == m_DataInstance->TotalTime)
		timer1->stop();

	emit simover();
}

void GenerateData::clearDataList()//清除历史数据list
{
	//遍历所有的舱室，清除历史数据
	for (int cabin = 0; cabin < m_DataInstance->SelectAllcabinID().size(); cabin++) {

		QString cabinID = m_DataInstance->m_CabinPar.at(cabin)->cabinID;//得到舱室的id
																		//然后根据舱室id查找所有的软件，但是只需要选取其中一个软件的cabinT等值，作为对应舱室的cabinT的值
		QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(cabinID);
		if (softVec.size() > 0) { //保证舱室有软件
			m_DataInstance->m_CabinPar.at(cabin)->cabinT.clear();
			m_DataInstance->m_CabinPar.at(cabin)->cabinH.clear();
		}
		else {
			qDebug() << "!!error!!dont have this cabin!!" << endl;
		}
	}

	//遍历所有的主机，清除历史数据
	for (int host = 0; host < m_DataInstance->SelectAllhostID().size(); host++) {
		QString hostID = m_DataInstance->m_HostPar.at(host)->hostID;//得到主机ID
																	//然后根据主机id查找对应的所有软件，但是只需要选取其中一个软件的cabinT等值，作为对应主机的cabinT的值
		QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(hostID);
		if (softVec.size() > 0) { //保证舱室有软件
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

	//遍历所有的软件，清除历史数据
	for (int software = 0; software < m_DataInstance->SelectAllsoftwareID().size(); software++) {
		QString softwareID = m_DataInstance->m_SoftwarePar.at(software)->softwareID;//得到软件ID
																					//根据软件id，返回对应的软件
		SoftwareData *soft = m_DataInstance->SelectBysoftwareID(softwareID);
		if (soft != NULL) { //保证有软件
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
	//遍历所有的舱室，保存历史数据
	for (int cabin = 0; cabin < m_DataInstance->SelectAllcabinID().size(); cabin++){

		QString cabinID = m_DataInstance->m_CabinPar.at(cabin)->cabinID;//得到舱室的id
		//然后根据舱室id查找所有的软件，但是只需要选取其中一个软件的cabinT等值，作为对应舱室的cabinT的值
		QVector<SoftwareData *> softVec = m_DataInstance->SelectBycabinID(cabinID);
		if (softVec.size() > 0) { //保证舱室有软件
			  //添加相应时间的历史值
			m_DataInstance->m_CabinPar.at(cabin)->cabinT.append(softVec.at(0)->cabinT);
			m_DataInstance->m_CabinPar.at(cabin)->cabinH.append(softVec.at(0)->cabinH);
		}
		else{
			qDebug() << "!!error!!dont have this cabin!!" << endl;
		}

	}

	//遍历所有的主机，保存历史数据
	for (int host = 0; host < m_DataInstance->SelectAllhostID().size(); host++){
		QString hostID = m_DataInstance->m_HostPar.at(host)->hostID;//得到主机ID
		//然后根据主机id查找对应的所有软件，但是只需要选取其中一个软件的cabinT等值，作为对应主机的cabinT的值
		QVector<SoftwareData *> softVec = m_DataInstance->SelectByhostID(hostID);
		if (softVec.size() > 0) { //保证舱室有软件
            //添加相应时间的历史值
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

	//遍历所有的软件，保存历史数据
	for (int software = 0; software < m_DataInstance->SelectAllsoftwareID().size(); software++){
		QString softwareID = m_DataInstance->m_SoftwarePar.at(software)->softwareID;//得到软件ID
		//根据软件id，返回对应的软件
		SoftwareData *soft = m_DataInstance->SelectBysoftwareID(softwareID);
		if (soft != NULL) { //保证有软件
            //添加相应时间的历史值
			m_DataInstance->m_SoftwarePar.at(software)->softwareState.append(soft->softwareHeartBeat);
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
	//获取系统现在的时间
	QDateTime time = QDateTime::currentDateTime();
	//设置系统时间显示格式
	QString qstr = time.toString("yyyy-MM-dd hh:mm:ss");
	qDebug() << "************************" << qstr << "*********************" << endl;

	//qDebug() << count << "  " << m_DataInstance->m_SoftWareData.at(0)->cabinT;
	//qDebug() << count << "  " << m_DataInstance->m_SoftWareData.at(4)->cabinH;
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
	//显示导弹信息
	//m_DataInstance->m_SoftWareData.at(0)->showData();

	//显示一下某一个列表的信息
	//qDebug() << "..........list start...........";
	//for (int i = 0; i < m_DataInstance->m_CabinPar.at(0)->cabinT.size(); i++){
	//	qDebug() << m_DataInstance->m_CabinPar.at(0)->cabinT.at(i);
	//}
	//qDebug() << "...........list end..........";
}