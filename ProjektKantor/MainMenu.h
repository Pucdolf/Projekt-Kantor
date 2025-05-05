#pragma once

#include "Client.h"
#include "Admin.h"
#include "Border.h"

/**
 * @class MainMenu
 * @brief Klasa reprezentuj¹ca g³ówne menu aplikacji.
 *
 * Klasa MainMenu dziedziczy po klasach Base i IUser, zapewniaj¹c interfejs g³ównego menu aplikacji.
 */
class MainMenu : public Base, public IUser
{
    Client client; /**< Obiekt reprezentuj¹cy klienta. */
    Administrator admin; /**< Obiekt reprezentuj¹cy administratora. */

public:
    /**
     * @brief Konstruktor domyœlny klasy MainMenu.
     */
    MainMenu();

    /**
     * @brief Wyœwietla g³ówne menu aplikacji.
     *
     * Metoda nadpisuje funkcjê displayMenu z interfejsu IUser.
     */
    void displayMenu() override;

    /**
     * @brief Sprawdza b³êdy na podstawie wyboru u¿ytkownika.
     *
     * @param[in] choice Wybór u¿ytkownika.
     * @param[in] error_msg Wiadomoœæ b³êdu do wyœwietlenia w przypadku nieprawid³owego wyboru.
     * @return Zwraca true, jeœli wyst¹pi³ b³¹d; false w przeciwnym razie.
     */
    bool error(int choice, std::string error_msg);
};
