#pragma once
#include "Signal.h"
#include <memory>
#include <nlohmann/json.hpp>

/**
* @Author Jakub Dudek
* @function CreateSignalFromJson
* @brief Funkcja tworzy sygna� na podstawie danych JSON.
* @param json Obiekt JSON zawieraj�cy dane modelu sygna�u.
*/
std::unique_ptr<Signal> CreateSignalFromJson(const nlohmann::json& json);
