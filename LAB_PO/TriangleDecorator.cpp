#include "TriangleDecorator.h"

TriangleDecorator::TriangleDecorator(SignalGenerator* signalType, double amplitude, int period, double saturation)
	: Decorator(signalType), amplitude(amplitude), period(period), saturation(saturation) 
{

}

double TriangleDecorator::Generate(int sample)
{
	int value = sample % period;
	double phase = static_cast<double>(value) / period;
	double out = phase < saturation
		? (2 * amplitude / saturation) * phase - amplitude
		: (-2 * amplitude / (1 - saturation)) * (phase - saturation) + amplitude;
	return signalType->Generate(sample) + out;
}

void TriangleDecorator::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "TriangleDecorator";

	nlohmann::json decorated_json;
	signalType->Serialize(decorated_json);
	json["Decorated"] = decorated_json;

	std::ofstream file(path);
	file << json.dump(4);
}