//#include <iostream>
//#include <memory>
//#include <iomanip>
//#include "Signal.h"
//#include "SaturationDecorator.h"
//#include "AddDecorator.h"
//#include "Sine.h"
//#include "Square.h"
//#include "WhiteNoise.h"
//#include "Constant.h"
//#include "RegulatorPID.h"
//#include "nlohmann/json.hpp"
//#include "SignalFactory.h"
//
//int main() {
//
//// Serializacja sygna³u do pliku JSON
//
//
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
//// Serializacja do pliku
//nlohmann::json j = generator->Serialize();
//std::ofstream file("generator.json");
//if (!file.is_open()) {
//    std::cerr << "Failed to create generator.json for writing\n";
//    return 1;
//}
//file << j.dump(4);
//file.close();
//
////Deserializacja z pliku
//std::ifstream file_in("generator.json");
//if (!file_in.is_open()) {
//    std::cerr << "Failed to open generator.json for reading\n";
//    return 1;
//}
//nlohmann::json j_in;
//file_in >> j_in;
//auto generator2 = CreateSignalFromJson(j_in);
//
//// Testowanie dzia³ania zdeserializowanego generatora
//
//
//for (int t = 0; t < 5; ++t) {
//    double val = generator->Symuluj(t);
//    std::cout << "t=" << t << "  wynik=" << val << std::endl;
//}
//
//return 0;
//}