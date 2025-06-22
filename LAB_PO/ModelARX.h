#pragma once
#include <vector>
#include <deque>
#include <random>
#include <nlohmann/json.hpp>
#include "ObiektSISO.h"
/**
* @author Jakub Dudek
* @class ModelARX
* @brief Implementacja modelu dyskretnego ARX
* @param a Wspó³czynniki AR
* @param b Wspó³czynniki X
* @param k OpóŸnienie transportowe (liczba próbek)
* @param noise Odchylenie standardowe zak³ócenia (szumu)
* @param generator Generator liczb losowych na potrzeby rozk³adu normalnego
* @param distribution Rozk³ad normalny do generowania szumu
*/
class ModelARX : public ObiektSISO
{
public:
	/**
	* @brief Konstruktor klasy ModelARX
	* @param a Wspó³czynniki AR
	* @param b Wspó³czynniki X
	* @param k OpóŸnienie transportowe (liczba próbek)
	* @param noise Odchylenie standardowe zak³ócenia (szumu)
	*/
	ModelARX(std::vector<double> a, std::vector<double> b, unsigned int k, double noise);

	/**
	* @brief Domyœlny konstruktor klasy ModelARX
	*/
	ModelARX() = default;

	/**
	* @brief Funkcja symuluj¹ca model ARX
	* @param input Nowa wartoœæ wejœciowa
	* @return Wygenerowana wartoœæ wyjœciowa na podstawie wartoœci wejœciowej
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
	void Deserialize(const nlohmann::json& json) override;

	/**
	* @brief Funkcja zwracaj¹ca ostatni¹ wartoœæ wejœciow¹
	* @return Ostatnia wartoœæ wejœciowa
	*/
	double GetLastInput() const;


private:
	std::vector<double> a;
	std::vector<double> b;

	std::deque<double> in;
	std::deque<double> out;

	unsigned int k;
    double noise;

	std::default_random_engine generator;
	std::normal_distribution<double> distribution{ 0.0, 1.0 };

	/**
	* @brief Funkcja generuj¹ca szum
	* @return Wartoœæ szumu
	*/
	double GenerateNoise()
	{
		return distribution(generator) * noise;
	}
};

