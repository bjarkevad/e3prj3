#include "drinkpicker.h"

#include "ui_drinkpicker.h"

DrinkPicker::DrinkPicker(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::DrinkPicker)
{

    ui->setupUi(this);
    this->show();
    this->raise();
    this->setFocus();
}
