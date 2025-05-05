#pragma once

#include "IUser.h"
#include "Border.h"
#include "Kantor.h"

/**
 * @class Administrator
 * @brief Klasa reprezentuj�ca administratora systemu.
 *
 * Klasa dziedziczy po interfejsie IUser oraz klasach Base i Kantor.
 * Odpowiada za zarz�dzanie systemem, w tym za zmiany kurs�w, zarz�dzanie zasobami oraz obs�ug� transakcji.
 */
class Administrator : public IUser, public Base, public Kantor
{
    std::string password{}; /**< Has�o administratora. */
    std::string passwordFile = "password.txt"; /**< Nazwa pliku, w kt�rym przechowywane jest has�o. */
public:
    static bool logged; /**< Flaga informuj�ca o stanie zalogowania administratora. */

    /**
     * @brief Konstruktor klasy Administrator.
     *
     * @param[in] password Has�o administratora.
     */
    Administrator(std::string password);

    /**
     * @brief Metoda do wprowadzania has�a.
     */
    void typePassword();

    /**
     * @brief Wy�wietla menu administratora.
     *
     * Metoda nadpisuje funkcj� displayMenu z interfejsu IUser.
     */
    void displayMenu() override;

    /**
     * @brief Metoda do zmiany kurs�w walut.
     */
    void changeRates();

    /**
     * @brief Zapisuje kursy walut do pliku.
     *
     * @param[in] filename Nazwa pliku, do kt�rego maj� zosta� zapisane kursy.
     * @param[in] rates Mapa zawieraj�ca kursy walut.
     */
    void saveRatesToFile(std::string filename, std::map<std::string, double> rates);

    /**
     * @brief Wy�wietla zasoby systemu.
     */
    void showResources();

    /**
     * @brief Ustawia zmiany w systemie.
     */
    void setChange();

    /**
     * @brief Zmienia has�o administratora.
     */
    void changePassword();

    /**
     * @brief Wy�wietla histori� transakcji.
     */
    void showTransactions();

    /**
     * @brief Czy�ci histori� transakcji.
     */
    void clearTransactions();

    /**
     * @brief Sprawdza b��dy na podstawie wyboru u�ytkownika.
     *
     * @param[in] choice Wyb�r u�ytkownika.
     * @param[in] error_msg Wiadomo�� b��du do wy�wietlenia w przypadku nieprawid�owego wyboru.
     * @return Zwraca true, je�li wyst�pi� b��d; false w przeciwnym razie.
     */
    bool error(int choice, const std::string error_msg);

    /**
     * @brief Sprawdza b��dy na podstawie wprowadzonego has�a.
     *
     * @param[in] inputPassword Wprowadzone has�o.
     * @param[in] error_msg Wiadomo�� b��du do wy�wietlenia w przypadku nieprawid�owego has�a.
     * @return Zwraca true, je�li wyst�pi� b��d; false w przeciwnym razie.
     */
    bool error(const std::string& inputPassword, std::string error_msg);

private:
    /**
     * @brief Zapisuje has�o do pliku.
     */
    void savePasswordToFile();

    /**
     * @brief Wczytuje has�o z pliku.
     */
    void loadPasswordFromFile();
};
