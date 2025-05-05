#pragma once

#include "IUser.h"
#include "Border.h"
#include "Kantor.h"

/**
 * @class Client
 * @brief Klasa reprezentuj�ca klienta systemu.
 *
 * Klasa dziedziczy po interfejsie IUser oraz klasach Base i Kantor.
 * Odpowiada za zarz�dzanie informacjami o kliencie oraz operacjami zwi�zanymi z transakcjami.
 */
class Client : public IUser, public Base, public Kantor
{
    std::string imie{}; /**< Imi� klienta. */
    std::string nazwisko{}; /**< Nazwisko klienta. */

public:
    /**
     * @brief Ustawia imi� klienta.
     */
    void setName();

    /**
     * @brief Wy�wietla menu klienta.
     *
     * Metoda nadpisuje funkcj� displayMenu z interfejsu IUser.
     */
    void displayMenu() override;

    /**
     * @brief Ustawia transakcj� klienta.
     *
     * @param[in] transaction Opis transakcji.
     */
    void setTransaction(const std::string transaction);

    /**
     * @brief Sprawdza b��dy na podstawie wyboru u�ytkownika.
     *
     * @param[in] choice Wyb�r u�ytkownika.
     * @param[in] error_msg Wiadomo�� b��du do wy�wietlenia w przypadku nieprawid�owego wyboru.
     * @return Zwraca true, je�li wyst�pi� b��d; false w przeciwnym razie.
     */
    bool error(int choice, std::string error_msg);

    /**
     * @brief Sprawdza b��dy na podstawie wyboru transakcji.
     *
     * @param[in] choice Wyb�r u�ytkownika.
     * @param[in] size Oczekiwana wielko�� transakcji.
     * @param[in] error_msg Wiadomo�� b��du do wy�wietlenia w przypadku nieprawid�owej transakcji.
     * @return Zwraca true, je�li wyst�pi� b��d; false w przeciwnym razie.
     */
    bool error_transaction(int choice, int size, std::string error_msg);
};
