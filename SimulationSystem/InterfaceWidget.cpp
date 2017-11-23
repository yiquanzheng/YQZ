#include "InterfaceWidget.h"
#include <QTextCodec>
#include <QStringList>
InterfaceWidget::InterfaceWidget(QWidget *parent)
	: QMainWindow(parent)
{
	m_DataInstance = QDocument::getInstance();
	ui.setupUi(this);
}

InterfaceWidget::~InterfaceWidget()
{

}

void InterfaceWidget::init()
{
	initMenuBar();
	initmodeltype();
	initSettingWidget();
	ui.horizontalLayout_2->setStretchFactor(ui.groupBox, 2);
	ui.horizontalLayout_2->setStretchFactor(ui.settingwidget, 3);
	ui.horizontalLayout_2->setStretchFactor(ui.listView, 3);
	ui.verticalLayout_2->setStretchFactor(ui.errorsettingwidget, 5);
	ui.verticalLayout_2->setStretchFactor(ui.timesettingwidget, 2);
	ui.verticalLayout_2->setStretchFactor(ui.comfrimwidget, 1);
	ui.gridLayout->setColumnStretch(0, 2);
	ui.gridLayout->setColumnStretch(1, 5);
	ui.gridLayout_2->setColumnStretch(0, 1);
	ui.gridLayout_2->setColumnStretch(1, 1);
	ModelList.append(ui.radioButton);
	ModelList.append(ui.radioButton_2);
	ModelList.append(ui.radioButton_3);
	ModelList.append(ui.radioButton_4);
	ModelList.append(ui.radioButton_5);
	ModelList.append(ui.radioButton_6);
	ModelList.append(ui.radioButton_7);
	ModelList.append(ui.radioButton_8);
	ModelList.append(ui.radioButton_9);
	ModelList.append(ui.radioButton_10);
	for (int i = 0; i < ModelList.size(); i++)
	{
		connect(ModelList.at(i), SIGNAL(clicked(bool)), this, SLOT(faultModelSelected()));
	}
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

void InterfaceWidget::initmodeltype()
{
	faultmodelname[0] = QString::fromLocal8Bit("舱室温度升高");
	faultmodelname[1] = QString::fromLocal8Bit("舱室湿度升高");
	faultmodelname[2] = QString::fromLocal8Bit("主机运行失效");
	faultmodelname[3] = QString::fromLocal8Bit("软件运行失效");
	faultmodelname[4] = QString::fromLocal8Bit("导弹来袭");
	faultmodelname[5] = QString::fromLocal8Bit("主机CPU温度升高");
	faultmodelname[6] = QString::fromLocal8Bit("主机硬盘温度升高");
	faultmodelname[7] = QString::fromLocal8Bit("主板主板温度升高");
	faultmodelname[8] = QString::fromLocal8Bit("主机可用资源减少");
	faultmodelname[9] = QString::fromLocal8Bit("任务优先级变更");
	QVector<QString> modeltype1;    //舱室温度上升可选项
	modeltype1.append(QString::fromLocal8Bit("舱室起火"));
	modeltype1.append(QString::fromLocal8Bit("空调失效"));
	QVector<QString> modeltype2;    //舱室进水可选项
	modeltype2.append(QString::fromLocal8Bit("舱室进水"));
	QVector<QString> modeltype3;   //主机运行时失效可选项
	modeltype3.append(QString::fromLocal8Bit("主机运行失效"));
	QVector<QString> modeltype4;   //主机运行时失效可选项
	modeltype4.append(QString::fromLocal8Bit("软件运行失效"));
	QVector<QString> modeltype5;   //导弹来袭
	modeltype5.append(QString::fromLocal8Bit("导弹来袭"));
	QVector<QString> modeltype6;   //主机CPU温度升高
	modeltype6.append(QString::fromLocal8Bit("CPU超频使用"));
	modeltype6.append(QString::fromLocal8Bit("风扇散热不好"));
	modeltype6.append(QString::fromLocal8Bit("主机起火"));
	QVector<QString> modeltype7;   //主机硬盘温度升高
	modeltype7.append(QString::fromLocal8Bit("硬盘读写频繁"));
	modeltype7.append(QString::fromLocal8Bit("风扇散热不好"));
	modeltype7.append(QString::fromLocal8Bit("主机起火"));
	QVector<QString> modeltype8;   //主机主板温度升高
	modeltype8.append(QString::fromLocal8Bit("固件老化灰尘多"));
	modeltype8.append(QString::fromLocal8Bit("风扇散热不好"));
	modeltype8.append(QString::fromLocal8Bit("主机起火"));
	QVector<QString> modeltype9;
	modeltype9.append(QString::fromLocal8Bit("软件运行占用资源过多"));
	QVector<QString> modeltype10;
	modeltype10.append(QString::fromLocal8Bit("任务优先级变更"));

	modeltype.append(modeltype1);
	modeltype.append(modeltype2);
	modeltype.append(modeltype3);
	modeltype.append(modeltype4);
	modeltype.append(modeltype5);
	modeltype.append(modeltype6);
	modeltype.append(modeltype7);
	modeltype.append(modeltype8);
	modeltype.append(modeltype9);
	modeltype.append(modeltype10);
}

void InterfaceWidget::initSettingWidget()           //初始化下拉列表框内容
{
	//更改可选模式相关项
	pModelLineEdit = new QLineEdit(this);
	pModelLineEdit->setReadOnly(true);
	ui.modelBox->setLineEdit(pModelLineEdit);
	connect(pModelLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(modeltextChanged(const QString &)));
	pModelListWidget = new QListWidget(this);
	ui.modelBox->setModel(pModelListWidget->model());
	ui.modelBox->setView(pModelListWidget);

	//更改舱室选择相关项
	pCabinLineEdit = new QLineEdit(this);
	pCabinLineEdit->setReadOnly(true);
	ui.cabinBox->setLineEdit(pCabinLineEdit);
	connect(pCabinLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(cabintextChanged(const QString &)));
	pCabinListWidget = new QListWidget(this);
	ui.cabinBox->setModel(pCabinListWidget->model());
	ui.cabinBox->setView(pCabinListWidget);

	//更改主机选择相关项
	pHostLineEdit = new QLineEdit(this);
	pHostLineEdit->setReadOnly(true);
	ui.hostBox->setLineEdit(pHostLineEdit);
	connect(pHostLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(hosttextChanged(const QString &)));
	pHostListWidget = new QListWidget(this);
	ui.hostBox->setModel(pHostListWidget->model());
	ui.hostBox->setView(pHostListWidget);

	//更改软件选择相关项
	pSoftwareLineEdit = new QLineEdit(this);
	pSoftwareLineEdit->setReadOnly(true);
	ui.softwareBox->setLineEdit(pSoftwareLineEdit);
	connect(pSoftwareLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(softwaretextChanged(const QString &)));
	pSoftwareListWidget = new QListWidget(this);
	ui.softwareBox->setModel(pSoftwareListWidget->model());
	ui.softwareBox->setView(pSoftwareListWidget);
	
	//默认设置一个初始选择
	for (int i = 0; i < 10; i++)
	{
		modelSelect[i] = modeltype.at(i).at(0);
	}

	//设置按钮值
	connect(ui.comfrim, SIGNAL(clicked(bool)), this, SLOT(comfrim()));
	connect(ui.clear, SIGNAL(clicked(bool)), this, SLOT(clear()));

}

void InterfaceWidget::faultModelSelected()   //模式选择复选框事件
{
	for (int i = 0; i < ModelList.size(); i++)
	{
		if (sender() == ModelList.at(i))
		{
			m_Last_Faultmodel = i+1;
			ui.modelBox->setEnabled(false);
			ui.hostBox->setEnabled(false);
			ui.cabinBox->setEnabled(false);
			ui.softwareBox->setEnabled(false);
			showSettingWidget();
			break;
		}
	}
}


void InterfaceWidget::showSettingWidget()     //显示故障模式
{
	switch (m_Last_Faultmodel)
	{
	case 1:
		ui.modelBox->setEnabled(true);
		ui.cabinBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 2:
		ui.modelBox->setEnabled(true);
		ui.cabinBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 3:
		ui.modelBox->setEnabled(true);
		ui.hostBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 4:
		ui.modelBox->setEnabled(true);
		ui.softwareBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 5:
		ui.modelBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 6:
		ui.modelBox->setEnabled(true);
		ui.hostBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 7:
		ui.modelBox->setEnabled(true);
		ui.hostBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 8:
		ui.modelBox->setEnabled(true);
		ui.hostBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 9:
		ui.modelBox->setEnabled(true);
		ui.hostBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	case 10:
		ui.modelBox->setEnabled(true);
		setmodelBox();
		setcabinBox();
		sethostBox();
		setsoftwareBox();
		break;
	default:
		break;
	}
}


//模式选择框相关事件
void InterfaceWidget::setmodelBox()       //设置模式复选框
{
	pModelListWidget->clear();
	for (int i = 0; i < modeltype.at(m_Last_Faultmodel-1).size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pModelListWidget);
		pModelListWidget->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		QRadioButton *pRadioButton = new QRadioButton(this);
		pRadioButton->setText(modeltype.at(m_Last_Faultmodel - 1).at(i));
		if (modelSelect[m_Last_Faultmodel - 1] == modeltype.at(m_Last_Faultmodel - 1).at(i))
		{
			pRadioButton->setChecked(true);
		}
		pModelListWidget->addItem(pItem);
		pModelListWidget->setItemWidget(pItem, pRadioButton);
		connect(pRadioButton, SIGNAL(clicked(bool)), this, SLOT(modelChanged()));
	}
	pModelLineEdit->setText(modelSelect[m_Last_Faultmodel - 1]);
	pModelLineEdit->setToolTip(modelSelect[m_Last_Faultmodel - 1]);
}

