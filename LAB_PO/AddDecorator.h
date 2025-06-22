#pragma once
#include "Decorator.h"


/**
* @Author Jakub Dudek
* @Class AddDecorator
* @brief Klasa dekoratora sygna�u, kt�ry dodaje warto�� drugiego sygna�u do pierwszego.
* Klasa ta dziedziczy po klasie Decorator i implementuje metod� Symuluj,
* kt�ra zwraca sum� warto�ci obu sygna��w.
* @param secondSignal Wska�nik do drugiego sygna�u, kt�ry b�dzie dodawany do pierwszego sygna�u.
*/
class AddDecorator : public Decorator 
{
public:

	/**
	* @brief Domy�lny konstruktor dekoratora.
	*/
	AddDecorator() : Decorator(nullptr), secondSignal(nullptr) {}

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

	/**
	* @brief Funkcja serializuj�ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj�cy stan obiektu
	*/
	nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj�ca obiekt z pliku
	* @param json Obiekt JSON zawieraj�cy dane do deserializacji
	*/
	void Deserialize(const nlohmann::json& json) override;

private:
    std::unique_ptr<Signal> secondSignal;
};
