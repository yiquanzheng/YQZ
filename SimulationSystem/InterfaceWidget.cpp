#include "InterfaceWidget.h"
#include <QTextCodec>
#include <QStringList>
InterfaceWidget::InterfaceWidget(QWidget *parent)
	: QMainWindow(parent)
{
	m_DataInstance = QDocument::getInstance();
	m_mswidget = new ModeSettingWidget();
	connect(m_mswidget, SIGNAL(updateMode()), this, SLOT(updateStateWidget()));
	ui.setupUi(this);
}

InterfaceWidget::~InterfaceWidget()
{

}

void InterfaceWidget::init()
{
	initMenuBar();
	//设置图表绘制区域
	setAllChartView();
	initparBox();
	connect(ui.modesetbtn, SIGNAL(clicked()), this, SLOT(openModeSetWidget()));
	connect(ui.startsimbtn, SIGNAL(clicked()), this, SLOT(run()));
	m_mswidget->init();
}

void InterfaceWidget::openModeSetWidget()
{
	m_mswidget->show();
	m_mswidget->setFocus();
}

void InterfaceWidget::initMenuBar()
{
	//添加顶级菜单栏
	m_editMenu = ui.menuBar->addMenu(QString::fromLocal8Bit("设置"));
	m_runMenu = ui.menuBar->addMenu(QString::fromLocal8Bit("运行"));
	m_windowMenu = ui.menuBar->addMenu(QString::fromLocal8Bit("窗口"));
	m_helpMenu = ui.menuBar->addMenu(QString::fromLocal8Bit("帮助"));
	//添加编辑菜单下可选项
	m_edit_shipxml = m_editMenu->addAction(QString::fromLocal8Bit("设置舱室配置"));
	connect(m_edit_shipxml, SIGNAL(triggered()), this, SLOT(change_shipxml()));
	m_edit_normal = m_editMenu->addAction(QString::fromLocal8Bit("设置正常值"));
	connect(m_edit_normal, SIGNAL(triggered()), this, SLOT(change_normalvalue()));
	m_edit_abnormal = m_editMenu->addAction(QString::fromLocal8Bit("设置异常值"));
	connect(m_edit_abnormal, SIGNAL(triggered()), this, SLOT(change_abnormalvalue()));
	m_editMenu->addSeparator();
	m_edit_exit = m_editMenu->addAction(QString::fromLocal8Bit("退出"));
	connect(m_edit_exit, SIGNAL(triggered()), this, SLOT(exit()));
	//添加运行菜单下可选项
	m_run = m_runMenu->addAction(QString::fromLocal8Bit("运行"));
	connect(m_run, SIGNAL(triggered()), this, SLOT(run()));
	m_run_chart = m_runMenu->addAction(QString::fromLocal8Bit("显示实时图"));
	connect(m_run_chart, SIGNAL(triggered()), this, SLOT(run_chart()));
	//添加窗口菜单下可选项
	m_maxwindow = m_windowMenu->addAction(QString::fromLocal8Bit("窗口最大化"));
	connect(m_maxwindow, SIGNAL(triggered()), this, SLOT(maxwindows()));
	m_minwindow = m_windowMenu->addAction(QString::fromLocal8Bit("窗口最小化"));
	connect(m_minwindow, SIGNAL(triggered()), this, SLOT(minwindows()));
	//添加帮助菜单下可选项
	m_help_open = m_helpMenu->addAction(QString::fromLocal8Bit("查看帮助"));
	connect(m_help_open, SIGNAL(triggered()), this, SLOT(openhelp()));
	m_help_contract = m_helpMenu->addAction(QString::fromLocal8Bit("反馈我们"));
	connect(m_help_contract, SIGNAL(triggered()), this, SLOT(contact()));
	m_help_right = m_helpMenu->addAction(QString::fromLocal8Bit("版权信息"));
	connect(m_help_right, SIGNAL(triggered()), this, SLOT(right_reserve()));
	//
	ui.menuBar->setVisible(true);
	ui.menuBar->setFixedHeight(40);
}

