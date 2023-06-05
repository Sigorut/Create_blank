#ifndef ADD_EX_H
#define ADD_EX_H

#include <QDialog>

namespace Ui {
class Add_ex;
}

class Add_ex : public QDialog
{
    Q_OBJECT

public:
    explicit Add_ex(QWidget *parent = nullptr);
    ~Add_ex();

private:
    Ui::Add_ex *ui;
};

#endif // ADD_EX_H
