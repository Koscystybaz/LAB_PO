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

void Square::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "Square";
	json["Amplitude"] = this->amplitude;
	json["Frequency"] = this->frequency;
	json["Fill"] = this->fill;

	std::ofstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
	file << json.dump(4);
	file.close();
}

void Square::Deserialize(const std::string& path)
{
	std::ifstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do odczytu");

	nlohmann::json json;
	file >> json;
	if (json["Type"] != "Square")
		throw std::runtime_error("Nieprawid³owy typ sygna³u");
	this->amplitude = json["Amplitude"].get<double>();
	this->frequency = json["Frequency"].get<double>();
	this->fill = json["Fill"].get<double>();
	file.close();
}