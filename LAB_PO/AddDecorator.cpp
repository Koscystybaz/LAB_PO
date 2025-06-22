#include "AddDecorator.h"
#include "SignalFactory.h"

AddDecorator::AddDecorator(Signal* comp1, Signal* comp2)
	: Decorator(comp1), secondSignal(comp2)
{

}

double AddDecorator::Symuluj(int t) 
{
	return component->Symuluj(t) + secondSignal->Symuluj(t);
}

nlohmann::json AddDecorator::Serialize() const
{
	return 
    { 
        {"Type", "AddDecorator"},
        {"Component1", component ? component->Serialize() : nlohmann::json()},
        {"Component2", secondSignal ? secondSignal->Serialize() : nlohmann::json()}
    };
}

void AddDecorator::Deserialize(const nlohmann::json& json)
{
    if (!json.contains("Component1") || !json.contains("Component2")) {
        throw std::runtime_error("AddDecorator JSON missing Component1 or Component2");
    }
    component = CreateSignalFromJson(json.at("Component1"));
    secondSignal = CreateSignalFromJson(json.at("Component2"));
}