void InterfaceWidget::modelChanged()
{
	QString strSelectedData("");
	int nCount = pModelListWidget->count();
	QObject *object = QObject::sender();
	for (int i = 0; i < nCount; ++i)
	{
		QListWidgetItem *pItem = pModelListWidget->item(i);
		QWidget *pWidget = pModelListWidget->itemWidget(pItem);
		QRadioButton *pCheckBox = (QRadioButton *)pWidget;
		if (sender() == pCheckBox)
		{
			strSelectedData.append(modeltype.at(m_Last_Faultmodel - 1).at(i));
		}
	}
	modelSelect[m_Last_Faultmodel - 1] = strSelectedData;
	pModelLineEdit->setText(modelSelect[m_Last_Faultmodel - 1]);
	pModelLineEdit->setToolTip(modelSelect[m_Last_Faultmodel - 1]);
}

void InterfaceWidget::modeltextChanged(const QString &text)
{
	pModelLineEdit->setText(modelSelect[m_Last_Faultmodel - 1]);
}

//舱室选择框相关事件
void InterfaceWidget::setcabinBox()       //设置舱室复选框
{
	pCabinListWidget->clear();
	QVector<QString> AllcabinID = m_DataInstance->SelectAllcabinID();
	QString selectcabin = cabinSelect[m_Last_Faultmodel - 1];
	QStringList tempcabin = selectcabin.split(";");
	for (int i = 0; i < AllcabinID.size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pCabinListWidget);
		pCabinListWidget->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		QCheckBox *pCheckBox = new QCheckBox(this);
		pCheckBox->setText(AllcabinID.at(i));
		for (int j = 0; j < tempcabin.size(); j++)
		{
			if (AllcabinID.at(i) == tempcabin.at(j))
			{
				pCheckBox->setChecked(true);
				break;
			}
		}
		pCabinListWidget->addItem(pItem);
		pCabinListWidget->setItemWidget(pItem, pCheckBox);
		connect(pCheckBox, SIGNAL(clicked(bool)), this, SLOT(cabinChanged()));
	}
	pCabinLineEdit->setText(selectcabin);
	pCabinLineEdit->setToolTip(selectcabin);
}

