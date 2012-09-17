#ifndef TREEWIDGETCOMPONENT_H
#define TREEWIDGETCOMPONENT_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
class TreeWidgetComponent : public QTreeWidget
{
	Q_OBJECT
public:
	explicit TreeWidgetComponent(QWidget *parent = 0);

	void mousePressEvent(QMouseEvent *event);
signals:
	
public slots:

protected:

private slots:
	void slotItemDoubleClicked(QTreeWidgetItem *item, int index);
	void slotItemPress(QTreeWidgetItem *item, int index);
private:
	void initSetting();
	void initData();
	void initGui();
private:
	QString text_;
};

#endif // TREEWIDGETCOMPONENT_H
