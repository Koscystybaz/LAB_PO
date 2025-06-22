#pragma once
#include "Decorator.h"


/**
* @brief Klasa dekoratora sygna³u, który dodaje wartoœæ drugiego sygna³u do pierwszego.
* Klasa ta dziedziczy po klasie Decorator i implementuje metodê Symuluj,
* która zwraca sumê wartoœci obu sygna³ów.
*/
class AddDecorator : public Decorator 
{
public:
    /**
	* @brief Konstruktor dekoratora, który przyjmuje dwa sygna³y.
	* @param comp1 Pierwszy sygna³ do dekoracji.
	* @param comp2 Drugi sygna³ do dekoracji.
    */
    AddDecorator(Signal* comp1, Signal* comp2);

	/**
	* @brief Metoda symuluj¹ca dzia³anie dekoratora.
	* @param t Czas symulacji.
	* @return Suma wartoœci obu sygna³ów w czasie t.
    */
	double Symuluj(int t) override;

private:
    std::unique_ptr<Signal> secondSignal;
};
