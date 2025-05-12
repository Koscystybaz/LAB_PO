#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include "Decorator.h"
/**
* @author Jakub Dudek
* @class SaturationDecorator
* @brief Klasa dekoratora dla nasycenia, która dodaje dodatkowe funkcjonalnoœci do sygna³u
* @param saturationLevel Poziom nasycenia
*/
class SaturationDecorator : public Decorator
{
public:
	/**
	* @brief Konstruktor klasy SaturationDecorator
	* @param signalGenerator WskaŸnik do obiektu klasy SignalGenerator, który bêdzie dekorowany
	* @param saturationLevel Poziom nasycenia
	*/
	SaturationDecorator(SignalGenerator* signalGenerator, double saturationLevel);

	/**
	* @brief Funkcja generuj¹ca sygna³ z nasyceniem
	* @param sample Próbka, dla której generowany jest sygna³
	* @return Wartoœæ sygna³u z nasyceniem
	*/
	double Generate(int sample) override;

	/**
	* @brief Funkcja serializuj¹ca sygna³ do pliku
	* @param path Œcie¿ka do pliku, do którego zostanie zapisany sygna³
	* @return Plik JSON z danymi sygna³u
	*/
	void Serialize(const std::string& path) const override;

private:
	double saturationLevel;
};