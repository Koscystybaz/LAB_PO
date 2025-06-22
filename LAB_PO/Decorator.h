#pragma once
#include "Signal.h"
#include <memory>

/**
* @Author Jakub Dudek
* @Class Decorator
* @brief Klasa bazowa dla dekorator�w sygna��w.
* @param component Wska�nik do komponentu sygna�u, kt�ry jest dekorowany.
* 
*/
class Decorator : public Signal
{
public:

	/**
	* @brief Konstruktor dekoratora.
	* @param comp Wska�nik do komponentu sygna�u, kt�ry jest dekorowany.
	*/
    Decorator(Signal* comp) : component(comp) {}

	/**
	* @brief Wirtualny destruktor dekoratora.
	*/
    virtual ~Decorator() = default;

protected:
    std::unique_ptr<Signal> component;
};
