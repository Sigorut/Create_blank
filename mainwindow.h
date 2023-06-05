
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QWebEngineView>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QListWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QByteArray>
#include "add_ex.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString path_to_bd;
    int count_ex = 0;
    int last_index = 0;
    QJsonArray json_all_ex;
    QVector<QPushButton*> list_ex_add_butt;
    QVector<QLabel*> list_ex;
    QVector<QLayout*> list_layout;
    QVector<QWidget*> list_widget;
    QVector<QListWidgetItem*> list_items;
    QWebEngineView *form;
    QListWidget *wgt_ex;
    void fill_list_widget(QJsonArray json_select_ex);
    void add_form_one_ex(QJsonObject ex);

    void set_field_int(int value, QString field_id);
    void set_field_string(QString value, QString field_id);
    void set_field_image(QJsonObject ex);


    void create_html_num_string_ex(int id, int type);
    void fill_html_num_string_ex(QJsonObject ex);

    void create_html_comp_ex(QJsonObject ex);
    void fill_html_comp_ex(QJsonObject ex);

    void delete_html_ex(int id);
private slots:
    void slot_open_bd();
    void slot_delete_ex();
    void slot_add_ex();
};

#endif // MAINWINDOW_H
