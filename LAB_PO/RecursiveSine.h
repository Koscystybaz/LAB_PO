#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"


/**
* @brief Klasa reprezentuj¹ca sygna³ sinusoidalny generowany rekurencyjnie
* @param amplitude Amplituda sygna³u
* @param frequency Czêstotliwoœæ sygna³u
* @param sampleFrequency Czêstotliwoœæ próbkowania sygna³u
* @param t Czas w próbkach, dla którego ma zostaæ wygenerowana wartoœæ sygna³u
* @param lastSample1 Ostatnia próbka sygna³u (n-1)
* @param lastSample2 Przedostatnia próbka sygna³u (n-2)
* @param firstIteration Flaga informuj¹ca, czy jest to pierwsza iteracja generowania sygna³u
*/
class RecursiveSine : public Signal
{
public:

	/**
	* @brief Konstruktor domyœlny klasy RecursiveSine
	*/
	RecursiveSine() = default;

	/**
	* @brief Konstruktor klasy RecursiveSine
	* @param amp Amplituda sygna³u
	* @param freq Czêstotliwoœæ sygna³u
	* @param sampleFreq Czêstotliwoœæ próbkowania sygna³u
    */
    RecursiveSine(double amp, double freq, double sampleFreq);


	/**
	* @brief Funkcja generuj¹ca wartoœæ sygna³u sinusoidalnego w danym czasie
	* @param t Czas w próbkach, dla którego ma zostaæ wygenerowana wartoœæ sygna³u
	* @return Wartoœæ sygna³u sinusoidalnego w czasie t
    */
    double Symuluj(int t) override;

	/**
	* @brief Funkcja serializuj¹ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj¹cy stan obiektu
	*/
	nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param json Obiekt JSON zawieraj¹cy dane do deserializacji
	*/
	void Deserialize(const nlohmann::json& json) override;

private:
    double amplitude;
    double omega; // 2*pi*f/fs
    mutable double lastSample1, lastSample2; 
    mutable bool firstIteration;
};