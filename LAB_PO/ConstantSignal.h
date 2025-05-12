#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include "SignalGenerator.h"

/**
* @author Jakub Dudek
* @class PermanentSignal
* @brief Klasa reprezentuj¹ca sygna³ sta³y
* @param value Wartoœæ sygna³u sta³ego
*/
class ConstantSignal : public SignalGenerator
{
public:
	/**
	* @brief Konstruktor klasy PermanentSignal
	* @param value Wartoœæ sygna³u sta³ego
	*/
	ConstantSignal(double value);

	/**
	* @brief Funkcja generuj¹ca sygna³ sta³y
	* @param sample Czas, dla którego generowany jest sygna³
	* @return Wartoœæ sygna³u sta³ego
	*/
	double Generate(int sample) override;

	/**
	* @brief Funkcja serializuj¹ca sygna³ do pliku
	* @param path Œcie¿ka do pliku, do którego zostanie zapisany sygna³
	*/
	void Serialize(const std::string& path) const override;

private:
	double value;
};
