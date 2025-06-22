#include "Sine.h"

Sine::Sine(double amplitude, double frequency)
	: amplitude(amplitude), frequency(frequency) 
{

}

double Sine::Symuluj(int t) 
{
	return amplitude * sin(2 * M_PI * frequency * t);
}

void Sine::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "Sine";
	json["Amplitude"] = this->amplitude;
	json["Frequency"] = this->frequency;

	std::ofstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
	file << json.dump(4);
	file.close();
}

void Sine::Deserialize(const std::string& path)
{
	std::ifstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do odczytu");

	nlohmann::json json;
	file >> json;
	if (json["Type"] != "Sine")
		throw std::runtime_error("Nieprawid³owy typ sygna³u");
	this->amplitude = json["Amplitude"].get<double>();
	this->frequency = json["Frequency"].get<double>();
	file.close();
}