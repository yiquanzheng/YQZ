#pragma once
#ifndef Publisher_H
#define Publisher_H

#include <QObject>
#include "QDocument.h"
#include <QVector>

#include "TopicTypes.h"
#include "TopicTypesSupport.h"
#include "ndds/ndds_cpp.h"

class Publisher : public QObject
{
	Q_OBJECT

public:
	Publisher(QObject *parent = Q_NULLPTR);
	~Publisher();

	int startupParticipant(DDSDomainParticipant * participant);
	int shutdownParticipant(DDSDomainParticipant * participant);

public slots :
	void publishSoftwareState();	// 发布所有软件的数据

private:
	int publishOneSoftwareState(SoftwareData* software);

	QDocument *m_DataInstance;		// 数据操作类对象
	SoftwareStateDataWriter *m_softwareStateWriter;	// 软件状态写者
};

#endif // !Publisher_H
