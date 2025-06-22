#pragma once
#include "Signal.h"
#include <memory>
#include <nlohmann/json.hpp>

std::unique_ptr<Signal> CreateSignalFromJson(const nlohmann::json& j);
