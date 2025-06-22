#include "WhiteNoise.h"

WhiteNoise::WhiteNoise(double amplitude)
	: amplitude(amplitude), 
	generator(std::random_device{}()),
	distribution(0.0, 1.0) 
{

}

double WhiteNoise::Symuluj(int t) 
{
	return amplitude * distribution(generator);
}

nlohmann::json WhiteNoise::Serialize() const
{
	return { {"Type", "WhiteNoise"}, {"Amplitude", this->amplitude} };
}

void WhiteNoise::Deserialize(const nlohmann::json& json)
{
	this->amplitude = json.at("Amplitude").get<double>();
}