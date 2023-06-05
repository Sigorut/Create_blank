
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
void MainWindow::fill_list_widget()
{
    if(list_ex.size() !=0){
        for(int j = list_ex.size() - 1; j >= 0; j--){
            delete list_ex[j];
            delete list_ex_add_butt[j];
            delete list_layout[j];
            delete list_widget[j];
            delete list_items[j];
            list_ex.remove(j);
            list_ex_add_butt.remove(j);
            list_layout.remove(j);
            list_widget.remove(j);
            list_items.remove(j);
        }
         ui->listWidget->clear();

    }

    int i = 0;
    foreach (const QJsonValue & value, json_all_ex){
        QJsonObject obj = value.toObject();
        list_ex_add_butt << new QPushButton();
        list_ex << new QLabel();
        list_items << new QListWidgetItem(ui->listWidget);
        list_layout << new QHBoxLayout();
        list_widget << new QWidget();

        list_ex[i]->setMaximumWidth(70);
        list_ex[i]->setText(obj.value("text_ex").toString());
        list_ex_add_butt[i]->setObjectName(QString::number(obj.value("id").toInt()));

        list_layout[i]->addWidget(list_ex[i]);
        list_layout[i]->addWidget(list_ex_add_butt[i]);
        list_widget[i]->setLayout(list_layout[i]);
        list_items[i]->setSizeHint(list_widget[i]->sizeHint());
        ui->listWidget->setItemWidget(list_items[i], list_widget[i]);
        qDebug() << list_ex_add_butt[i]->objectName();
        i++;
    }
    qDebug() <<  "----";

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
            fill_list_widget();
            bd.close();
        }
    }
}

void MainWindow::slot_add_ex()
{
    Add_ex form_add_ex;
    if(form_add_ex.exec()){

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}




