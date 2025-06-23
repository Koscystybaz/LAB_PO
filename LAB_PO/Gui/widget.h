#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "PetlaUAR.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    std::unique_ptr<PetlaUAR> loop;

private slots:
    void on_btnLoadConfig_clicked();
    void on_btnSaveConfig_clicked();
    void on_btnSimulate_clicked();
};
#endif // WIDGET_H
