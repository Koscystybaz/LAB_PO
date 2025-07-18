#pragma once

#include <string>
#include <memory>
#include <nlohmann/json.hpp>
#include "PetlaUAR.h"
#include "Signal.h"

class Config
{
public:

    Config() = default;

    ~Config() = default;

    void SaveToFile(const std::string& fileName) const;

    void LoadFromFile(const std::string& fileName);

    nlohmann::json Serialize() const;

    void Deserialize(const nlohmann::json& json);

    double Symuluj(int input);

    unsigned int sampleNumber = 100;

    std::unique_ptr<Signal> signalGenerator = nullptr;

    std::unique_ptr<PetlaUAR> loop = nullptr;
};