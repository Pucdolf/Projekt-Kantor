#include <iostream>
#include <vector>
#include <conio.h>

#include "Client.h"
#include "MainMenu.h"

void Client::displayMenu()
{
	loadResources("zasoby.txt", currencies);
	loadRates("kupno.txt", "sprzedaz.txt");

	std::system("cls");
	int choice{};

	std::vector<std::string>clientMenuItems = {
			"1. Wyswietl aktualne kursy walut",
			"2. Dokonaj transakcji kupna waluty",
			"3. Dokonaj transakcji sprzedazy waluty",
			"4. Menu glowne",
			"5. Wyjscie"
	};
	do {
		drawBorder(clientMenuItems);
		std::cout << "Wybierz opje[1-5]: ";
		std::cin >> choice;

	} while (!error(choice, "Blad! By wybrac ponownie nacisnij dowolny klawisz."));

	MainMenu main_menu;

	switch (choice)
	{
	case 1:
		showRates();
		_getch();
		displayMenu();
		break;
	case 2:
		setName();
		setTransaction("kupic");
		break;
	case 3:
		setName();
		setTransaction("sprzedac");
		break;
	case 4:
		system("cls");
		main_menu.displayMenu();
		break;
	case 5:
		std::cout << "Zamknieto program...";
		exit(0);
	}
}

void Client::setName()
{

	system("cls");
	std::string line;

	std::cout << "Podaj imie i nazwisko [-back by wrocic]: ";
	std::cin.clear();
	std::cin.ignore(1024, '\n');
	std::getline(std::cin, line);

	if (line == "-back")
	{
		system("cls");
		displayMenu();
	}

	std::istringstream iss(line);
	while (!(iss >> imie >> nazwisko));
}

void Client::setTransaction(const std::string transaction)
{
	system("cls");
	std::string currency;
	int choice;
	double amount;
	std::cin.clear();

	std::map<int, std::string> currencyList;
	int il = 1;
	for (const auto& entry : currencies)
	{
		if (entry.first != "PLN")
			currencyList[il++] = entry.first;
	}

	do {
		std::cout << "Podaj jaka walute chcesz " << transaction << "\n";
		for (const auto& option : currencyList)
			std::cout << option.first << ") " << option.second << std::endl;

		std::cout << "Wybierz opcje[1-" << currencyList.size() << "]:";
		std::cin >> choice;
	} while (!error_transaction(choice, currencyList.size(), "Blad! By wybrac ponownie nacisnij dowolny klawisz."));

	currency = currencyList[choice];
	double price;

	//KUPNO
	if (transaction == "kupic")
	{
		do
		{
			std::cout << "Podaj ile " << currency << " chcesz " << transaction << "(Kantor ma: " << currencies[currency] << ")." << std::endl;
			std::cin >> amount;

		} while (!error_am(currency, amount, "Kantor nie ma wystarczajacej ilosci waluty."));


		price = amount * buyRates[currency];

		std::cout << "Cena za " << amount << " " << currency << " to: " << price << " PLN" << "(Kurs: " << buyRates[currency] << ")." << std::endl;

		std::cout << "Czy chcesz dokonac transakcji? (tak/nie): ";
		std::string answer;
		std::cin >> answer;

		if (answer == "tak")
		{
			makeTransaction(imie, nazwisko, currency, amount, price, "BUY");
		}
		else
		{
			std::cout << "Transakcja anulowana." << std::endl;
		}
	}
	//SPRZEDAZ
	else
	{
		do
		{
			std::cout << "Podaj ile " << currency << " chcesz " << transaction << "(Kantor ma: " << currencies["PLN"] << " PLN)." << std::endl;
			std::cin >> amount;

		} while (!error_am("PLN", amount, "Kantor nie ma wystarczajacej ilosci waluty."));

		price = amount * sellRates[currency];

		std::cout << "Cena za " << amount << " " << currency << " to: " << price << " PLN" << "(Kurs: " << sellRates[currency] << ")." << std::endl;

		std::cout << "Czy chcesz dokonac transakcji? (tak/nie): ";
		std::string answer;
		std::cin >> answer;

		std::cout << "Za " << amount << " " << currency << " otrzymasz " << price << " PLN na swoje konto." << std::endl;

		if (answer == "tak")
		{
			makeTransaction(imie, nazwisko, currency, amount, price, "SELL");
		}
		else
		{
			std::cout << "Transakcja anulowana." << std::endl;
		}
	}

	_getch();
	displayMenu();
}

bool Client::error(int choice, std::string error_msg)
{
	if (choice > 5 or choice < 1 or std::cin.rdstate())
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

bool Client::error_transaction(int choice, int size, std::string error_msg)
{
	if (choice > size or choice < 1 or std::cin.rdstate())
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