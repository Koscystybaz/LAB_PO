#pragma once
#include <memory>
#include <nlohmann/json.hpp>
#include "RegulatorPID.h"

/**
* @Author Jakub Dudek
* @function CreateRegulatorFromJson
* @brief Funkcja tworzy regulator sygna³u na podstawie danych JSON.
* @param json Obiekt JSON zawieraj¹cy dane modelu sygna³u.
*/
std::unique_ptr<RegulatorPID> CreateRegulatorFromJson(const nlohmann::json& json);