#pragma once
#include <memory>
#include <nlohmann/json.hpp>
#include "ObiektSISO.h"

std::unique_ptr<ObiektSISO> CreateObiektSISOFromJson(const nlohmann::json& j);