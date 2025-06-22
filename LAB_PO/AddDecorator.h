#pragma once
#include "Decorator.h"


/**
* @Author Jakub Dudek
* @Class AddDecorator
* @brief Klasa dekoratora sygna³u, który dodaje wartoœæ drugiego sygna³u do pierwszego.
* Klasa ta dziedziczy po klasie Decorator i implementuje metodê Symuluj,
* która zwraca sumê wartoœci obu sygna³ów.
* @param secondSignal WskaŸnik do drugiego sygna³u, który bêdzie dodawany do pierwszego sygna³u.
*/
class AddDecorator : public Decorator 
{
public:

	/**
	* @brief Domyœlny konstruktor dekoratora.
	*/
	AddDecorator() : Decorator(nullptr), secondSignal(nullptr) {}

    /**
	* @brief Konstruktor dekoratora, który przyjmuje dwa sygna³y.
	* @param comp1 Pierwszy sygna³ do dekoracji.
	* @param comp2 Drugi sygna³ do dekoracji.
    */
    AddDecorator(Signal* comp1, Signal* comp2);

	/**
	* @brief Metoda symuluj¹ca dzia³anie dekoratora.
	* @param t Czas symulacji.
	* @return Suma wartoœci obu sygna³ów w czasie t.
    */
	double Symuluj(int t) override;

	/**
	* @brief Funkcja serializuj¹ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj¹cy stan obiektu
	*/
	nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param json Obiekt JSON zawieraj¹cy dane do deserializacji
	*/
	void Deserialize(const nlohmann::json& json) override;

private:
    std::unique_ptr<Signal> secondSignal;
};
