#include "ShipEnvironment.h"

using namespace std;


ShipEnvironment::ShipEnvironment(QObject *parent) : QObject(parent)
{
	m_DataInstance = QDocument::getInstance();
	srand((unsigned)time(NULL));
	init();
}


ShipEnvironment::~ShipEnvironment()
{
}

void ShipEnvironment::setShipEnv(ShipEnv shipEnv)
{
	this->m_shipEnv = shipEnv;
}

ShipEnv ShipEnvironment::getShipEnv()
{
	return this->m_shipEnv;
}

//ShipEnv ShipEnvironment::normal()
//{
//	return getShipEnv();
//}

void ShipEnvironment::missileDetected()
{
	if (this->m_shipEnv.missileTag == false)
	{
		// 舰艇检测范围100km
		this->m_shipEnv.missileTag = true;
		this->m_shipEnv.missileX = rand() % 201 / 111.0 * cos(this->m_shipEnv.shipY) + this->m_shipEnv.shipX;
		this->m_shipEnv.missileY = rand() % 201 / 111.0 + this->m_shipEnv.shipY;
		this->m_shipEnv.missileSpeed = rand() % 101 + 900.0;
		this->m_shipEnv.missileD = rand() % 101 / 100.0 * 360;
	}
	else
	{
		ShipEnv temp = this->m_shipEnv;
		// 导弹1s移动的距离
		float distance = temp.missileSpeed / 3600.0;
		this->m_shipEnv.missileX = temp.missileX + distance * sin(temp.missileD) / (111.0 * cos(temp.missileY));
		this->m_shipEnv.missileY = temp.missileY + distance * cos(temp.missileD) / 111.0;
	}

	// 写入数据缓冲区
	writeData();
}

void ShipEnvironment::init()
{
	this->m_shipEnv.missileX = 0.0;
	this->m_shipEnv.missileY = 0.0;
	this->m_shipEnv.missileSpeed = 0.0;
	this->m_shipEnv.missileD = 0.0;									// 导弹速度[900, 1000]
	this->m_shipEnv.missileTag = false;

	// 高精度浮点数生成
	uniform_real_distribution<float> u(-90, 90);					// 生成在[-90, 90]上均匀分布的随机数
	mt19937 engine((unsigned)time(NULL));							// 产生随机数
	this->m_shipEnv.shipX = u(engine) * 2.0;
	this->m_shipEnv.shipY = u(engine);
	this->m_shipEnv.shipSpeed = rand() % 101 / 100.0 * 20 + 30;			// 船速[30, 50]
	this->m_shipEnv.shipD = rand() % 101 / 100.0 * 360;
	this->m_shipEnv.shipLength = 50.0;

	writeData();
}

void ShipEnvironment::writeData()
{
	QVector<QString> softwareIDs = m_DataInstance->SelectAllsoftwareID();
	for (int i = 0; i < softwareIDs.size(); i++)
	{
		SoftwareData * software = m_DataInstance->SelectBysoftwareID(softwareIDs.at(i));
		software->missileX = this->m_shipEnv.missileX;
		software->missileY = this->m_shipEnv.missileY;
		software->missileSpeed = this->m_shipEnv.missileSpeed;
		software->missileD = this->m_shipEnv.missileD;
		software->missileTag = this->m_shipEnv.missileTag;
		software->shipX = this->m_shipEnv.shipX;
		software->shipY = this->m_shipEnv.shipY;
		software->shipSpeed = this->m_shipEnv.shipSpeed;
		software->shipD = this->m_shipEnv.shipD;
		software->shipLength = this->m_shipEnv.shipLength;
		m_DataInstance->SetBysoftware(softwareIDs.at(i), software);
	}
}