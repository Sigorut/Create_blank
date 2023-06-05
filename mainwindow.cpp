
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    wgt_ex = new QListWidget();

    form = new QWebEngineView();
    form->load(QUrl("qrc:/blank.html"));
    ui->verticalLayout_2->addWidget(form);

    connect(ui->action_open, SIGNAL(triggered()), SLOT(slot_open_bd()));
    connect(ui->butt_add_ex, SIGNAL(clicked()), SLOT(slot_add_ex()));

}
void MainWindow::fill_list_widget(QJsonArray json_select_ex)
{
    //    if(list_ex.size() !=0){
    //        for(int j = list_ex.size() - 1; j >= 0; j--){
    //            delete list_ex[j];
    //            delete list_ex_add_butt[j];
    //            delete list_layout[j];
    //            delete list_widget[j];
    //            delete list_items[j];
    //            list_ex.remove(j);
    //            list_ex_add_butt.remove(j);
    //            list_layout.remove(j);
    //            list_widget.remove(j);
    //            list_items.remove(j);
    //        }
    //         ui->listWidget->clear();

    //    }


    foreach (const QJsonValue & value, json_select_ex){
        QJsonObject obj = value.toObject();

        list_ex_add_butt << new QPushButton();
        list_ex << new QLabel();
        list_items << new QListWidgetItem(ui->listWidget);
        list_layout << new QHBoxLayout();
        list_widget << new QWidget();

        list_ex[last_index]->setMaximumWidth(70);
        list_ex[last_index]->setText("Задание " + QString::number(count_ex+1));
        list_ex_add_butt[last_index]->setObjectName(QString::number(obj.value("id").toInt()));
        list_ex_add_butt[last_index]->setMaximumSize(25,25);
        connect(list_ex_add_butt[last_index], SIGNAL(clicked()), SLOT(slot_delete_ex()));

        list_layout[last_index]->addWidget(list_ex[last_index]);
        list_layout[last_index]->addWidget(list_ex_add_butt[last_index]);
        list_widget[last_index]->setLayout(list_layout[last_index]);
        list_items[last_index]->setSizeHint(list_widget[last_index]->sizeHint());

        ui->listWidget->setItemWidget(list_items[last_index], list_widget[last_index]);

        add_form_one_ex(obj);
        qDebug() << list_ex_add_butt[last_index]->objectName();

        last_index++;
        count_ex++;
    }
    qDebug() <<  "----";

}

void MainWindow::add_form_one_ex(QJsonObject ex)
{
    switch (ex["type"].toInt()) {
    case Ex::number:
        create_html_num_string_ex(ex["id"].toInt(), Ex::number);
        fill_html_num_string_ex(ex);
        break;
    case Ex::string:
        create_html_num_string_ex(ex["id"].toInt(), Ex::string);
        fill_html_num_string_ex(ex);
        break;
    case Ex::comp:
        create_html_comp_ex(ex);
        break;
    case Ex::seq:
        break;
    case Ex::tablword:
        break;
    case Ex::treetf:
        break;
    default:
        break;
    }

}

void MainWindow::create_html_num_string_ex(int id, int type)
{
//    QString type_ex;
//    if(type == 1){
//        type_ex = "num";
//    }else{
//        type_ex = "string";
//    }
    bool flg = false;
    form->page()->runJavaScript("create_fields_for_num(" + QString::number(id) + ")",
                                [&](QVariant result)->void{
        flg = true;
    });
    while(!flg){
        QApplication::processEvents();
    }
}

void MainWindow::fill_html_num_string_ex(QJsonObject ex)
{
    set_field_string(ex["text_ex"].toString(), "text_" + QString::number(ex["id"].toInt()));
    if(ex["image"].toString().size()){
        set_field_image(ex);
    }
    set_field_string(ex["answer"].toString(), "answer_" + QString::number(ex["id"].toInt()));
    set_field_string(ex["solution"].toString(), "solution_" + QString::number(ex["id"].toInt()));
}

void MainWindow::create_html_comp_ex(QJsonObject ex)
{
    bool flg = false;
    form->page()->runJavaScript("create_fields_for_comp(" + QString::number(id) + ")",
                                [&](QVariant result)->void{
        flg = true;
    });
    while(!flg){
        QApplication::processEvents();
    }
}

void MainWindow::fill_html_comp_ex(QJsonObject ex)
{

}

void MainWindow::delete_html_ex(int id)
{
    bool flg = false;
    form->page()->runJavaScript("delete_ex(" + QString::number(id) + ")",
                                [&](QVariant result)->void{
        flg = true;
    });
    while(!flg){
        QApplication::processEvents();
    }
}

