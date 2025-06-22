#pragma once
#include "Signal.h"
#include <memory>
#include <nlohmann/json.hpp>

/**
* @Author Jakub Dudek
* @function CreateModelFromJson
* @brief Funkcja tworzy model sygna³u na podstawie danych JSON.
* @param json Obiekt JSON zawieraj¹cy dane modelu sygna³u.
*/
std::unique_ptr<Signal> CreateModelFromJson(const nlohmann::json& json);
