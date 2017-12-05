#pragma once
#ifndef Decision_H
#define Decision_H

#include <QObject>

#include "Subscriber.h"

class Decision : public QObject
{
	Q_OBJECT

public:
	Decision(QObject* parent = Q_NULLPTR);
	~Decision();

	Subscriber *subscriber;

private:
	DDSDomainParticipant *m_participant = NULL;

};

#endif // !Decision_H
