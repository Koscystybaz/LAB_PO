#pragma once
#include <memory>
#include <nlohmann/json.hpp>
#include "RegulatorPID.h"

std::unique_ptr<RegulatorPID> CreateRegulatorFromJson(const nlohmann::json& j);