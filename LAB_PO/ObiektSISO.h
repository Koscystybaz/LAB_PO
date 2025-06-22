#pragma once
#include <nlohmann/json.hpp>

/**
* @author: Jakub Dudek
* @class ObiektSISO
* @brief Wirtualna klasa dla obiekt�w SISO (Single Input Single Output)
*/
class ObiektSISO
{
public:
	/**
	* @brief Wirtualny destruktor
	*/
	virtual ~ObiektSISO() = default;

	/**
	* @brief Wirtualna funkcja symuluj�ca obiekt
	* @param input Warto�� wej�ciowa
	* @return Wygenerowana warto�� wyj�ciowa na podstawie warto�ci wej�ciowej
	*/
	virtual double Symuluj(double input) = 0;

	/**
	* @brief Funkcja serializuj�ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj�cy stan obiektu
	*/
	virtual nlohmann::json Serialize() const = 0;

	/**
	* @brief Funkcja deserializuj�ca obiekt z pliku
	* @param json Obiekt JSON zawieraj�cy dane do deserializacji
	*/
	virtual void Deserialize(const nlohmann::json& json) = 0;
};