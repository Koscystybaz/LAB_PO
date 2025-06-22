#pragma once
#include "Signal.h"
#include <memory>

/**
* @Author Jakub Dudek
* @Class Decorator
* @brief Klasa bazowa dla dekoratorów sygna³ów.
* @param component WskaŸnik do komponentu sygna³u, który jest dekorowany.
* 
*/
class Decorator : public Signal
{
public:

	/**
	* @brief Konstruktor dekoratora.
	* @param comp WskaŸnik do komponentu sygna³u, który jest dekorowany.
	*/
    Decorator(Signal* comp) : component(comp) {}

	/**
	* @brief Wirtualny destruktor dekoratora.
	*/
    virtual ~Decorator() = default;

protected:
    std::unique_ptr<Signal> component;
};
