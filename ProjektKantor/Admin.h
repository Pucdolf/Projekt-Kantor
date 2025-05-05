#pragma once

#include "IUser.h"
#include "Border.h"
#include "Kantor.h"

/**
 * @class Administrator
 * @brief Klasa reprezentuj¹ca administratora systemu.
 *
 * Klasa dziedziczy po interfejsie IUser oraz klasach Base i Kantor.
 * Odpowiada za zarz¹dzanie systemem, w tym za zmiany kursów, zarz¹dzanie zasobami oraz obs³ugê transakcji.
 */
class Administrator : public IUser, public Base, public Kantor
{
    std::string password{}; /**< Has³o administratora. */
    std::string passwordFile = "password.txt"; /**< Nazwa pliku, w którym przechowywane jest has³o. */
public:
    static bool logged; /**< Flaga informuj¹ca o stanie zalogowania administratora. */

    /**
     * @brief Konstruktor klasy Administrator.
     *
     * @param[in] password Has³o administratora.
     */
    Administrator(std::string password);

    /**
     * @brief Metoda do wprowadzania has³a.
     */
    void typePassword();

    /**
     * @brief Wyœwietla menu administratora.
     *
     * Metoda nadpisuje funkcjê displayMenu z interfejsu IUser.
     */
    void displayMenu() override;

    /**
     * @brief Metoda do zmiany kursów walut.
     */
    void changeRates();

    /**
     * @brief Zapisuje kursy walut do pliku.
     *
     * @param[in] filename Nazwa pliku, do którego maj¹ zostaæ zapisane kursy.
     * @param[in] rates Mapa zawieraj¹ca kursy walut.
     */
    void saveRatesToFile(std::string filename, std::map<std::string, double> rates);

    /**
     * @brief Wyœwietla zasoby systemu.
     */
    void showResources();

    /**
     * @brief Ustawia zmiany w systemie.
     */
    void setChange();

    /**
     * @brief Zmienia has³o administratora.
     */
    void changePassword();

    /**
     * @brief Wyœwietla historiê transakcji.
     */
    void showTransactions();

    /**
     * @brief Czyœci historiê transakcji.
     */
    void clearTransactions();

    /**
     * @brief Sprawdza b³êdy na podstawie wyboru u¿ytkownika.
     *
     * @param[in] choice Wybór u¿ytkownika.
     * @param[in] error_msg Wiadomoœæ b³êdu do wyœwietlenia w przypadku nieprawid³owego wyboru.
     * @return Zwraca true, jeœli wyst¹pi³ b³¹d; false w przeciwnym razie.
     */
    bool error(int choice, const std::string error_msg);

    /**
     * @brief Sprawdza b³êdy na podstawie wprowadzonego has³a.
     *
     * @param[in] inputPassword Wprowadzone has³o.
     * @param[in] error_msg Wiadomoœæ b³êdu do wyœwietlenia w przypadku nieprawid³owego has³a.
     * @return Zwraca true, jeœli wyst¹pi³ b³¹d; false w przeciwnym razie.
     */
    bool error(const std::string& inputPassword, std::string error_msg);

private:
    /**
     * @brief Zapisuje has³o do pliku.
     */
    void savePasswordToFile();

    /**
     * @brief Wczytuje has³o z pliku.
     */
    void loadPasswordFromFile();
};
