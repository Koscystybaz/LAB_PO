#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include "Decorator.h"

/**
* @brief Klasa dekoratora sygna�u, kt�ry ogranicza warto�� sygna�u do maksymalnej warto�ci.
* * Klasa ta dziedziczy po klasie Decorator i implementuje metod� Symuluj,
* * kt�ra zwraca warto�� sygna�u ograniczon� do maksymalnej warto�ci.
*/
class SaturationDecorator : public Decorator {
private:
    double maxVal;

public:
    SaturationDecorator(Signal* comp, double max_val);

    double Symuluj(int t) override;
};
