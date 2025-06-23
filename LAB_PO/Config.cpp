#include "Config.h"
#include "SignalFactory.h"

void Config::SaveToFile(const std::string& fileName) const
{
	std::ofstream file(fileName);
	file << Serialize().dump(4);
	file.close();
}

void Config::LoadFromFile(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open()) 
	{
		throw std::runtime_error("Could not open file: " + fileName);
	}
	nlohmann::json json;
	file >> json;
	Deserialize(json);
	file.close();
}

nlohmann::json Config::Serialize() const
{
	nlohmann::json json;
	json["SampleNumber"] = sampleNumber;

	if (signalGenerator) 
	{
		json["SignalGenerator"] = signalGenerator->Serialize();
	}
	if (loop) 
	{
		json["Loop"] = loop->Serialize();
	}
	return json;
}

void Config::Deserialize(const nlohmann::json& json)
{
	this->sampleNumber = json.value("liczbaKrokow", 10);
	if (!json.at("Generator").is_null())
	{
		signalGenerator = CreateSignalFromJson(json.at("Generator"));
	}
	if (!json.at("Loop").is_null()) {
		loop = std::make_unique<PetlaUAR>();
		loop->Deserialize(j.at("petla"));
	}
}