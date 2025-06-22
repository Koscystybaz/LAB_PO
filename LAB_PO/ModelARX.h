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
* @param a Wsp�czynniki AR
* @param b Wsp�czynniki X
* @param k Op�nienie transportowe (liczba pr�bek)
* @param noise Odchylenie standardowe zak��cenia (szumu)
* @param generator Generator liczb losowych na potrzeby rozk�adu normalnego
* @param distribution Rozk�ad normalny do generowania szumu
*/
class ModelARX : public ObiektSISO
{
public:
	/**
	* @brief Konstruktor klasy ModelARX
	* @param a Wsp�czynniki AR
	* @param b Wsp�czynniki X
	* @param k Op�nienie transportowe (liczba pr�bek)
	* @param noise Odchylenie standardowe zak��cenia (szumu)
	*/
	ModelARX(std::vector<double> a, std::vector<double> b, unsigned int k, double noise);

	/**
	* @brief Domy�lny konstruktor klasy ModelARX
	*/
	ModelARX() = default;

	/**
	* @brief Funkcja symuluj�ca model ARX
	* @param input Nowa warto�� wej�ciowa
	* @return Wygenerowana warto�� wyj�ciowa na podstawie warto�ci wej�ciowej
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
	void Deserialize(const nlohmann::json& json) override;

	/**
	* @brief Funkcja zwracaj�ca ostatni� warto�� wej�ciow�
	* @return Ostatnia warto�� wej�ciowa
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
	* @brief Funkcja generuj�ca szum
	* @return Warto�� szumu
	*/
	double GenerateNoise()
	{
		return distribution(generator) * noise;
	}
};

