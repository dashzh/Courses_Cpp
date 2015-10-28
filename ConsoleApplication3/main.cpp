//13 - enter
//27 - escape
//8 - backspace
//32 - space 
//
//72 - UP 
//80 - DOWN
//75 - LEFT 
//77 - RIGHT

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
/////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////
	string str3 = "m";
	string str4 = "w";
	string buf;
	cout << "Gender (m or w): ";
	cin >> buf;
	while ((buf != str3) & (buf != str4)) {
		cout << "repeat: ";
		cin >> buf;
	}
	built_biathlonist.set_gender(buf);
//////////////////////////////////////////////////////////////////////////////////////////////
		int units;
		do{
			cout << "Enter the units (1-6)" << endl <<"1.Individual, 2.Sprint, 3.Pursuit, 4.MassStart, 5.Relay, 6.MixRelay: ";
			cin >> units;
		} while (units < 1 || units > 6);
		built_biathlonist.set_unit(units);
		double buf_double; //for distance
		int buf_int; // for shoot
		if(buf == str3){ // m
		switch(units){
		case 1: 
				buf_double = 20; 
				do{
				cout << "Shoot - 4 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>20));
				break;
		case 2: 
				buf_double = 7.5;
				do{
				cout << "Shoot - 2 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>10));
			break;
		case 3: 
				buf_double = 10;
				do{
				cout << "Shoot - 4 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>20));
			break;
		case 4: 
				buf_double = 15;
				do{
				cout << "Shoot - 4 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>20));
			break;
		case 5: 
				buf_double = 7.5;
				do{
				cout << "Shoot - 2 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>10));
			break;
		case 6: 
				buf_double = 7.5;
				do{
				cout << "Shoot - 2 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>10));
			break;
		default:
			break;
		}
		}
		else {
			switch(units){ // w
		case 1: 
				buf_double = 15;
				do{
				cout << "Shoot - 4 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>20));
				break;
		case 2: 
				buf_double = 10;
				do{
				cout << "Shoot - 2 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>10));
			break;
		case 3: 
				buf_double = 12.5;
				do{
				cout << "Shoot - 4 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>20));
			break;
		case 4: 
				buf_double = 12.5;
				do{
				cout << "Shoot - 4 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>20));
			break;
		case 5: 
				buf_double = 6;
				do{
				cout << "Shoot - 2 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>10));
			break;
		case 6: 
				buf_double = 6;
				do{
				cout << "Shoot - 2 times: ";
				cin.clear();
				cin.sync();
				cin >> buf_int;
			} while (cin.fail() || (buf_int<0) || (buf_int>10));
			break;
		default:
			break;
		}
		}
		cout << "Distance: "<< buf_double << "km" <<endl;
		built_biathlonist.set_distance(buf_double);
		built_biathlonist.set_shoot(buf_int);
//////////////////////////////////////////////////////////////////////////////////////////////		
		int buf_min;
		int buf_sec;
		int buf_milisec;
		do{
				cout << "Time - minutes: ";
				cin.clear();
				cin.sync();
				cin >> buf_min;
			} while (cin.fail() || (buf_min<0) || (buf_min>60));
		do{
				cout << "Seconds: ";
				cin.clear();
				cin.sync();
				cin >> buf_sec;
			} while (cin.fail() || (buf_sec<0) || (buf_sec>60));
		do{
				cout << "Miliseconds: ";
				cin.clear();
				cin.sync();
				cin >> buf_milisec;
			} while (cin.fail() || (buf_milisec<0) || (buf_milisec>1000));

		built_biathlonist.set_minutes(buf_min);
		built_biathlonist.set_seconds(buf_sec);
		built_biathlonist.set_milisec(buf_milisec);
/////////////////////////////////////////////////////////////////////////////////////////	

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
	biathlon.real_rating();
}
void del_element(Singleton& biathlon){
	int buf_id;
	cout << "Enter the biathlonist1s ID: ";
	cin >> buf_id;
	biathlon.remove(buf_id);

}

void operations(Singleton& biathlon, int count){
	switch (count){
	case 1:
		help();
		break;
	case 2:
		add_element(biathlon);
		break;
	case 3:
		del_element(biathlon);
		break;
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

		case 13: { //enter // запретить нажатие других клавиш
			system("cls");
			operations(biathlon, count);
			cout << endl << endl << "To back to the main menu press SPACE ";
			int key = _getch();
			switch(key){
			case 32: { //space
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
