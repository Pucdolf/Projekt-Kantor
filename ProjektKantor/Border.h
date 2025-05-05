#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @class Base
 * @brief Klasa bazowa zawieraj¹ca metody wspólne dla innych klas.
 *
 * Klasa zawiera metodê do rysowania obramowania wokó³ elementów menu.
 */
class Base
{
public:
    /**
     * @brief Rysuje obramowanie wokó³ menu.
     *
     * Metoda rysuje obramowanie wokó³ przekazanych elementów menu. Ka¿dy element menu jest wyœwietlany
     * w osobnej linii z obramowaniem z góry, do³u oraz po bokach.
     *
     * @param[in] menuItems Wektor zawieraj¹cy elementy menu do wyœwietlenia.
     */
    void drawBorder(const std::vector<std::string>& menuItems) const {

        // ZnajdŸ najd³u¿sz¹ liniê
        size_t maxLength{ 0 };
        for (const auto& item : menuItems) {
            maxLength = std::max(maxLength, item.length());
        }

        // Rysuj górne obramowanie
        std::cout << "+";
        for (size_t i{ 0 }; i < maxLength + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "+\n";

        // Rysuj menu z bocznymi obramowaniami
        for (const auto& item : menuItems) {
            std::cout << "| " << item;
            for (size_t i{ item.length() }; i < maxLength; ++i) {
                std::cout << " ";
            }
            std::cout << " |\n";
        }

        // Rysuj dolne obramowanie
        std::cout << "+";
        for (size_t i{ 0 }; i < maxLength + 2; ++i) {
            std::cout << "-";
        }
        std::cout << "+\n";
    }
};
