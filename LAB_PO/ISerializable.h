#pragma once
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

/**
* @Author Jakub Dudek
* @Class ISerializable
* @brief Interfejs do serializacji obiektów.
*/
class ISerializable {
public:
	/**
	* @brief Wirtualny destruktor interfejsu ISerializable.
    */
    virtual ~ISerializable() = default;

	/**
	* @brief Metoda do serializacji obiektu do formatu tekstowego.
	* @param path Œcie¿ka do pliku, do którego ma zostaæ zapisany obiekt.
    */
    virtual nlohmann::json Serialize() const = 0;

	/**
	* @brief Metoda do deserializacji obiektu z formatu tekstowego.
	* @param path Œcie¿ka do pliku, z którego ma zostaæ odczytany obiekt.
	*/
    virtual void Deserialize(const nlohmann::json& json) = 0;
};
