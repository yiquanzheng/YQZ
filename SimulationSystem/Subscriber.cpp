#include "Subscriber.h"
#include <QDebug>

// �������ݽ����¼�
void SoftwareStateListener::on_data_available(DDSDataReader *reader)
{
	SoftwareStateDataReader *softwareReader = NULL;
	SoftwareStateSeq data_seq;
	DDS_SampleInfoSeq info_seq;
	DDS_ReturnCode_t retCode = DDS_RETCODE_OK;

	// ��ȡ���ݶ���
	softwareReader = SoftwareStateDataReader::narrow(reader);
	if (softwareReader == NULL) {
		qDebug() << "DataReader narrow error";
		return;
	}
	// �����ݶ�����ȡδ�����ݵ�data_seq��
	retCode = softwareReader->take(data_seq, info_seq);
	// �жϲ�����״̬
	if (retCode == DDS_RETCODE_NO_DATA) {
		return;
	}
	else if (retCode != DDS_RETCODE_OK) {
		qDebug() << "take error";
		return;
	}
	
	for (int i = 0; i < data_seq.length(); i++) {
		if (info_seq[i].valid_data) {		// ����Ӧ���������Ƿ���Ч
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

	// -----------�������⣨���״̬��-----------
	// ע���������ͣ�SoftwareState
	typeName = SoftwareStateTypeSupport::get_type_name();
	retCode = SoftwareStateTypeSupport::register_type(participant, typeName);
	if (retCode != DDS_RETCODE_OK)
	{
		qDebug() << "register_type error " << retCode;
		shutdownParticipant(participant);
		return -1;
	}
	// ��������:SoftwareState
	topic = participant->create_topic("SoftwareState", typeName, DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
	if (topic == NULL)
	{
		qDebug() << "create topic error ";
		shutdownParticipant(participant);
		return -1;
	}
	// �������ݶ���
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

	// --------------ɾ����������д�����ʵ��-------------
	retCode = participant->delete_contained_entities();
	if (retCode != DDS_RETCODE_OK)
	{
		qDebug() << "delete_contained_entities error " << retCode;
		status = -1;
	}

	// ----------------�������ݶ��߼�����-----------------
	if (m_softwareStateReaderListener != NULL) {
		delete m_softwareStateReaderListener;
		m_softwareStateReaderListener = NULL;
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
