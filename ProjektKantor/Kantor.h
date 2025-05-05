#pragma once
#include "Currency.h"
#include <string>
#include <chrono>
#include <map>

/**
 * @class Kantor
 * @brief Klasa reprezentuj�ca kantor wymiany walut.
 *
 * Klasa Kantor dziedziczy po klasie Currency i zawiera metody do zarz�dzania zasobami walut oraz realizacji transakcji.
 */
class Kantor : public Currency
{
protected:
    std::map<std::string, double> currencies; /**< Mapa przechowuj�ca dost�pne waluty i ich ilo�ci. */

public:
    /**
     * @brief Wczytuje zasoby walut z pliku.
     *
     * @param[in] file_name Nazwa pliku zawieraj�cego zasoby walut.
     * @param[out] currencies Mapa, do kt�rej zostan� wczytane zasoby walut.
     */
    void loadResources(const std::string file_name, std::map<std::string, double>& currencies);

    /**
     * @brief Wy�wietla dost�pne zasoby walut.
     */
    void showResources();

    /**
     * @brief Zmienia zasoby walut.
     *
     * @param[in] currency Nazwa waluty.
     * @param[in] amount Ilo�� waluty do zmiany.
     * @param[in] command Komenda okre�laj�ca typ zmiany (dodanie/usuni�cie).
     * @param[in] transaction Opis transakcji.
     */
    void changeResources(const std::string currency, double amount, const std::string command, std::string transaction);

    /**
     * @brief Przeprowadza transakcj� wymiany walut.
     *
     * @param[in] imie Imi� klienta.
     * @param[in] nazwisko Nazwisko klienta.
     * @param[in] currency Nazwa waluty.
     * @param[in] amount Ilo�� waluty do wymiany.
     * @param[in] price Cena wymiany.
     * @param[in] transaction Opis transakcji.
     */
    void makeTransaction(const std::string& imie, const std::string& nazwisko, const std::string& currency, double amount, double price, std::string transaction);

    /**
     * @brief Sprawdza b��dy zwi�zane z wyborem waluty.
     *
     * @param[in] choice Wyb�r waluty.
     * @param[in] error_msg Wiadomo�� b��du do wy�wietlenia w przypadku nieprawid�owego wyboru.
     * @return Zwraca true, je�li wyst�pi� b��d; false w przeciwnym razie.
     */
    bool error_cur(int choice, std::string error_msg);

    /**
     * @brief Sprawdza b��dy zwi�zane z ilo�ci� waluty.
     *
     * @param[in] currency Nazwa waluty.
     * @param[in] amount Ilo�� waluty.
     * @param[in] error_msg Wiadomo�� b��du do wy�wietlenia w przypadku nieprawid�owej ilo�ci.
     * @return Zwraca true, je�li wyst�pi� b��d; false w przeciwnym razie.
     */
    bool error_am(std::string currency, double amount, const std::string error_msg);
};
