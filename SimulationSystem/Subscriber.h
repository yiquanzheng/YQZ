#pragma once
#ifndef Subscriber_H
#define Subscriber_H

#include <QObject>

#include "TopicTypes.h"
#include "TopicTypesSupport.h"
#include "ndds/ndds_cpp.h"

class SoftwareStateListener : public DDSDataReaderListener
{
public:
	virtual void on_data_available(DDSDataReader* reader);	// 监听数据接收事件
};

class Subscriber : public QObject
{
	Q_OBJECT

public:
	Subscriber(QObject * parent = NULL);
	~Subscriber();

	int startupParticipant(DDSDomainParticipant* participant);
	int shutdownParticipant(DDSDomainParticipant* participant);

private:
	DDSDataReader *m_softwareStateReader = NULL;
	DDSDataReaderListener* m_softwareStateReaderListener = NULL;

};

#endif // !Subscriber_H
