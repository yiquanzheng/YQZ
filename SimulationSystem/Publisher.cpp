#include "Publisher.h"
#include <QDebug>

Publisher::Publisher(QObject *parent) : QObject(parent)
{
	m_DataInstance = QDocument::getInstance();			// 获得数据操作类对象
}

Publisher::~Publisher()
{

}

int Publisher::startupParticipant(DDSDomainParticipant * participant)
{
	const char* typeName = NULL;
	DDSTopic* topic = NULL;
	DDSDataWriter* dataWriter = NULL;
	DDS_ReturnCode_t retCode = DDS_RETCODE_OK;

	if (participant == NULL)
	{
		qDebug() << "participant is empty";
		return -1;
	}

	// -----------发布主题（软件状态）-----------
	// 注册数据类型：SoftwareState
	typeName = SoftwareStateTypeSupport::get_type_name();
	retCode = SoftwareStateTypeSupport::register_type(participant, typeName);
	if (retCode != DDS_RETCODE_OK) {
		qDebug() << "register type error " << retCode;
		shutdownParticipant(participant);
		return -1;
	}
	// 创建主题：SoftwareState
	topic = participant->create_topic("SoftwareState", typeName, DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
	if (topic == NULL) {
		qDebug() << "create topic error ";
		shutdownParticipant(participant);
		return -1;
	}
	// 创建数据写者
	dataWriter = participant->create_datawriter(topic, DDS_DATAWRITER_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
	if (dataWriter == NULL) {
		qDebug() << "create datawriter error ";
		shutdownParticipant(participant);
		return -1;
	}
	m_softwareStateWriter = SoftwareStateDataWriter::narrow(dataWriter);
	if (m_softwareStateWriter == NULL) {
		qDebug() << "DataWriter narrow error ";
		shutdownParticipant(participant);
		return -1;
	}

	// ------------启用服务-------------
	participant->enable();

	return 0;
}

int Publisher::shutdownParticipant(DDSDomainParticipant * participant)
{
	DDS_ReturnCode_t retCode = DDS_RETCODE_OK;
	int status = 0;
	if (participant == NULL)
	{
		return status;
	}
	// --------------删除域参与者中创建的实体-------------
	retCode = participant->delete_contained_entities();
	if (retCode != DDS_RETCODE_OK)
	{
		qDebug() << "delete_contained_entities error " << retCode;
		status = -1;
	}

	// -------------------删除域参与者--------------------
	retCode = DDSTheParticipantFactory->delete_participant(participant);
	if (retCode != DDS_RETCODE_OK)
	{
		qDebug() << "delete_participan error " << retCode;
		status = -1;
	}
	participant = NULL;

	return status;
}

int Publisher::publishOneSoftwareState(SoftwareData* software)
{
	DDS_ReturnCode_t retCode = DDS_RETCODE_OK;
	int status = 0;

	// 创建数据样本
	SoftwareState *sample = SoftwareStateTypeSupport::create_data();
	if (sample == NULL) {
		qDebug() << "create_data error";
		return -1;
	}
	// 给数据样本赋值
	QByteArray tempString;
	tempString = software->taskID.toLatin1();		// QString转char*
	sample->taskID = tempString.data();
	sample->priority = software->priority;

	sample->missileX = software->missileX;
	sample->missileY = software->missileY;
	sample->missileSpeed = software->missileSpeed;
	sample->missileD = software->missileD;
	sample->missileTag = software->missileTag;
	sample->shipX = software->shipX;
	sample->shipY = software->shipY;
	sample->shipSpeed = software->shipSpeed;
	sample->shipD = software->shipD;
	sample->shipLength = software->shipLength;

	tempString = software->cabinID.toLatin1();
	sample->cabinID = tempString.data();
	sample->cabinH = software->cabinH;
	sample->cabinT = software->cabinT;

	tempString = software->hostID.toLatin1();
	sample->hostID = tempString.data();
	sample->hostState = software->hostState;
	sample->hostComputeOR = software->hostComputeOR;
	sample->hostMemoryOR = software->hostMemoryOR;
	sample->hostBandwidthOR = software->hostBandwidthOR;
	sample->hostStorageOR = software->hostStorageOR;
	sample->hostMainboardT = software->hostMainboardT;
	sample->hostCpuT = software->hostCpuT;
	sample->hostHarddiskT = software->hostHarddiskT;

	tempString = software->softwareID.toLatin1();
	sample->softwareID = tempString.data();
	sample->softwareComputeOR = software->softwareComputeOR;
	sample->softwareMemoryOR = software->softwareMemoryOR;
	sample->softwareBandwidthOR = software->softwareBandwidthOR;
	sample->softwareStroageOR = software->softwareStorageOR;

	// 发布数据样本
	retCode = m_softwareStateWriter->write(*sample, DDS_HANDLE_NIL);

	if (retCode != DDS_RETCODE_OK) {
		qDebug() << "write error " << retCode;
		status = -1;
	}

	// 删除数据样本
	//retCode = SoftwareStateTypeSupport::delete_data(sample);
	//if (retCode != DDS_RETCODE_OK) {
	//	qDebug() << "delete_data error " << retCode;
	//	status = -1;
	//}
	
	return status;
}

void Publisher::publishSoftwareState()
{
	QVector<QString> softwareIDs = m_DataInstance->SelectAllsoftwareID();
	for (int i = 0; i < softwareIDs.size(); i++)
	{
		SoftwareData *software = m_DataInstance->SelectBysoftwareID(softwareIDs.at(i));
		publishOneSoftwareState(software);			// 发送单个软件数据
	}
}