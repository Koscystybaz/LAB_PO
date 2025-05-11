#include "PetlaSprzerzeniaZwrotnego.h"

double PetlaSprzerzeniaZwrotnego::operator()(RegulatorPID& regulator, ModelARX& model, const double setValue)
{
	double lastInput = model.GetLastInput();
	double input = setValue - lastInput;
	double control = regulator.Symuluj(input);
	double output = model.Symuluj(control);
	return output;
}