void InterfaceWidget::initparBox()        //初始化参数可选框
{
	parname[0] = QString::fromLocal8Bit("舱室温度");
	parname[1] = QString::fromLocal8Bit("舱室湿度");
	parname[2] = QString::fromLocal8Bit("主机在线状态");
	parname[3] = QString::fromLocal8Bit("主板温度");
	parname[4] = QString::fromLocal8Bit("CPU温度");
	parname[5] = QString::fromLocal8Bit("硬盘温度");
	parname[6] = QString::fromLocal8Bit("主机CPU占用率");
	parname[7] = QString::fromLocal8Bit("主机内存占用率");
	parname[8] = QString::fromLocal8Bit("主机带宽占用率");
	parname[9] = QString::fromLocal8Bit("主机磁盘占用率");
	parname[10] = QString::fromLocal8Bit("软件在线状态");
	parname[11] = QString::fromLocal8Bit("软件CPU占用率");
	parname[12] = QString::fromLocal8Bit("软件内存占用率");
	parname[13] = QString::fromLocal8Bit("软件带宽占用率");
	parname[14] = QString::fromLocal8Bit("软件磁盘占用率");
	pParSelect11 = parname[0];
	pParSelect12 = parname[1];
	pParSelect21 = parname[2];
	pParSelect22 = parname[10];


    //窗体11
	pParLineEdit11 = new QLineEdit(ui.selectwidget11);
	pParLineEdit11->setReadOnly(true);
	ui.parBox11->setLineEdit(pParLineEdit11);
	connect(pParLineEdit11, SIGNAL(textChanged(const QString &)), this, SLOT(showparlast11(const QString &)));
	pPosLineEdit11 = new QLineEdit(ui.selectwidget11);
	pPosLineEdit11->setReadOnly(true);
	ui.posBox11->setLineEdit(pPosLineEdit11);
	connect(pPosLineEdit11, SIGNAL(textChanged(const QString &)), this, SLOT(showposlast11(const QString &)));
	pParListWidget11 = new QListWidget(ui.selectwidget11);
	ui.parBox11->setModel(pParListWidget11->model());
	ui.parBox11->setView(pParListWidget11);
	pPosListWidget11 = new QListWidget(ui.selectwidget11);
	ui.posBox11->setModel(pPosListWidget11->model());
	ui.posBox11->setView(pPosListWidget11);
	for (int i = 0; i < 15; i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pParListWidget11);
		pParListWidget11->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget11);
		pRadioButton->setText(parname[i]);
		if (i == pParListId11)
		{
			pRadioButton->setChecked(true);
		}
		pParListWidget11->addItem(pItem);
		pParListWidget11->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(parBoxChange11()));
	}
	pParLineEdit11->setText(pParSelect11);
	pParLineEdit11->setToolTip(pParSelect11);
	setPosWidget11();


	//窗体12
	pParLineEdit12 = new QLineEdit(ui.selectwidget12);
	pParLineEdit12->setReadOnly(true);
	ui.parBox12->setLineEdit(pParLineEdit12);
	connect(pParLineEdit12, SIGNAL(textChanged(const QString &)), this, SLOT(showparlast12(const QString &)));
	pPosLineEdit12 = new QLineEdit(ui.selectwidget12);
	pPosLineEdit12->setReadOnly(true);
	ui.posBox12->setLineEdit(pPosLineEdit12);
	connect(pPosLineEdit12, SIGNAL(textChanged(const QString &)), this, SLOT(showposlast12(const QString &)));
	pParListWidget12 = new QListWidget(ui.selectwidget12);
	ui.parBox12->setModel(pParListWidget12->model());
	ui.parBox12->setView(pParListWidget12);
	pPosListWidget12 = new QListWidget(ui.selectwidget12);
	ui.posBox12->setModel(pPosListWidget12->model());
	ui.posBox12->setView(pPosListWidget12);
	for (int i = 0; i < 15; i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pParListWidget12);
		pParListWidget12->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget12);
		pRadioButton->setText(parname[i]);
		if (i == pParListId12)
		{
			pRadioButton->setChecked(true);
		}
		pParListWidget12->addItem(pItem);
		pParListWidget12->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(parBoxChange12()));
	}
	pParLineEdit12->setText(pParSelect12);
	pParLineEdit12->setToolTip(pParSelect12);
	setPosWidget12();


	//窗体21
	pParLineEdit21 = new QLineEdit(ui.selectwidget21);
	pParLineEdit21->setReadOnly(true);
	ui.parBox21->setLineEdit(pParLineEdit21);
	connect(pParLineEdit21, SIGNAL(textChanged(const QString &)), this, SLOT(showparlast21(const QString &)));
	pPosLineEdit21 = new QLineEdit(ui.selectwidget21);
	pPosLineEdit21->setReadOnly(true);
	ui.posBox21->setLineEdit(pPosLineEdit21);
	connect(pPosLineEdit21, SIGNAL(textChanged(const QString &)), this, SLOT(showposlast21(const QString &)));
	pParListWidget21 = new QListWidget(ui.selectwidget21);
	ui.parBox21->setModel(pParListWidget21->model());
	ui.parBox21->setView(pParListWidget21);
	pPosListWidget21 = new QListWidget(ui.selectwidget21);
	ui.posBox21->setModel(pPosListWidget21->model());
	ui.posBox21->setView(pPosListWidget21);
	for (int i = 0; i < 15; i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pParListWidget21);
		pParListWidget21->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget21);
		pRadioButton->setText(parname[i]);
		if (i == pParListId21)
		{
			pRadioButton->setChecked(true);
		}
		pParListWidget21->addItem(pItem);
		pParListWidget21->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(parBoxChange21()));
	}
	pParLineEdit21->setText(pParSelect21);
	pParLineEdit21->setToolTip(pParSelect21);
	setPosWidget21();


	//窗体22
	pParLineEdit22 = new QLineEdit(ui.selectwidget22);
	pParLineEdit22->setReadOnly(true);
	ui.parBox22->setLineEdit(pParLineEdit22);
	connect(pParLineEdit22, SIGNAL(textChanged(const QString &)), this, SLOT(showparlast22(const QString &)));
	pPosLineEdit22 = new QLineEdit(ui.selectwidget22);
	pPosLineEdit22->setReadOnly(true);
	ui.posBox22->setLineEdit(pPosLineEdit22);
	connect(pPosLineEdit22, SIGNAL(textChanged(const QString &)), this, SLOT(showposlast22(const QString &)));
	pParListWidget22 = new QListWidget(ui.selectwidget22);
	ui.parBox22->setModel(pParListWidget22->model());
	ui.parBox22->setView(pParListWidget22);
	pPosListWidget22 = new QListWidget(ui.selectwidget22);
	ui.posBox22->setModel(pPosListWidget22->model());
	ui.posBox22->setView(pPosListWidget22);
	for (int i = 0; i < 15; i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pParListWidget22);
		pParListWidget22->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget22);
		pRadioButton->setText(parname[i]);
		if (i == pParListId22)
		{
			pRadioButton->setChecked(true);
		}
		pParListWidget22->addItem(pItem);
		pParListWidget22->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(parBoxChange22()));
	}
	pParLineEdit22->setText(pParSelect22);
	pParLineEdit22->setToolTip(pParSelect22);
	setPosWidget22();

}