void InterfaceWidget::cabinChanged()     //改变舱室相关选项
{
	QString strSelectedData("");
	int nCount = pCabinListWidget->count();
	for (int i = 0; i < nCount; ++i)
	{
		QListWidgetItem *pItem = pCabinListWidget->item(i);
		QWidget *pWidget = pCabinListWidget->itemWidget(pItem);
		QCheckBox *pCheckBox = (QCheckBox *)pWidget;
		if (pCheckBox->isChecked())
		{
			QString strText = pCheckBox->text();
			strSelectedData.append(strText).append(";");
		}
		//所点击的复选框
		if (sender() == pCheckBox)
		{
			int nData = pItem->data(Qt::UserRole).toInt();
			qDebug() << QString("I am sender...id : %1").arg(nData);
		}
	}
	if (strSelectedData.endsWith(";"))
		strSelectedData.remove(strSelectedData.count() - 1, 1);
	cabinSelect[m_Last_Faultmodel - 1] = strSelectedData;
	if (!strSelectedData.isEmpty())
	{
		pCabinLineEdit->setText(strSelectedData);
		pCabinLineEdit->setToolTip(strSelectedData);
	}
	else
	{
		pCabinLineEdit->clear();
	}
}

void InterfaceWidget::cabintextChanged(const QString &text)      //舱室框内容更新
{
	if (cabinSelect[m_Last_Faultmodel - 1] != "")
	{
		pCabinLineEdit->setText(cabinSelect[m_Last_Faultmodel - 1]);
	}
}

