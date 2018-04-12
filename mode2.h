#ifndef MODE2_H
#define MODE2_H
//------------------------------------------------------------------------------
#include "modewidget.h"
//------------------------------------------------------------------------------
namespace Ui {
class Mode2;
}
//------------------------------------------------------------------------------
class Mode2 : public ModeWidget
{
	Q_OBJECT

public:
	explicit Mode2(QWidget *parent = 0);
	void Start();
	~Mode2();

	void KeyReleaseEvent(QKeyEvent *e);
private slots:
	void on_pushButton_clicked();

private:
	Ui::Mode2 *ui;
};
//------------------------------------------------------------------------------
#endif // MODE2_H