void MainWindow::set_field_int(int value, QString field_id)
{
    bool flag_finish = false;
    qDebug() << field_id;
    form->page()->runJavaScript("document.getElementById(\"" + field_id + "\").value = " + QString::number(value) + ";",
                                [&](QVariant result)->void{
        flag_finish = true;
    });
    while(!flag_finish){
        QApplication::processEvents();
    }
}

void MainWindow::set_field_string(QString value, QString field_id)
{
    bool flag_finish = false;
    qDebug() << field_id;
    form->page()->runJavaScript("document.getElementById(\"" + field_id + "\").innerText = \"" + value + "\";",
                                [&](QVariant result)->void{
        flag_finish = true;
    });
    while(!flag_finish){
        QApplication::processEvents();
    }
}

void MainWindow::set_field_image(QJsonObject ex)
{
    QByteArray base64 = ex.value("image").toString().toUtf8();
    if(base64.size()!= 0){
        QPixmap testt;
        testt.loadFromData(QByteArray::fromBase64(base64), ex.value("image_type").toString().toLocal8Bit().data());
        QByteArray bytes;
        QBuffer buffer(&bytes);
        buffer.open(QIODevice::WriteOnly);
        testt.save(&buffer, "PNG");
        // to base64
        QByteArray ba = bytes.toBase64();

        QString html;
        html += QString("<img src='data:image/png;base64,%1'/>").arg(QString(ba));
                bool flag_finish = false;
        form->page()->runJavaScript("document.getElementById(\"image_" + QString::number(ex["id"].toInt()) + "\").innerHTML += \"" + html + "\";",
                [&](QVariant result)->void{
            flag_finish = true;
        });
        while(!flag_finish){
            QApplication::processEvents();
        }
    }
}

void MainWindow::slot_open_bd()
{
    QString path_to_file = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        "/",
                                                        tr("*.json"));
    if(!path_to_file.isEmpty()){
        //        set_enabled_butt(true);
        path_to_bd = path_to_file;
        QFile bd(path_to_bd);
        QString text_content;
        QJsonDocument json_content;
        if(bd.open(QIODevice::ReadOnly)){
            text_content = bd.readAll();
            json_content = QJsonDocument::fromJson(text_content.toUtf8());
            json_all_ex = json_content.array();
            bd.close();
        }
    }
}

void MainWindow::slot_delete_ex()
{
    QString butt_cur_name;
    QPushButton* butt = qobject_cast<QPushButton*>(sender());
    butt_cur_name = butt->objectName();
    for(int i = 0; i < list_ex_add_butt.size(); i++){
        if(list_ex_add_butt[i]->objectName() == butt_cur_name){
            delete list_ex[i];
            delete list_ex_add_butt[i];
            delete list_layout[i];
            delete list_widget[i];
            delete list_items[i];
            list_ex.remove(i);
            list_ex_add_butt.remove(i);
            list_layout.remove(i);
            list_widget.remove(i);
            list_items.remove(i);
            json_all_ex.removeAt(i);
            last_index--;
            count_ex--;

            delete_html_ex(butt_cur_name.toInt());
            break;
        }
    }
    for(int i = 0; i < list_ex.size(); i++){
        list_ex[i]->setText("Задание " + QString::number(i+1));
    }
}

void MainWindow::slot_add_ex()
{
    Add_ex form_add_ex;
    QJsonArray select_ex;
    QJsonArray select_ex_new_id;
    if(form_add_ex.exec()){
        select_ex = form_add_ex.get_selected_ex();
    }
    QVector<bool> free_slot(1000,true);
    QJsonValue single;
    for(int i = 0; i < json_all_ex.size(); i++){
        for(int j = 0; free_slot.size(); j++){
            single = json_all_ex[i];
            if(single["id"].toInt() == j){
                free_slot[j] = false;
                break;
            }
        }
    }
    QJsonObject obj_single;
    for(int j = 0; j < select_ex.size(); j++){
        single = select_ex[j];
        obj_single = single.toObject();
        for(int i = 0; i < free_slot.size(); i++){
            if(free_slot[i]){
                obj_single.insert("id", i);
                select_ex_new_id << obj_single;
                json_all_ex << obj_single;
                free_slot[i] = false;
                break;
            }
        }
    }
    fill_list_widget(select_ex_new_id);
}

MainWindow::~MainWindow()
{
    delete ui;
}