//主机选择框相关事件
void InterfaceWidget::sethostBox()        //设置主机复选框
{
	pHostListWidget->clear();
	QVector<QString> AllhostID = m_DataInstance->SelectAllhostID();
	QString selecthost = hostSelect[m_Last_Faultmodel - 1];
	QStringList temphost = selecthost.split(";");
	for (int i = 0; i < AllhostID.size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pHostListWidget);
		pHostListWidget->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		QCheckBox *pCheckBox = new QCheckBox(this);
		pCheckBox->setText(AllhostID.at(i));
		for (int j = 0; j < temphost.size(); j++)
		{
			if (AllhostID.at(i) == temphost.at(j))
			{
				pCheckBox->setChecked(true);
				break;
			}
		}
		pHostListWidget->addItem(pItem);
		pHostListWidget->setItemWidget(pItem, pCheckBox);
		connect(pCheckBox, SIGNAL(clicked(bool)), this, SLOT(hostChanged()));
	}
	pHostLineEdit->setText(selecthost);
	pHostLineEdit->setToolTip(selecthost);
}

void InterfaceWidget::hostChanged()     //改变主机相关选项
{
	QString strSelectedData("");
	int nCount = pHostListWidget->count();
	for (int i = 0; i < nCount; ++i)
	{
		QListWidgetItem *pItem = pHostListWidget->item(i);
		QWidget *pWidget = pHostListWidget->itemWidget(pItem);
		QCheckBox *pCheckBox = (QCheckBox *)pWidget;
		if (pCheckBox->isChecked())
		{
			QString strText = pCheckBox->text();
			strSelectedData.append(strText).append(";");
		}
		//所点击的复选框
		if (sender() == pCheckBox)
		{
			int nData = pItem->data(Qt::UserRole).toInt();
			qDebug() << QString("I am sender...id : %1").arg(nData);
		}
	}
	if (strSelectedData.endsWith(";"))
		strSelectedData.remove(strSelectedData.count() - 1, 1);
	hostSelect[m_Last_Faultmodel - 1] = strSelectedData;
	if (!strSelectedData.isEmpty())
	{
		pHostLineEdit->setText(strSelectedData);
		pHostLineEdit->setToolTip(strSelectedData);
	}
	else
	{
		pHostLineEdit->clear();
	}
}

