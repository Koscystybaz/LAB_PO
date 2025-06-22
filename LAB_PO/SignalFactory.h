#pragma once
#include "Signal.h"
#include <memory>
#include <nlohmann/json.hpp>

/**
* @Author Jakub Dudek
* @function CreateSignalFromJson
* @brief Funkcja tworzy sygna³ na podstawie danych JSON.
* @param json Obiekt JSON zawieraj¹cy dane modelu sygna³u.
*/
std::unique_ptr<Signal> CreateSignalFromJson(const nlohmann::json& json);
