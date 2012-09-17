#include "WidgetEdit.h"
#include <QMouseEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDebug>
#include <QGridLayout>

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

bool WidgetEdit::eventFilter(QObject *target, QEvent *event)
{
    if(target == pQmlEditView_)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        switch(event->type())
        {
            case QEvent::MouseMove:
            {
                qDebug() << "QEvent::MouseMove";

                break;
            }
            case QEvent::MouseButtonRelease:
            {
                qDebug() << "QEvent::MouseButtonRelease";
                break;
            }
            default:
            {
                //...
                break;
            }
        }
    }
    return 0;
}

void WidgetEdit::initSetting()
{
	//接受拖放
	//this->setAcceptDrops(true);
}

void WidgetEdit::initData()
{
	pTreeWidget_ = NULL;
    pQmlEditView_ = new QDeclarativeView(this);
    //pQmlEditView_->installEventFilter(this);
    pQmlEditView_->setSource(QUrl::fromLocalFile("QML_Edit.qml"));

    pQmlEditItem_ = (QObject *)pQmlEditView_->rootObject();
    connect(this, SIGNAL(signalCreateComponent(QVariant,QVariant,QVariant)), pQmlEditItem_, SLOT(createComponent(QVariant,QVariant,QVariant)));
    //emit signalCreateComponent(100, 100, tr("QML_Item.qml"));
}

void WidgetEdit::initGui()
{
	//qmlEditView_.show();

	//添加QML组件到QWidget上
    QGridLayout *pGridLayout = new QGridLayout(this);
    pGridLayout->addWidget(pQmlEditView_);
    this->setLayout(pGridLayout);
}

