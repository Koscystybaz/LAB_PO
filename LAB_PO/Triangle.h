#pragma once
#include "Signal.h"

/**
* @Author Jakub Dudek
* @Class Triangle
* @brief Klasa reprezentujaca sygnal trojkatny
* Klasa dziedziczy po klasie Signal i implementuje metode Symuluj,
* ktora zwraca wartosc sygnalu trojkatnego w danym czasie t.
* @param amplitude Amplituda sygnalu trojkatnego
* @param frequency Częstotliwość sygnalu trojkatnego
*/
class Triangle : public Signal
{
public:

	/**
	* @brief Konstruktor domyślny klasy Triangle
	*/
	Triangle() = default;

	/**
	* @brief Konstruktor klasy Triangle
	* @param amp Amplituda sygnalu
	* @param freq Częstotliwość sygnalu
    */
    Triangle(double amp, double freq);

	/**
	* @brief Metoda symulujaca sygnal trojkatny
	* @param t Czas, w ktorym ma byc obliczona wartosc sygnalu
	* @return Wartosc sygnalu trojkatnego w czasie t
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