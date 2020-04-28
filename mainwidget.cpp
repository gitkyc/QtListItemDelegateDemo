#include "mainwidget.h"
#include "ui_mainwidget.h"

#include "listitemdelegate.h"
#include "listviewmodel.h"
#include <QListView>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ListViewModel *listViewModel=new ListViewModel(this);
    ui->listView->setModel(listViewModel);

    ListItemDelegate *delegate=new ListItemDelegate(this);
    ui->listView->setItemDelegate(delegate);

    ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setResizeMode(QListView::Adjust);
    ui->listView->setSelectionMode(QListView::SingleSelection);
    ui->listView->setSpacing(10);
    ui->listView->setWordWrap(true);
    ui->listView->setUpdatesEnabled(true);
    ui->listView->setEditTriggers(QListView::NoEditTriggers);
    ui->listView->setMouseTracking(true);
}

MainWidget::~MainWidget()
{
    delete ui;
}
