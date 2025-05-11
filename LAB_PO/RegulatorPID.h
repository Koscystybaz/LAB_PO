#pragma once
#include "ObiektSISO.h"

/**
* @author Jakub Dudek
* @class Klasa regulatora PID
* @brief Klasa implementuj¹ca regulator PID
* @param k Wzmocnienie regulatora
* @param Ti Czas ca³kowania
* @param Td Czas ró¿niczkowania
* @param sumOfErrors Suma uchybów dla ca³ki
* @param lastError Poprzenida wartoœæ uchybu dla ró¿niczki
*/
class RegulatorPID : public ObiektSISO
{
public:
	/**
	* @brief Konstruktor klasy RegulatorPID z 1 parametrem
	* @param k Wzmocnienie regulatora
	*/
	RegulatorPID(double k);

	/**
	* @brief Konstruktor klasy RegulatorPID z 2 parametrami
	* @param k Wzmocnienie regulatora
	* @param Ti Czas ca³kowania
	*/
	RegulatorPID(double k, double Ti);

	/**
	* @brief Konstruktor klasy RegulatorPID z 3 parametrami
	* @param k Wzmocnienie regulatora
	* @param Ti Czas ca³kowania
	* @param Td Czas ró¿niczkowania
	*/
	RegulatorPID(double k, double Ti, double Td);

	/**
	* @brief Destruktor klasy RegulatorPID
	*/
	~RegulatorPID();

	/**
	* @brief Funkcja symuluj¹ca regulator PID
	* @param input Nowa wartoœæ wejœciowa
	* @return Wygenerowana wartoœæ wyjœciowa na podstawie wartoœci wejœciowej
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
	* @param i Czas ca³kowania
	*/
	void setPI(double p, double i);

	/**
	* @brief Setter PID
	* @param p Wzmocnienie regulatora
	* @param i Czas ca³kowania
	* @param d Czas ró¿niczkowania
	*/
	void setPID(double p, double i, double d);

private:
	double k = 0.0;
	double Ti = 0.0;
	double Td = 0.0;
	double sumOfErrors = 0.0;
	double lastError = 0.0;

	/**
	*@brief Funkcja waliduj¹ca parametry regulatora PID
	*/
	void ValidateParameters() const;
};