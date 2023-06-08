#include "add_ex.h"
#include "ui_add_ex.h"

Add_ex::Add_ex(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_ex)
{
    model = new QStandardItemModel();

    ui->setupUi(this);
    ui->table_view->horizontalHeader()->setStretchLastSection(true);
    ui->table_view->setSortingEnabled(true);
    ui->table_view->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->butt_open, SIGNAL(clicked()), SLOT(slot_open_bd()));
    connect(ui->table_view, SIGNAL(doubleClicked(QModelIndex)),SLOT(slot_open_current_ex()));
    connect(ui->table_view, SIGNAL(clicked(const QModelIndex &)),SLOT(slot_current_index_model(const QModelIndex &)));
    connect(ui->butt_search, SIGNAL(clicked()), SLOT(slot_search()));
    connect(ui->butt_add, SIGNAL(clicked()), SLOT(accept()));
    connect(ui->butt_cancel, SIGNAL(clicked()), SLOT(reject()));

}

void Add_ex::slot_open_bd()
{
    QString path_to_file = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "/",
                                                        tr("*.json"));
    if(!path_to_file.isEmpty()){
//        set_enabled_butt(true);
        path_to_bd = path_to_file;
        open_bd();
    }
}

QJsonArray Add_ex::get_all_ex()
{
    QFile bd(path_to_bd);
    QString text_content;
    QJsonDocument json_content;
    QJsonArray json_all_ex;
    if(bd.open(QIODevice::ReadOnly)){
        text_content = bd.readAll();
        json_content = QJsonDocument::fromJson(text_content.toUtf8());
        json_all_ex = json_content.array();
        bd.close();
    }
    return json_all_ex;
}

QJsonArray Add_ex::get_selected_ex()
{
    QJsonArray select_ex;
    QJsonArray all_ex = get_all_ex();
    QJsonValue single_ex;
    QVector<int> select_ex_id;
    QModelIndexList indexes = ui->table_view->selectionModel()->selection().indexes();
    qDebug() << "-----------";
    for (int i = 0; i < indexes.count(); ++i)
    {
        QModelIndex index = indexes.at(i);
        if(index.column() == 3){
            select_ex_id << index.data().toInt();
        }
    }
    for(int i = 0; i < all_ex.size(); i++){
        for(int j = 0; j < select_ex_id.size(); j++){
            single_ex = all_ex[i];
            if(single_ex["id"].toInt() == select_ex_id[j]){
                select_ex.push_back(single_ex);
            }
        }
    }
    qDebug() << select_ex;
    return select_ex;
}

void Add_ex::slot_current_index_model(const QModelIndex &item)
{

    qDebug() << item.row();
    QJsonArray all_ex = get_all_ex();
    QJsonValue single_ex;
    for(int i = 0; i < all_ex.size(); i++){
        single_ex = all_ex[i];
        if(single_ex["id"].toInt() == model->item(item.row(),3)->text().toInt()){
//            qDebug() << single_ex;
            selected_ex_id = single_ex["id"].toInt();
            break;
        }
    }

}

void Add_ex::slot_open_current_ex()
{
    qDebug() << "open";
    QJsonArray all_ex = get_all_ex();
    QJsonValue single_ex;
    int i = 0;
    for(;i < all_ex.size(); i++){
        single_ex = all_ex[i];
        if(single_ex["id"].toInt() == selected_ex_id){
            break;
        }
    }
    if(single_ex["type"].toInt() > 6){
        View_28line view_ex(single_ex.toObject(), this);
        view_ex.exec();
    }else{
        Edit_ex edit_ex_form(single_ex["type"].toInt(), single_ex["parent_type"].toInt(), this);
        edit_ex_form.set_ex(single_ex);
        edit_ex_form.exec();
    }
}

