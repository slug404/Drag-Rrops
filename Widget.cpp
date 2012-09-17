#include "Widget.h"
#include <QDebug>
#include <QDragEnterEvent>
#include <QTreeWidgetItemIterator>

Widget::Widget(QWidget *parent) :
	QWidget(parent)
{
	setupUi(this);
	initSetting();
	initData();
	initGui();
}

void Widget::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type())
	{
		case QEvent::LanguageChange:
			retranslateUi(this);
			break;
		default:
			break;
	}
}

void Widget::initSetting()
{

}

void Widget::initData()
{
	QTreeWidgetItemIterator it(treeWidget);
	int i = 0;
	while (*it)
	{
		++i;
		(*it)->setData(0, Qt::UserRole, (*it)->text(0));
		++it;
	}
	qDebug() << i;

	widgetEditArea->addTreeWidget(treeWidget);
}

void Widget::initGui()
{
	treeWidget->expandAll();
}
