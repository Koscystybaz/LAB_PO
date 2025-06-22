#pragma once
#include "Signal.h"
#include "ISerializable.h"

/**
 * @brief Klasa reprezentuj¹ca sta³y sygna³
 * Klasa ta dziedziczy po klasie Signal i implementuje funkcjê Symuluj,
 * która zwraca sta³¹ wartoœæ niezale¿nie od czasu.
 */
class Constant : public Signal, public ISerializable
{
public:
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
	* @param path Œcie¿ka do pliku, do którego zostanie zapisany obiekt
	*/
	void Serialize(const std::string& path) const override;

	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param data Œcie¿ka do pliku, z którego zostanie odczytany obiekt
	*/
	void Deserialize(const std::string& data) override;

private:
    double value;
};
