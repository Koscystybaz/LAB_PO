#include "SaturationDecorator.h"

SaturationDecorator::SaturationDecorator(SignalGenerator* signalGenerator, double saturationLevel)
: Decorator(signalGenerator), saturationLevel(saturationLevel)
{

}

double SaturationDecorator::Generate(int sample)
{
	double generatedSample = signalType->Generate(sample);
	if (generatedSample > saturationLevel) {
		return saturationLevel;
	}
	else if (generatedSample < -saturationLevel) {
		return -saturationLevel;
	}
	return generatedSample;
}

void SaturationDecorator::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "SaturationDecorator";
	json["SaturationLevel"] = saturationLevel;

	nlohmann::json decorated_json;
	signalType->Serialize(decorated_json); 
	json["Decorated"] = decorated_json;

	std::ofstream file(path);
	file << json.dump(4);
}