#pragma once

#include "IUser.h"
#include "Border.h"
#include "Kantor.h"

/**
 * @class Client
 * @brief Klasa reprezentuj¹ca klienta systemu.
 *
 * Klasa dziedziczy po interfejsie IUser oraz klasach Base i Kantor.
 * Odpowiada za zarz¹dzanie informacjami o kliencie oraz operacjami zwi¹zanymi z transakcjami.
 */
class Client : public IUser, public Base, public Kantor
{
    std::string imie{}; /**< Imiê klienta. */
    std::string nazwisko{}; /**< Nazwisko klienta. */

public:
    /**
     * @brief Ustawia imiê klienta.
     */
    void setName();

    /**
     * @brief Wyœwietla menu klienta.
     *
     * Metoda nadpisuje funkcjê displayMenu z interfejsu IUser.
     */
    void displayMenu() override;

    /**
     * @brief Ustawia transakcjê klienta.
     *
     * @param[in] transaction Opis transakcji.
     */
    void setTransaction(const std::string transaction);

    /**
     * @brief Sprawdza b³êdy na podstawie wyboru u¿ytkownika.
     *
     * @param[in] choice Wybór u¿ytkownika.
     * @param[in] error_msg Wiadomoœæ b³êdu do wyœwietlenia w przypadku nieprawid³owego wyboru.
     * @return Zwraca true, jeœli wyst¹pi³ b³¹d; false w przeciwnym razie.
     */
    bool error(int choice, std::string error_msg);

    /**
     * @brief Sprawdza b³êdy na podstawie wyboru transakcji.
     *
     * @param[in] choice Wybór u¿ytkownika.
     * @param[in] size Oczekiwana wielkoœæ transakcji.
     * @param[in] error_msg Wiadomoœæ b³êdu do wyœwietlenia w przypadku nieprawid³owej transakcji.
     * @return Zwraca true, jeœli wyst¹pi³ b³¹d; false w przeciwnym razie.
     */
    bool error_transaction(int choice, int size, std::string error_msg);
};
