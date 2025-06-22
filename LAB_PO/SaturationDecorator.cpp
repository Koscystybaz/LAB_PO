#include "SaturationDecorator.h"

SaturationDecorator::SaturationDecorator(Signal* comp, double maxVal)
	: Decorator(comp), maxVal(maxVal)
{

}

double SaturationDecorator::Symuluj(int t) 
{
	double wartosc = component->Symuluj(t);
	return std::clamp(wartosc, -maxVal, maxVal);
}