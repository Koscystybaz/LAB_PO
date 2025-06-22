#pragma once
#include <random>
#include "Signal.h"

/**
* @Author Jakub Dudek
* @Class WhiteNoise
* @brief Klasa reprezentujaca sygnal bialego szumu
* Klasa dziedziczy po klasie Signal i implementuje metode Symuluj,
* ktora zwraca wartosc sygnalu bialego szumu w danym czasie t.
* @param amplitude Amplituda sygnalu bialego szumu
* @param generator Generator liczb losowych
* @param distribution Rozklad normalny do generowania wartosci szumu
*/
class WhiteNoise : public Signal
{
public:

	/**
	* @brief Konstruktor domyœlny klasy WhiteNoise
	*/
	WhiteNoise() = default;

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
    mutable std::mt19937 generator;
    mutable std::normal_distribution<double> distribution;
};
