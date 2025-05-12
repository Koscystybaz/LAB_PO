#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include <algorithm>
#include "SignalGenerator.h"

/**
* @author: Jakub Dudek
* @class TriangleSignal
* @brief Klasa reprezentuj¹ca sygna³ trójk¹tny
* @param amplitude Amplituda sygna³u trójk¹tnego
* @param frequency Czêstotliwoœæ sygna³u trójk¹tnego
* @param phase Faza sygna³u trójk¹tnego
*/
class TriangleSignal : public SignalGenerator
{
public:
	/**
	* @brief Konstruktor klasy TriangleSignal
	* @param amplitude Amplituda sygna³u trójk¹tnego
	* @param frequency Czêstotliwoœæ sygna³u trójk¹tnego
	* @param saturation Nasycenie sygna³u trójk¹tnego
	*/
	TriangleSignal(double amplitude, int period, double saturation);

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

