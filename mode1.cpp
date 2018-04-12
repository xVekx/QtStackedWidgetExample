#include "mode1.h"
#include "ui_mode1.h"
//------------------------------------------------------------------------------
Mode1::Mode1(QWidget *parent) :
ModeWidget(parent),
ui(new Ui::Mode1)
{
	NameMode = "Mode1";
	ui->setupUi(this);
}
//------------------------------------------------------------------------------
void Mode1::Start()
{
	qDebug()<<Q_FUNC_INFO;
	BottomText(QStringList()
					<<QString::fromUtf8("Меню 1")
					<<QString::fromUtf8("Меню 2")
					<<QString::fromUtf8("Меню 3")
					<<QString::fromUtf8("Меню 4"));

}
//------------------------------------------------------------------------------
void Mode1::KeyReleaseEvent(QKeyEvent *e)
{
	qDebug()<<Q_FUNC_INFO;
	BottomClick(e->key(),false);
	switch(e->key()) {
		case Qt::Key_1: {
			SetMode(ModeEnum1);
			break;
		}
		case Qt::Key_2: {
			SetMode(ModeEnum2);
			break;
		}
		case Qt::Key_3: {
			SetMode(ModeEnum3);
			break;
		}
		case Qt::Key_4: {
			SetMode(ModeEnum4);
			break;
		}
		default:break;
	}
}
//------------------------------------------------------------------------------
void Mode1::DataPrintTimer()
{
	static int count = 0;
	ui->QL->setText(QString("%1").arg(count++));
}
//------------------------------------------------------------------------------
Mode1::~Mode1()
{
	delete ui;
}
//------------------------------------------------------------------------------
void Mode1::on_pushButton_clicked()
{
	qDebug()<<Q_FUNC_INFO;
	SetMode(ModeEnum4);
}
