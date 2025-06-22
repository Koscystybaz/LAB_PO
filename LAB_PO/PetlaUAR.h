#pragma once
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include "ObiektSISO.h"

std::unique_ptr<ObiektSISO> CreateObiektSISOFromJson(const nlohmann::json& json);

/**
* @Author Jakub Dudek
* @Class PetlaUAR
* @brief Klasa reprezentuj¹ca pêtlê UAR (Uproszczony Algorytm Regulacji)
* @param close Czy pêtla jest zamkniêta
* @param startingY Wartoœæ pocz¹tkowa sygna³u wyjœciowego
* @param components Wektor komponentów SISO w pêtli
*/
class PetlaUAR : public ObiektSISO 
{
public:

    /**
	* @brief Domyœlny konstruktor klasy PetlaUAR
    */
	PetlaUAR() = default;

	/**
	* @brief Konstruktor klasy PetlaUAR
	* @param close Czy pêtla jest zamkniêta
	* @param startingY Wartoœæ pocz¹tkowa sygna³u wyjœciowego
    */
    PetlaUAR(bool close, double startingY = 0.0);

	/**
	* @brief Dodaje komponent SISO do pêtli UAR
	* @param component WskaŸnik do komponentu SISO
    */
    void AddComponent(std::unique_ptr<ObiektSISO>&& component);

	/**
	* @brief Dodaje komponent SISO do pêtli UAR na okreœlonej pozycji
	* @param componentn WskaŸnik do komponentu SISO
	* @param index Indeks, na którym ma zostaæ dodany komponent
    */
    void AddComponentAt(std::unique_ptr<ObiektSISO>&& componentn, size_t index);

	/**
	* @brief Usuwa komponent SISO z pêtli UAR
	* @param index Indeks komponentu do usuniêcia
	*/
	void DeleteComponent(size_t index);

	/**
	* @brief Symuluje dzia³anie pêtli UAR
	* @param input Sygna³ wejœciowy
	* @return Sygna³ wyjœciowy po symulacji
	*/
    double Symuluj(double input) override;

	/**
	* @Zamyka lub otwiera pêtlê UAR
	* @param closeLoop Czy pêtla ma byæ zamkniêta
	*/
    void SetClose(bool closeLoop);

	/**
	* @brief Sprawdza, czy pêtla jest zamkniêta
	*/
	bool IsClosed() const;

	/**
	* @brief Funkcja serializuj¹ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj¹cy stan obiektu
	*/
    nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj¹ca obiekt z pliku
	* @param json Obiekt JSON zawieraj¹cy dane do deserializacji
	*/
    void Deserialize(const nlohmann::json& j) override;


private:
    bool close;
    double previousY;
    std::vector<std::unique_ptr<ObiektSISO>> components;

};