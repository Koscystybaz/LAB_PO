#include "WhiteNoiseDecorator.h"

WhiteNoiseDecorator::WhiteNoiseDecorator(SignalGenerator* signalType, double deviation)
	: Decorator(signalType), distribution(0.0, deviation)
{

}

double WhiteNoiseDecorator::Generate(int sample)
{
	return signalType->Generate(sample) + distribution(generator);
}

void WhiteNoiseDecorator::Serialize(const std::string& path) const
{
    nlohmann::json json;
    json["Type"] = "WhiteNoiseDecorator";
    json["deviation"] = distribution.stddev();

    nlohmann::json decorated_json;
    signalType->Serialize(decorated_json);
    json["Decorated"] = decorated_json;

    std::ofstream file(path);
    file << json.dump(4);
}