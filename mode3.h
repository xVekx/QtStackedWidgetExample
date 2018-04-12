#ifndef MODE3_H
#define MODE3_H
//------------------------------------------------------------------------------
#include "modewidget.h"
//------------------------------------------------------------------------------
namespace Ui {
class Mode3;
}
//------------------------------------------------------------------------------
class Mode3 : public ModeWidget
{
	Q_OBJECT

public:
	explicit Mode3(QWidget *parent = 0);
	void Start();
	~Mode3();

	void KeyReleaseEvent(QKeyEvent *e);
private:
	Ui::Mode3 *ui;
};
//------------------------------------------------------------------------------
#endif // MODE3_H
