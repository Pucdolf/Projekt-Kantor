#pragma once

/**
 * @class IUser
 * @brief Interfejs u�ytkownika.
 *
 * Klasa IUser definiuje interfejs dla u�ytkownik�w systemu, wymagaj�cy implementacji metody displayMenu.
 */
class IUser
{
public:
    /**
     * @brief Wy�wietla menu u�ytkownika.
     *
     * Metoda czysto wirtualna, kt�ra jest zaimplementowana przez klasy dziedzicz�ce.
     */
    virtual void displayMenu() = 0;

    /**
     * @brief Wirtualny destruktor.
     *
     * Umo�liwia prawid�owe zarz�dzanie zasobami w klasach dziedzicz�cych.
     */
    virtual ~IUser() = default;
};
