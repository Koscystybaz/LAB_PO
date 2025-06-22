#pragma once
#include "Signal.h"


/**
 * @brief Klasa reprezentuj�ca sta�y sygna�
 * Klasa ta dziedziczy po klasie Signal i implementuje funkcj� Symuluj,
 * kt�ra zwraca sta�� warto�� niezale�nie od czasu.
 */
class Constant : public Signal
{
public:

	Constant() = default;

	/**
	 * @brief Konstruktor klasy Constant
	 * @param value Warto�� sta�ego sygna�u
	 */
    Constant(double value);

	/**
	 * @brief Funkcja symuluj�ca sta�y sygna�
	 * @param t Czas, dla kt�rego ma zosta� obliczona warto�� sygna�u
	 * @return Zwraca sta�� warto�� niezale�nie od czasu
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
    double value;
};
