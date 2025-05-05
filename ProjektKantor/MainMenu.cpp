#include <iostream>
#include <vector>
#include <conio.h>

#include"MainMenu.h"

MainMenu::MainMenu() :admin("admin") {}

void MainMenu::displayMenu()
{
	Administrator::logged = false;
	int choice{};
	std::vector<std::string> mainMenuItems = {
		"--Main Menu--",
		"1.Klient",
		"2.Administrator",
		"3.Wyjdz"
	};

	do
	{
		drawBorder(mainMenuItems);
		std::cout << "Wybierz opcje[1-3]: ";
		std::cin >> choice;

	} while (!error(choice, "Blad! By wybrac ponownie nacisnij dowolny klawisz."));



	switch (choice)
	{
	case 1:
		client.displayMenu();
		break;
	case 2:
		admin.displayMenu();
		break;
	case 3:
		std::cout << "Zamknieto program...";
		exit(0);
	}
}

bool MainMenu::error(int choice, const std::string error_msg)
{
	if (choice > 3 or choice < 0 or std::cin.rdstate())
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

