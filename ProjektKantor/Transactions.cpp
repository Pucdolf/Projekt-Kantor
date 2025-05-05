#include "Transactions.h"
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>

Transaction::Transaction(const std::string& name, const std::string& surname, const std::string& curr, double amt, double pr, const std::string& typ)
    : clientName(name), clientSurname(surname), currency(curr), amount(amt), price(pr), type(typ)
{
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm t;
    localtime_s(&t, &now); // U¿ywamy localtime_s zamiast localtime

    std::stringstream ss;
    ss << std::put_time(&t, "%Y-%m-%d %X");
    datetime = ss.str();
}

void Transaction::saveToFile(const std::string& file_name, std::string transaction) const {
    std::ofstream file(file_name, std::ios::app);
    if (file.is_open()) {
        if (transaction == "BUY")
            file << clientName << " " << clientSurname << " " << type << " " << currency << " " << amount << " +" << price << " " << datetime << "\n";
        else
            file << clientName << " " << clientSurname << " " << type << " " << currency << " " << amount << " -" << price << " " << datetime << "\n";
        file.close();
    }
}
