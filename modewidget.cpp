#include <QtGui>
#include <QScreen>
#include <QApplication>

#include "modewidget.h"
//------------------------------------------------------------------------------
ModeWidget::ModeWidget(QWidget *parent) : QWidget(parent),NameMode("NULL")
{
	qDebug()<<Q_FUNC_INFO;
}
//------------------------------------------------------------------------------
ModeWidget::~ModeWidget()
{
	qDebug()<<Q_FUNC_INFO;
}
//------------------------------------------------------------------------------
QString ModeWidget::GetName()
{
	qDebug()<<Q_FUNC_INFO;
	return NameMode;
}
//------------------------------------------------------------------------------
void ModeWidget::KeyEvent(QKeyEvent *event)
{
	qDebug()<<Q_FUNC_INFO;
	switch (event->type()) {
		case QEvent::KeyPress:{KeyPressEvent(event);break;}
		case QEvent::KeyRelease:{KeyReleaseEvent(event);break;}
		default:break;
	}
}
//------------------------------------------------------------------------------
void ModeWidget::KeyPressEvent(QKeyEvent *event)
{
	qDebug()<<Q_FUNC_INFO;
	BottomClick(event->key(),true);
}
//------------------------------------------------------------------------------
void ModeWidget::KeyReleaseEvent(QKeyEvent *event)
{
	BottomClick(event->key(),false);
	qDebug()<<Q_FUNC_INFO;
}
//------------------------------------------------------------------------------
void ModeWidget::keyPressEvent(QKeyEvent *event)
{
	qDebug()<<Q_FUNC_INFO;
	KeyEvent(event);
}
//------------------------------------------------------------------------------
void ModeWidget::keyReleaseEvent(QKeyEvent *event)
{
	qDebug()<<Q_FUNC_INFO;
	KeyEvent(event);
}
//------------------------------------------------------------------------------
void ModeWidget::Start()
{
	qDebug()<<Q_FUNC_INFO;
}
//------------------------------------------------------------------------------
void ModeWidget::BottomText(QWidget *qw,const QString &str,int n)
{
	qDebug()<<Q_FUNC_INFO;
	if(n >= 0 && n < 5) {
		QStringList edit = Bottom.value(qw);
		edit[n] = str;
		BottomText(edit);
	}
}
//------------------------------------------------------------------------------
void ModeWidget::DataPrintTimer()
{

}
//------------------------------------------------------------------------------
