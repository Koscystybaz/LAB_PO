#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <nlohmann/json.hpp>

std::unique_ptr<PetlaUAR> petla; // globalnie lub jako pole klasy Widget

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnLoadConfig_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Wczytaj konfigurację", "", "Pliki JSON (*.json)");
    if (filename.isEmpty()) return;

    std::ifstream file(filename.toStdString());
    if (!file) {
        QMessageBox::warning(this, "Błąd", "Nie można otworzyć pliku!");
        return;
    }
    nlohmann::json j;
    file >> j;
    loop = std::make_unique<PetlaUAR>();
    loop->Deserialize(j);
    QMessageBox::information(this, "OK", "Konfiguracja została wczytana.");
}

void Widget::on_btnSaveConfig_clicked()
{
    if (!loop) {
        QMessageBox::warning(this, "Błąd", "Brak konfiguracji do zapisania!");
        return;
    }
    QString filename = QFileDialog::getSaveFileName(this, "Zapisz konfigurację", "", "Pliki JSON (*.json)");
    if (filename.isEmpty()) return;

    nlohmann::json j = loop->Serialize();
    std::ofstream file(filename.toStdString());
    file << j.dump(4);
    QMessageBox::information(this, "OK", "Konfiguracja została zapisana.");
}

void Widget::on_btnSimulate_clicked()
{
    QMessageBox::information(this, "Test", "Klik działa!");
    if (!loop) {
        QMessageBox::warning(this, "Błąd", "Brak konfiguracji!");
        return;
    }
    int steps = ui->spinSteps ? ui->spinSteps->value() : 10; // domyślnie 10 kroków
    QString results;
    for (int t = 0; t < steps; ++t) {
        double y = loop->Symuluj(1.0); // lub wartość z generatora
        results += QString("t=%1  y=%2\n").arg(t).arg(y);
    }
    ui->textResults->setPlainText(results);
}
