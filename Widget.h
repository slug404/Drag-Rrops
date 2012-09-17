#ifndef WIDGET_H
#define WIDGET_H

#include "ui_Widget.h"

class Widget : public QWidget, private Ui::Widget
{
	Q_OBJECT
	
public:
	explicit Widget(QWidget *parent = 0);
	
protected:
	void changeEvent(QEvent *e);
private:
	void initSetting();
	void initData();
	void initGui();
private:

};

#endif // WIDGET_H
