#include "listviewmodel.h"
#include <QSize>
#include <QDebug>

ListViewModel::ListViewModel(QObject *parent) : QAbstractListModel(parent)
{
    for(int i=1; i<=28; i++)
    {
        m_dataList.push_back(QString("%1.jpg").arg(i));
    }
}

ListViewModel::~ListViewModel()
{
}

int ListViewModel::rowCount(const QModelIndex &parent) const
{
    return m_dataList.size();
}

int ListViewModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant ListViewModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
        case Qt::SizeHintRole:
        {
            return QSize(300, 200);
            break;
        }
        case Qt::DisplayRole:
        {
            return m_dataList.at(index.row());
            break;
        }
        case Qt::UserRole:
        {
            return m_dataList.at(index.row());
            break;
        }
    }
    return QVariant();
}

void ListViewModel::updateRow(int row)
{
    qDebug()<<"update row="<<row;
    emit dataChanged(this->index(row), this->index(row));
}
