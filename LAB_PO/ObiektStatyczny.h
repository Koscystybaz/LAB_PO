#pragma once
#include "ObiektSISO.h"
#include <algorithm>


/**
* @Author Jakub Dudek
* @Class ObiektStatyczny
* @brief Klasa reprezentujaca obiekt statyczny, ktory przyjmuje wartosc wej�ciow� i zwraca j� w zakresie [minX, maxX].
* @param minX Minimalna wartosc wyj�ciowa.
* @param maxX Maksymalna wartosc wyj�ciowa.
*/
class ObiektStatyczny : public ObiektSISO {

public:
    
    /**
	* @brief Domy�lny konstruktor klasy ObiektStatyczny.
    */
	ObiektStatyczny() = default;

	/**
	* @brief Konstruktor klasy ObiektStatyczny z parametrami.
	* @param min Minimalna wartosc wyj�ciowa.
	* @param max Maksymalna wartosc wyj�ciowa.
    */
    ObiektStatyczny(double min, double max);

	/**
	* @brief Funkcja symuluj�ca obiekt statyczny.
	* @param input Wartosc wej�ciowa.
	* @return Wartosc wyj�ciowa, ograniczona do zakresu [minX, maxX].
    */
    double Symuluj(double input) override;

	/**
	* @brief Funkcja serializuj�ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj�cy stan obiektu
	*/
    nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj�ca obiekt z pliku
	* @param json Obiekt JSON zawieraj�cy dane do deserializacji
	*/
    void Deserialize(const nlohmann::json& j) override;

    
private:
    double minX;
    double maxX;
};
