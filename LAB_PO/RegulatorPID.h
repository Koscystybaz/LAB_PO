#pragma once
#include "ObiektSISO.h"

/**
* @author Jakub Dudek
* @class Klasa regulatora PID
* @brief Klasa implementująca regulator PID
* @param k Wzmocnienie regulatora
* @param Ti Czas całkowania
* @param Td Czas różniczkowania
* @param sumOfErrors Suma uchybów dla całki
* @param lastError Poprzenida wartość uchybu dla różniczki
*/
class RegulatorPID : public ObiektSISO
{
public:
	/**
	* @brief Domyślny konstruktor klasy RegulatorPID
	*/
	RegulatorPID() = default;

	/**
	* @brief Konstruktor klasy RegulatorPID z 1 parametrem
	* @param k Wzmocnienie regulatora
	*/
	RegulatorPID(double k);

	/**
	* @brief Konstruktor klasy RegulatorPID z 2 parametrami
	* @param k Wzmocnienie regulatora
	* @param Ti Czas całkowania
	*/
	RegulatorPID(double k, double Ti);

	/**
	* @brief Konstruktor klasy RegulatorPID z 3 parametrami
	* @param k Wzmocnienie regulatora
	* @param Ti Czas całkowania
	* @param Td Czas różniczkowania
	*/
	RegulatorPID(double k, double Ti, double Td);

	/**
	* @brief Destruktor klasy RegulatorPID
	*/
	~RegulatorPID();

	/**
	* @brief Funkcja symulująca regulator PID
	* @param input Nowa wartość wejściowa
	* @return Wygenerowana wartość wyjściowa na podstawie wartości wejściowej
	*/
	double Symuluj(double input) override;

	/**
	* @brief Setter P 
	* @param p Wzmocnienie regulatora
	*/
	void SetP(double p);

	/**
	* @brief Setter PI
	* @param p Wzmocnienie regulatora
	* @param i Czas całkowania
	*/
	void setPI(double p, double i);

	/**
	* @brief Setter PID
	* @param p Wzmocnienie regulatora
	* @param i Czas całkowania
	* @param d Czas różniczkowania
	*/
	void setPID(double p, double i, double d);

	/**
	* @brief Funkcja serializująca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentujący stan obiektu
	*/
	nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializująca obiekt z pliku
	* @param json Obiekt JSON zawierający dane do deserializacji
	*/
	void Deserialize(const nlohmann::json& json) override;

private:
	double k = 0.0;
	double Ti = 0.0;
	double Td = 0.0;
	double sumOfErrors = 0.0;
	double lastError = 0.0;

	/**
	*@brief Funkcja walidująca parametry regulatora PID
	*/
	void ValidateParameters() const;
};