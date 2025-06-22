#include "AddDecorator.h"

AddDecorator::AddDecorator(Signal* comp1, Signal* comp2)
	: Decorator(comp1), secondSignal(comp2) 
{

}

double AddDecorator::Symuluj(int t) 
{
	return component->Symuluj(t) + secondSignal->Symuluj(t);
}