#pragma once
#include "Decorator.h"
#include <nlohmann/json.hpp>
#include <fstream>

/**
* @author: Jakub Dudek
* @class TriangleDecorator
* @brief Klasa reprezentuj¹ca dekorator sygna³u trójk¹tnego
* @param amplitude Amplituda sygna³u trójk¹tnego
* @param period Czêstotliwoœæ sygna³u trójk¹tnego
* @param saturation Nasycenie sygna³u trójk¹tnego
*/
class TriangleDecorator : public Decorator
{
public:
	/**
	* @brief Konstruktor klasy TriangleDecorator
	* @param amplitude Amplituda sygna³u trójk¹tnego
	* @param period Czêstotliwoœæ sygna³u trójk¹tnego
	* @param saturation Nasycenie sygna³u trójk¹tnego
	*/
	TriangleDecorator(SignalGenerator* signalType, double amplitude, int period, double saturation);

	/**
	* @brief Funkcja generuj¹ca sygna³ trójk¹tny
	* @param sample Próbka, dla której generowany jest sygna³
	* @return Wartoœæ sygna³u trójk¹tnego
	*/
	double Generate(int sample) override;

	/**
	* @brief Funkcja Serializuj¹ca sygna³ do pliku JSON
	* @param path Œcie¿ka do pliku, do którego zostanie zapisany sygna³
	*/
	void Serialize(const std::string& path) const override;

private:
	double amplitude;
	int period;
	double saturation;
};