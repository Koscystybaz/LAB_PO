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
	* @brief Wirtualna funkcja symulująca obiekt
	* @param input Wartość wejściowa
	* @return Wygenerowana wartość wyjściowa na podstawie wartości wejściowej
	*/
	virtual double Symuluj(double input) = 0;

	/**
	* @brief Funkcja serializująca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentujący stan obiektu
	*/
	virtual nlohmann::json Serialize() const = 0;

	/**
	* @brief Funkcja deserializująca obiekt z pliku
	* @param json Obiekt JSON zawierający dane do deserializacji
	*/
	virtual void Deserialize(const nlohmann::json& json) = 0;
};