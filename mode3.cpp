#include "mode3.h"
#include "ui_mode3.h"
//------------------------------------------------------------------------------
Mode3::Mode3(QWidget *parent) :
ModeWidget(parent),
ui(new Ui::Mode3)
{
	NameMode = "Mode3";
	ui->setupUi(this);
}
//------------------------------------------------------------------------------
void Mode3::Start()
{
	BottomText(QStringList()
					<<QString::null
					<<QString::null
					<<QString::null
					<<QString::fromUtf8("Меню 4"));

}
//------------------------------------------------------------------------------
void Mode3::KeyReleaseEvent(QKeyEvent *e)
{
	BottomClick(e->key(),false);
	switch(e->key()) {
		case Qt::Key_1: {
			break;
		}
		case Qt::Key_2: {
			break;
		}
		case Qt::Key_3: {
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
Mode3::~Mode3()
{
	delete ui;
}
