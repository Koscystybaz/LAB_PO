#pragma once
#include <random>
#include <fstream>
#include <nlohmann/json.hpp>
#include "Signalgenerator.h"

/**
* @author Jakub Dudek
* @class WhiteNoise
* @brief Klasa generujaca szum bialy
* @param generator generator
* @param distribution rozklad normalny
*/
class
	WhiteNoise : public SignalGenerator
{
public:
	/**
	* @brief Konstruktor
	* @param mean srednia
	* @param deviation odchylenie standardowe
	*/
	WhiteNoise(double mean, double deviation);

	/**
	* @brief Funkcja generujaca szum
	* @param sample Probka
	* @return Wygenerowany sygna³ dla podanej probki
	*/
	double Generate(int sample) override;

	/**
	* @brief Funkcja serializujaca
	* @param path Sciezka do pliku
	*/
	void Serialize(const std::string& path) const override;



private:
	std::default_random_engine generator;
	std::normal_distribution<double> distribution;
};
