#include "SISOFactory.h"
#include "RegulatorPID.h"
#include "ModelARX.h"
#include "ObiektStatyczny.h"
#include "PetlaUAR.h"

std::unique_ptr<ObiektSISO> CreateObiektSISOFromJson(const nlohmann::json& json) 
{
    std::string type = json.at("Type").get<std::string>();
    if (type == "RegulatorPID") {
        auto ptr = std::make_unique<RegulatorPID>();
        ptr->Deserialize(json);
        return ptr;
    }
    else if (type == "ModelARX") {
        auto ptr = std::make_unique<ModelARX>();
        ptr->Deserialize(json);
        return ptr;
    }
    else if (type == "ObiektStatyczny") {
        auto ptr = std::make_unique<ObiektStatyczny>();
        ptr->Deserialize(json);
        return ptr;
    }
    else if (type == "PetlaUAR") {
        auto ptr = std::make_unique<PetlaUAR>();
        ptr->Deserialize(json);
        return ptr;
    }
    throw std::runtime_error("Unknown SISO object type: " + type);
}