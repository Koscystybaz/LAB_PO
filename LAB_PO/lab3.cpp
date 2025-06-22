#include <iostream>
#include <memory>
#include <iomanip>
#include "Signal.h"
#include "SaturationDecorator.h"
#include "AddDecorator.h"
#include "Sine.h"
#include "Square.h"
#include "WhiteNoise.h"
#include "Constant.h"
#include "RegulatorPID.h"
#include "nlohmann/json.hpp"
#include "SignalFactory.h"

//int main() {
//    // Tworzenie sygna³u z³o¿onego z wzorca dekorator
//    std::unique_ptr<Signal> sygnal_zlozony(
//        new SaturationDecorator(
//            new AddDecorator(
//                new AddDecorator(
//                    new Sine(1.0, 1.0),
//                    new Square(0.5, 2.0, 0.5)
//                ),
//                new WhiteNoise(0.1)
//            ),
//            2.0  // ograniczenie amplitudy
//        )
//    );
//
//    // Symulacja dla 50 próbek
//    std::cout << "t\tWartoœæ sygna³u" << std::endl;
//    for (int t = 0; t < 50; ++t) {
//        double wartosc = sygnal_zlozony->Symuluj(t);
//        std::cout << t << "\t" << wartosc << std::endl;
//    }
//
//    //// Test generatora rekurencyjnego
//    //std::cout << "\nGenerator rekurencyjny:" << std::endl;
//    //GeneratorSinusaRekurencyjny gen_rek(1.0, 1.0);
//    //for (int t = 0; t < 20; ++t) {
//    //    std::cout << t << "\t" << gen_rek.symuluj(t) << std::endl;
//    //}
//
//    return 0;
//}



int main() {

constexpr size_t LICZ_ITER = 50;

// Sk³adamy sygna³ z kilku generatorów i dekoratorów
// Sygna³: suma sinusoidy (amp=1, okres=20), prostok¹ta (amp=0.5, okres=10, wyp=0.3), szumu bia³ego (amp=0.2)
// Ca³oœæ ograniczona do [-1.2, 1.2]
//std::unique_ptr<Signal> generator(
//    new SaturationDecorator(
//        new AddDecorator(
//            new AddDecorator(
//                new Sine(1.0, 20),
//                new Square(0.5, 10, 0.3)
//            ),
//            new WhiteNoise(0.2)
//        ),
//        1.2
//    )
//);
//
//// Przygotuj sygna³ wejœciowy
//std::vector<double> sygWe(LICZ_ITER);
//for (int i = 0; i < LICZ_ITER; ++i)
//    sygWe[i] = generator->Symuluj(i);
//
//// Symulacja uk³adu z poprzedniego laboratorium (np. regulator P)
//RegulatorPID regulator(0.5); // tylko wzmocnienie proporcjonalne
//
//std::vector<double> sygWy(LICZ_ITER);
//for (int i = 0; i < LICZ_ITER; ++i)
//    sygWy[i] = regulator.Symuluj(sygWe[i]);
//
//// Wynik: czas, wejœcie, wyjœcie
//std::cout << std::fixed << std::setprecision(3);
//std::cout << "# t\twejscie\twyjscie\n";
//for (int i = 0; i < LICZ_ITER; ++i)
//    std::cout << i << "\t" << sygWe[i] << "\t" << sygWy[i] << "\n";


// Serializacja sygna³u do pliku JSON


std::unique_ptr<Signal> generator(
    new SaturationDecorator(
        new AddDecorator(
            new AddDecorator(
                new Sine(1.0, 20),
                new Square(0.5, 10, 0.3)
            ),
            new WhiteNoise(0.2)
        ),
        1.2
    )
);

// Serializacja do pliku
nlohmann::json j = generator->Serialize();
std::ofstream file("generator.json");
if (!file.is_open()) {
    std::cerr << "Failed to create generator.json for writing\n";
    return 1;
}
file << j.dump(4);
file.close();

//Deserializacja z pliku
std::ifstream file_in("generator.json");
if (!file_in.is_open()) {
    std::cerr << "Failed to open generator.json for reading\n";
    return 1;
}
nlohmann::json j_in;
file_in >> j_in;
auto generator2 = CreateSignalFromJson(j_in);

// Testowanie dzia³ania zdeserializowanego generatora

bool ok = true;
for (int t = 0; t < 5; ++t) {
    double val = generator->Symuluj(t);
    std::cout << "t=" << t << "  wynik=" << val << std::endl;
    if (val != 1.5) ok = false;
}

if (ok)
std::cout << "Test OK: wynik zawsze 1.5" << std::endl;
else
std::cout << "Test NIEPOWODZENIE: wynik niezgodny z oczekiwaniem!" << std::endl;

return 0;
}