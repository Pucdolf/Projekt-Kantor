#pragma once
#include "Currency.h"
#include <string>
#include <chrono>
#include <map>

/**
 * @class Kantor
 * @brief Klasa reprezentuj¹ca kantor wymiany walut.
 *
 * Klasa Kantor dziedziczy po klasie Currency i zawiera metody do zarz¹dzania zasobami walut oraz realizacji transakcji.
 */
class Kantor : public Currency
{
protected:
    std::map<std::string, double> currencies; /**< Mapa przechowuj¹ca dostêpne waluty i ich iloœci. */

public:
    /**
     * @brief Wczytuje zasoby walut z pliku.
     *
     * @param[in] file_name Nazwa pliku zawieraj¹cego zasoby walut.
     * @param[out] currencies Mapa, do której zostan¹ wczytane zasoby walut.
     */
    void loadResources(const std::string file_name, std::map<std::string, double>& currencies);

    /**
     * @brief Wyœwietla dostêpne zasoby walut.
     */
    void showResources();

    /**
     * @brief Zmienia zasoby walut.
     *
     * @param[in] currency Nazwa waluty.
     * @param[in] amount Iloœæ waluty do zmiany.
     * @param[in] command Komenda okreœlaj¹ca typ zmiany (dodanie/usuniêcie).
     * @param[in] transaction Opis transakcji.
     */
    void changeResources(const std::string currency, double amount, const std::string command, std::string transaction);

    /**
     * @brief Przeprowadza transakcjê wymiany walut.
     *
     * @param[in] imie Imiê klienta.
     * @param[in] nazwisko Nazwisko klienta.
     * @param[in] currency Nazwa waluty.
     * @param[in] amount Iloœæ waluty do wymiany.
     * @param[in] price Cena wymiany.
     * @param[in] transaction Opis transakcji.
     */
    void makeTransaction(const std::string& imie, const std::string& nazwisko, const std::string& currency, double amount, double price, std::string transaction);

    /**
     * @brief Sprawdza b³êdy zwi¹zane z wyborem waluty.
     *
     * @param[in] choice Wybór waluty.
     * @param[in] error_msg Wiadomoœæ b³êdu do wyœwietlenia w przypadku nieprawid³owego wyboru.
     * @return Zwraca true, jeœli wyst¹pi³ b³¹d; false w przeciwnym razie.
     */
    bool error_cur(int choice, std::string error_msg);

    /**
     * @brief Sprawdza b³êdy zwi¹zane z iloœci¹ waluty.
     *
     * @param[in] currency Nazwa waluty.
     * @param[in] amount Iloœæ waluty.
     * @param[in] error_msg Wiadomoœæ b³êdu do wyœwietlenia w przypadku nieprawid³owej iloœci.
     * @return Zwraca true, jeœli wyst¹pi³ b³¹d; false w przeciwnym razie.
     */
    bool error_am(std::string currency, double amount, const std::string error_msg);
};
