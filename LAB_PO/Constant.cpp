#include "Constant.h"

Constant::Constant(double value) : value(value)
{

}

double Constant::Symuluj(int t)
{
	return this->value;
}

void Constant::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["Type"] = "Constant";
	json["Value"] = this->value;

	std::ofstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do zapisu");
	file << json.dump(4);
	file.close();
}

void Constant::Deserialize(const std::string& path)
{
	std::ifstream file(path);
	if (!file) throw std::runtime_error("Nie mo¿na otworzyæ pliku do odczytu");

	nlohmann::json json;
	file >> json;
	if (json["Type"] != "Constant")
		throw std::runtime_error("Nieprawid³owy typ sygna³u");
	this->value = json["Value"].get<double>();
	file.close();
}
