#ifndef MW_H
#define MW_H
//------------------------------------------------------------------------------
#include <QMainWindow>
#include "mode1.h"
#include "mode2.h"
#include "mode3.h"
#include "mode4.h"
//------------------------------------------------------------------------------
namespace Ui {
class MW;
}
//------------------------------------------------------------------------------
class MW : public QMainWindow
{
	Q_OBJECT

public:
	explicit MW(QWidget *parent = 0);
	~MW();
//------------------------------------------------------------------------------
private slots:
	void BottomClick(int key, bool state);
	bool SetPagesCurrentIndex(ModeEnum index);

	void on_QPBM1_pressed();
	void on_QPBM1_released();
	void on_QPBM3_pressed();
	void on_QPBM3_released();
	void on_QPBM2_pressed();
	void on_QPBM2_released();
	void on_QPBM4_pressed();
	void on_QPBM4_released();
	void BottomText(QStringList tb);

protected:
	void resizeEvent(QResizeEvent *event);
	void showEvent (QShowEvent *event);
	void timerEvent(QTimerEvent *e);
	void BottomEvent(QKeyEvent *e);
//------------------------------------------------------------------------------
private:
	QHash<ModeEnum,QWidget*>	index_widget;
	QStackedWidget				*st_widget;

	Mode1 mode1;
	Mode2 mode2;
	Mode3 mode3;
	Mode4 mode4;

	Ui::MW *ui;
};
//------------------------------------------------------------------------------
#endif // MW_H
