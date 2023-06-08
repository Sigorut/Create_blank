#ifndef ADD_EX_H
#define ADD_EX_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QJsonValue>
#include <QModelIndexList>
#include "edit_ex.h"
#include "view_28line.h"

namespace Ui {
class Add_ex;
}

class Add_ex : public QDialog
{
    Q_OBJECT

public:
    explicit Add_ex(QWidget *parent = nullptr);
    ~Add_ex();
    QJsonArray get_selected_ex();

private:
    Ui::Add_ex *ui;
    int selected_ex_id;

    QStandardItemModel* model;
    QString path_to_bd;
    void open_bd();
    void update_model(QJsonArray ex_all);
    QJsonArray get_all_ex();

    QString get_type(int type);
    QString get_parent_type(int parent_type);

private slots:
    void slot_current_index_model(const QModelIndex &item);
    void slot_open_bd();
    void slot_open_current_ex();
    void slot_search();
};

#endif // ADD_EX_H
