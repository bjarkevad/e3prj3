#ifndef DRINKPICKER_H
#define DRINKPICKER_H

#include <QMainWindow>

namespace Ui
{
    class DrinkPicker;
}

class DrinkPicker : public QMainWindow
{
    Q_OBJECT
public:
    explicit DrinkPicker(QWidget *parent = 0);

private:
    Ui::DrinkPicker *ui;
    
signals:
    
public slots:
    
};

#endif // DRINKPICKER_H
