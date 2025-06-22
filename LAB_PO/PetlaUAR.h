#pragma once
#include <memory>
#include <vector>
#include <nlohmann/json.hpp>
#include "ObiektSISO.h"

std::unique_ptr<ObiektSISO> CreateObiektSISOFromJson(const nlohmann::json& json);

/**
* @Author Jakub Dudek
* @Class PetlaUAR
* @brief Klasa reprezentuj�ca p�tl� UAR (Uproszczony Algorytm Regulacji)
* @param close Czy p�tla jest zamkni�ta
* @param startingY Warto�� pocz�tkowa sygna�u wyj�ciowego
* @param components Wektor komponent�w SISO w p�tli
*/
class PetlaUAR : public ObiektSISO 
{
public:

    /**
	* @brief Domy�lny konstruktor klasy PetlaUAR
    */
	PetlaUAR() = default;

	/**
	* @brief Konstruktor klasy PetlaUAR
	* @param close Czy p�tla jest zamkni�ta
	* @param startingY Warto�� pocz�tkowa sygna�u wyj�ciowego
    */
    PetlaUAR(bool close, double startingY = 0.0);

	/**
	* @brief Dodaje komponent SISO do p�tli UAR
	* @param component Wska�nik do komponentu SISO
    */
    void AddComponent(std::unique_ptr<ObiektSISO>&& component);

	/**
	* @brief Dodaje komponent SISO do p�tli UAR na okre�lonej pozycji
	* @param componentn Wska�nik do komponentu SISO
	* @param index Indeks, na kt�rym ma zosta� dodany komponent
    */
    void AddComponentAt(std::unique_ptr<ObiektSISO>&& componentn, size_t index);

	/**
	* @brief Usuwa komponent SISO z p�tli UAR
	* @param index Indeks komponentu do usuni�cia
	*/
	void DeleteComponent(size_t index);

	/**
	* @brief Symuluje dzia�anie p�tli UAR
	* @param input Sygna� wej�ciowy
	* @return Sygna� wyj�ciowy po symulacji
	*/
    double Symuluj(double input) override;

	/**
	* @Zamyka lub otwiera p�tl� UAR
	* @param closeLoop Czy p�tla ma by� zamkni�ta
	*/
    void SetClose(bool closeLoop);

	/**
	* @brief Sprawdza, czy p�tla jest zamkni�ta
	*/
	bool IsClosed() const;

	/**
	* @brief Funkcja serializuj�ca obiekt do pliku
	* @return Zwraca obiekt JSON reprezentuj�cy stan obiektu
	*/
    nlohmann::json Serialize() const override;

	/**
	* @brief Funkcja deserializuj�ca obiekt z pliku
	* @param json Obiekt JSON zawieraj�cy dane do deserializacji
	*/
    void Deserialize(const nlohmann::json& j) override;


private:
    bool close;
    double previousY;
    std::vector<std::unique_ptr<ObiektSISO>> components;

};