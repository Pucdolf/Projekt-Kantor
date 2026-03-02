#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>

/**
 * @class Currency
 * @brief Klasa do zarządzania kursami walut.
 *
 * Klasa Currency zawiera metody do wczytywania i wyświetlania kursów kupna i sprzedaży walut.
 */
class Currency
{
protected:
    std::map<std::string, double> buyRates; /**< Mapa przechowująca kursy kupna walut. */
    std::map<std::string, double> sellRates; /**< Mapa przechowująca kursy sprzedaży walut. */

    /**
     * @brief Konstruktor domyślny klasy Currency.
     */
    Currency() = default;

    /**
     * @brief Wczytuje kursy kupna i sprzedaży z plików.
     *
     * @param[in] BuyRatesFile Nazwa pliku zawierającego kursy kupna.
     * @param[in] SellRatesFile Nazwa pliku zawierającego kursy sprzedaży.
     */
    void loadRates(std::string BuyRatesFile, std::string SellRatesFile)
    {
        loadBuyRates(BuyRatesFile);
        loadSellRates(SellRatesFile);
    }

    /**
     * @brief Wyświetla kursy kupna i sprzedaży.
     */
    void showRates()
    {
        system("cls");
        std::cout << "Kursy kupna:\n";
        for (const auto& pair : buyRates)
        {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
        std::cout << "\nKursy sprzedazy:\n";
        for (const auto& pair : sellRates)
        {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }

private:
    /**
     * @brief Wczytuje kursy kupna z pliku.
     *
     * @param[in] BuyRatesFile Nazwa pliku zawierającego kursy kupna.
     */
    void loadBuyRates(std::string BuyRatesFile)
    {
        loadRatesFromFile(BuyRatesFile, buyRates);
    }

    /**
     * @brief Wczytuje kursy sprzedaży z pliku.
     *
     * @param[in] SellRatesFile Nazwa pliku zawierającego kursy sprzedaży.
     */
    void loadSellRates(std::string SellRatesFile)
    {
        loadRatesFromFile(SellRatesFile, sellRates);
    }

    /**
     * @brief Wczytuje kursy z pliku do podanej mapy.
     *
     * @param[in] file_name Nazwa pliku z kursami.
     * @param[out] RatesMap Mapa, do której zostaną wczytane kursy.
     */
    void loadRatesFromFile(const std::string file_name, std::map<std::string, double>& RatesMap)
    {
        std::ifstream in(file_name);

        if (!in.is_open())
        {
            std::cerr << "Nie udało się otworzyć pliku '" << file_name << "' !" << std::endl;
            return;
        }

        std::string line;

        while (std::getline(in, line))
        {
            std::istringstream iss(line);
            std::string currency;
            double rate;
            if (!(iss >> currency >> rate))
            {
                std::cerr << "Błąd wczytywania kursu z linii!" << std::endl;
                continue;
            }

            RatesMap[currency] = rate;
        }

        in.close();
    }
};
