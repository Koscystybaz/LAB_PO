#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"

/**
 * @brief Klasa ta reprezentuje sygna� sinusoidalny dziedzicz�ca po klasie Signal.
 * Zawiera implementacj� funkcji Symuluj, kt�ra oblicza warto�� sygna�u sinusoidalnego w danym czasie.
 */
class Sine : public Signal
{
public:

	/**
	 * @brief Konstruktor domy�lny klasy Sine
	 */
	Sine() = default;

	/**
	 * @brief Konstruktor klasy Sine
	 * @param amplitude Amplituda fali sinusoidalnej
	 * @param frequency Cz�stotliwo�� fali sinusoidalnej
	 */
	Sine(double amplitude, double frequency);

	/**
	 * @brief Funkcja symuluj�ca sygna� sinusoidalny
	 * @param t Czas, dla kt�rego ma zosta� obliczona warto�� sygna�u
	 * @return Warto�� sygna�u sinusoidalnego w danym czasie
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
	double amplitude;
	double frequency;
};