void InterfaceWidget::setAllChartView()
{
	//第一个chart
	line11 = new QLineSeries(this);
	line11->setPointsVisible(true);
	//line11->setPointLabelsFormat("@yPoint");
	//line11->setPointLabelsVisible(true);
	axisX11 = new QBarCategoryAxis();
	QStringList categories;
	for (int i = 0; i < maxshow; i++)
	{
		categories << QString::number(i+1);
	}
	axisX11->append(categories);   //设置X坐标范围   
	axisX11->setTitleText("t/s"); //设置X坐标名字  
	axisY11 = new QValueAxis; 
	axisY11->setRange(0, 100);
	chartview11 = new QChartView(this);
	chartview11->setRenderHint(QPainter::Antialiasing);
	ui.verticalLayout_2->addWidget(chartview11);
	ui.verticalLayout_2->setStretch(0, 1);
	ui.verticalLayout_2->setStretch(1, 7);
	chart11 = chartview11->chart();
	chart11->setAnimationOptions(QChart::SeriesAnimations);//设置曲线呈动画显示 
	chart11->addSeries(line11);
	chart11->addAxis(axisX11, Qt::AlignBottom);  //并且XY轴的位置是下和左  
	chart11->addAxis(axisY11, Qt::AlignLeft);
	chart11->setAxisX(axisX11, line11);
	chart11->setAxisY(axisY11, line11);
	chart11->legend()->hide();


	//第二个chart
	line12 = new QLineSeries(this);
	line12->setPointsVisible(true);
	//line12->setPointLabelsFormat("@yPoint");
	//line12->setPointLabelsVisible(true);
	axisX12 = new QBarCategoryAxis();
	axisX12->append(categories);   //设置X坐标范围   
	axisX12->setTitleText("t/s"); //设置X坐标名字  
	axisY12 = new QValueAxis();
	axisY12->setRange(0, 100);
	chartview12 = new QChartView(this);
	chartview12->setRenderHint(QPainter::Antialiasing);
	ui.verticalLayout_3->addWidget(chartview12);
	ui.verticalLayout_3->setStretch(0, 1);
	ui.verticalLayout_3->setStretch(1, 7);
	chart12 = chartview12->chart();
	chart12->setAnimationOptions(QChart::SeriesAnimations);//设置曲线呈动画显示 
	chart12->addSeries(line12);
	chart12->addAxis(axisX12, Qt::AlignBottom);  //并且XY轴的位置是下和左  
	chart12->addAxis(axisY12, Qt::AlignLeft);
	chart12->setAxisX(axisX12, line12);
	chart12->setAxisY(axisY12, line12);
	chart12->legend()->hide();


	//第三个chart
	line21 = new QLineSeries(this);
	line21->setPointsVisible(true);
	//line21->setPointLabelsFormat("@yPoint");
	//line21->setPointLabelsVisible(true);
	axisX21 = new QBarCategoryAxis();
	axisX21->append(categories);   //设置X坐标范围   
	axisX21->setTitleText("t/s"); //设置X坐标名字  
	axisY21 = new QValueAxis();
	axisY21->setRange(0, 100);
	chartview21 = new QChartView(this);
	chartview21->setRenderHint(QPainter::Antialiasing);
	ui.verticalLayout_4->addWidget(chartview21);
	ui.verticalLayout_4->setStretch(0, 1);
	ui.verticalLayout_4->setStretch(1, 7);
	chart21 = chartview21->chart();
	chart21->setAnimationOptions(QChart::SeriesAnimations);//设置曲线呈动画显示 
	chart21->addSeries(line21);
	chart21->addAxis(axisX21, Qt::AlignBottom);  //并且XY轴的位置是下和左  
	chart21->addAxis(axisY21, Qt::AlignLeft);
	chart21->setAxisX(axisX21, line21);
	chart21->setAxisY(axisY21, line21);
	chart21->legend()->hide();


	//第四个chart
	line22 = new QLineSeries(this);
	line22->setPointsVisible(true);
	//line22->setPointLabelsFormat("@yPoint");
	//line22->setPointLabelsVisible(true);
	axisX22 = new QBarCategoryAxis();
	axisX22->append(categories);   //设置X坐标范围   
	axisX22->setTitleText("t/s"); //设置X坐标名字  
	axisY22 = new QValueAxis();
	axisY22->setRange(0, 100);
	chartview22 = new QChartView(this);
	chartview22->setRenderHint(QPainter::Antialiasing);
	ui.verticalLayout->addWidget(chartview22);
	ui.verticalLayout->setStretch(0, 1);
	ui.verticalLayout->setStretch(1, 7);
	chart22 = chartview22->chart();
	chart22->setAnimationOptions(QChart::SeriesAnimations);//设置曲线呈动画显示 
	chart22->addSeries(line22);
	chart22->addAxis(axisX22, Qt::AlignBottom);  //并且XY轴的位置是下和左  
	chart22->addAxis(axisY22, Qt::AlignLeft);
	chart22->setAxisX(axisX22, line22);
	chart22->setAxisY(axisY22, line22);
	chart22->legend()->hide();
}

