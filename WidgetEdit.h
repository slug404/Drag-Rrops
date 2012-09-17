#ifndef WIDGETEDIT_H
#define WIDGETEDIT_H

#include <QWidget>
#include <QTreeWidget>
#include <QDeclarativeView>
#include <QDeclarativeEngine>
#include <QDeclarativeComponent>
#include <QDeclarativeContext>

class WidgetEdit : public QWidget
{
	Q_OBJECT
public:
	explicit WidgetEdit(QWidget *parent = 0);
	void addTreeWidget(QTreeWidget *p);
signals:
    void signalCreateComponent(QVariant x, QVariant y, QVariant qmlName);
public slots:

protected:
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);
    bool eventFilter(QObject *target, QEvent *event);
private:
	void initSetting();
	void initData();
	void initGui();
private:
	QTreeWidget *pTreeWidget_;
	QDeclarativeView *pQmlEditView_;
	QObject *pQmlEditItem_;
};

#endif // WIDGETEDIT_H
