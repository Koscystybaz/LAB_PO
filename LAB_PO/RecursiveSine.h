#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"


/**
* @brief Klasa reprezentuj�ca sygna� sinusoidalny generowany rekurencyjnie
* @param amplitude Amplituda sygna�u
* @param frequency Cz�stotliwo�� sygna�u
* @param sampleFrequency Cz�stotliwo�� pr�bkowania sygna�u
* @param t Czas w pr�bkach, dla kt�rego ma zosta� wygenerowana warto�� sygna�u
* @param lastSample1 Ostatnia pr�bka sygna�u (n-1)
* @param lastSample2 Przedostatnia pr�bka sygna�u (n-2)
* @param firstIteration Flaga informuj�ca, czy jest to pierwsza iteracja generowania sygna�u
*/
class RecursiveSine : public Signal
{
public:

	/**
	* @brief Konstruktor domy�lny klasy RecursiveSine
	*/
	RecursiveSine() = default;

	/**
	* @brief Konstruktor klasy RecursiveSine
	* @param amp Amplituda sygna�u
	* @param freq Cz�stotliwo�� sygna�u
	* @param sampleFreq Cz�stotliwo�� pr�bkowania sygna�u
    */
    RecursiveSine(double amp, double freq, double sampleFreq);


	/**
	* @brief Funkcja generuj�ca warto�� sygna�u sinusoidalnego w danym czasie
	* @param t Czas w pr�bkach, dla kt�rego ma zosta� wygenerowana warto�� sygna�u
	* @return Warto�� sygna�u sinusoidalnego w czasie t
    */
    double Symuluj(int t) override;

	/**
	* @brief Funkcja serializuj�ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj�cy stan obiektu
	*/
	nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj�ca obiekt z pliku
	* @param json Obiekt JSON zawieraj�cy dane do deserializacji
	*/
	void Deserialize(const nlohmann::json& json) override;

private:
    double amplitude;
    double omega; // 2*pi*f/fs
    mutable double lastSample1, lastSample2; 
    mutable bool firstIteration;
};