#pragma once
#include <nlohmann/json.hpp>

/**
* @author: Jakub Dudek
* @class ObiektSISO
* @brief Wirtualna klasa dla obiektów SISO (Single Input Single Output)
*/
class ObiektSISO
{
public:
	/**
	* @brief Wirtualny destruktor
	*/
	virtual ~ObiektSISO() = default;

	/**
	* @brief Wirtualna funkcja symuluj¹ca obiekt
	* @param input Wartoœæ wejœciowa
	* @return Wygenerowana wartoœæ wyjœciowa na podstawie wartoœci wejœciowej
	*/
	virtual double Symuluj(double input) = 0;

	/**
	* @brief Funkcja serializuj¹ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj¹cy stan obiektu
	*/
	virtual nlohmann::json Serialize() const = 0;

	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param json Obiekt JSON zawieraj¹cy dane do deserializacji
	*/
	virtual void Deserialize(const nlohmann::json& json) = 0;
};