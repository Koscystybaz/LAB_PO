#pragma once
#include "Signal.h"

/**
* @Author Jakub Dudek
* @Class Square
* @brief Definicja klasy Square
* Klasa ta reprezentuje sygnał prostokątny dziedzicząca po klasie Signal.
* Zawiera implementację funkcji Symuluj, która oblicza wartość sygnału prostokątnego w danym czasie.
* @param amplitude Amplituda sygnału prostokątnego
* @param frequency Częstotliwość sygnału prostokątnego
* @param fill Wypełnienie sygnału prostokątnego
*/
class Square : public Signal
{
public:

	/**
	* @brief Konstruktor domyślny klasy Square
	*/
	Square() = default;

	/**
	* @brief Konstruktor klasy Square
	* @param amplitude Amplituda sygnału prostokątnego
	* @param frequency Częstotliwość sygnału prostokątnego
	*/
	Square(double amplitude, double frequency, double fill);
	/**
	* @brief Funkcja symulująca sygnał prostokątny
	* @param t Czas, dla którego ma zostać obliczona wartość sygnału
	* @return Wartość sygnału prostokątnego w danym czasie
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
	double fill;
};