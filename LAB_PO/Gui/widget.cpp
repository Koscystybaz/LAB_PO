#include "widget.h"
#include "Config.h"
#include "PetlaUAR.h"
#include "RegulatorPID.h"
#include "ModelARX.h"
#include "Square.h"
#include <memory>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    amplitudeEdit = new QLineEdit;
    freqEdit = new QLineEdit;
    fillEdit = new QLineEdit;
    kEdit = new QLineEdit;
    tiEdit = new QLineEdit;
    tdEdit = new QLineEdit;
    aEdit = new QLineEdit;
    bEdit = new QLineEdit;
    arxKEdit = new QLineEdit;
    noiseEdit = new QLineEdit;
    outputEdit = new QTextEdit;
    outputEdit->setReadOnly(true);
    outputEdit->setMaximumHeight(150);
    startButton = new QPushButton("Start");
    plotWidget = new QCustomPlot;
    plotWidget->setMinimumHeight(150);

    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow("Amplituda sygnału:", amplitudeEdit);
    formLayout->addRow("Częstotliwość sygnału:", freqEdit);
    formLayout->addRow("Wypełnienie sygnału:", fillEdit);
    formLayout->addRow("Wzmocnienie regulatora (k):", kEdit);
    formLayout->addRow("Czas całkowania (Ti):", tiEdit);
    formLayout->addRow("Czas różniczkowania (Td):", tdEdit);
    formLayout->addRow("Współczynnik AR (a[0]):", aEdit);
    formLayout->addRow("Współczynnik X (b[0]):", bEdit);
    formLayout->addRow("Opóźnienie transportowe (arxK):", arxKEdit);
    formLayout->addRow("Odchylenie standardowe szumu:", noiseEdit);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(startButton);
    mainLayout->addWidget(outputEdit);
    mainLayout->addWidget(plotWidget);
    mainLayout->addWidget(plotWidget, 1);

    setLayout(mainLayout);

    connect(startButton, &QPushButton::clicked, this, &Widget::onStartClicked);
}

void Widget::onStartClicked()
{
    double amplitude = amplitudeEdit->text().toDouble();
    double freq = freqEdit->text().toDouble();
    double fill = fillEdit->text().toDouble();
    double k = kEdit->text().toDouble();
    double Ti = tiEdit->text().toDouble();
    double Td = tdEdit->text().toDouble();
    double a0 = aEdit->text().toDouble();
    double b0 = bEdit->text().toDouble();
    unsigned int arxK = arxKEdit->text().toUInt();
    double noise = noiseEdit->text().toDouble();

    std::vector<double> a = { a0 };
    std::vector<double> b = { b0 };

    Config config;
    auto petla = std::make_unique<PetlaUAR>(true);
    auto generator = std::make_unique<Square>(amplitude, freq, fill);

    petla->AddComponent(std::make_unique<RegulatorPID>(k, Ti, Td));
    petla->AddComponent(std::make_unique<ModelARX>(a, b, arxK, noise));

    config.signalGenerator = std::move(generator);
    config.loop = std::move(petla);

    outputEdit->clear();
    for (int t = 0; t < config.sampleNumber; ++t) {
        double yzad = config.signalGenerator->Symuluj(t);
        double y = config.loop->Symuluj(yzad);
        outputEdit->append(QString("t=%1 yzad=%2 y=%3")
                               .arg(t).arg(yzad).arg(y));
    }

    QVector<double> tData, yzadData, yData;
    for (int t = 0; t < config.sampleNumber; ++t) {
        double yzad = config.signalGenerator->Symuluj(t);
        double y = config.loop->Symuluj(yzad);
        tData.append(t);
        yzadData.append(yzad);
        yData.append(y);
    }

    plotWidget->clearGraphs();
    plotWidget->addGraph();
    plotWidget->graph(0)->setData(tData, yzadData);
    plotWidget->graph(0)->setName("yzad");
    plotWidget->graph(0)->setPen(QPen(Qt::blue));

    plotWidget->addGraph();
    plotWidget->graph(1)->setData(tData, yData);
    plotWidget->graph(1)->setName("y");
    plotWidget->graph(1)->setPen(QPen(Qt::red));

    plotWidget->xAxis->setLabel("t");
    plotWidget->yAxis->setLabel("Wartość");
    plotWidget->legend->setVisible(true);
    plotWidget->rescaleAxes();
    plotWidget->replot();

}
