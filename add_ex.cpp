#include "add_ex.h"
#include "ui_add_ex.h"

Add_ex::Add_ex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_ex)
{
    ui->setupUi(this);
    ui->table_view->horizontalHeader()->setStretchLastSection(true);
    ui->table_view->setSortingEnabled(true);
    ui->table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_view->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Add_ex::~Add_ex()
{
    delete ui;
}
