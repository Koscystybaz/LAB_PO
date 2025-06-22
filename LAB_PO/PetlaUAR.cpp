#include "PetlaUAR.h"
#include "SISOFactory.h"

PetlaUAR::PetlaUAR(bool close, double startingY)
	: close(close), previousY(startingY)
{

}

void PetlaUAR::AddComponent(std::unique_ptr<ObiektSISO>&& component)
{
	components.push_back(std::move(component));
}

void PetlaUAR::AddComponentAt(std::unique_ptr<ObiektSISO>&& component, size_t index)
{
	if (index > components.size()) 
		index = components.size();
	components.insert(components.begin() + index, std::move(component));
}

void PetlaUAR::DeleteComponent(size_t index)
{
	if (index < components.size())
	{
		components.erase(components.begin() + index);
	}
	else
	{
		throw std::out_of_range("PetlaUAR: Index out of range.");
	}
}

double PetlaUAR::Symuluj(double input) 
{
	if (components.empty())
	{
		throw std::runtime_error("PetlaUAR: No components to simulate.");
	}

	double in = input;
	if (close) 
	{
		in = input - previousY;
	}

	double out = in;
	for (auto& component : components) 
	{
		out = component->Symuluj(out);
	}

	previousY = out;
	return out;
}

bool PetlaUAR::IsClosed() const
{
	return close;
}

void PetlaUAR::SetClose(bool closeLoop)
{
	close = closeLoop;
}

nlohmann::json PetlaUAR::Serialize() const 
{
	nlohmann::json jcomponents = nlohmann::json::array();
	for (const auto& component : components) {
		jcomponents.push_back(component->Serialize());
	}
	return {
		{"Type", "PetlaUAR"},
		{"Close", close},
		{"PreviousY", previousY},
		{"Components", jcomponents}
	};
}

void PetlaUAR::Deserialize(const nlohmann::json& json) 
{
	close = json.at("Close").get<bool>();
	previousY = json.at("PreviousY").get<double>();

	components.clear();
	for (const auto& jkomp : json.at("Components")) 
	{
		components.push_back(CreateObiektSISOFromJson(jkomp));
	}
}