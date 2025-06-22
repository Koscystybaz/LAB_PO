#include "SaturationDecorator.h"
#include "SignalFactory.h"

SaturationDecorator::SaturationDecorator(Signal* comp, double maxVal)
	: Decorator(comp), maxVal(maxVal)
{

}

double SaturationDecorator::Symuluj(int t) 
{
	double wartosc = component->Symuluj(t);
	return std::clamp(wartosc, -maxVal, maxVal);
}

nlohmann::json SaturationDecorator::Serialize() const
{
	return
	{
		{"Type", "SaturationDecorator"},
		{"MaxVal", maxVal},
		{"Component", component ? component->Serialize() : nlohmann::json()}
	};
}

void SaturationDecorator::Deserialize(const nlohmann::json& json)
{
	if (!json.contains("MaxVal") || !json.contains("Component"))
	{
		throw std::runtime_error("SaturationDecorator JSON missing MaxVal or Component");
	}
	maxVal = json["MaxVal"].get<double>();
	component = CreateSignalFromJson(json["Component"]);
}