void Add_ex::slot_search()
{
    QString data;
    QString search_line = ui->lineEdit_search->text();
    search_line = search_line.toLower();
    for(int i = 0; i < model->rowCount(); i++){
        ui->table_view->hideRow(i);
        for(int j = 0; j < model->columnCount(); j++){
            qDebug() << model->item(i,j)->text();
            data = model->item(i,j)->text();
            data = data.toLower();
            if(data.contains(search_line)){
                ui->table_view->showRow(i);
            }
        }
    }
}



void Add_ex::open_bd()
{
    QFile bd(path_to_bd);
    QString text_content;
    QJsonDocument json_content;
    QStringList labels;
    selected_ex_id = -1;
    model->clear();
    labels << "Тип задания" << "Вид Задания" << "Текст задания" << "id";
    model->setHorizontalHeaderLabels(labels);
    if(bd.open(QIODevice::ReadOnly)){
        text_content = bd.readAll();
        json_content = QJsonDocument::fromJson(text_content.toUtf8());
        QJsonArray json_all_ex = json_content.array();
        //        qDebug() << text_content;
        update_model(json_all_ex);
        ui->table_view->setModel(model);
        ui->table_view->setColumnHidden(3, true);
        ui->table_view->sortByColumn(0, Qt::SortOrder::AscendingOrder);
        bd.close();
    }
}

void Add_ex::update_model(QJsonArray ex_all)
{
    int i = 0;
    int sort_column = ui->table_view->horizontalHeader()->sortIndicatorSection();
    int sort_order = ui->table_view->horizontalHeader()->sortIndicatorOrder();
    QStandardItem *item;
    QStringList labels;
    qDebug() << "update" << ex_all.size();
    model->clear();
    labels << "Тип задания" << "Вид Задания" << "Текст задания" << "id";
    model->setHorizontalHeaderLabels(labels);
    ui->table_view->clearMask();
    QString type, parent_type;
    foreach (const QJsonValue & value, ex_all) {
        QJsonObject obj = value.toObject();
        qDebug() << obj.value("type").toInt();
        type = get_type(obj.value("type").toInt());
        item = new QStandardItem(QString("%1").arg(type));
        model->setItem(i,0,item);
        parent_type = get_parent_type(obj.value("parent_type").toInt());
//        item = new QStandardItem(QString("%1").arg(obj.value("parent_type").toInt()));
        item = new QStandardItem(QString("%1").arg(parent_type));
        model->setItem(i,1,item);
        QString valuetemp = obj.value("text_ex").toString();
        if(valuetemp.contains("\\n")){
            QStringList temp;
            temp = valuetemp.split("\\n");
            valuetemp.clear();
            for(int i = 0; i < temp.size(); i++){
                valuetemp += temp[i];
                if(i != temp.size()-1){
                    valuetemp += + "\n";
                }
            }
        }
        item = new QStandardItem(QString("%1").arg(valuetemp));
        model->setItem(i,2,item);
        item = new QStandardItem(QString("%1").arg(obj.value("id").toInt()));
        model->setItem(i,3,item);
        i++;
    }
    ui->table_view->setColumnHidden(3, true);
    ui->table_view->sortByColumn(sort_column, Qt::SortOrder(sort_order));
}
QString Add_ex::get_type(int type)
{
    switch (type) {
    case 1:
        return "Числовой ответ";
        break;
    case 2:
        return "Строковый ответ";
        break;
    case 3:
        return "Сопоставление";
        break;
    case 4:
        return "Последовательность";
        break;
    case 5:
        return "Пропущенное слово";
        break;
    case 6:
        return "Выбор верных/неверных";
        break;
    case 7:
        return "28line";
        break;
    default:
        break;
    }
    return "";
}

QString Add_ex::get_parent_type(int parent_type)
{
    switch (parent_type) {
    case 1:
        return "Числовой";
        break;
    case 2:
        return "Строковый";
        break;
    case 3:
        return "Табличный";
        break;
    case 4:
        return "Множественный";
        break;
    case 5:
        return "28line";
        break;
    default:
        break;
    }
        return "";
}


Add_ex::~Add_ex()
{
    delete ui;
}
