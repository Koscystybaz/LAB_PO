#pragma once
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

/**
* @Author Jakub Dudek
* @Class ISerializable
* @brief Interfejs do serializacji obiekt�w.
*/
class ISerializable {
public:
	/**
	* @brief Wirtualny destruktor interfejsu ISerializable.
    */
    virtual ~ISerializable() = default;

	/**
	* @brief Metoda do serializacji obiektu do formatu tekstowego.
	* @param path �cie�ka do pliku, do kt�rego ma zosta� zapisany obiekt.
    */
    virtual nlohmann::json Serialize() const = 0;

	/**
	* @brief Metoda do deserializacji obiektu z formatu tekstowego.
	* @param path �cie�ka do pliku, z kt�rego ma zosta� odczytany obiekt.
	*/
    virtual void Deserialize(const nlohmann::json& json) = 0;
};
