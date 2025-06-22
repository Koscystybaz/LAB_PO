#include "Triangle.h"

Triangle::Triangle(double amp, double freq)
	: amplitude(amp), frequency(freq)
{

}

double Triangle::Symuluj(int t)
{
    int period = static_cast<int>(100.0 / frequency);
    int pos = t % period;
    double normalized = static_cast<double>(pos) / period;

    if (normalized <= 0.5) {
        return amplitude * (4.0 * normalized - 1.0);
    }
    else 
    {
        return amplitude * (3.0 - 4.0 * normalized);
    }
}

nlohmann::json Triangle::Serialize() const
{
	return { {"Type", "Triangle"}, {"Amplitude", this->amplitude}, {"Frequency", this->frequency} };
}

void Triangle::Deserialize(const nlohmann::json& json)
{
	this->amplitude = json.at("Amplitude").get<double>();
	this->frequency = json.at("Frequency").get<double>();
}