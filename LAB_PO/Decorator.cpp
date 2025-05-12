#include "Decorator.h"

Decorator::Decorator(SignalGenerator* signalGenerator) : signalType(signalGenerator)
{

}

Decorator::~Decorator()
{
	delete signalType;
}

double Decorator::Generate(int sample)
{
	//TODO sprawdzic
	return signalType->Generate(sample);
}

void Decorator::Serialize(const std::string& path) const
{
	signalType->Serialize(path);
}

void Decorator::Deserialize(const std::string& path)
{
	signalType->Deserialize(path);
}