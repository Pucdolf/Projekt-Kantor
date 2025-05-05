//#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <fstream>
#include <sstream>
#include "Kantor.h"
#include "Transactions.h"

void Kantor::loadResources(const std::string file_name, std::map<std::string, double>& currencies)
{
	std::ifstream in(file_name);

	if (!in.is_open())
	{
		std::cerr << "Nie udalo sie otworzyc pliku '" << file_name << "' !" << std::endl;
		return;
	}

	std::string line;

	while (std::getline(in, line))
	{
		std::istringstream iss(line);
		std::string currency;
		double rate;
		if (!(iss >> currency >> rate))
		{
			std::cerr << "Blad wczytywania kursu z linii!" << std::endl;
			continue;
		}

		currencies[currency] = rate;
	}

	in.close();
}


void Kantor::changeResources(const std::string currency, double amount, const std::string command, std::string transaction)
{
	if (command == "plus")
	{
		currencies[currency] += amount;
		if (transaction == "BUY")
			std::cout << "Dodano " << amount << " " << currency << " do zasobow kantoru." << std::endl;
		else
			std::cout << "Zabrano " << amount << " " << currency << " z zasobow kantoru." << std::endl;

	}
	else if (command == "minus")
	{
		currencies[currency] -= amount;
	}
	std::ofstream out("zasoby.txt");

	for (const auto& pair : currencies)
	{
		out << pair.first << " " << pair.second << "\n";
	}

}

void Kantor::makeTransaction(const std::string& imie, const std::string& nazwisko, const std::string& currency, double amount, double price, std::string transaction)
{

	std::cout << "Czy na pewno chcesz przeprowadzic transakcje? (tak/nie): ";
	std::string answer;
	std::cin >> answer;

	if (answer == "tak" and transaction == "BUY")
	{
		changeResources(currency, amount, "minus", "BUY");
		changeResources("PLN", price, "plus", "BUY");

		Transaction transaction(imie, nazwisko, currency, amount, price, "BUY");
		transaction.saveToFile("transactions.txt", "BUY");
		std::cout << "Transakcja zakonczona pomyslnie." << std::endl;
	}
	else if (answer == "tak" and transaction == "SELL")
	{
		changeResources(currency, amount, "plus", "SELL");
		changeResources("PLN", price, "minus", "SELL");

		Transaction transaction(imie, nazwisko, currency, amount, price, "SELL");
		transaction.saveToFile("transactions.txt", "SELL");
		std::cout << "Transakcja zakonczona pomyslnie." << std::endl;
	}
	else
	{
		std::cout << "Transakcja anulowana." << std::endl;
	}
}

bool Kantor::error_cur(int choice, const std::string error_msg)
{
	if (choice > currencies.size() or choice < 0 or std::cin.rdstate())
	{
		std::cin.clear();
		std::cin.ignore(1024, '\n');

		system("cls");
		std::cout << error_msg;
		_getch();
		system("cls");
		return false;
	}
	return true;
}


bool Kantor::error_am(std::string currency, double amount, const std::string error_msg)
{

	if (currencies[currency] < amount)
	{
		std::cin.clear();
		std::cin.ignore(1024, '\n');

		std::system("cls");
		std::cout << error_msg;
		_getch();
		std::system("cls");
		return false;
	}
	return true;
}

