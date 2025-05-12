#include "SquareDecorator.h"

SquareDecorator::SquareDecorator(SignalGenerator* signalType, double amplitude, int frequency, double fill)
	: Decorator(signalType), amplitude(amplitude), frequency(frequency), fill(fill)
{

}

double SquareDecorator::Generate(int sample)
{
	int val = sample % frequency;
	double result = (val < (frequency * fill)) ? amplitude : 0.0;
	return signalType->Generate(sample) + result;
}

void SquareDecorator::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "SquareDecorator";

	nlohmann::json decorated_json;
	signalType->Serialize(decorated_json);
	json["Decorated"] = decorated_json;

	std::ofstream file(path);
	file << json.dump(4);
}