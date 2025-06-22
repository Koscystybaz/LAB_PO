#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <iomanip>
#include "PetlaUAR.h"
#include "RegulatorPID.h"
#include "ObiektStatyczny.h"
#include "ModelARX.h"

int main() {
    // 1. Build the loop
    auto loop = std::make_unique<PetlaUAR>(true);
    loop->AddComponent(std::make_unique<RegulatorPID>(0.5, 0.1, 0.01));
    loop->AddComponent(std::make_unique<ObiektStatyczny>(-1.0, 1.0));
    loop->AddComponent(std::make_unique<ModelARX>(
        std::vector<double>{0.5}, std::vector<double>{0.3}, 1, 0.00));

    // 2. Simulate t=0...4
    std::vector<double> results;
    for (int t = 0; t < 5; ++t) {
        double y = loop->Symuluj(1.0);
        results.push_back(y);
        std::cout << "Original t=" << t << "  y=" << y << std::endl;
    }

    // 3. Serialize after t=4
    nlohmann::json j = loop->Serialize();
    std::ofstream file("petla_test.json");
    file << j.dump(4);
    file.close();

    // 4. Continue simulation t=5...9
    std::vector<double> originalResults;
    for (int t = 5; t < 10; ++t) {
        double y = loop->Symuluj(1.0);
        originalResults.push_back(y);
        std::cout << "Original t=" << t << "  y=" << y << std::endl;
    }

    // 5. Deserialize into new object
    std::ifstream file_in("petla_test.json");
    nlohmann::json j_in;
    file_in >> j_in;
    auto loop2 = std::make_unique<PetlaUAR>();
    loop2->Deserialize(j_in);

    // 6. Simulate t=5...9 on deserialized object
    std::vector<double> deserializedResults;
    for (int t = 5; t < 10; ++t) {
        double y = loop2->Symuluj(1.0);
        deserializedResults.push_back(y);
        std::cout << "Deserialized t=" << t << "  y=" << y << std::endl;
    }

    // 7. Compare results
    std::cout << "\nOriginal Results (t=5...9): ";
    for (auto v : originalResults) std::cout << v << " ";
    std::cout << "\nDeserialized Results (t=5...9): ";
    for (auto v : deserializedResults) std::cout << v << " ";
    std::cout << std::endl;

    // 8. Continuity test
    bool ok = true;
    for (size_t i = 0; i < originalResults.size(); ++i) {
        if (std::abs(originalResults[i] - deserializedResults[i]) > 1e-6) {
            ok = false;
            break;
        }
    }

    if (ok)
        std::cout << "Simulation continuity test OK!" << std::endl;
    else
        std::cout << "Error: The continuity of the simulation has been interrupted!" << std::endl;

    return 0;
}