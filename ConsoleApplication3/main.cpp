//13 - enter
//27 - escape
//8 - backspace
//32 - space 
//
//72 - Стрелка вверх 
//80 - Стрелка вниз 
//75 - Стрелка влево 
//77 - Стрелка вправо 

// The item "DELETE" doesn`t realise//

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Singleton.h"

using namespace std;

void add_element(Singleton& biathlon)
{
	item built_biathlonist;
	int check;

	string buf_str;
	cout << "Name: ";
	cin >> buf_str;
	built_biathlonist.set_name(buf_str);

	cout << "Last name: ";
	string buf_str1;
	cin >> buf_str1;
	built_biathlonist.set_last_name(buf_str1);
	
	srand(time(NULL));
	cout << "ID: ";
	int buf_time = rand() %10000 + 1;
	cout << buf_time << endl;
	built_biathlonist.set_id(buf_time);

		int buf_int;
		do{
			cout << "Shoot: ";
			cin.clear();
			cin.sync();
			cin >> buf_int;
		} while (cin.fail() || (buf_int<0) || (buf_int>6));
	built_biathlonist.set_shoot(buf_int);

	string str3 = "m";
	string str4 = "w";
	string buf;
	cout << "Gender (m or w): ";
	cin >> buf;

	while ((buf != str3) & (buf != str4))
	{
		cout << "repeat: ";
		cin >> buf;
	}
	built_biathlonist.set_gender(buf);

	double buf_double;
	do{
			cout << "Distance: ";
			cin.clear();
			cin.sync();
			cin >> buf_double;
			} while (cin.fail() || (buf_double<0) );
	built_biathlonist.set_distance(buf_double);

	check = biathlon.add(built_biathlonist);
	if (check != 0){
		cout << "You can`t add more biathlonists";
	}
}
void help() {
		cout << "You can use arrows like UP or DOWN to change the menu item.";
		cout << "To choose the item you should press ENTER and SPACE - to back to the main menu! ";
}
void show_list(Singleton& biathlon){
	biathlon.list();
}

void operations(Singleton& biathlon, int count){
	switch (count){
	case 1:
		help();
		break;
	case 2:
		add_element(biathlon);
		break;
	//case 3:
	//	del(Biathlon, num);
	//	break;
	case 4:
		show_list(biathlon);
		break;
	case 5:
		exit(2);
		break;
	}
}
int menu(Singleton& biathlon){
	
	bool exit = false;
	int press; //what is the key?
	int item = 5; // menu_item
	int count = 1; // count menu_item

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {0, 1};
	cout << "Biathlonists" << endl; 
	cout << "* 1. Help" << endl << "  2. Add" << endl << "  3. Delete" << endl << "  4. All list" << endl << "  5. Exit" << endl; 
	SetConsoleCursorPosition(hConsole, position);
	
	while (!exit)
	{
		press = _getch(); //reads a character directly from the console without buffer, and without echo.
		switch (press)	{
		case 224: {
			switch (_getch())
			{
			case 72: { // up
				if (position.Y-1){
					cout << " ";
					position.Y--;
					SetConsoleCursorPosition(hConsole, position);
					cout << "*";
					SetConsoleCursorPosition(hConsole, position);
					count--;	
					if (count == 0) {count = 1;}
				}
					break;
			}
			case 80: {// down
				if (position.Y < item)	{
					cout << " ";
					position.Y++;
					SetConsoleCursorPosition(hConsole, position);
					cout <<"*";
					SetConsoleCursorPosition(hConsole, position);
					count++;	
					if (count == 6) {count = 5;}
				}
					break;
					}
					default:
						break;
					}
					break;
		}
		case 13: {
			system("cls");
			operations(biathlon, count);
			cout << endl << endl << "To back to the main menu press SPACE ";
			int key = _getch();
			switch(key){
			case 32: {
				system("cls");
				menu(biathlon );
				break;
			}
			default:
			break;
			}
			break;
		}
		case 27: //esc
			exit = true;
			break;
		default:
			break;
		}
	}
	return 0;
}
int main()
{
	Singleton& biathlon = Singleton::Instance();
	menu(biathlon);

	system("pause");
	return 0;
}
