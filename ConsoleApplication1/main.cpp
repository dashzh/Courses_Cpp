//Function keys - decimal indices 
//13 - enter
//27 - escape
//8 - backspace
//32 - space 
//
//72 - UP - 22472
//80 - DOWN - 22480
//75 - LEFT - 22475
//77 - RIGHT - 22477

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum unit{Individual, Sprint, Pursuit};

struct biathlonist
{
	int id;
	string name;
	int kol_vo_race;
	double distance;
	unit unit;
};
 
int help() {
	cout << "You entered the number of the biathlonists and now you cant change it.";
	cout << "You can use   arrows like UP or DOWN to  change the menu item.";
	cout << "To choose the item you should press ENTER and SPACE to back to the main menu! ";
	return 1;
	}
int add(biathlonist *Biathlon, int num) {
	int m;
	for (int i = 0; i < num;i++){
		if(Biathlon[i].id == 0) {
			m = i;
			break;
		}
	}
	if (m < num){
		if (Biathlon[m].id ==0){
		cout << m <<"__________________________________________________________"<< endl;
		cout << "Name: " << Biathlon[m].name;
		//getline(cin, Biathlon[i].name);
		cin >> Biathlon[m].name;
		srand(time(NULL));
		Biathlon[m].id  = rand() %1000 * rand()%10000;
		cout << "ID: " << Biathlon[m].id << endl;
			do{
			cout << "The number of the race(More then NULL): ";
			cin.clear();
			cin.sync();
			cin >> Biathlon[m].kol_vo_race;
		} while (cin.fail() || ( Biathlon[m].kol_vo_race<0));
		do{
			cout << "The number of the race(More then NULL): ";
			cin.clear();
			cin.sync();
			cin >> Biathlon[m].distance;
			} while (cin.fail() || ( Biathlon[m].distance<0));
		int units;
		do{
			cout << "Enter the units (1-3) 1.Individual, 2.Sprint, 3.Pursuit: ";
			cin >> units;

		} while (units < 1 || units > 3);
		Biathlon[m].unit = (unit)units;
		cout <<"___________________________________________________________"<< endl;
				}
	}
	else {
		cout << "You cant add new biathlonist. The list is over" << endl;
	}
		return 1;
}

int del(biathlonist *Biathlon, int num) {
	int dele;
	do {
		cout << "What biathlonist do you want to delete? Enter the number. " << endl;
		cout << "This number should be more than 0 and less than " << (num-1) << " : ";
		cin >> dele;
		} while ((dele < 0) || (dele > num));
		
		Biathlon[dele].name= " ";
		Biathlon[dele].id  = 0;
		Biathlon[dele].kol_vo_race = 0;
		Biathlon[dele].distance = 0; 
	return 1;
}
int list(biathlonist *Biathlon, int num) {
	for (int i = 0; i < num;){
		if (Biathlon[i].id != 0){
		cout << i <<"__________________________________________________________"<< endl;
		cout << "Name: " << Biathlon[i].name << endl;
		cout << "ID: " << Biathlon[i].id << endl;
		cout << "The number of the race: " << Biathlon[i].kol_vo_race << endl;
		cout << "Distance: " << Biathlon[i].distance << endl;
		//cout << "Units: " << Biathlon[i].unit << endl;
		cout << "The type of the race: " ;
		switch (Biathlon[i].unit){
		case 1:{
				   cout << "Individual"<< endl;
				   break;
		}
		case 2:{
				   cout <<" Sprint"<< endl;
				   break;
		}
		case 3:{
				   cout << "Pursuit"<< endl;
				   break;
		}
		}
		cout <<"___________________________________________________________"<< endl;
		i++;
		}
		else {
			i++;
		}
		}
	return 1;
}
int exit() {
		exit(2);
}

void operations(int count, biathlonist *Biathlon, int num){
	switch (count){
	case 1:
		help();
		break;
	case 2:
		add(Biathlon, num);
		break;
	case 3:
		del(Biathlon, num);
		break;
	case 4:
		list(Biathlon, num);
		break;
	case 5:
		exit();
		break;
	}
}
int menu(biathlonist *Biathlon, int num){
	
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
		case 13: { //enter
			system("cls");
			operations(count, Biathlon, num);
			cout << endl << endl << "Press SPACE to back to the main menu  ";
			int key = _getch();
			switch(key){
			case 32: {
				system("cls");
				menu(Biathlon, num);
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
	int num;
		do{
			cout << "Enter the  number of the biathlonist. ";
			cout << "More then NULL: ";
			cin.clear();
			cin.sync();
			cin >> num;
			//if (cin.fail()) cout << "error" << endl;
		} while (cin.fail() || (num<0));
		
		system("cls");
	biathlonist *Biathlon = new biathlonist[num];
	for (int i = 0; i < num;i++){
		Biathlon[i].name= " ";
		Biathlon[i].id  = 0;
		Biathlon[i].kol_vo_race = 0;
		Biathlon[i].distance = 0; 
		}
	menu(Biathlon, num);
	
	return 0;
	delete []Biathlon;
}