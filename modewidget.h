#ifndef MODEWIDGET_H
#define MODEWIDGET_H
//------------------------------------------------------------------------------
#include <QtGui>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets>
#endif
//------------------------------------------------------------------------------
enum ModeEnum {
	ModeNULL = 0,
	ModeEnum1,
	ModeEnum2,
	ModeEnum3,
	ModeEnum4
};
//------------------------------------------------------------------------------
class ModeWidget : public QWidget
{
	Q_OBJECT

public:

	QString	NameMode;
	QHash<QWidget*,QStringList> Bottom;
	QString GetName();

	ModeWidget(QWidget *parent = 0);
	~ModeWidget();

	virtual void KeyPressEvent(QKeyEvent *event);
	virtual void KeyReleaseEvent(QKeyEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

	void BottomText(QWidget *qw, const QString &str, int n);

	virtual void Start();
	virtual void DataPrintTimer();


public slots:
	void KeyEvent(QKeyEvent *event);

signals:
	void BottomClick(int key, bool state);
	void SetMode(ModeEnum index);
	void BottomText(QStringList tb);

private:

};
//------------------------------------------------------------------------------
#endif // MODEWIDGET_H
