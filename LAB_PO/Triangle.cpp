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

void Triangle::Serialise(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "Triangle";
	json["Amplitude"] = this->amplitude;
	json["Frequency"] = this->frequency;

	std::ofstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
	file << json.dump(4);
	file.close();
}

void Triangle::Deserialise(const std::string& path)
{
	std::ifstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do odczytu");

	nlohmann::json json;
	file >> json;
	if (json["Type"] != "Triangle")
		throw std::runtime_error("Nieprawid³owy typ sygna³u");
	this->amplitude = json["Amplitude"].get<double>();
	this->frequency = json["Frequency"].get<double>();
	file.close();
}