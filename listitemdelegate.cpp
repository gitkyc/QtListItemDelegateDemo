#include "listitemdelegate.h"
#include <QPainter>
#include <QFontMetrics>
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
#include "listviewmodel.h"
#include <QApplication>
#include <QMessageBox>

ListItemDelegate::ListItemDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    m_image=new QImage(":/image/test.jpg");
    m_icon=new QImage(":/image/icon.png");
    m_iconHover=new QImage(":/image/icon_hover.png");
    m_mouseHover=false;
    m_mouseCurrentRow=-1;
}

ListItemDelegate::~ListItemDelegate()
{

}

void ListItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    qDebug()<<"ListItemDelegate::paint row="<<index.row();
    painter->drawImage(option.rect, *m_image);
    QRect rect=QRect(option.rect.left()+option.rect.width()-30, option.rect.top(), 30, 30);
    if((m_mouseCurrentRow==index.row()) && m_mouseHover)
    {
        painter->drawImage(rect, *m_iconHover);
    }
    else
    {
        painter->drawImage(rect, *m_icon);
    }
}

bool ListItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    qDebug()<<"ListItemDelegate::editorEvent type="<<event->type()<<", row="<<index.row();
    QRect decorationRect(option.rect.left()+option.rect.width()-30, option.rect.top(), 30, 30);
    if(event->type()==QMouseEvent::MouseMove)
    {
        QMouseEvent *mouseEvent=static_cast<QMouseEvent*>(event);
        if(decorationRect.contains(mouseEvent->pos()))
        {
            setMouseHover(true, model, index);
            qApp->setOverrideCursor(Qt::PointingHandCursor);
        }
        else
        {
            setMouseHover(false, model, index);
            qApp->restoreOverrideCursor();
        }
    }
    else if(event->type()==QMouseEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent=static_cast<QMouseEvent*>(event);
        if(decorationRect.contains(mouseEvent->pos()))
        {
            QMessageBox::about(NULL, "About", "Icon clicked!");
        }
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

void ListItemDelegate::setMouseHover(bool mouseHover, QAbstractItemModel *model, const QModelIndex &index)
{
    ListViewModel *listViewModel=dynamic_cast<ListViewModel*>(model);
    if(listViewModel==0)
    {
        return;
    }
    if(m_mouseCurrentRow!=index.row() && m_mouseCurrentRow>=0)
    {
        listViewModel->updateRow(m_mouseCurrentRow);
    }
    m_mouseCurrentRow=index.row();

    if(m_mouseHover!=mouseHover)
    {
        m_mouseHover=mouseHover;
        listViewModel->updateRow(index.row());
    }
}
