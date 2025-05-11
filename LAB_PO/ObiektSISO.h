#pragma once
/**
* @author: Jakub Dudek
* @class ObiektSISO
* @brief Wirtualna klasa dla obiekt�w SISO (Single Input Single Output)
*/
class ObiektSISO
{
public:
	/**
	* @brief Wirtualny destruktor
	*/
	virtual ~ObiektSISO() = default;

	/**
	* @brief Wirtualna funkcja symuluj�ca obiekt
	* @param input Warto�� wej�ciowa
	* @return Wygenerowana warto�� wyj�ciowa na podstawie warto�ci wej�ciowej
	*/
	virtual double Symuluj(double input) = 0;
};