#pragma once
#include "ISerializable.h"

/**
 * @brief Klasa reprezentuj¹ca sygna³
 * Klasa ta jest abstrakcyjn¹ klas¹ bazow¹ dla ró¿nych typów sygna³ów.
 * Zawiera wirtualn¹ funkcjê `Symuluj`, która musi byæ zaimplementowana w klasach pochodnych.
*/
class Signal : public ISerializable
{
public:
	/**
	 * @brief Wirtualny destruktor
	 */
    virtual ~Signal() = default;

	/**
	* @brief Wirtualna funkcja symuluj¹ca sygna³
	* @param input Wejœciowy sygna³, dla którego ma zostaæ obliczona wartoœæ
	* @return Wartoœæ sygna³u
	*/
    virtual double Symuluj(int input) = 0;

	/**
	* @brief Funkcja serializuj¹ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj¹cy stan obiektu
	*/
	virtual nlohmann::json Serialize() const = 0;
	
	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param json Obiekt JSON zawieraj¹cy dane do deserializacji
	*/
	virtual void Deserialize(const nlohmann::json&) = 0;
};