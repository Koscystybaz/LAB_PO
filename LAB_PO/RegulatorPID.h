#pragma once
#include "ObiektSISO.h"

/**
* @author Jakub Dudek
* @class Klasa regulatora PID
* @brief Klasa implementuj�ca regulator PID
* @param k Wzmocnienie regulatora
* @param Ti Czas ca�kowania
* @param Td Czas r�niczkowania
* @param sumOfErrors Suma uchyb�w dla ca�ki
* @param lastError Poprzenida warto�� uchybu dla r�niczki
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
	* @param Ti Czas ca�kowania
	*/
	RegulatorPID(double k, double Ti);

	/**
	* @brief Konstruktor klasy RegulatorPID z 3 parametrami
	* @param k Wzmocnienie regulatora
	* @param Ti Czas ca�kowania
	* @param Td Czas r�niczkowania
	*/
	RegulatorPID(double k, double Ti, double Td);

	/**
	* @brief Destruktor klasy RegulatorPID
	*/
	~RegulatorPID();

	/**
	* @brief Funkcja symuluj�ca regulator PID
	* @param input Nowa warto�� wej�ciowa
	* @return Wygenerowana warto�� wyj�ciowa na podstawie warto�ci wej�ciowej
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
	* @param i Czas ca�kowania
	*/
	void setPI(double p, double i);

	/**
	* @brief Setter PID
	* @param p Wzmocnienie regulatora
	* @param i Czas ca�kowania
	* @param d Czas r�niczkowania
	*/
	void setPID(double p, double i, double d);

private:
	double k = 0.0;
	double Ti = 0.0;
	double Td = 0.0;
	double sumOfErrors = 0.0;
	double lastError = 0.0;

	/**
	*@brief Funkcja waliduj�ca parametry regulatora PID
	*/
	void ValidateParameters() const;
};