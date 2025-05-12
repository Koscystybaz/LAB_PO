#pragma once  
#include <cmath>
#include <fstream>
#include <nlohmann/json.hpp>
#include "SignalGenerator.h"  

#define M_PI 3.14159265358979323846  

/**  
* @author Jakub Dudek  
* @class SineSignal  
* @brief Klasa reprezentuj¹ca sygna³ sinusoidalny
* @param amplitude Amplituda sygna³u sinusoidalnego
* @param frequency Czêstotliwoœæ sygna³u sinusoidalnego
* @param previousSample Poprzednia próbka sygna³u
* @param previousPreviousSample Druga poprzednia próbka sygna³u
* @param lastTime Ostatni czas, dla którego generowany by³ sygna³
*/  
class SineSignal : public SignalGenerator  
{  
public:  
	/**  
	 * @brief Konstruktor klasy SineSignal  
	 * @param amplitude Amplituda sygna³u sinusoidalnego  
	 * @param frequency Czêstotliwoœæ sygna³u sinusoidalnego  
	 */  
	SineSignal(double amplitude, double frequency);

	/**  
	 * @brief Funkcja generuj¹ca sygna³ sinusoidalny  
	 * @param time Czas, dla którego generowany jest sygna³  
	 * @return Wartoœæ sygna³u sinusoidalnego  
	 */  
	double Generate(int sample) override;  

	/**
	* @brief Funkcja serializuj¹ca sygna³ do pliku
	* @param path Œcie¿ka do pliku, do którego zostanie zapisany sygna³
	*/
	void Serialize(const std::string& path) const override;

private:  
	double amplitude;  
	double frequency;
	double previousSample;
	double previousPreviousSample;
	double lastSample;
};
