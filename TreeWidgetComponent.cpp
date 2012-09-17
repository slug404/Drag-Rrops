#include "TreeWidgetComponent.h"
#include <QMouseEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDebug>
#include <QTreeWidgetItemIterator>

TreeWidgetComponent::TreeWidgetComponent(QWidget *parent) :
	QTreeWidget(parent)
{
	initSetting();
	initData();
	initGui();
}

void TreeWidgetComponent::mousePressEvent(QMouseEvent *event)
{
	QTreeWidget::mousePressEvent(event);

	qDebug() << text_;
	QTreeWidget *pItem = (QTreeWidget *)(childAt(event->pos()));
	if (!pItem)
		return;

	QByteArray itemData;
//	QString tmp =pItem->data(0, Qt::UserRole).toString();
	//qDebug() << tmp;
	itemData.append(text_);

	QMimeData *mimeData = new QMimeData;
	mimeData->setData("application/x-dnditemdata", itemData);

	QDrag *drag = new QDrag(this);
	drag->setMimeData(mimeData);
	drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}

void TreeWidgetComponent::slotItemDoubleClicked(QTreeWidgetItem *item, int index)
{
	text_ = item->data(0, Qt::UserRole).toString();
	//qDebug() << text_;
}

void TreeWidgetComponent::slotItemPress(QTreeWidgetItem *item, int index)
{
	text_ = item->data(0, Qt::UserRole).toString();
	//qDebug() << text_;
}

void TreeWidgetComponent::initSetting()
{
	this->expandAll();
	//设置选择模式为单选
	this->setSelectionMode(QAbstractItemView::SingleSelection);
	//启动拖放
	this->setDragEnabled(true);
	//接受拖放
	this->setAcceptDrops(true);
	//设置显示将要被放置的位置
	this->setDropIndicatorShown(true);
	//设置拖放模式为移动项目, 如果不设置,默认为复制项目
	//this->setDragDropMode(QAbstractItemView::InternalMove);
}

void TreeWidgetComponent::initData()
{
	text_ = "";
	//connect(this, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(slotItemDoubleClicked(QTreeWidgetItem*,int)));
	connect(this, SIGNAL(itemPressed(QTreeWidgetItem*,int)), this, SLOT(slotItemPress(QTreeWidgetItem*,int)));
}

void TreeWidgetComponent::initGui()
{

}

