#include <stdexcept>
#include "RegulatorPID.h"

RegulatorPID::RegulatorPID(double k) : k(k), Ti(0.0), Td(0.0), sumOfErrors(0.0), lastError(0.0)
{
	ValidateParameters();
}

RegulatorPID::RegulatorPID(double k, double Ti) : k(k), Ti(Ti), Td(0.0), sumOfErrors(0.0), lastError(0.0)
{
	ValidateParameters();
}

RegulatorPID::RegulatorPID(double k, double Ti, double Td) : k(k), Ti(Ti), Td(Td), sumOfErrors(0.0), lastError(0.0)
{
	ValidateParameters();
}

RegulatorPID::~RegulatorPID()
{

}

double RegulatorPID::Symuluj(double input)
{
	this->sumOfErrors += input;
	double errorDiffirence = input - this->lastError;
	double output = this->k * input 
					+ (this->Ti != 0.0 ? (this->sumOfErrors / this->Ti) : 0.0)
					+ this->Td * errorDiffirence;
	this->lastError = input;
	return output;
}

void RegulatorPID::ValidateParameters() const
{
	if (this->k < 0 || this->Ti < 0 || this->Td < 0)
	{
		throw std::invalid_argument("Wszystkie parametry regulatora PID musz¹ byæ wiêksze od zera.");
	}
}

void RegulatorPID::SetP(double p)
{
	this->k = p;
	ValidateParameters();
}

void RegulatorPID::setPI(double p, double i)
{
	this->k = p;
	this->Ti = i;
	ValidateParameters();
	
}

void RegulatorPID::setPID(double p, double i, double d)
{
	this->k = p;
	this->Ti = i;
	this->Td = d;
	ValidateParameters();
}

nlohmann::json RegulatorPID::Serialize() const
{
	return {
	   {"Type", "RegulatorPID"},
	   {"K", k},
	   {"Ti", Ti},
	   {"Td", Td},
	   {"SumOfErrors", sumOfErrors},
	   {"LastError", lastError}
	};
}

void RegulatorPID::Deserialize(const nlohmann::json& json)
{
	k = json.at("K").get<double>();
	Ti = json.at("Ti").get<double>();
	Td = json.at("Td").get<double>();
	sumOfErrors = json.at("SumOfErrors").get<double>();
	lastError = json.at("LastError").get<double>();
} 