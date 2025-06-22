#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Decorator.h"

/**
* @brief Klasa dekoratora sygna³u, który ogranicza wartoœæ sygna³u do maksymalnej wartoœci.
* * Klasa ta dziedziczy po klasie Decorator i implementuje metodê Symuluj,
* * która zwraca wartoœæ sygna³u ograniczon¹ do maksymalnej wartoœci.
*/
class SaturationDecorator : public Decorator {
private:
    double maxVal;

public:
    SaturationDecorator(Signal* comp, double max_val);

    double Symuluj(int t) override;
};
