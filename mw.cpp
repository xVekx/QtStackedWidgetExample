#include "mw.h"
#include "ui_mw.h"
//------------------------------------------------------------------------------
MW::MW(QWidget *parent) :
QMainWindow(parent),
mode1(this),
mode2(this),
mode3(this),
mode4(this),
ui(new Ui::MW)
{
	ui->setupUi(this);

	st_widget	= new QStackedWidget(ui->QWPages);

	st_widget->addWidget(&mode1);
	st_widget->addWidget(&mode2);
	st_widget->addWidget(&mode3);
	st_widget->addWidget(&mode4);

	index_widget.insert(ModeEnum1,&mode1);
	index_widget.insert(ModeEnum2,&mode2);
	index_widget.insert(ModeEnum3,&mode3);
	index_widget.insert(ModeEnum4,&mode4);

	SetMode(ModeEnum1);

	startTimer(1000);
}
//------------------------------------------------------------------------------
MW::~MW()
{
	delete ui;
}
//------------------------------------------------------------------------------
void MW::resizeEvent(QResizeEvent *event)
{
	st_widget->resize(ui->QWPages->size());
	QMainWindow::resizeEvent(event);
}
//------------------------------------------------------------------------------
void MW::showEvent(QShowEvent *event)
{
	st_widget->resize(ui->QWPages->size());
	QMainWindow::showEvent(event);
}
//------------------------------------------------------------------------------
void MW::BottomClick(int key,bool state)
{
	switch (key) {
		case Qt::Key_1:{ui->QPBM1->setDown(state);break;}
		case Qt::Key_2:{ui->QPBM2->setDown(state);break;}
		case Qt::Key_3:{ui->QPBM3->setDown(state);break;}
		case Qt::Key_4:{ui->QPBM4->setDown(state);break;}
		default:break;
	}
}
//------------------------------------------------------------------------------
bool MW::SetMode(ModeEnum index)
{
	qDebug()<<Q_FUNC_INFO;
	if(index_widget.value(index) == 0) {
		qDebug()<<"NO Set!!!"<<index_widget.value(index);
		return false;
	}
	disconnect(st_widget->currentWidget(),SIGNAL(BottomClick(int,bool)),
			   this,SLOT(BottomClick(int,bool)));

	disconnect(st_widget->currentWidget(),SIGNAL(SetMode(ModeEnum)),
			   this,SLOT(SetMode(ModeEnum)));

	disconnect(st_widget->currentWidget(),SIGNAL(BottomText(QStringList)),
			   this,SLOT(BottomText(QStringList)));


	st_widget->setCurrentWidget(index_widget.value(index));


	connect(st_widget->currentWidget(),SIGNAL(SetMode(ModeEnum)),
			this,SLOT(SetMode(ModeEnum)));

	connect(st_widget->currentWidget(),SIGNAL(BottomClick(int,bool)),
			this,SLOT(BottomClick(int,bool)));

	connect(st_widget->currentWidget(),SIGNAL(BottomText(QStringList)),
			this,SLOT(BottomText(QStringList)));

	st_widget->resize(ui->QWPages->size());

	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	ui->QLSelect->setText(bw->GetName());
	bw->Start();
	bw->setFocus();
	return true;
}
//------------------------------------------------------------------------------
void MW::BottomText(QStringList tb)
{
	ui->QPBM1->setText(tb.at(0));
	ui->QPBM2->setText(tb.at(1));
	ui->QPBM3->setText(tb.at(2));
	ui->QPBM4->setText(tb.at(3));

	ui->QPBM1->setEnabled(!tb[0].isNull());
	ui->QPBM2->setEnabled(!tb[1].isNull());
	ui->QPBM3->setEnabled(!tb[2].isNull());
	ui->QPBM4->setEnabled(!tb[3].isNull());
}
//------------------------------------------------------------------------------
void MW::timerEvent(QTimerEvent *e)
{
	Q_UNUSED(e);
	QDate Date = QDate::currentDate();
	QTime Time = QTime::currentTime();
	ui->QLTime->setText(Time.toString("hh:mm:ss"));
	ui->QLData->setText(Date.toString("dd.MM.yy"));

	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->DataPrintTimer();
}
//------------------------------------------------------------------------------
void MW::on_QPBM1_pressed()
{
	qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyPress,Qt::Key_1,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
//------------------------------------------------------------------------------
void MW::on_QPBM2_pressed()
{
	qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyPress,Qt::Key_2,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
//------------------------------------------------------------------------------
void MW::on_QPBM3_pressed()
{
		qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyPress,Qt::Key_3,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
//------------------------------------------------------------------------------
void MW::on_QPBM4_pressed()
{
	qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyPress,Qt::Key_4,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
//------------------------------------------------------------------------------
void MW::on_QPBM1_released()
{
	qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyRelease,Qt::Key_1,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
//------------------------------------------------------------------------------
void MW::on_QPBM2_released()
{
	qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyRelease,Qt::Key_2,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
//------------------------------------------------------------------------------
void MW::on_QPBM3_released()
{
	qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyRelease,Qt::Key_3,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
//------------------------------------------------------------------------------
void MW::on_QPBM4_released()
{
	qDebug()<<Q_FUNC_INFO;
	QKeyEvent Event = QKeyEvent(QEvent::KeyRelease,Qt::Key_4,Qt::NoModifier);
	ModeWidget *bw = qobject_cast<ModeWidget*>(st_widget->currentWidget());
	if(bw != 0)
		bw->KeyEvent(&Event);
	QApplication::processEvents();
}
