#pragma	once
#include <random>
#include <nlohmann/json.hpp>
#include <fstream>
#include "Decorator.h"

/**
* @author: Jakub Dudek
* @class WhiteNoiseDecorator
* @brief Klasa dekorujaca sygnal generowany przez obiekt klasy SignalGenerator
* @param generator generator
* @param distribution rozklad normalny
*/
class WhiteNoiseDecorator : public Decorator
{
public:
	/**
	* @brief Konstruktor klasy WhiteNoiseDecorator
	* @param signalType WskaŸnik do obiektu klasy SignalGenerator, który bêdzie dekorowany
	* @param deviation Odchylenie standardowe szumu bia³ego
	*/
	WhiteNoiseDecorator(SignalGenerator* signalType, double deviation);

	/**
	* @brief Funkcja generujaca szum
	* @param sample Probka
	* @return Wygenerowany sygna³ dla podanej probki
	*/
	double Generate(int sample) override;

	/**
	* @brief Funkcja serializujaca do pliku JSON
	* @param path Sciezka do pliku
	*/
	void Serialize(const std::string& path) const override;

private:
	std::default_random_engine generator; 
	std::normal_distribution<double> distribution;
};
