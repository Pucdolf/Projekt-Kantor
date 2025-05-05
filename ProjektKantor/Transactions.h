#pragma once
#include <string>

/**
 * @class Transaction
 * @brief Klasa reprezentuj�ca transakcj� wymiany walut.
 *
 * Klasa Transaction zawiera informacje o transakcji, takie jak imi� i nazwisko klienta, waluta, ilo��, cena, typ transakcji oraz data i czas.
 */
class Transaction
{
private:
    std::string clientName{}; /**< Imi� klienta. */
    std::string clientSurname{}; /**< Nazwisko klienta. */
    std::string currency{}; /**< Waluta transakcji. */
    double amount{}; /**< Ilo�� waluty. */
    double price{}; /**< Cena transakcji. */
    std::string type{}; /**< Typ transakcji: "BUY" lub "SELL". */
    std::string datetime{}; /**< Data i czas transakcji. */

public:
    /**
     * @brief Konstruktor domy�lny klasy Transaction.
     */
    Transaction() {}

    /**
     * @brief Konstruktor klasy Transaction z parametrami.
     *
     * @param[in] name Imi� klienta.
     * @param[in] surname Nazwisko klienta.
     * @param[in] curr Waluta transakcji.
     * @param[in] amt Ilo�� waluty.
     * @param[in] pr Cena transakcji.
     * @param[in] typ Typ transakcji: "BUY" lub "SELL".
     */
    Transaction(const std::string& name, const std::string& surname, const std::string& curr, double amt, double pr, const std::string& typ);

    /**
     * @brief Zapisuje transakcj� do pliku.
     *
     * @param[in] file_name Nazwa pliku, do kt�rego zostanie zapisana transakcja.
     * @param[in] transaction Opis transakcji do zapisania.
     */
    void saveToFile(const std::string& file_name, std::string transaction) const;
};
