#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Decorator.h"

/**
* @brief Klasa dekoratora sygna�u, kt�ry ogranicza warto�� sygna�u do maksymalnej warto�ci.
* Klasa ta dziedziczy po klasie Decorator i implementuje metod� Symuluj,
* kt�ra zwraca warto�� sygna�u ograniczon� do maksymalnej warto�ci.
*/
class SaturationDecorator : public Decorator {
private:
    double maxVal;

public:

    /**
	* @brief Konstruktor domy�lny dekoratora saturacji.
    */
    SaturationDecorator() : Decorator(nullptr), maxVal(0.0) {}

	/**
	* @brief Konstruktor dekoratora saturacji.
	* @param comp Wska�nik do sygna�u, kt�ry ma by� dekorowany.
	* @param maxVal Maksymalna warto��, do kt�rej sygna� b�dzie ograniczany.
    */
    SaturationDecorator(Signal* comp, double maxVal);

    /**
	* @brief Metoda symuluj�ca sygna� z ograniczeniem do maksymalnej warto�ci.
	* @param t Czas symulacji.
	* @return Ograniczona warto�� sygna�u.
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
};
