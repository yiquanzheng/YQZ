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
	void publishSoftwareState();	// �����������������

private:
	int publishOneSoftwareState(SoftwareData* software);

	QDocument *m_DataInstance;		// ���ݲ��������
	SoftwareStateDataWriter *m_softwareStateWriter;	// ���״̬д��
};

#endif // !Publisher_H
