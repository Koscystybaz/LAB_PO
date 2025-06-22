#include "ObiektStatyczny.h"

ObiektStatyczny::ObiektStatyczny(double min = -1.0, double max = 1.0)
	: ObiektSISO(), minX(min), maxX(max)
{

}

double ObiektStatyczny::Symuluj(double input)
{
	return std::clamp(input, minX, maxX);
}

nlohmann::json ObiektStatyczny::Serialize() const
{
    return { {"Type", "ObiektStatyczny"}, {"MinX", minX}, {"MaxX", maxX} };
}

void ObiektStatyczny::Deserialize(const nlohmann::json& j)
{
    minX = j.at("MinX").get<double>();
    maxX = j.at("MaxX").get<double>();
}

