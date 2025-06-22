#pragma once
#include <random>
#include "Signal.h"
#include "ISerializable.h"

/**
 * @brief Klasa reprezentujaca sygnal bialego szumu
 * Klasa dziedziczy po klasie Signal i implementuje metode Symuluj,
 * ktora zwraca wartosc sygnalu bialego szumu w danym czasie t.
 */
class WhiteNoise : public Signal, public ISerializable
{
public:
	/**
	 * @brief Konstruktor klasy WhiteNoise
	 * @param amplitude Amplituda sygnalu bialego szumu
	 */
    WhiteNoise(double amplitude);

	/**
	* @brief Metoda symulujaca sygnal bialego szumu
	* @param t Czas, w ktorym ma byc obliczona wartosc sygnalu
	* @return Wartosc sygnalu bialego szumu w czasie t
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
	void  Deserialize(const std::string& path) override;

private:
    double amplitude;
    mutable std::mt19937 generator;
    mutable std::normal_distribution<double> distribution;
};
