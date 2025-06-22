#pragma once
#include "Signal.h"


/**
 * @brief Klasa reprezentuj¹ca sta³y sygna³
 * Klasa ta dziedziczy po klasie Signal i implementuje funkcjê Symuluj,
 * która zwraca sta³¹ wartoœæ niezale¿nie od czasu.
 */
class Constant : public Signal
{
public:

	Constant() = default;

	/**
	 * @brief Konstruktor klasy Constant
	 * @param value Wartoœæ sta³ego sygna³u
	 */
    Constant(double value);

	/**
	 * @brief Funkcja symuluj¹ca sta³y sygna³
	 * @param t Czas, dla którego ma zostaæ obliczona wartoœæ sygna³u
	 * @return Zwraca sta³¹ wartoœæ niezale¿nie od czasu
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
    double value;
};
