#pragma once
#include <cmath>
#include <fstream>
#include <nlohmann/json.hpp>
#include "SignalGenerator.h"

/**
* @author Jakub Dudek
* @class SquareSignal
* @brief Klasa reprezentuj¹ca sygna³ prostok¹tny
* @param amplitude Amplituda sygna³u prostok¹tnego
* @param frequency Czêstotliwoœæ sygna³u prostok¹tnego
* @param fill Wype³nienie sygna³u prostok¹tnego
*/
class SquareSignal : public SignalGenerator
{
public:
	/**
	* @brief Konstruktor klasy SquareSignal
	* @param amplitude Amplituda sygna³u prostok¹tnego
	* @param frequency Czêstotliwoœæ sygna³u prostok¹tnego
	* @param fill Wype³nienie sygna³u prostok¹tnego
	*/
	SquareSignal(double amplitude, double frequency, double fill);

	/**
	* @brief Funkcja generuj¹ca sygna³ prostok¹tny
	* @param sample Czas, dla którego generowany jest sygna³
	* @return Wartoœæ sygna³u prostok¹tnego
	*/
	double Generate(int sapmle) override;

	/**
	* @brief Funkcja Serializuj¹ca sygna³ prostok¹tny
	* @param path Œcie¿ka do pliku, w którym ma byæ zapisany sygna³
	*/
	void Serialize(const std::string& path) const override;

private:
	double amplitude;
	double frequency;
	double fill;
};