void InterfaceWidget::hosttextChanged(const QString &text)       //主机框内容更新
{
	if (hostSelect[m_Last_Faultmodel - 1] != "")
	{
		pHostLineEdit->setText(hostSelect[m_Last_Faultmodel - 1]);
	}
}

//软件选择框相关事件
void InterfaceWidget::setsoftwareBox()    //设置软件复选框
{
	pSoftwareListWidget->clear();
	QVector<QString> AllsoftwareID = m_DataInstance->SelectAllsoftwareID();
	QString selectsoftware = softwareSelect[m_Last_Faultmodel - 1];
	QStringList tempsoftware = selectsoftware.split(";");
	for (int i = 0; i < AllsoftwareID.size(); i++)
	{
		QListWidgetItem *pItem = new QListWidgetItem(pSoftwareListWidget);
		pSoftwareListWidget->addItem(pItem);
		pItem->setData(Qt::UserRole, i);
		QCheckBox *pCheckBox = new QCheckBox(this);
		pCheckBox->setText(AllsoftwareID.at(i));
		for (int j = 0; j < tempsoftware.size(); j++)
		{
			if (AllsoftwareID.at(i) == tempsoftware.at(j))
			{
				pCheckBox->setChecked(true);
				break;
			}
		}
		pSoftwareListWidget->addItem(pItem);
		pSoftwareListWidget->setItemWidget(pItem, pCheckBox);
		connect(pCheckBox, SIGNAL(clicked(bool)), this, SLOT(softwareChanged()));
	}
	pSoftwareLineEdit->setText(selectsoftware);
	pSoftwareLineEdit->setToolTip(selectsoftware);
}

void InterfaceWidget::softwareChanged()     //改变软件相关选项
{
	QString strSelectedData("");
	int nCount = pSoftwareListWidget->count();
	for (int i = 0; i < nCount; ++i)
	{
		QListWidgetItem *pItem = pSoftwareListWidget->item(i);
		QWidget *pWidget = pSoftwareListWidget->itemWidget(pItem);
		QCheckBox *pCheckBox = (QCheckBox *)pWidget;
		if (pCheckBox->isChecked())
		{
			QString strText = pCheckBox->text();
			strSelectedData.append(strText).append(";");
		}
		//所点击的复选框
		if (sender() == pCheckBox)
		{
			int nData = pItem->data(Qt::UserRole).toInt();
			qDebug() << QString("I am sender...id : %1").arg(nData);
		}
	}
	if (strSelectedData.endsWith(";"))
		strSelectedData.remove(strSelectedData.count() - 1, 1);
	softwareSelect[m_Last_Faultmodel - 1] = strSelectedData;
	if (!strSelectedData.isEmpty())
	{
		pSoftwareLineEdit->setText(strSelectedData);
		pSoftwareLineEdit->setToolTip(strSelectedData);
	}
	else
	{
		pSoftwareLineEdit->clear();
	}
}

void InterfaceWidget::softwaretextChanged(const QString &text)   //软件框内容更新
{
	if (softwareSelect[m_Last_Faultmodel - 1] != "")
	{
		pSoftwareLineEdit->setText(softwareSelect[m_Last_Faultmodel - 1]);
	}
}


