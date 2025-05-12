#pragma once
#include "SignalGenerator.h"


/**
* @author Jakub Dudek
* @class Decorator
* @brief Klasa dekoratora, która dodaje dodatkowe funkcjonalnoœci do sygna³u
* @param signalGenerator WskaŸnik do obiektu klasy SignalGenerator, który bêdzie dekorowany
*/
class Decorator : public SignalGenerator
{
public:
	/**
	* @brief Konstruktor klasy Decorator
	* @param signalGenerator WskaŸnik do obiektu klasy SignalGenerator, który bêdzie dekorowany
	*/
	Decorator(SignalGenerator* signalGenerator);

	/**
	* @brief Destruktor klasy Decorator niszczy obiekt klasy SignalGenerator
	*/
	virtual ~Decorator();

	/**
	* @brief Metoda do generowania sygna³u
	* @param sample Indeks próbki
	* @return Wartoœæ sygna³u w danym punkcie czasowym
	*/
	virtual double Generate(int sample) override;

	/**
	* @brief Metoda do serializacji obiektu do pliku
	* @param path Œcie¿ka do pliku, do którego zostanie zapisany obiekt
	*/
	void Serialize(const std::string& path) const override;
	
	/**
	* @brief Metoda do deserializacji obiektu z pliku
	* @param path Œcie¿ka do pliku, z którego zostanie odczytany obiekt
	*/
	void Deserialize(const std::string& path) override;

	

protected:
	SignalGenerator* signalType;
};