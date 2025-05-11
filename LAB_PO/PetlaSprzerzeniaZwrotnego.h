#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

/**
* @author Jakub Dudek
* @class PetlaSprzerzeniaZwrotnego
* @brief Implementacja funktora pêtli sprzê¿enia zwrotnego
*/
class PetlaSprzerzeniaZwrotnego
{
public:
	/**
	* @brief Funktor do symulacji pêtli sprzê¿enia zwrotnego
	* @param regulator Regulator PID
	* @param model Model ARX
	* @param setValue Wartoœæ zadana
	* @return Wartoœæ wyjœciowa regulatora
	*/
	double operator()(RegulatorPID& regulator, ModelARX& model, const double setValue = 1.0);
};