#include "ModeSettingWidget.h"
#include <QTextCodec>
#include <QStringList>
ModeSettingWidget::ModeSettingWidget(QWidget *parent)
	: QWidget(parent)
{
	m_DataInstance = QDocument::getInstance();
	ui.setupUi(this);
	this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

ModeSettingWidget::~ModeSettingWidget()
{

}

void ModeSettingWidget::init()
{
	initmodeltype();
	initSettingWidget();
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


void ModeSettingWidget::initmodeltype()
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

void ModeSettingWidget::initSettingWidget()           //初始化下拉列表框内容
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

void ModeSettingWidget::setshow(QVector<FaultState *> temp,int t)
{
	faultStateList = temp;
	simtotaltime = t;
	ui.totalTime->setValue(simtotaltime);
	this->show();

}


void ModeSettingWidget::faultModelSelected()   //模式选择复选框事件
{
	for (int i = 0; i < ModelList.size(); i++)
	{
		if (sender() == ModelList.at(i))
		{
			m_Last_Faultmodel = i + 1;
			ui.modelBox->setEnabled(false);
			ui.hostBox->setEnabled(false);
			ui.cabinBox->setEnabled(false);
			ui.softwareBox->setEnabled(false);
			showSettingWidget();
			break;
		}
	}
}


void ModeSettingWidget::showSettingWidget()     //显示故障模式
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
void ModeSettingWidget::setmodelBox()       //设置模式复选框
{
	pModelListWidget->clear();
	for (int i = 0; i < modeltype.at(m_Last_Faultmodel - 1).size(); i++)
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

void ModeSettingWidget::modelChanged()
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

void ModeSettingWidget::modeltextChanged(const QString &text)
{
	pModelLineEdit->setText(modelSelect[m_Last_Faultmodel - 1]);
}

//舱室选择框相关事件
void ModeSettingWidget::setcabinBox()       //设置舱室复选框
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

void ModeSettingWidget::cabinChanged()     //改变舱室相关选项
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

void ModeSettingWidget::cabintextChanged(const QString &text)      //舱室框内容更新
{
	if (cabinSelect[m_Last_Faultmodel - 1] != "")
	{
		pCabinLineEdit->setText(cabinSelect[m_Last_Faultmodel - 1]);
	}
}

//主机选择框相关事件
void ModeSettingWidget::sethostBox()        //设置主机复选框
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

void ModeSettingWidget::hostChanged()     //改变主机相关选项
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

void ModeSettingWidget::hosttextChanged(const QString &text)       //主机框内容更新
{
	if (hostSelect[m_Last_Faultmodel - 1] != "")
	{
		pHostLineEdit->setText(hostSelect[m_Last_Faultmodel - 1]);
	}
}

//软件选择框相关事件
void ModeSettingWidget::setsoftwareBox()    //设置软件复选框
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

void ModeSettingWidget::softwareChanged()     //改变软件相关选项
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

void ModeSettingWidget::softwaretextChanged(const QString &text)   //软件框内容更新
{
	if (softwareSelect[m_Last_Faultmodel - 1] != "")
	{
		pSoftwareLineEdit->setText(softwareSelect[m_Last_Faultmodel - 1]);
	}
}


//设置确定和清除按键值
void ModeSettingWidget::comfrim()
{
	simtotaltime = ui.totalTime->value();
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
			emit updateMode();
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
			emit updateMode();
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
			emit updateMode();
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
		emit updateMode();
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
		emit updateMode();
		break;
	}
	}
}

void ModeSettingWidget::clear()
{
	modelSelect[m_Last_Faultmodel - 1] = modeltype.at(m_Last_Faultmodel - 1).at(0);
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

void ModeSettingWidget::closeEvent(QCloseEvent *event)
{
	this->hide();
}