QList<float> InterfaceWidget::findData(int par, QString pos)
{
	int id;
	QList<float> data;
	if (par == 0 || par == 1)
	{
		//观察舱室的信息
		id = m_DataInstance->SelectCabinParBycabinID(pos);
		if (id != -1)
		{
			if (par == 0)
			{
				data = m_DataInstance->m_CabinPar.at(id)->cabinT;
			}
			else
			{
				data = m_DataInstance->m_CabinPar.at(id)->cabinH;
			}

		}
	}
	else if (par >= 2 && par <= 9)
	{
		//观察主机的信息
		id = m_DataInstance->SelectHostParByhostID(pos);
		if (id != -1)
		{
			if (par == 2)
			{
				QList<bool> data1;
				data1 = m_DataInstance->m_HostPar.at(id)->hostState;
				for (int m = 0; m < data1.size(); m++)
				{
					if (data1.at(m) == true)
					{
						data.append(1);
					}
					else
					{
						data.append(0);
					}
				}
			}
			else if (par == 3)
			{
				data = m_DataInstance->m_HostPar.at(id)->hostMT;
			}
			else if (par == 4)
			{
				data = m_DataInstance->m_HostPar.at(id)->hostCT;
			}
			else if (par == 5)
			{
				data = m_DataInstance->m_HostPar.at(id)->hostHT;
			}
			else if (par == 6)
			{
				data = m_DataInstance->m_HostPar.at(id)->hostCOR;
			}
			else if (par == 7)
			{
				data = m_DataInstance->m_HostPar.at(id)->hostMOR;
			}
			else if (par == 8)
			{
				data = m_DataInstance->m_HostPar.at(id)->hostBOR;
			}
			else
			{
				data = m_DataInstance->m_HostPar.at(id)->hostSOR;
			}
		}
	}
	else if (par >= 10 && par <= 14)
	{
		id = m_DataInstance->SelectSoftwareParBysoftwareID(pos);
		if (id != -1)
		{
			if (par == 10)
			{
				QList<bool> data1;
				data1 = m_DataInstance->m_SoftwarePar.at(id)->softwareState;
				for (int m = 0; m < data1.size(); m++)
				{
					if (data1.at(m) == true)
					{
						data.append(1);
					}
					else
					{
						data.append(0);
					}
				}
			}
			else if (par == 11)
			{
				data = m_DataInstance->m_SoftwarePar.at(id)->softwareCOR;
			}
			else if (par == 12)
			{
				data = m_DataInstance->m_SoftwarePar.at(id)->softwareMOR;
			}
			else if (par == 13)
			{
				data = m_DataInstance->m_SoftwarePar.at(id)->softwareBOR;
			}
			else
			{
				data = m_DataInstance->m_SoftwarePar.at(id)->softwareSOR;
			}
		}
	}
	else
	{
		//观察导弹信息
	}
	return data;
}

//已选状态栏更新框
void InterfaceWidget::updateStateWidget()   //已选状态栏更新
{
	qDebug() << "helleleoele!";
	faultStateList = m_mswidget->faultStateList;
	qDebug() << faultStateList;
	simtotaltime = m_mswidget->simtotaltime;
	standardItemModel = new QStandardItemModel(this);
	QStringList list;
	for (int i = 0; i < faultStateList.size(); i++)
	{
		QString s = QObject::tr("ID:") + faultStateList.at(i)->ID;
		s += QString("    ");
		s += QString::fromLocal8Bit("故障:") + faultStateList.at(i)->fault_model_name;
		s += QString("    ");
		s += QString::fromLocal8Bit("原因:") + faultStateList.at(i)->fault_func_name;
		list << s;
	}
	for (int i = 0; i < list.size(); i++)
	{
		QString string = static_cast<QString>(list.at(i));
		QStandardItem *item = new QStandardItem(string);
		if (i % 2 == 1)
		{
			QLinearGradient linearGrad(QPointF(0, 0), QPointF(200, 200));
			linearGrad.setColorAt(0, Qt::gray);
			linearGrad.setColorAt(1, Qt::gray);
			QBrush brush(linearGrad);
			item->setBackground(brush);
		}
		standardItemModel->appendRow(item);
	}
	ui.modelistView->setModel(standardItemModel);
}

void InterfaceWidget::addmodel(int i)       //添加故障模式
{

}

void InterfaceWidget::removemodel(int i)    //移除故障模式
{

}

void InterfaceWidget::change_shipxml()   //更改船的配置文件
{
	qDebug() << "change_shipxml";
}

void InterfaceWidget::change_normalvalue()  //更改正常值配置文件
{
	qDebug() << "change_normalvalue";
}

void InterfaceWidget::change_abnormalvalue()  //更改异常值配置文件
{
	qDebug() << "change_abnormalvalue";
}

void InterfaceWidget::exit()         //退出
{
	qDebug() << "exit";
}

void InterfaceWidget::run()          //运行
{
	qDebug() << "run";
	m_DataInstance->m_FaultStateData = faultStateList;
	m_DataInstance->TotalTime = simtotaltime;
	emit startsim();
}

