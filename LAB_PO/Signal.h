#pragma once
//#include "ISerializable.h"

/**
 * @brief Klasa reprezentuj¹ca sygna³
 * Klasa ta jest abstrakcyjn¹ klas¹ bazow¹ dla ró¿nych typów sygna³ów.
 * Zawiera wirtualn¹ funkcjê `Symuluj`, która musi byæ zaimplementowana w klasach pochodnych.
*/
class Signal
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
};