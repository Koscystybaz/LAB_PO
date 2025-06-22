#pragma once
#include "Signal.h"
#include <memory>
#include <nlohmann/json.hpp>

/**
* @Author Jakub Dudek
* @function CreateModelFromJson
* @brief Funkcja tworzy model sygna�u na podstawie danych JSON.
* @param json Obiekt JSON zawieraj�cy dane modelu sygna�u.
*/
std::unique_ptr<Signal> CreateModelFromJson(const nlohmann::json& json);
