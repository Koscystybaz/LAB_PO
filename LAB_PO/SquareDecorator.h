#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include "Decorator.h"

/**
* @author Jakub Dudek
* @class SquareDecorator
* @brief Klasa dekoratora, która dodaje funkcjonalnoœæ generowania sygna³u prostok¹tnego
* @param amplitude Amplituda sygna³u prostok¹tnego
* @param frequency Czêstotliwoœæ sygna³u prostok¹tnego
* @param fill Wype³nienie sygna³u prostok¹tnego
*/
class SquareDecorator : public Decorator
{
public:
	/**
	* @brief Konstruktor klasy SquareDecorator
	* @param signalGenerator WskaŸnik do obiektu klasy SignalGenerator, który bêdzie dekorowany
	*/
	SquareDecorator(SignalGenerator* signalType, double amplitude, int frequency, double fill);

	/**
	* @brief Funkcja generuj¹ca sygna³ prostok¹tny
	* @param sample Próbka, dla której generowany jest sygna³
	* @return Wartoœæ sygna³u prostok¹tnego
	*/
	double Generate(int sample) override;
	
	/**
	* @brief Funkcja serializuj¹ca sygna³ do pliku
	* @param path Œcie¿ka do pliku, do którego zostanie zapisany sygna³
	* @return Plik JSON z danymi sygna³u
	*/
	void Serialize(const std::string& path) const override;

private:
	double amplitude;
	int frequency;
	double fill;
};
