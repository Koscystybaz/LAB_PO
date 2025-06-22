#pragma once
#include "Signal.h"

/**
 * @brief Definicja klasy Square
 * Klasa ta reprezentuje sygna³ prostok¹tny dziedzicz¹ca po klasie Signal.
 * Zawiera implementacjê funkcji Symuluj, która oblicza wartoœæ sygna³u prostok¹tnego w danym czasie.
 */
class Square : public Signal
{
public:

	/**
	 * @brief Konstruktor domyœlny klasy Square
	 */
	Square() = default;

	/**
	 * @brief Konstruktor klasy Square
	 * @param amplitude Amplituda sygna³u prostok¹tnego
	 * @param frequency Czêstotliwoœæ sygna³u prostok¹tnego
	 */
	Square(double amplitude, double frequency, double fill);
	/**
	 * @brief Funkcja symuluj¹ca sygna³ prostok¹tny
	 * @param t Czas, dla którego ma zostaæ obliczona wartoœæ sygna³u
	 * @return Wartoœæ sygna³u prostok¹tnego w danym czasie
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
	double fill;
};