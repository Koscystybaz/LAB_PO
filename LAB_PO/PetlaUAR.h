#pragma once
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include "ObiektSISO.h"

std::unique_ptr<ObiektSISO> CreateObiektSISOFromJson(const nlohmann::json& json);

class PetlaUAR : public ObiektSISO 
{
public:

	PetlaUAR() = default;

    PetlaUAR(bool close, double startingY = 0.0);

    void AddComponent(std::unique_ptr<ObiektSISO>&& component);

    void AddComponentAt(std::unique_ptr<ObiektSISO>&& componentn, size_t index);

	void DeleteComponent(size_t index);

    double Symuluj(double input) override;

    void SetClose(bool closeLoop);

	bool IsClosed() const;
 
    nlohmann::json Serialize() const override;

    void Deserialize(const nlohmann::json& j) override;


private:
    bool close;
    double previousY;
    std::vector<std::unique_ptr<ObiektSISO>> components;

};