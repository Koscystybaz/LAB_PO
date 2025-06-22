#pragma once
#include "Signal.h"
#include "ISerializable.h"

/**
 * @brief Klasa reprezentuj�ca sta�y sygna�
 * Klasa ta dziedziczy po klasie Signal i implementuje funkcj� Symuluj,
 * kt�ra zwraca sta�� warto�� niezale�nie od czasu.
 */
class Constant : public Signal, public ISerializable
{
public:
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
	* @param path �cie�ka do pliku, do kt�rego zostanie zapisany obiekt
	*/
	void Serialize(const std::string& path) const override;

	/**
	* @brief Funkcja deserializuj�ca obiekt z pliku
	* @param data �cie�ka do pliku, z kt�rego zostanie odczytany obiekt
	*/
	void Deserialize(const std::string& data) override;

private:
    double value;
};
