#include "SysControl.h"
#include "QDocument.h"
#include <QtWidgets/QApplication>
QDocument *QDocument::m_DataInstance = new QDocument();  //单例模式数据类全局实例化
QDocument::GC QDocument::gc;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SysControl syscontrol;
	syscontrol.InitSys();
	syscontrol.m_inwidget->show();
	return a.exec();
}
