#pragma once

#include "Client.h"
#include "Admin.h"
#include "Border.h"

/**
 * @class MainMenu
 * @brief Klasa reprezentuj�ca g��wne menu aplikacji.
 *
 * Klasa MainMenu dziedziczy po klasach Base i IUser, zapewniaj�c interfejs g��wnego menu aplikacji.
 */
class MainMenu : public Base, public IUser
{
    Client client; /**< Obiekt reprezentuj�cy klienta. */
    Administrator admin; /**< Obiekt reprezentuj�cy administratora. */

public:
    /**
     * @brief Konstruktor domy�lny klasy MainMenu.
     */
    MainMenu();

    /**
     * @brief Wy�wietla g��wne menu aplikacji.
     *
     * Metoda nadpisuje funkcj� displayMenu z interfejsu IUser.
     */
    void displayMenu() override;

    /**
     * @brief Sprawdza b��dy na podstawie wyboru u�ytkownika.
     *
     * @param[in] choice Wyb�r u�ytkownika.
     * @param[in] error_msg Wiadomo�� b��du do wy�wietlenia w przypadku nieprawid�owego wyboru.
     * @return Zwraca true, je�li wyst�pi� b��d; false w przeciwnym razie.
     */
    bool error(int choice, std::string error_msg);
};