void InterfaceWidget::run_chart()    //运行显示图表
{
	qDebug() << "run_chart";
}

void InterfaceWidget::maxwindows()   //最大化窗体
{
	qDebug() << "maxwindows";
}

void InterfaceWidget::minwindows()   //最小化窗体
{
	qDebug() << "minwindows";
}

void InterfaceWidget::openhelp()     //打开帮助
{
	qDebug() << "openhelp";
}

void InterfaceWidget::contact()     //联系我们
{
	qDebug() << "contact";
}

void InterfaceWidget::right_reserve()  //版权所有
{
	qDebug() << "right_reserve";
}

//绘制图表窗体事件
//窗体11*****************************************************
void InterfaceWidget::parBoxChange11()
{
	//设置观察参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pParListWidget11->count(); ++i)
	{
		QListWidgetItem *pItem = pParListWidget11->item(i);
		QWidget *pWidget = pParListWidget11->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pParListId11 = i;
			break;
		}
	}
	pParSelect11 = parname[pParListId11];
	pParLineEdit11->setText(pParSelect11);
	pParLineEdit11->setToolTip(pParSelect11);
	//设置第二个复选框的数值
	setPosWidget11();
}

void InterfaceWidget::showparlast11(const QString &)
{
	pParLineEdit11->setText(pParSelect11);
}

void InterfaceWidget::setPosWidget11()
{
	posname11.clear();
	if (pParListId11 == 0 || pParListId11 == 1)
	{
		//观察舱室的信息
		posname11.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllcabinID().size(); i++)
		{
			posname11.append(m_DataInstance->SelectAllcabinID().at(i));
		}
	}
	else if (pParListId11 >= 2 && pParListId11 <= 9)
	{
		//观察主机的信息
		posname11.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllhostID().size(); i++)
		{
			posname11.append(m_DataInstance->SelectAllhostID().at(i));
		}
	}
	else if (pParListId11 >= 10 && pParListId11 <= 14)
	{
		//观察软件的信息
		posname11.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllsoftwareID().size(); i++)
		{
			posname11.append(m_DataInstance->SelectAllsoftwareID().at(i));
		}
	}
	else
	{
		//观察导弹信息
	}
	//设置窗体里面的数值
	pPosListWidget11->clear();
	pPosListId11 = 0;
	for (int i = 0; i < posname11.size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pPosListWidget11);
		pPosListWidget11->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget11);
		pRadioButton->setText(posname11.at(i));
		if (i == pPosListId11)
		{
			pRadioButton->setChecked(true);
		}
		pPosListWidget11->addItem(pItem);
		pPosListWidget11->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(posBoxChange11()));
	}
	pPosSelect11 = posname11.at(pPosListId11);
	pPosLineEdit11->setText(pPosSelect11);
	pPosLineEdit11->setToolTip(pPosSelect11);
	//显示观察曲线
	drawchart11();
}

void InterfaceWidget::posBoxChange11()
{
	//设置观察参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pPosListWidget11->count(); ++i)
	{
		QListWidgetItem *pItem = pPosListWidget11->item(i);
		QWidget *pWidget = pPosListWidget11->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pPosListId11 = i;
			break;
		}
	}
	pPosSelect11 = posname11.at(pPosListId11);
	pPosLineEdit11->setText(pPosSelect11);
	pPosLineEdit11->setToolTip(pPosSelect11);
	//显示观察曲线
	drawchart11();
}

void InterfaceWidget::showposlast11(const QString &)
{
	pPosLineEdit11->setText(pPosSelect11);
}

void InterfaceWidget::drawchart11()
{
	QList<float> data = findData(pParListId11, pPosSelect11);
	//根据得到的数值设置坐标
	if (data.size() > 0)
	{
		QVector<QPointF> points;
		QStringList categories;
		if (data.size() >= maxshow)
		{
			for (int i = 0; i < maxshow; i++)
			{
				points.append(QPointF(i, data.at(data.size() - maxshow + i)));
				categories << QString::number(i + 1);
			}
		}
		else
		{
			for (int i = 0; i < data.size(); i++)
			{
				points.append(QPointF(i, data.at(i)));
				categories << QString::number(i + 1);
			}
		}
		line11->replace(points);
		axisX11->clear();
		axisX11->append(categories);
	}
	int pos = pParListId11;
	if (pos == 0 || pos == 3 || pos==4 || pos==5)
	{
		axisY11->setRange(0, 100);
		axisY11->setTickCount(6);
	}
	else if (pos == 1 || pos == 6 || pos == 7 || pos == 8 || pos == 9 || pos == 11 || pos == 12 || pos == 13 || pos == 14)
	{
		axisY11->setRange(0, 1.2);
		axisY11->setTickCount(7);
	}
	else
	{
		axisY11->setRange(-1, 2);
		axisY11->setTickCount(4);
	}
}


//窗体12**************************************************************
void InterfaceWidget::parBoxChange12()
{
	//设置观察参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pParListWidget12->count(); ++i)
	{
		QListWidgetItem *pItem = pParListWidget12->item(i);
		QWidget *pWidget = pParListWidget12->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pParListId12 = i;
			break;
		}
	}
	pParSelect12 = parname[pParListId12];
	pParLineEdit12->setText(pParSelect12);
	pParLineEdit12->setToolTip(pParSelect12);
	//设置观察值窗体
	setPosWidget12();
}

void InterfaceWidget::showparlast12(const QString &)
{
	pParLineEdit12->setText(pParSelect12);
}

