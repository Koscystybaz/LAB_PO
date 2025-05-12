#include "ConstantSignal.h"

ConstantSignal::ConstantSignal(double value) : value(value)
{

}

double ConstantSignal::Generate(int sample)
{
	return this->value;
}

void ConstantSignal::Serialize(const std::string& path) const
{
	nlohmann::json json;
	json["SignalValue"] = value;

	std::ofstream file(path);
	if (file.is_open()) {
		file << json.dump(4);
		file.close();
	}
}
