#include "Config.h"
#include "PetlaUAR.h"
#include "RegulatorPID.h"
#include "ObiektStatyczny.h"
#include "ModelARX.h"
#include "Square.h"
#include <iostream>

int main()
{
    double signalFreq;
    double signalAmplitude;
    double signalFill;
    double k;
    double Ti;
    double Td;
    std::vector<double> a = { 0.0 };
    std::vector<double> b = { 0.0 };
    unsigned int arxK;
    double noise;

    std::cout << "Podaj podaj warto�ci dla sygna�u" << std::endl;
    std::cout << "Podaj amplitud� sygna�u: " << std::endl;
    std::cin >> signalAmplitude;
    std::cout << "Podaj cz�stotliwo�� sygna�u: " << std::endl;
    std::cin >> signalFreq;
    std::cout << "Podaj wype�nienie sygna�u: " << std::endl;
    std::cin >> signalFill;
    std::cout << "Podaj warto�ci dla regulatora PID" << std::endl;
    std::cout << "Podaj wzmocnienie regulatora: " << std::endl;
    std::cin >> k;
    std::cout << "Podaj czas ca�kowania regulatora: " << std::endl;
    std::cin >> Ti;
    std::cout << "Podaj czas r�niczkowania regulatora: " << std::endl;
    std::cin >> Td;
    std::cout << "Podaj wsp�czynnik AR" << std::endl << std::endl;
    std::cin >> a[0];
    std::cout << "Podaj wsp�czynnik X" << std::endl << std::endl;
    std::cin >> b[0];
    std::cout << "Podaj op�nienie transportowe (liczba pr�bek): " << std::endl;
    std::cin >> arxK;
    std::cout << "Podaj odchylenie standardowe zak��cenia (szumu): " << std::endl;
    std::cin >> noise;


    Config config;

    auto petla = std::make_unique<PetlaUAR>(true); // true = zamkni�ta p�tla

    auto generator = std::make_unique<Square>(signalAmplitude, signalFreq, signalFreq);

    petla->AddComponent(std::make_unique<RegulatorPID>(k, Ti, Td));
    petla->AddComponent(std::make_unique<ModelARX>(
        a, b, arxK, noise));

    config.signalGenerator = std::move(generator);
    config.loop = std::move(petla);

    for (int t = 0; t < config.sampleNumber; ++t) {
        double yzad = config.signalGenerator->Symuluj(t);
        double y = config.loop->Symuluj(yzad);
        std::cout << "t=" << t << " yzad=" << yzad << " y=" << y << std::endl;
    }

}