#include "SysControl.h"
#include "QDocument.h"
#include <QtWidgets/QApplication>
QDocument *QDocument::m_DataInstance = new QDocument();  //����ģʽ������ȫ��ʵ����
QDocument::GC QDocument::gc;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SysControl syscontrol;
	syscontrol.InitSys();
	syscontrol.m_inwidget->show();
	return a.exec();
}
