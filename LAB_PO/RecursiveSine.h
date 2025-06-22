#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"
#include "ISerializable.h"

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
class RecursiveSine : public Signal, public ISerializable
{
public:

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
    * @brief Funkcja serializuj�ca obiekt do pliku JSON
    * @param path �cie�ka do pliku, do kt�rego zostan� zapisane dane obiektu
    */
    void Serialise(const std::string& path) const;

    /**
     * @brief Funkcja deserializuj�ca obiekt z pliku JSON
     * @param path �cie�ka do pliku, z kt�rego zostan� odczytane dane obiektu
     */
    void  Deserialise(const std::string& path);

private:
    double amplitude;
    double omega; // 2*pi*f/fs
    mutable double lastSample1, lastSample2; 
    mutable bool firstIteration;
};