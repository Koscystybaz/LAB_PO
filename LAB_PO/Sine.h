#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"

/**
* @Author Jakub Dudek
* @Class Sine
* @brief Klasa ta reprezentuje sygnał sinusoidalny dziedzicząca po klasie Signal.
* Zawiera implementację funkcji Symuluj, która oblicza wartość sygnału sinusoidalnego w danym czasie.
* @param amplitude Amplituda fali sinusoidalnej
* @param frequency Częstotliwość fali sinusoidalnej
*/
class Sine : public Signal
{
public:

	/**
	* @brief Konstruktor domyślny klasy Sine
	*/
	Sine() = default;

	/**
	* @brief Konstruktor klasy Sine
	* @param amplitude Amplituda fali sinusoidalnej
	* @param frequency Częstotliwość fali sinusoidalnej
	*/
	Sine(double amplitude, double frequency);

	/**
	* @brief Funkcja symulująca sygnał sinusoidalny
	* @param t Czas, dla którego ma zostać obliczona wartość sygnału
	* @return Wartość sygnału sinusoidalnego w danym czasie
	*/
	double Symuluj(int t) override;

	/**
	* @brief Funkcja serializująca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentujący stan obiektu
	*/
	nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializująca obiekt z pliku
	* @param json Obiekt JSON zawierający dane do deserializacji
	*/
	void Deserialize(const nlohmann::json& json) override;

private:
	double amplitude;
	double frequency;
};