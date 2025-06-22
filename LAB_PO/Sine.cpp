#include "Sine.h"

Sine::Sine(double amplitude, double frequency)
	: amplitude(amplitude), frequency(frequency) 
{

}

double Sine::Symuluj(int t) 
{
	return this->amplitude * sin(2 * M_PI * this->frequency * t);
}

nlohmann::json Sine::Serialize() const
{
	return { {"Type", "Sine"}, {"Amplitude", this->amplitude}, {"Frequency", this->frequency} };
}

void Sine::Deserialize(const nlohmann::json& json)
{
	this->amplitude = json.at("Amplitude").get<double>();
	this->frequency = json.at("Frequency").get<double>();
}