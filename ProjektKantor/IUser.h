#pragma once

/**
 * @class IUser
 * @brief Interfejs u¿ytkownika.
 *
 * Klasa IUser definiuje interfejs dla u¿ytkowników systemu, wymagaj¹cy implementacji metody displayMenu.
 */
class IUser
{
public:
    /**
     * @brief Wyœwietla menu u¿ytkownika.
     *
     * Metoda czysto wirtualna, która jest zaimplementowana przez klasy dziedzicz¹ce.
     */
    virtual void displayMenu() = 0;

    /**
     * @brief Wirtualny destruktor.
     *
     * Umo¿liwia prawid³owe zarz¹dzanie zasobami w klasach dziedzicz¹cych.
     */
    virtual ~IUser() = default;
};
