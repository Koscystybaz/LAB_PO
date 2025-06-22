#pragma once
#include "Signal.h"
#include "ISerializable.h"
/**
 * @brief Definicja klasy Square
 * Klasa ta reprezentuje sygna³ prostok¹tny dziedzicz¹ca po klasie Signal.
 * Zawiera implementacjê funkcji Symuluj, która oblicza wartoœæ sygna³u prostok¹tnego w danym czasie.
 */
class Square : public Signal, public ISerializable
{
public:
	/**
	 * @brief Konstruktor klasy Square
	 * @param amplitude Amplituda sygna³u prostok¹tnego
	 * @param frequency Czêstotliwoœæ sygna³u prostok¹tnego
	 */
	Square(double amplitude, double frequency, double fill);
	/**
	 * @brief Funkcja symuluj¹ca sygna³ prostok¹tny
	 * @param t Czas, dla którego ma zostaæ obliczona wartoœæ sygna³u
	 * @return Wartoœæ sygna³u prostok¹tnego w danym czasie
	 */
	double Symuluj(int t) override;

	/**
	 * @brief Funkcja serializuj¹ca obiekt do pliku JSON
	 * @param path Œcie¿ka do pliku, do którego zostan¹ zapisane dane obiektu
	 */
	void Serialize(const std::string& path) const override;

	/**
	 * @brief Funkcja deserializuj¹ca obiekt z pliku JSON
	 * @param path Œcie¿ka do pliku, z którego zostan¹ odczytane dane obiektu
	 */
	void  Deserialize(const std::string& path) override;


private:
	double amplitude;
	double frequency;
	double fill;
};