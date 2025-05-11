#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

/**
* @author Jakub Dudek
* @class PetlaSprzerzeniaZwrotnego
* @brief Implementacja funktora p�tli sprz�enia zwrotnego
*/
class PetlaSprzerzeniaZwrotnego
{
public:
	/**
	* @brief Funktor do symulacji p�tli sprz�enia zwrotnego
	* @param regulator Regulator PID
	* @param model Model ARX
	* @param setValue Warto�� zadana
	* @return Warto�� wyj�ciowa regulatora
	*/
	double operator()(RegulatorPID& regulator, ModelARX& model, const double setValue = 1.0);
};