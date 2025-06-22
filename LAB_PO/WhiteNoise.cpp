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

void WhiteNoise::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "WhiteNoise";
	json["Amplitude"] = this->amplitude;

	std::ofstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
	file << json.dump(4);
	file.close();
}

void WhiteNoise::Deserialize(const std::string& path)
{
	std::ifstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do odczytu");

	nlohmann::json json;
	file >> json;
	if (json["Type"] != "WhiteNoise")
		throw std::runtime_error("Nieprawid³owy typ sygna³u");
	this->amplitude = json["Amplitude"].get<double>();
	file.close();
}