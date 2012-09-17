#include "WidgetEdit.h"
#include <QMouseEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDebug>

WidgetEdit::WidgetEdit(QWidget *parent) :
	QWidget(parent)
{
	initSetting();
	initData();
	initGui();
}

void WidgetEdit::addTreeWidget(QTreeWidget *p)
{
	pTreeWidget_ = p;
}

//拖动进入事件
void WidgetEdit::dragEnterEvent(QDragEnterEvent *event)
{
	qDebug() << trUtf8("进入拖拽区域");
	if (event->source() == pTreeWidget_)
	{
		event->accept();
		event->setDropAction(Qt::MoveAction);
	}
	else
	{
		event->ignore();
	}
}

//放下事件
void WidgetEdit::dropEvent(QDropEvent *event)
{
	if (event->mimeData()->hasFormat("application/x-dnditemdata"))
	{
		QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
		qDebug() << itemData;
	}
	else
	{
		event->ignore();
	}
}

void WidgetEdit::initSetting()
{
	//接受拖放
	this->setAcceptDrops(true);
}

void WidgetEdit::initData()
{
	pTreeWidget_ = NULL;
}

void WidgetEdit::initGui()
{
}

