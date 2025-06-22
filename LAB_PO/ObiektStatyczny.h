#pragma once
#include "ObiektSISO.h"
#include <algorithm>


/**
* @Author Jakub Dudek
* @Class ObiektStatyczny
* @brief Klasa reprezentujaca obiekt statyczny, ktory przyjmuje wartosc wejœciow¹ i zwraca j¹ w zakresie [minX, maxX].
* @param minX Minimalna wartosc wyjœciowa.
* @param maxX Maksymalna wartosc wyjœciowa.
*/
class ObiektStatyczny : public ObiektSISO {

public:
    
    /**
	* @brief Domyœlny konstruktor klasy ObiektStatyczny.
    */
	ObiektStatyczny() = default;

	/**
	* @brief Konstruktor klasy ObiektStatyczny z parametrami.
	* @param min Minimalna wartosc wyjœciowa.
	* @param max Maksymalna wartosc wyjœciowa.
    */
    ObiektStatyczny(double min, double max);

	/**
	* @brief Funkcja symuluj¹ca obiekt statyczny.
	* @param input Wartosc wejœciowa.
	* @return Wartosc wyjœciowa, ograniczona do zakresu [minX, maxX].
    */
    double Symuluj(double input) override;

	/**
	* @brief Funkcja serializuj¹ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj¹cy stan obiektu
	*/
    nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param json Obiekt JSON zawieraj¹cy dane do deserializacji
	*/
    void Deserialize(const nlohmann::json& j) override;

    
private:
    double minX;
    double maxX;
};
