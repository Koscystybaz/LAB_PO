#pragma once
#include "Signal.h"
#include <memory>

class Decorator : public Signal
{
public:

    Decorator(Signal* comp) : component(comp) {}

    virtual ~Decorator() = default;

protected:
    std::unique_ptr<Signal> component;
};
