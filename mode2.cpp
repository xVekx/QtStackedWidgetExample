#include "mode2.h"
#include "ui_mode2.h"
//------------------------------------------------------------------------------
Mode2::Mode2(QWidget *parent) :
ModeWidget(parent),
ui(new Ui::Mode2)
{
	NameMode = "Mode2";
	ui->setupUi(this);
}
//------------------------------------------------------------------------------
void Mode2::Start()
{
	BottomText(QStringList()
					<<QString::null
					<<QString::null
					<<QString::fromUtf8("Меню 3")
					<<QString::null);

}

void Mode2::KeyReleaseEvent(QKeyEvent *e)
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
			SetMode(ModeEnum3);
			break;
		}
		case Qt::Key_4: {
			break;
		}
		default:break;
	}
}
//------------------------------------------------------------------------------
Mode2::~Mode2()
{
	delete ui;
}

void Mode2::on_pushButton_clicked()
{
	SetMode(ModeEnum3);
}
