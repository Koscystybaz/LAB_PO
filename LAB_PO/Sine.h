#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"
#include "ISerializable.h"

/**
 * @brief Klasa ta reprezentuje sygna³ sinusoidalny dziedzicz¹ca po klasie Signal.
 * Zawiera implementacjê funkcji Symuluj, która oblicza wartoœæ sygna³u sinusoidalnego w danym czasie.
 */
class Sine : public Signal, public ISerializable
{
public:
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
	 * @brief Funkcja serializuj¹ca obiekt do pliku JSON
	 * @param path Œcie¿ka do pliku, do którego zostan¹ zapisane dane obiektu
	 */
	void Serialize(const std::string& path) const override;

	/**
	 * @brief Funkcja deserializuj¹ca obiekt z pliku JSON
	 * @param path Œcie¿ka do pliku, z którego zostan¹ odczytane dane obiektu
	 */
	void Deserialize(const std::string& path) override;


private:
	double amplitude;
	double frequency;
};