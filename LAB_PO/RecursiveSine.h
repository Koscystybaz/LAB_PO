#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include "Signal.h"
#include "ISerializable.h"

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
class RecursiveSine : public Signal, public ISerializable
{
public:

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
    * @brief Funkcja serializuj¹ca obiekt do pliku JSON
    * @param path Œcie¿ka do pliku, do którego zostan¹ zapisane dane obiektu
    */
    void Serialise(const std::string& path) const;

    /**
     * @brief Funkcja deserializuj¹ca obiekt z pliku JSON
     * @param path Œcie¿ka do pliku, z którego zostan¹ odczytane dane obiektu
     */
    void  Deserialise(const std::string& path);

private:
    double amplitude;
    double omega; // 2*pi*f/fs
    mutable double lastSample1, lastSample2; 
    mutable bool firstIteration;
};