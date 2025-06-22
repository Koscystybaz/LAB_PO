#pragma once
#include "Signal.h"
#include "ISerializable.h"
/**
 * @brief Definicja klasy Square
 * Klasa ta reprezentuje sygna� prostok�tny dziedzicz�ca po klasie Signal.
 * Zawiera implementacj� funkcji Symuluj, kt�ra oblicza warto�� sygna�u prostok�tnego w danym czasie.
 */
class Square : public Signal, public ISerializable
{
public:
	/**
	 * @brief Konstruktor klasy Square
	 * @param amplitude Amplituda sygna�u prostok�tnego
	 * @param frequency Cz�stotliwo�� sygna�u prostok�tnego
	 */
	Square(double amplitude, double frequency, double fill);
	/**
	 * @brief Funkcja symuluj�ca sygna� prostok�tny
	 * @param t Czas, dla kt�rego ma zosta� obliczona warto�� sygna�u
	 * @return Warto�� sygna�u prostok�tnego w danym czasie
	 */
	double Symuluj(int t) override;

	/**
	 * @brief Funkcja serializuj�ca obiekt do pliku JSON
	 * @param path �cie�ka do pliku, do kt�rego zostan� zapisane dane obiektu
	 */
	void Serialize(const std::string& path) const override;

	/**
	 * @brief Funkcja deserializuj�ca obiekt z pliku JSON
	 * @param path �cie�ka do pliku, z kt�rego zostan� odczytane dane obiektu
	 */
	void  Deserialize(const std::string& path) override;


private:
	double amplitude;
	double frequency;
	double fill;
};