void InterfaceWidget::setPosWidget12()
{
	//先获取这个相关的数值
	posname12.clear();
	if (pParListId12 == 0 || pParListId12 == 1)
	{
		//观察舱室的信息
		posname12.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllcabinID().size(); i++)
		{
			posname12.append(m_DataInstance->SelectAllcabinID().at(i));
		}
	}
	else if (pParListId12 >= 2 && pParListId12 <= 9)
	{
		//观察主机的信息
		posname12.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllhostID().size(); i++)
		{
			posname12.append(m_DataInstance->SelectAllhostID().at(i));
		}
	}
	else if (pParListId12 >= 10 && pParListId21 <= 14)
	{
		//观察软件的信息
		posname12.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllsoftwareID().size(); i++)
		{
			posname12.append(m_DataInstance->SelectAllsoftwareID().at(i));
		}
	}
	else
	{
		//观察导弹信息
	}
	//设置窗体里面的数值
	pPosListWidget12->clear();
	pPosListId12 = 0;
	for (int i = 0; i < posname12.size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pPosListWidget12);
		pPosListWidget12->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget12);
		pRadioButton->setText(posname12.at(i));
		if (i == pPosListId12)
		{
			pRadioButton->setChecked(true);
		}
		pPosListWidget12->addItem(pItem);
		pPosListWidget12->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(posBoxChange12()));
	}
	pPosSelect12 = posname12.at(pPosListId12);
	pPosLineEdit12->setText(pPosSelect12);
	pPosLineEdit12->setToolTip(pPosSelect12);
	//显示观察曲线
	drawchart12();
}

void InterfaceWidget::posBoxChange12()
{
	//设置观察参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pPosListWidget12->count(); ++i)
	{
		QListWidgetItem *pItem = pPosListWidget12->item(i);
		QWidget *pWidget = pPosListWidget12->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pPosListId12 = i;
			break;
		}
	}
	pPosSelect12 = posname12.at(pPosListId12);
	pPosLineEdit12->setText(pPosSelect12);
	pPosLineEdit12->setToolTip(pPosSelect12);
	//显示观察曲线
	drawchart12();
}

void InterfaceWidget::showposlast12(const QString &)
{
	pPosLineEdit12->setText(pPosSelect12);
}

void InterfaceWidget::drawchart12()
{
	QList<float> data = findData(pParListId12, pPosSelect12);
	//根据得到的数值设置坐标
	if (data.size() > 0)
	{
		QVector<QPointF> points;
		QStringList categories;
		if (data.size() >= maxshow)
		{
			for (int i = 0; i < maxshow; i++)
			{
				points.append(QPointF(i, data.at(data.size() - maxshow + i)));
				categories << QString::number(i + 1);
			}
		}
		else
		{
			for (int i = 0; i < data.size(); i++)
			{
				points.append(QPointF(i, data.at(i)));
				categories << QString::number(i + 1);
			}
		}
		line12->replace(points);
		axisX12->clear();
		axisX12->append(categories);
	}
	
	int pos = pParListId12;
	if (pos == 0 || pos == 3 || pos == 4 || pos == 5)
	{
		axisY12->setRange(0, 100);
		axisY12->setTickCount(6);
	}
	else if (pos == 1 || pos == 6 || pos == 7 || pos == 8 || pos == 9 || pos == 11 || pos == 12 || pos == 13 || pos == 14)
	{
		axisY12->setRange(0, 1.2);
		axisY12->setTickCount(7);
	}
	else
	{
		axisY12->setRange(-1, 2);
		axisY12->setTickCount(4);
	}
}


//窗体21**********************************************************
void InterfaceWidget::parBoxChange21()
{
	//设置观察参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pParListWidget21->count(); ++i)
	{
		QListWidgetItem *pItem = pParListWidget21->item(i);
		QWidget *pWidget = pParListWidget21->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pParListId21 = i;
			break;
		}
	}
	pParSelect21 = parname[pParListId21];
	pParLineEdit21->setText(pParSelect21);
	pParLineEdit21->setToolTip(pParSelect21);
	//设置观察值选择框
	setPosWidget21();
}

void InterfaceWidget::showparlast21(const QString &)
{
	pParLineEdit21->setText(pParSelect21);
}

void InterfaceWidget::setPosWidget21()
{
	//先获取这个相关的数值
	posname21.clear();
	if (pParListId21 == 0 || pParListId21 == 1)
	{
		//观察舱室的信息
		posname21.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllcabinID().size(); i++)
		{
			posname21.append(m_DataInstance->SelectAllcabinID().at(i));
		}
	}
	else if (pParListId21 >= 2 && pParListId21 <= 9)
	{
		//观察主机的信息
		posname21.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllhostID().size(); i++)
		{
			posname21.append(m_DataInstance->SelectAllhostID().at(i));
		}
	}
	else if (pParListId21 >= 10 && pParListId21 <= 14)
	{
		//观察软件的信息
		posname21.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllsoftwareID().size(); i++)
		{
			posname21.append(m_DataInstance->SelectAllsoftwareID().at(i));
		}
	}
	else
	{
		//观察导弹信息
	}
	//设置窗体里面的数值
	pPosListWidget21->clear();
	pPosListId21 = 0;
	for (int i = 0; i < posname21.size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pPosListWidget21);
		pPosListWidget21->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget21);
		pRadioButton->setText(posname21.at(i));
		if (i == pPosListId21)
		{
			pRadioButton->setChecked(true);
		}
		pPosListWidget21->addItem(pItem);
		pPosListWidget21->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(posBoxChange21()));
	}
	pPosSelect21 = posname21.at(pPosListId21);
	pPosLineEdit21->setText(pPosSelect21);
	pPosLineEdit21->setToolTip(pPosSelect21);
	//显示观察曲线
	drawchart21();
}

