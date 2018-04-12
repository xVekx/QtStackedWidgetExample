#include "mode4.h"
#include "ui_mode4.h"
//------------------------------------------------------------------------------
Mode4::Mode4(QWidget *parent) :
ModeWidget(parent),
ui(new Ui::Mode4)
{
	ui->setupUi(this);
}
//------------------------------------------------------------------------------
void Mode4::Start()
{
	BottomText(QStringList()
					<<QString::fromUtf8("Меню 1")
					<<QString::null
					<<QString::null
					<<QString::null);

}

void Mode4::KeyReleaseEvent(QKeyEvent *e)
{
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
Mode4::~Mode4()
{
	delete ui;
}
