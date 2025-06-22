#include "SignalFactory.h"
#include "Constant.h"
#include "Signal.h"
#include "SaturationDecorator.h"
#include "AddDecorator.h"
#include "Sine.h"
#include "Square.h"
#include "Triangle.h"
#include "WhiteNoise.h"
#include "RecursiveSine.h"


std::unique_ptr<Signal> CreateSignalFromJson(const nlohmann::json& j) {
    std::string type = j.at("Type").get<std::string>();
    if (type == "AddDecorator") {
        auto ptr = std::make_unique<AddDecorator>();
        ptr->Deserialize(j);
        return ptr;
    }
	if (type == "SaturationDecorator") {
		auto ptr = std::make_unique<SaturationDecorator>();
		ptr->Deserialize(j);
		return ptr;
	}
	if (type == "Constant")
	{
		auto ptr = std::make_unique<Constant>();
		ptr->Deserialize(j);
		return ptr;
	}
	if (type == "Sine") {
		auto ptr = std::make_unique<Sine>();
		ptr->Deserialize(j);
		return ptr;
	}
	if (type == "Square")
	{
		auto ptr = std::make_unique<Square>();
		ptr->Deserialize(j);
		return ptr;
	}
	if (type == "Triangle")
	{
		auto ptr = std::make_unique<Triangle>();
		ptr->Deserialize(j);
		return ptr;
	}
	if (type == "WhiteNoise")
	{
		auto ptr = std::make_unique<WhiteNoise>();
		ptr->Deserialize(j);
		return ptr;
	}
	if (type == "RecursiveSine")
	{
		auto ptr = std::make_unique<RecursiveSine>();
		ptr->Deserialize(j);
		return ptr;
	}

    throw std::runtime_error("Unknown signal type: " + type);
}
