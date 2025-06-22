#pragma once
#include <memory>
#include <nlohmann/json.hpp>
#include "ObiektSISO.h"

/**
* @Author Jakub Dudek
* @function CreateObiektSISOFromJson
* @brief Funkcja tworzy obiekt SISO sygna³u na podstawie danych JSON.
* @param json Obiekt JSON zawieraj¹cy dane modelu sygna³u.
*/
std::unique_ptr<ObiektSISO> CreateObiektSISOFromJson(const nlohmann::json& j);