void InterfaceWidget::posBoxChange21()
{
	//设置观察参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pPosListWidget21->count(); ++i)
	{
		QListWidgetItem *pItem = pPosListWidget21->item(i);
		QWidget *pWidget = pPosListWidget21->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pPosListId21 = i;
			break;
		}
	}
	pPosSelect21 = posname21.at(pPosListId21);
	pPosLineEdit21->setText(pPosSelect21);
	pPosLineEdit21->setToolTip(pPosSelect21);
	//显示观察曲线
	drawchart21();
}

void InterfaceWidget::showposlast21(const QString &)
{
	pPosLineEdit21->setText(pPosSelect21);
}

void InterfaceWidget::drawchart21()
{
	QList<float> data = findData(pParListId21, pPosSelect21);
	//根据得到的数值设置坐标
	if (data.size() > 0)
	{
		QVector<QPointF> points;
		QStringList categories;
		if (data.size() >= maxshow)
		{
			for (int i = 0; i < maxshow; i++)
			{
				points.append(QPointF(i, data.at(data.size() - maxshow + i)));
				categories << QString::number(i + 1);
			}
		}
		else
		{
			for (int i = 0; i < data.size(); i++)
			{
				points.append(QPointF(i, data.at(i)));
				categories << QString::number(i + 1);
			}
		}
		line21->replace(points);
		axisX21->clear();
		axisX21->append(categories);
	}
	
	int pos = pParListId21;
	if (pos == 0 || pos == 3 || pos == 4 || pos == 5)
	{
		axisY21->setRange(0, 100);
		axisY21->setTickCount(6);
	}
	else if (pos == 1 || pos == 6 || pos == 7 || pos == 8 || pos == 9 || pos == 11 || pos == 12 || pos == 13 || pos == 14)
	{
		axisY21->setRange(0, 1.2);
		axisY21->setTickCount(7);
	}
	else
	{
		axisY21->setRange(-1, 2);
		axisY21->setTickCount(4);
	}
}


//窗体22***********************************************************
void InterfaceWidget::parBoxChange22()
{
	//设置参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pParListWidget22->count(); ++i)
	{
		QListWidgetItem *pItem = pParListWidget22->item(i);
		QWidget *pWidget = pParListWidget22->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pParListId22 = i;
			break;
		}
	}
	pParSelect22 = parname[pParListId22];
	pParLineEdit22->setText(pParSelect22);
	pParLineEdit22->setToolTip(pParSelect22);
	//设置观察值选择框
	setPosWidget22();
}

void InterfaceWidget::showparlast22(const QString &)
{
	pParLineEdit22->setText(pParSelect22);
}

void InterfaceWidget::setPosWidget22()
{
	//先获取这个相关的数值
	posname22.clear();
	if (pParListId22 == 0 || pParListId22 == 1)
	{
		//观察舱室的信息
		posname22.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllcabinID().size(); i++)
		{
			posname22.append(m_DataInstance->SelectAllcabinID().at(i));
		}
	}
	else if (pParListId22 >= 2 && pParListId22 <= 9)
	{
		//观察主机的信息
		posname22.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllhostID().size(); i++)
		{
			posname22.append(m_DataInstance->SelectAllhostID().at(i));
		}
	}
	else if (pParListId22 >= 10 && pParListId22 <= 14)
	{
		//观察软件的信息
		posname22.append(QString::fromLocal8Bit("不限"));
		for (int i = 0; i < m_DataInstance->SelectAllsoftwareID().size(); i++)
		{
			posname22.append(m_DataInstance->SelectAllsoftwareID().at(i));
		}
	}
	else
	{
		//观察导弹信息
	}
	//设置窗体里面的数值
	pPosListWidget22->clear();
	pPosListId22 = 0;
	for (int i = 0; i < posname22.size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pPosListWidget22);
		pPosListWidget22->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		//父窗体被关闭时候，自身的这些创建局部指针也会关闭，就不会造成内存泄露的问题
		QRadioButton *pRadioButton = new QRadioButton(ui.selectwidget22);
		pRadioButton->setText(posname22.at(i));
		if (i == pPosListId22)
		{
			pRadioButton->setChecked(true);
		}
		pPosListWidget22->addItem(pItem);
		pPosListWidget22->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(posBoxChange22()));
	}
	pPosSelect22 = posname22.at(pPosListId22);
	pPosLineEdit22->setText(pPosSelect22);
	pPosLineEdit22->setToolTip(pPosSelect22);
	//显示观察曲线
	drawchart22();
}

void InterfaceWidget::posBoxChange22()
{
	//设置观察参数选择框
	QObject *object = QObject::sender();
	for (int i = 0; i < pPosListWidget22->count(); ++i)
	{
		QListWidgetItem *pItem = pPosListWidget22->item(i);
		QWidget *pWidget = pPosListWidget22->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			pPosListId22 = i;
			break;
		}
	}
	pPosSelect22 = posname22.at(pPosListId22);
	pPosLineEdit22->setText(pPosSelect22);
	pPosLineEdit22->setToolTip(pPosSelect22);
	//显示观察曲线
	drawchart22();
}

