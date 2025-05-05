#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>

/**
 * @class Currency
 * @brief Klasa do zarz¹dzania kursami walut.
 *
 * Klasa Currency zawiera metody do wczytywania i wyœwietlania kursów kupna i sprzeda¿y walut.
 */
class Currency
{
protected:
    std::map<std::string, double> buyRates; /**< Mapa przechowuj¹ca kursy kupna walut. */
    std::map<std::string, double> sellRates; /**< Mapa przechowuj¹ca kursy sprzeda¿y walut. */

    /**
     * @brief Konstruktor domyœlny klasy Currency.
     */
    Currency() = default;

    /**
     * @brief Wczytuje kursy kupna i sprzeda¿y z plików.
     *
     * @param[in] BuyRatesFile Nazwa pliku zawieraj¹cego kursy kupna.
     * @param[in] SellRatesFile Nazwa pliku zawieraj¹cego kursy sprzeda¿y.
     */
    void loadRates(std::string BuyRatesFile, std::string SellRatesFile)
    {
        loadBuyRates(BuyRatesFile);
        loadSellRates(SellRatesFile);
    }

    /**
     * @brief Wyœwietla kursy kupna i sprzeda¿y.
     */
    void showRates()
    {
        system("cls");
        std::cout << "Kursy kupna:\n";
        for (const auto& pair : buyRates)
        {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
        std::cout << "\nKursy sprzeda¿y:\n";
        for (const auto& pair : sellRates)
        {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }

private:
    /**
     * @brief Wczytuje kursy kupna z pliku.
     *
     * @param[in] BuyRatesFile Nazwa pliku zawieraj¹cego kursy kupna.
     */
    void loadBuyRates(std::string BuyRatesFile)
    {
        loadRatesFromFile(BuyRatesFile, buyRates);
    }

    /**
     * @brief Wczytuje kursy sprzeda¿y z pliku.
     *
     * @param[in] SellRatesFile Nazwa pliku zawieraj¹cego kursy sprzeda¿y.
     */
    void loadSellRates(std::string SellRatesFile)
    {
        loadRatesFromFile(SellRatesFile, sellRates);
    }

    /**
     * @brief Wczytuje kursy z pliku do podanej mapy.
     *
     * @param[in] file_name Nazwa pliku z kursami.
     * @param[out] RatesMap Mapa, do której zostan¹ wczytane kursy.
     */
    void loadRatesFromFile(const std::string file_name, std::map<std::string, double>& RatesMap)
    {
        std::ifstream in(file_name);

        if (!in.is_open())
        {
            std::cerr << "Nie uda³o siê otworzyæ pliku '" << file_name << "' !" << std::endl;
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
                std::cerr << "B³¹d wczytywania kursu z linii!" << std::endl;
                continue;
            }

            RatesMap[currency] = rate;
        }

        in.close();
    }
};
