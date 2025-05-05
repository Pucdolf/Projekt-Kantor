#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @class Base
 * @brief Klasa bazowa zawieraj�ca metody wsp�lne dla innych klas.
 *
 * Klasa zawiera metod� do rysowania obramowania wok� element�w menu.
 */
class Base
{
public:
    /**
     * @brief Rysuje obramowanie wok� menu.
     *
     * Metoda rysuje obramowanie wok� przekazanych element�w menu. Ka�dy element menu jest wy�wietlany
     * w osobnej linii z obramowaniem z g�ry, do�u oraz po bokach.
     *
     * @param[in] menuItems Wektor zawieraj�cy elementy menu do wy�wietlenia.
     */
    void drawBorder(const std::vector<std::string>& menuItems) const {

        // Znajd� najd�u�sz� lini�
        size_t maxLength{ 0 };
        for (const auto& item : menuItems) {
            maxLength = std::max(maxLength, item.length());
        }

        // Rysuj g�rne obramowanie
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
