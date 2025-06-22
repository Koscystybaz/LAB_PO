#include "Square.h"

Square::Square(double amplitude, double frequency, double fill)
	: amplitude(amplitude), frequency(frequency), fill(fill)
{

}

double Square::Symuluj(int t)
{
	int period = static_cast<int>(100.0 / frequency);
	double pos = t % period;
	
	return (pos < period * fill) 
		? amplitude 
		: -amplitude;
}

nlohmann::json Square::Serialize() const
{
	return { {"Type", "Square"}, {"Amplitude", amplitude}, {"Frequency", frequency}, {"Fill", fill } };
}

void Square::Deserialize(const nlohmann::json& json)
{
	amplitude = json.at("Amplitude").get<double>();
	frequency = json.at("Frequency").get<double>();
	fill = json.at("Fill").get<double>();
}