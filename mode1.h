#ifndef MODE1_H
#define MODE1_H
//------------------------------------------------------------------------------
#include "modewidget.h"
//------------------------------------------------------------------------------
namespace Ui {
class Mode1;
}
//------------------------------------------------------------------------------
class Mode1 : public ModeWidget
{
	Q_OBJECT

public:
	explicit Mode1(QWidget *parent = 0);
	~Mode1();
	void Start();
	void DataPrintTimer();
	void KeyReleaseEvent(QKeyEvent *e);
private slots:
	void on_pushButton_clicked();

private:
	Ui::Mode1 *ui;
};
//------------------------------------------------------------------------------
#endif // MODE1_H
