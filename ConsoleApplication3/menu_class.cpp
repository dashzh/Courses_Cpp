#include <windows.h>
#include <iostream>
#include <conio.h>

#include "menu_class.h"

using namespace std;

void Menu::prepare()
{
	system("cls");
	cout << "Biathlonists" << endl;
	cout << "* 1. Help" << endl << "  2. Add" << endl << "  3. Changes(id) " << endl << "  4. Remove(id)" << endl << "  5. All list(general rating)" << endl << "  6. Exit" << endl;
	SetConsoleCursorPosition(hConsole, position);
}

bool Menu::exit = false;
int Menu::item = 6;
int Menu::count = 1; //Global menu counter

HANDLE Menu::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Menu::position = { 0, 1 };


void upMenu::draw() {
	if (position.Y - 1){
		cout << " ";
		position.Y--;
		SetConsoleCursorPosition(hConsole, position);
		cout << "*";
		SetConsoleCursorPosition(hConsole, position);
		count--;
		if (count == 0) { count = 1; }
	}
}

void upMenu::for_prepare()
{
	prepare();
}

void downMenu::draw() {
	if (position.Y < item)	{
		cout << " ";
		position.Y++;
		SetConsoleCursorPosition(hConsole, position);
		cout << "*";
		SetConsoleCursorPosition(hConsole, position);
		count++;
		if (count == 7) { count = 6; }
	}
}
void downMenu::for_prepare()
{
	prepare();
}


void enterMenu::draw() {
	int key;
	while (1){
		key = _getch();
		if (key == 32) { //Space is pressed
			count = 1;
			hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			position = { 0, count };
			prepare();
			break;
		}
	}
}
void enterMenu::for_prepare()
{
	prepare();
}

void escMenu::draw() {
	system("cls");
	cout << "Ending of the program..." << endl;
	Sleep(800);
}
void escMenu::for_prepare()
{
	prepare();
}