void InterfaceWidget::showposlast22(const QString &)
{
	pPosLineEdit22->setText(pPosSelect22);
}

void InterfaceWidget::drawchart22()
{
	QList<float> data = findData(pParListId22, pPosSelect22);
	//根据得到的数值设置坐标
	if (data.size() > 0)
	{
		QVector<QPointF> points;
		QStringList categories;
		if (data.size() >= maxshow)
		{
			for (int i = 0; i < maxshow; i++)
			{
				points.append(QPointF(i, data.at(data.size() - maxshow + i)));
				categories << QString::number(i + 1);
			}
		}
		else
		{
			for (int i = 0; i < data.size(); i++)
			{
				points.append(QPointF(i, data.at(i)));
				categories << QString::number(i + 1);
			}
		}
		line22->replace(points);
		axisX22->clear();
		axisX22->append(categories);
	}
	
	int pos = pParListId22;
	if (pos == 0 || pos == 3 || pos == 4 || pos == 5)
	{
		axisY22->setRange(0, 100);
		axisY22->setTickCount(6);
	}
	else if (pos == 1 || pos == 6 || pos == 7 || pos == 8 || pos == 9 || pos == 11 || pos == 12 || pos == 13 || pos == 14)
	{
		axisY22->setRange(0, 1.2);
		axisY22->setTickCount(7);
	}
	else
	{
		axisY22->setRange(-1, 2);
		axisY22->setTickCount(4);
	}
}



//外面接口，更新显示的数据
void InterfaceWidget::updateChartData()   //更新显示的数据
{
	//窗体11
	QList<float> data = findData(pParListId11, pPosSelect11);
	if (data.size() > 0)
	{
		if (line11->pointsVector().size() == maxshow)
		{
			QVector<QPointF> points = line11->pointsVector();
			points.removeFirst();
			for (int j = 0; j < points.size(); j++)
			{
				points[j] = QPointF(j, points.at(j).y());  //让这些点的横坐标-1
			}
			points.append(QPointF(maxshow-1, data.at(data.size() - 1)));
			line11->replace(points);
			QStringList categories = axisX11->categories();
			categories.removeFirst();
			categories << QString::number(data.size());
			axisX11->clear();
			axisX11->append(categories);
		}
		else
		{
			line11->append(QPointF(data.size() - 1, data.at(data.size() - 1)));
			QStringList categories = axisX11->categories();
			categories << QString::number(data.size());
			axisX11->clear();
			axisX11->append(categories);
		}
	}
	//窗体12
	data = findData(pParListId12, pPosSelect12);
	if (data.size() > 0)
	{
		if (line12->pointsVector().size() == maxshow)
		{
			QVector<QPointF> points = line12->pointsVector();
			points.removeFirst();
			for (int j = 0; j < points.size(); j++)
			{
				points[j] = QPointF(j, points.at(j).y());  //让这些点的横坐标-1
			}
			points.append(QPointF(maxshow - 1, data.at(data.size() - 1)));
			line12->replace(points);
			QStringList categories = axisX12->categories();
			categories.removeFirst();
			categories << QString::number(data.size());
			axisX12->clear();
			axisX12->append(categories);
		}
		else
		{
			line12->append(QPointF(data.size() - 1, data.at(data.size() - 1)));
			QStringList categories = axisX12->categories();
			categories << QString::number(data.size());
			axisX12->clear();
			axisX12->append(categories);
		}
	}
	//窗体21
	data = findData(pParListId21, pPosSelect21);
	if (data.size() > 0)
	{
		if (line21->pointsVector().size() == maxshow)
		{
			QVector<QPointF> points = line21->pointsVector();
			points.removeFirst();
			for (int j = 0; j < points.size(); j++)
			{
				points[j] = QPointF(j, points.at(j).y());  //让这些点的横坐标-1
			}
			points.append(QPointF(maxshow - 1, data.at(data.size() - 1)));
			line21->replace(points);
			QStringList categories = axisX21->categories();
			categories.removeFirst();
			categories << QString::number(data.size());
			axisX21->clear();
			axisX21->append(categories);
		}
		else
		{
			line21->append(QPointF(data.size() - 1, data.at(data.size() - 1)));
			QStringList categories = axisX21->categories();
			categories << QString::number(data.size());
			axisX21->clear();
			axisX21->append(categories);
		}
	}
	//窗体22
	data = findData(pParListId22, pPosSelect22);
	if (data.size() > 0)
	{
		if (line22->pointsVector().size() == maxshow)
		{
			QVector<QPointF> points = line22->pointsVector();
			points.removeFirst();
			for (int j = 0; j < points.size(); j++)
			{
				points[j] = QPointF(j, points.at(j).y());  //让这些点的横坐标-1
			}
			points.append(QPointF(maxshow - 1, data.at(data.size() - 1)));
			line22->replace(points);
			QStringList categories = axisX22->categories();
			categories.removeFirst();
			categories << QString::number(data.size());
			axisX22->clear();
			axisX22->append(categories);
		}
		else
		{
			line22->append(QPointF(data.size() - 1, data.at(data.size() - 1)));
			QStringList categories = axisX22->categories();
			categories << QString::number(data.size());
			axisX22->clear();
			axisX22->append(categories);
		}
	}
}