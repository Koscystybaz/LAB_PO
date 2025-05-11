#pragma once
/**
* @author: Jakub Dudek
* @class ObiektSISO
* @brief Wirtualna klasa dla obiektów SISO (Single Input Single Output)
*/
class ObiektSISO
{
public:
	/**
	* @brief Wirtualny destruktor
	*/
	virtual ~ObiektSISO() = default;

	/**
	* @brief Wirtualna funkcja symuluj¹ca obiekt
	* @param input Wartoœæ wejœciowa
	* @return Wygenerowana wartoœæ wyjœciowa na podstawie wartoœci wejœciowej
	*/
	virtual double Symuluj(double input) = 0;
};