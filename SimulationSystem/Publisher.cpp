#include "Publisher.h"
#include <QDebug>

Publisher::Publisher(QObject *parent) : QObject(parent)
{
	m_DataInstance = QDocument::getInstance();			// ������ݲ��������
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

	// -----------�������⣨���״̬��-----------
	// ע���������ͣ�SoftwareState
	typeName = SoftwareStateTypeSupport::get_type_name();
	retCode = SoftwareStateTypeSupport::register_type(participant, typeName);
	if (retCode != DDS_RETCODE_OK) {
		qDebug() << "register type error " << retCode;
		shutdownParticipant(participant);
		return -1;
	}
	// �������⣺SoftwareState
	topic = participant->create_topic("SoftwareState", typeName, DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
	if (topic == NULL) {
		qDebug() << "create topic error ";
		shutdownParticipant(participant);
		return -1;
	}
	// ��������д��
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

	// ------------���÷���-------------
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
	// --------------ɾ����������д�����ʵ��-------------
	retCode = participant->delete_contained_entities();
	if (retCode != DDS_RETCODE_OK)
	{
		qDebug() << "delete_contained_entities error " << retCode;
		status = -1;
	}

	// -------------------ɾ���������--------------------
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

	// ������������
	SoftwareState *sample = SoftwareStateTypeSupport::create_data();
	if (sample == NULL) {
		qDebug() << "create_data error";
		return -1;
	}
	// ������������ֵ
	QByteArray tempString;
	tempString = software->taskID.toLatin1();		// QStringתchar*
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

	// ������������
	retCode = m_softwareStateWriter->write(*sample, DDS_HANDLE_NIL);

	if (retCode != DDS_RETCODE_OK) {
		qDebug() << "write error " << retCode;
		status = -1;
	}

	// ɾ����������
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
		publishOneSoftwareState(software);			// ���͵����������
	}
}