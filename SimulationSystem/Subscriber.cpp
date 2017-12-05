#include "Subscriber.h"
#include <QDebug>

// 监听数据接收事件
void SoftwareStateListener::on_data_available(DDSDataReader *reader)
{
	SoftwareStateDataReader *softwareReader = NULL;
	SoftwareStateSeq data_seq;
	DDS_SampleInfoSeq info_seq;
	DDS_ReturnCode_t retCode = DDS_RETCODE_OK;

	// 获取数据读者
	softwareReader = SoftwareStateDataReader::narrow(reader);
	if (softwareReader == NULL) {
		qDebug() << "DataReader narrow error";
		return;
	}
	// 从数据读者中取未读数据到data_seq中
	retCode = softwareReader->take(data_seq, info_seq);
	// 判断操作的状态
	if (retCode == DDS_RETCODE_NO_DATA) {
		return;
	}
	else if (retCode != DDS_RETCODE_OK) {
		qDebug() << "take error";
		return;
	}
	
	for (int i = 0; i < data_seq.length(); i++) {
		if (info_seq[i].valid_data) {		// 检查对应数据样本是否有效
			qDebug() << "Recieved Data:";
			SoftwareStateTypeSupport::print_data(&data_seq[i]);
		}
	}

	retCode = softwareReader->return_loan(data_seq, info_seq);
	if (retCode != DDS_RETCODE_OK) {
		qDebug() << "return loan error " << retCode;
	}

}

Subscriber::Subscriber(QObject* parent) : QObject(parent)
{

}

Subscriber::~Subscriber()
{

}

int Subscriber::startupParticipant(DDSDomainParticipant* participant)
{
	const char* typeName = NULL;
	DDSTopic* topic = NULL;
	DDSDataReaderListener* listener = NULL;
	DDS_ReturnCode_t retCode = DDS_RETCODE_OK;

	if (participant == NULL) {
		qDebug() << "participant is empty ";
		return -1;
	}

	// -----------发布主题（软件状态）-----------
	// 注册数据类型：SoftwareState
	typeName = SoftwareStateTypeSupport::get_type_name();
	retCode = SoftwareStateTypeSupport::register_type(participant, typeName);
	if (retCode != DDS_RETCODE_OK)
	{
		qDebug() << "register_type error " << retCode;
		shutdownParticipant(participant);
		return -1;
	}
	// 创建主题:SoftwareState
	topic = participant->create_topic("SoftwareState", typeName, DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
	if (topic == NULL)
	{
		qDebug() << "create topic error ";
		shutdownParticipant(participant);
		return -1;
	}
	// 创建数据读者
	listener = new SoftwareStateListener();
	if (listener == NULL) {
		qDebug() << "create readerListener error";
		return -1;
	}
	m_softwareStateReader = participant->create_datareader(topic, DDS_DATAREADER_QOS_DEFAULT, listener, DDS_STATUS_MASK_ALL);
	if (m_softwareStateReader == NULL) {
		qDebug() << "create datareader error";
		shutdownParticipant(participant);
		return -1;
	}
	m_softwareStateReaderListener = listener;

	participant->enable();
	return 0;
}

int Subscriber::shutdownParticipant(DDSDomainParticipant* participant)
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

	// ----------------重置数据读者监听器-----------------
	if (m_softwareStateReaderListener != NULL) {
		delete m_softwareStateReaderListener;
		m_softwareStateReaderListener = NULL;
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
