#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFormLayout>

#include "qcustomplot.h"

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

private slots:
    void onStartClicked();

private:
    QLineEdit* amplitudeEdit;
    QLineEdit* freqEdit;
    QLineEdit* fillEdit;
    QLineEdit* kEdit;
    QLineEdit* tiEdit;
    QLineEdit* tdEdit;
    QLineEdit* aEdit;
    QLineEdit* bEdit;
    QLineEdit* arxKEdit;
    QLineEdit* noiseEdit;
    QTextEdit* outputEdit;
    QPushButton* startButton;
    QCustomPlot* plotWidget;
};
