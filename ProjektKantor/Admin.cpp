#include <iostream>
#include <conio.h>
#include <vector>

#include"Admin.h"
#include "MainMenu.h"
#include "Transactions.h"

bool Administrator::logged{ false };


Administrator::Administrator(std::string)
{
	loadPasswordFromFile();
}


void Administrator::displayMenu()
{
	loadResources("zasoby.txt", currencies);
	loadRates("kupno.txt", "sprzedaz.txt");

	if (!Administrator::logged)
	{
		typePassword();
		logged = true;
	}


	system("cls");
	int choice{};

	std::vector<std::string> adminMenuItems = {
			"--Admin--",
			"1. Wyswietl aktualne kursy walut",
			"2. Aktualizuj kursy walut",
			"3. Pokaz zasoby",
			"4. Dodaj zasoby",
			"5. Pokaz historie transakcji",
			"6. Wyczysc historie transakcji",
			"7. Zmien haslo",
			"8. Menu glowne",
			"9. Wyjscie"
	};

	do {

		drawBorder(adminMenuItems);
		std::cout << "Wybierz opcje[1-9]: ";
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
		changeRates();
		_getch();
		displayMenu();
		break;
	case 3:
		showResources();
		_getch();
		displayMenu();
		break;
	case 4:
		setChange();
		_getch();
		displayMenu();
		break;
	case 5:
		showTransactions();
		_getch();
		displayMenu();
		break;
	case 6:
		clearTransactions();
		_getch();
		displayMenu();
		break;
	case 7:
		changePassword();
		_getch();
		displayMenu();
		break;
	case 8:
		system("cls");
		main_menu.displayMenu();
		break;
	case 9:
		std::cout << "Zamknieto program...";
		exit(0);
	}

}

void Administrator::typePassword()
{

	system("cls");

	std::string inputPassword;
	MainMenu main_menu;
	do
	{
		std::cout << "Podaj haslo [-back by wrocic]: ";
		std::cin >> inputPassword;
		if (inputPassword == "-back")
		{
			system("cls");
			main_menu.displayMenu();
		}

	} while (!error(inputPassword, "Haslo niepoprawne! By sprobowac ponownie nacisnij dowolny klawisz."));

}

void Administrator::setChange()
{
	std::string line{};
	std::string currency{};
	double amount{};
	int choice;
	Client temp;

	std::map<int, std::string> currencyList;
	int il = 1;

	system("cls");

	for (const auto& entry : currencies)
	{
		if (entry.first != "PLN")
			currencyList[il++] = entry.first;
	}

	do {
		for (const auto& option : currencyList)
			std::cout << option.first << ") " << option.second << std::endl;
		std::cout << "Wybierz walute ktora chcesz dodac [1-" << currencyList.size() << "]:";
		std::cin >> choice;
		currency = currencyList[choice];
		std::cout << "Podaj ile " << currency << " chesz dodac: ";
		std::cin >> amount;

	} while (!temp.error_transaction(choice, currencyList.size(), "Blad! By wybrac ponownie nacisnij dowolny klawisz."));

	changeResources(currency, amount, "plus", "BUY");
}

void Administrator::changeRates()
{
	std::string currency{};
	double newBuyRate, newSellRate;

	system("cls");

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

	/*do*/ {
		std::cout << "Wybierz walute, ktorej kursy chcesz zmienic:" "\n";
		for (const auto& option : currencyList)
			std::cout << option.first << ") " << option.second << std::endl;

		std::cout << "Wybierz opcje[1-" << currencyList.size() << "]:";
		std::cin >> choice;
	}/* while (!error_transaction(choice, currencyList.size(), "Brak dostepnej waluty!"));*/

	currency = currencyList[choice];

	std::cout << "Obecny kurs kupna dla " << currency << ": " << buyRates[currency] << "\n";
	std::cout << "Podaj nowy kurs kupna: ";
	std::cin >> newBuyRate;

	std::cout << "Obecny kurs sprzedazy dla " << currency << ": " << sellRates[currency] << "\n";
	std::cout << "Podaj nowy kurs sprzedazy: ";
	std::cin >> newSellRate;

	buyRates[currency] = newBuyRate;
	sellRates[currency] = newSellRate;

	saveRatesToFile("kupno.txt", buyRates);
	saveRatesToFile("sprzedaz.txt", sellRates);

	std::cout << "Kursy waluty " << currency << " zostaly zaktualizowane.\n";

	_getch();
	displayMenu();

}

