#include "Constant.h"

Constant::Constant(double value) : value(value)
{

}

double Constant::Symuluj(int t)
{
	return this->value;
}

nlohmann::json Constant::Serialize() const
{
	return { {"Type", "Constant"}, {"Value", this->value }};
}

void Constant::Deserialize(const nlohmann::json& json)
{
	this->value = json.at("Value").get<double>();
}
