#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"
#include "ISerializable.h"

/**
 * @brief Klasa ta reprezentuje sygna� sinusoidalny dziedzicz�ca po klasie Signal.
 * Zawiera implementacj� funkcji Symuluj, kt�ra oblicza warto�� sygna�u sinusoidalnego w danym czasie.
 */
class Sine : public Signal, public ISerializable
{
public:
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
	 * @brief Funkcja serializuj�ca obiekt do pliku JSON
	 * @param path �cie�ka do pliku, do kt�rego zostan� zapisane dane obiektu
	 */
	void Serialize(const std::string& path) const override;

	/**
	 * @brief Funkcja deserializuj�ca obiekt z pliku JSON
	 * @param path �cie�ka do pliku, z kt�rego zostan� odczytane dane obiektu
	 */
	void Deserialize(const std::string& path) override;


private:
	double amplitude;
	double frequency;
};