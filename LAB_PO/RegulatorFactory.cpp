#include "RegulatorFactory.h"

std::unique_ptr<RegulatorPID> CreateRegulatorFromJson(const nlohmann::json& json) {
    std::string type = json.at("type").get<std::string>();
    if (type == "RegulatorPID") {
        auto ptr = std::make_unique<RegulatorPID>();
        ptr->Deserialize(json);
        return ptr;
    }
    throw std::runtime_error("Unknown regulator type: " + type);
}
