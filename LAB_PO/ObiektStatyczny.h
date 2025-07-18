#pragma once
#include "ObiektSISO.h"
#include <algorithm>


/**
* @Author Jakub Dudek
* @Class ObiektStatyczny
* @brief Klasa reprezentujaca obiekt statyczny, ktory przyjmuje wartosc wejściową i zwraca ją w zakresie [minX, maxX].
* @param minX Minimalna wartosc wyjściowa.
* @param maxX Maksymalna wartosc wyjściowa.
*/
class ObiektStatyczny : public ObiektSISO {

public:
    
    /**
	* @brief Domyślny konstruktor klasy ObiektStatyczny.
    */
	ObiektStatyczny() = default;

	/**
	* @brief Konstruktor klasy ObiektStatyczny z parametrami.
	* @param min Minimalna wartosc wyjściowa.
	* @param max Maksymalna wartosc wyjściowa.
    */
    ObiektStatyczny(double min, double max);

	/**
	* @brief Funkcja symulująca obiekt statyczny.
	* @param input Wartosc wejściowa.
	* @return Wartosc wyjściowa, ograniczona do zakresu [minX, maxX].
    */
    double Symuluj(double input) override;

	/**
	* @brief Funkcja serializująca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentujący stan obiektu
	*/
    nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializująca obiekt z pliku
	* @param json Obiekt JSON zawierający dane do deserializacji
	*/
    void Deserialize(const nlohmann::json& j) override;

    
private:
    double minX;
    double maxX;
};
