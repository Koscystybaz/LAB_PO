#pragma once
#include "Signal.h"

/**
 * @brief Definicja klasy Square
 * Klasa ta reprezentuje sygna� prostok�tny dziedzicz�ca po klasie Signal.
 * Zawiera implementacj� funkcji Symuluj, kt�ra oblicza warto�� sygna�u prostok�tnego w danym czasie.
 */
class Square : public Signal
{
public:

	/**
	 * @brief Konstruktor domy�lny klasy Square
	 */
	Square() = default;

	/**
	 * @brief Konstruktor klasy Square
	 * @param amplitude Amplituda sygna�u prostok�tnego
	 * @param frequency Cz�stotliwo�� sygna�u prostok�tnego
	 */
	Square(double amplitude, double frequency, double fill);
	/**
	 * @brief Funkcja symuluj�ca sygna� prostok�tny
	 * @param t Czas, dla kt�rego ma zosta� obliczona warto�� sygna�u
	 * @return Warto�� sygna�u prostok�tnego w danym czasie
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
	double fill;
};