#pragma once
#include "ObiektSISO.h"
#include <algorithm>

class ObiektStatyczny : public ObiektSISO {

public:

	ObiektStatyczny() = default;

    ObiektStatyczny(double min, double max);

    double Symuluj(double input) override;

    nlohmann::json Serialize() const override;

    void Deserialize(const nlohmann::json& j) override;

    
private:
    double minX;
    double maxX;
};
