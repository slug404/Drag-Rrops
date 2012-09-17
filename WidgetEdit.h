#ifndef WIDGETEDIT_H
#define WIDGETEDIT_H

#include <QWidget>
#include <QTreeWidget>
class WidgetEdit : public QWidget
{
	Q_OBJECT
public:
	explicit WidgetEdit(QWidget *parent = 0);
	void addTreeWidget(QTreeWidget *p);
signals:
	
public slots:

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
private:
	void initSetting();
	void initData();
	void initGui();
private:
	QTreeWidget *pTreeWidget_;
};

#endif // WIDGETEDIT_H
