#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"

/**
 * @brief Klasa ta reprezentuje sygna³ sinusoidalny dziedzicz¹ca po klasie Signal.
 * Zawiera implementacjê funkcji Symuluj, która oblicza wartoœæ sygna³u sinusoidalnego w danym czasie.
 */
class Sine : public Signal
{
public:

	/**
	 * @brief Konstruktor domyœlny klasy Sine
	 */
	Sine() = default;

	/**
	 * @brief Konstruktor klasy Sine
	 * @param amplitude Amplituda fali sinusoidalnej
	 * @param frequency Czêstotliwoœæ fali sinusoidalnej
	 */
	Sine(double amplitude, double frequency);

	/**
	 * @brief Funkcja symuluj¹ca sygna³ sinusoidalny
	 * @param t Czas, dla którego ma zostaæ obliczona wartoœæ sygna³u
	 * @return Wartoœæ sygna³u sinusoidalnego w danym czasie
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

private:
	double amplitude;
	double frequency;
};