#pragma once
#include "Signal.h"
#include "ISerializable.h"

/**
* @brief Klasa reprezentujaca sygnal trojkatny
* Klasa dziedziczy po klasie Signal i implementuje metode Symuluj,
* ktora zwraca wartosc sygnalu trojkatnego w danym czasie t.
* @param amplitude Amplituda sygnalu trojkatnego
* @param frequency Cz�stotliwo�� sygnalu trojkatnego
*/
class Triangle : public Signal, public ISerializable
{
public:
	/**
	* @brief Konstruktor klasy Triangle
	* @param amp Amplituda sygnalu
	* @param freq Cz�stotliwo�� sygnalu
    */
    Triangle(double amp, double freq);

	/**
	* @brief Metoda symulujaca sygnal trojkatny
	* @param t Czas, w ktorym ma byc obliczona wartosc sygnalu
	* @return Wartosc sygnalu trojkatnego w czasie t
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
    double frequency;
};