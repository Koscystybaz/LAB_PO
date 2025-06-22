#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Decorator.h"

/**
* @brief Klasa dekoratora sygna³u, który ogranicza wartoœæ sygna³u do maksymalnej wartoœci.
* Klasa ta dziedziczy po klasie Decorator i implementuje metodê Symuluj,
* która zwraca wartoœæ sygna³u ograniczon¹ do maksymalnej wartoœci.
*/
class SaturationDecorator : public Decorator {
private:
    double maxVal;

public:

    /**
	* @brief Konstruktor domyœlny dekoratora saturacji.
    */
    SaturationDecorator() : Decorator(nullptr), maxVal(0.0) {}

	/**
	* @brief Konstruktor dekoratora saturacji.
	* @param comp WskaŸnik do sygna³u, który ma byæ dekorowany.
	* @param maxVal Maksymalna wartoœæ, do której sygna³ bêdzie ograniczany.
    */
    SaturationDecorator(Signal* comp, double maxVal);

    /**
	* @brief Metoda symuluj¹ca sygna³ z ograniczeniem do maksymalnej wartoœci.
	* @param t Czas symulacji.
	* @return Ograniczona wartoœæ sygna³u.
    */
    double Symuluj(int t) override;

	/**
	* @brief Funkcja serializuj¹ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj¹cy stan obiektu
	*/
	nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param json Obiekt JSON zawieraj¹cy dane do deserializacji
	*/
	void Deserialize(const nlohmann::json& json) override;
};
