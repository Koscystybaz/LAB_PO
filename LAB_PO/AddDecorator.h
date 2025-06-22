#pragma once
#include "Decorator.h"


/**
* @brief Klasa dekoratora sygna�u, kt�ry dodaje warto�� drugiego sygna�u do pierwszego.
* Klasa ta dziedziczy po klasie Decorator i implementuje metod� Symuluj,
* kt�ra zwraca sum� warto�ci obu sygna��w.
*/
class AddDecorator : public Decorator 
{
public:
    /**
	* @brief Konstruktor dekoratora, kt�ry przyjmuje dwa sygna�y.
	* @param comp1 Pierwszy sygna� do dekoracji.
	* @param comp2 Drugi sygna� do dekoracji.
    */
    AddDecorator(Signal* comp1, Signal* comp2);

	/**
	* @brief Metoda symuluj�ca dzia�anie dekoratora.
	* @param t Czas symulacji.
	* @return Suma warto�ci obu sygna��w w czasie t.
    */
	double Symuluj(int t) override;

private:
    std::unique_ptr<Signal> secondSignal;
};