void Administrator::saveRatesToFile(std::string filename, std::map<std::string, double> Rates)
{
	std::ofstream outFile(filename);

	if (outFile)
	{
		for (const auto& rate : Rates)
		{
			outFile << rate.first << " " << rate.second << std::endl;
		}
		outFile.close();
	}
	else
		std::cerr << "Nie mozna zapisac pliku " << filename << std::endl;
}


void Administrator::showResources()
{
	system("cls");
	std::cout << "Zasoby kantoru:\n";
	for (const auto& pair : currencies)
	{
		std::cout << pair.first << ": " << pair.second << "\n";
	}
}

void Administrator::changePassword()
{
	std::string oldPassword;
	std::string newPassword;
	system("cls");

	std::cout << "Podaj obecne haslo:\n";
	std::cin >> oldPassword;

	if (oldPassword == password) {
		std::cout << "Podaj nowe haslo:\n";
		std::cin >> newPassword;
		password = newPassword;
		savePasswordToFile();  // Zapisz nowe has³o do pliku
		std::cout << "Haslo zostalo zmienione.\n";
	}
	else {
		std::cout << "Haslo niepoprawne.\n";
	}
}

void Administrator::savePasswordToFile() {
	std::ofstream outFile(passwordFile);
	if (outFile.is_open()) {
		outFile << password;
		outFile.close();
	}
	else {
		std::cerr << "Nie mozna zapisac hasla do pliku.\n";
	}
}

void Administrator::loadPasswordFromFile() {
	std::ifstream inFile(passwordFile);
	if (inFile.is_open()) {
		std::getline(inFile, password);
		inFile.close();
	}
	else {
		std::cerr << "Nie mozna odczytac hasla z pliku. Ustawiono domyslne haslo.\n";
		password = "default";  // Ustaw domyœlne has³o, jeœli plik nie istnieje
	}
}
void Administrator::showTransactions()
{
	system("cls");

	std::ifstream inFile("transactions.txt");

	std::cout << std::setw(20) << std::left << "IMIE"
		<< std::setw(20) << std::left << "NAZWISKO"
		<< std::setw(20) << std::left << "TRANSAKCJA"
		<< std::setw(20) << std::left << "WALUTA"
		<< std::setw(20) << std::left << "ILOSC"
		<< std::setw(20) << std::left << "CENA W PLN"
		<< std::setw(20) << std::left << "DATA"
		<< std::setw(20) << std::left << "GODZINA" << std::endl;

	if (inFile)
	{
		std::string imie, nazwisko, transakcja, waluta, ilosc, cena, data{}, godzina;
		while (inFile >> imie >> nazwisko >> transakcja >> waluta >> ilosc >> cena >> data >> godzina)
		{
			std::cout << std::setw(20) << std::left << imie
				<< std::setw(20) << std::left << nazwisko
				<< std::setw(20) << std::left << transakcja
				<< std::setw(20) << std::left << waluta
				<< std::setw(20) << std::left << ilosc
				<< std::setw(20) << std::left << cena
				<< std::setw(20) << std::left << data
				<< std::setw(20) << std::left << godzina << std::endl;
		}
	}
	else
	{
		std::cerr << "Nie udalo sie otworzyc pliku 'transactions.txt' !" << std::endl;
	}
}


void Administrator::clearTransactions()
{
	std::cout << "Czy chcesz usunac historie transakcji? (tak/nie):" << std::endl;
	std::string answer;
	std::cin >> answer;

	if (answer == "tak")
	{

		std::ofstream outFile("transactions.txt", std::ios::trunc); // Otwarcie pliku w trybie truncate

		if (outFile.is_open()) {
			outFile.close();
			std::cout << "Historia transakcji zostala wyczyszczona.\n";
		}

	}
}

bool Administrator::error(int choice, const std::string error_msg)
{
	if (choice > 9 or choice < 1 or std::cin.rdstate())
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

bool Administrator::error(const std::string& inputPassword, const std::string error_msg)
{
	if (inputPassword != password or std::cin.rdstate())
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