//设置确定和清除按键值
void InterfaceWidget::comfrim()
{
	switch (m_Last_Faultmodel)
	{
		//与舱室相关的故障模式
	case 1:
	case 2:
	{
		if (cabinSelect[m_Last_Faultmodel - 1] == "")
		{
			QMessageBox *m = new QMessageBox(QMessageBox::Warning, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请至少选择一个舱室！"));
			m->setStandardButtons(QMessageBox::Ok);
			m->setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
			m->show();
			m->exec();
		}
		else
		{
			QString selectcabin = cabinSelect[m_Last_Faultmodel - 1];
			QStringList tempcabin = selectcabin.split(";");
			for (int j = 0; j < tempcabin.size(); j++)
			{
				FaultState * temp = new FaultState();
				temp->fault_func_name = modelSelect[m_Last_Faultmodel - 1];
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("舱室起火"))
				{
					temp->fault_func = 1;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("空调失效"))
				{
					temp->fault_func = 0;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("舱室进水"))
				{
					temp->fault_func = 1;
				}
				temp->fault_model = m_Last_Faultmodel;
				temp->fault_model_name = faultmodelname[m_Last_Faultmodel - 1];
				temp->ID = tempcabin.at(j);
				temp->time = ui.errorBeginTime->value();
				bool appendstate = true;
				for (int i = 0; i < faultStateList.size(); i++)
				{
					if ((temp->ID == faultStateList.at(i)->ID) && (temp->fault_model == faultStateList.at(i)->fault_model))
					{
						appendstate = false;    //此时已经更改了，就不需要再添加
						faultStateList.at(i)->fault_func = temp->fault_func;
						faultStateList.at(i)->fault_func_name = temp->fault_func_name;
						faultStateList.at(i)->time = temp->time;
					}
				}
				if (appendstate)
				{
					faultStateList.append(temp);
				}
			}
			updateStateWidget();
		}
		break;
	}
		//与主机相关的故障模式
	case 3:
	case 6:
	case 7:
	case 8:
	case 9:
	{
		if (hostSelect[m_Last_Faultmodel - 1] == "")
		{
			QMessageBox *m = new QMessageBox(QMessageBox::Warning, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请至少选择一个主机！"));
			m->setStandardButtons(QMessageBox::Ok);
			m->setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
			m->show();
			m->exec();
		}
		else
		{
			QString selecthost = hostSelect[m_Last_Faultmodel - 1];
			QStringList temphost = selecthost.split(";");
			for (int j = 0; j < temphost.size(); j++)
			{
				FaultState * temp = new FaultState();
				temp->fault_func_name = modelSelect[m_Last_Faultmodel - 1];
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("主机运行失效"))
				{
					temp->fault_func = 2;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("CPU超频使用"))
				{
					temp->fault_func = 0;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("风扇散热不好"))
				{
					temp->fault_func = 0;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("主机起火"))
				{
					temp->fault_func = 1;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("硬盘读写频繁"))
				{
					temp->fault_func = 0;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("固件老化灰尘多"))
				{
					temp->fault_func = 0;
				}
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("软件运行占用资源过多"))
				{
					temp->fault_func = 3;
				}
				temp->fault_model = m_Last_Faultmodel;
				temp->fault_model_name = faultmodelname[m_Last_Faultmodel - 1];
				temp->ID = temphost.at(j);
				temp->time = ui.errorBeginTime->value();
				bool appendstate = true;
				for (int i = 0; i < faultStateList.size(); i++)
				{
					if ((temp->ID == faultStateList.at(i)->ID) && (temp->fault_model == faultStateList.at(i)->fault_model))
					{
						appendstate = false;    //此时已经更改了，就不需要再添加
						faultStateList.at(i)->fault_func = temp->fault_func;
						faultStateList.at(i)->fault_func_name = temp->fault_func_name;
						faultStateList.at(i)->time = temp->time;
						break;
					}
				}
				if (appendstate)
				{
					faultStateList.append(temp);
				}
			}
			updateStateWidget();
		}
		break;
	}
		//与软件相关的故障模式
	case 4:
	{
		if (softwareSelect[m_Last_Faultmodel - 1] == "")
		{
			QMessageBox *m = new QMessageBox(QMessageBox::Warning, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("请至少选择一个软件！"));
			m->setStandardButtons(QMessageBox::Ok);
			m->setButtonText(QMessageBox::Ok, QString::fromLocal8Bit("确定"));
			m->show();
			m->exec();
		}
		else
		{
			QString selectsoftware = softwareSelect[m_Last_Faultmodel - 1];
			QStringList tempsoftware = selectsoftware.split(";");
			for (int j = 0; j < tempsoftware.size(); j++)
			{
				FaultState * temp = new FaultState();
				temp->fault_func_name = modelSelect[m_Last_Faultmodel - 1];
				if (modelSelect[m_Last_Faultmodel - 1] == QString::fromLocal8Bit("软件运行失效"))
				{
					temp->fault_func = 1;
				}
				temp->fault_model = m_Last_Faultmodel;
				temp->fault_model_name = faultmodelname[m_Last_Faultmodel - 1];
				temp->ID = tempsoftware.at(j);
				temp->time = ui.errorBeginTime->value();
				bool appendstate = true;
				for (int i = 0; i < faultStateList.size(); i++)
				{
					if ((temp->ID == faultStateList.at(i)->ID) && (temp->fault_model == faultStateList.at(i)->fault_model))
					{
						appendstate = false;    //此时已经更改了，就不需要再添加
						faultStateList.at(i)->fault_func = temp->fault_func;
						faultStateList.at(i)->fault_func_name = temp->fault_func_name;
						faultStateList.at(i)->time = temp->time;
						break;
					}
				}
				if (appendstate)
				{
					faultStateList.append(temp);
				}
			}
			updateStateWidget();
		}
		break;
	}
		//与导弹相关的故障模式
	case 5:
	{
		FaultState * temp = new FaultState();
		temp->fault_func_name = modelSelect[m_Last_Faultmodel - 1];
		temp->fault_model = m_Last_Faultmodel;
		temp->fault_model_name = faultmodelname[m_Last_Faultmodel - 1];
		temp->time = ui.errorBeginTime->value();
		bool appendstate = true;
		for (int i = 0; i < faultStateList.size(); i++)
		{
			if (temp->fault_model == faultStateList.at(i)->fault_model)
			{
				appendstate = false;    //此时已经更改了，就不需要再添加
				faultStateList.at(i)->time = temp->time;
				break;
			}
		}
		if (appendstate)
		{
			faultStateList.append(temp);
		}
		updateStateWidget();
		break;
	}
	//与任务优先级相关的故障模式
	case 10:
	{
		FaultState * temp2 = new FaultState();
		temp2->fault_func_name = modelSelect[m_Last_Faultmodel - 1];
		temp2->fault_model = m_Last_Faultmodel;
		temp2->fault_model_name = faultmodelname[m_Last_Faultmodel - 1];
		temp2->time = ui.errorBeginTime->value();
		bool appendstate2 = true;
		for (int i = 0; i < faultStateList.size(); i++)
		{
			if (temp2->fault_model == faultStateList.at(i)->fault_model)
			{
				appendstate2 = false;    //此时已经更改了，就不需要再添加
				faultStateList.at(i)->time = temp2->time;
				break;
			}
		}
		if (appendstate2)
		{
			faultStateList.append(temp2);
		}
		updateStateWidget();
		break;
	}
	}
}

void InterfaceWidget::clear()
{
	modelSelect[m_Last_Faultmodel-1] = modeltype.at(m_Last_Faultmodel - 1).at(0);
	cabinSelect[m_Last_Faultmodel - 1] = ""; 
	hostSelect[m_Last_Faultmodel - 1] = ""; 
	softwareSelect[m_Last_Faultmodel - 1] = ""; 
	ui.totalTime->setValue(30);
	ui.errorBeginTime->setValue(5);
	ui.modelBox->setEnabled(false);
	ui.hostBox->setEnabled(false);
	ui.cabinBox->setEnabled(false);
	ui.softwareBox->setEnabled(false);
	showSettingWidget();   //重新设置
}

//已选状态栏更新框
void InterfaceWidget::updateStateWidget()   //已选状态栏更新
{
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
	ui.listView->setModel(standardItemModel);
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
	m_DataInstance->TotalTime = ui.totalTime->value();
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