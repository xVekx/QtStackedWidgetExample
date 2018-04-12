#ifndef MODE4_H
#define MODE4_H
//------------------------------------------------------------------------------
#include "modewidget.h"
//------------------------------------------------------------------------------
namespace Ui {
class Mode4;
}
//------------------------------------------------------------------------------
class Mode4 : public ModeWidget
{
	Q_OBJECT

public:
	explicit Mode4(QWidget *parent = 0);
	void Start();
	~Mode4();

	void KeyReleaseEvent(QKeyEvent *e);
private:
	Ui::Mode4 *ui;
};
//------------------------------------------------------------------------------
#endif // MODE4_H
