#pragma once

/**
 * @class IUser
 * @brief Interfejs użytkownika.
 *
 * Klasa IUser definiuje interfejs dla użytkowników systemu, wymagający implementacji metody displayMenu.
 */
class IUser
{
public:
    /**
     * @brief Wyświetla menu użytkownika.
     *
     * Metoda czysto wirtualna, która jest zaimplementowana przez klasy dziedziczące.
     */
    virtual void displayMenu() = 0;

    /**
     * @brief Wirtualny destruktor.
     *
     * Umożliwia prawidłowe zarządzanie zasobami w klasach dziedziczących.
     */
    virtual ~IUser() = default;
};
