#ifndef LISTVIEWMODEL_H
#define LISTVIEWMODEL_H


#include <QObject>
#include <QAbstractListModel>
#include <QList>

class ListViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ListViewModel(QObject *parent=0);
    ~ListViewModel();

    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    void updateRow(int row);

private:
    QList<QString> m_dataList;
};


#endif // LISTVIEWMODEL_H
