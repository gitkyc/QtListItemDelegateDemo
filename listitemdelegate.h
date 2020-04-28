#ifndef LISTITEMDELEGATE_H
#define LISTITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPushButton>
#include <QItemDelegate>

class ListItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ListItemDelegate(QObject *parent = 0);
    ~ListItemDelegate();

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:
    QPushButton *m_pushButton;
    QImage *m_image;
    QImage *m_icon;
    QImage *m_iconHover;
    bool m_mouseHover;
    int m_mouseCurrentRow;
    void setMouseHover(bool mouseHover, QAbstractItemModel *model, const QModelIndex &index);

signals:

public slots:
};

#endif // LISTITEMDELEGATE_H
