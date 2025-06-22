#include <memory>
#include <nlohmann/json.hpp>
#include "ModelARX.h"

std::unique_ptr<ModelARX> CreateModelFromJson(const nlohmann::json& json) 
{
    std::string type = json.at("Type").get<std::string>();
    if (type == "ModelARX") 
    {
        auto ptr = std::make_unique<ModelARX>();
        ptr->Deserialize(json);
        return ptr;
    }
    throw std::runtime_error("Unknown model type: " + type);
}
