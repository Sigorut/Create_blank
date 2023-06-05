
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

    QJsonArray json_all_ex;
    QVector<QPushButton*> list_ex_add_butt;
    QVector<QLabel*> list_ex;
    QVector<QLayout*> list_layout;
    QVector<QWidget*> list_widget;
    QVector<QListWidgetItem*> list_items;
    QWebEngineView *form;
    QListWidget *wgt_ex;
    void fill_list_widget();
private slots:
    void slot_open_bd();
    void slot_add_ex();
};

#endif // MAINWINDOW_H
