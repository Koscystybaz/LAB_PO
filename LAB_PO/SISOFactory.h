#pragma once
#include <memory>
#include <nlohmann/json.hpp>
#include "ObiektSISO.h"

/**
* @Author Jakub Dudek
* @function CreateObiektSISOFromJson
* @brief Funkcja tworzy obiekt SISO sygna�u na podstawie danych JSON.
* @param json Obiekt JSON zawieraj�cy dane modelu sygna�u.
*/
std::unique_ptr<ObiektSISO> CreateObiektSISOFromJson(const nlohmann::json& j);