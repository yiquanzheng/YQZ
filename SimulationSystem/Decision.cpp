#include "Decision.h"

Decision::Decision(QObject * parent) : QObject(parent)
{
	subscriber = new Subscriber();
	m_participant = DDSTheParticipantFactory->create_participant(0, DDS_PARTICIPANT_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);	// 创建域参与者
	subscriber->startupParticipant(m_participant);
}

Decision::~Decision()
{
	subscriber->shutdownParticipant(m_participant);
}