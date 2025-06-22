#pragma once
#include "ISerializable.h"

/**
 * @brief Klasa reprezentuj�ca sygna�
 * Klasa ta jest abstrakcyjn� klas� bazow� dla r�nych typ�w sygna��w.
 * Zawiera wirtualn� funkcj� `Symuluj`, kt�ra musi by� zaimplementowana w klasach pochodnych.
*/
class Signal : public ISerializable
{
public:
	/**
	 * @brief Wirtualny destruktor
	 */
    virtual ~Signal() = default;

	/**
	* @brief Wirtualna funkcja symuluj�ca sygna�
	* @param input Wej�ciowy sygna�, dla kt�rego ma zosta� obliczona warto��
	* @return Warto�� sygna�u
	*/
    virtual double Symuluj(int input) = 0;

	/**
	* @brief Funkcja serializuj�ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj�cy stan obiektu
	*/
	virtual nlohmann::json Serialize() const = 0;
	
	/**
	* @brief Funkcja deserializuj�ca obiekt z pliku
	* @param json Obiekt JSON zawieraj�cy dane do deserializacji
	*/
	virtual void Deserialize(const nlohmann::json&) = 0;
};