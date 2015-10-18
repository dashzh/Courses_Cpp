//Список десятичных индексов для функциональных клавиш:
//13 - enter
//27 - escape
//8 - backspace
//32 - space 
//
//72 - Стрелка вверх - 22472
//80 - Стрелка вниз - 22480
//75 - Стрелка влево - 22475
//77 - Стрелка вправо - 22477

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;


enum unit{Individual,Sprint,Pursuit};

struct biathlonist
{
	int id;
	string name;
	int kol_vo_race;
	double distance;
//	enum unit{km,ml,oz};
	unit unit;
};

 
int help() {
	cout << "You entered the number of biathlonists and now you cant change it.";
	cout << "You can use   arrows like UP or DOWN to  change the menu item.";
	cout << "To choose the item you should press ENTER and SPACE to back to the main menu! ";
	return 1;
	}
int add(biathlonist *Biathlon, int num) {
//	struct biathlonist biathlonist_;
////	getline(cin, biathlonist_.name);
//	cout << "Name: ";
//	cin >> biathlonist_.name;
////	cin.getline(biathlonist_.name, 255);
//	srand(time(NULL));
//	biathlonist_.id = rand() %1000 * rand()%10000;
//	cout << "ID: " << biathlonist_.id << endl;
//	cout << "kol_vo_race: ";
//	cin >> biathlonist_.kol_vo_race;
//	while (biathlonist_.kol_vo_race < 0 ){
//		cout << "Try again(>0): ";
//		cin >> biathlonist_.kol_vo_race;
//	}
//	cout << "Distance: ";
//	cin >> biathlonist_.distance;
//	while (biathlonist_.distance < 0 ){
//		cout << "Try again(>0): ";
//		cin >> biathlonist_.distance;
//	}
//
//	Biathlon[num] = biathlonist_;
//	return 1
//	int n = num;
	for (int i = 0; i < num;){
		if (Biathlon[i].id ==0){
		cout << i <<"_______________________________________________________"<< endl;
		cout << "Name: " << Biathlon[i].name;
		//getline(cin, Biathlon[i].name);
		cin >> Biathlon[i].name;
		srand(time(NULL));
		Biathlon[i].id  = rand() %1000 * rand()%10000;
		cout << "ID: " << Biathlon[i].id << endl;
		cout << "Kol_vo of the races: ";
		cin >> Biathlon[i].kol_vo_race;
		while (Biathlon[i].kol_vo_race <= 0 ){
		cout << "Try again(>0): ";
		cin >> Biathlon[i].kol_vo_race;
	}
		cout << "Distance: ";
		cin >> Biathlon[i].distance;
		while (Biathlon[i].distance <= 0 ){
		cout << "Try again(>0): ";
		cin >> Biathlon[i].distance;
	}
		int units;
		do{
			cout << "Enter the units (1-3) 1.Individual, 2.Sprint, 3.Pursuit: ";
			cin >> units;

		} while (units < 1 || units > 3);
		Biathlon[1].unit = (unit)units;
		cin.get();
		cout <<"___________________________________________________________"<< endl;
		i++;
		//int press;
		//cout << "Do you want to continue the entering of the biathlonists? enter BACKSPACE";
		//press=_getch();
		//switch (press){
		//case 8: {
		//menu(Biathlon, num);
		//		 break;}
		//
		//default:
		//	break;
		//}
		}
		else {
		i++;
		
		}
	}
//	i++;
		return 1;

}
int del(biathlonist *Biathlon, int num) {
	cout << "What biathlonist do you want to delete? Enter the number. " << endl;
	cout << "This number should be more than 0 and less than " << (num-1) << " : ";
	int dele;
	cin >> dele;
	while ((dele < 0) && (dele > num)){
		cout << "try again"<< endl;
		int dele;
		cin >> dele;
	}
		Biathlon[dele].name= " ";
		Biathlon[dele].id  = 0;
		Biathlon[dele].kol_vo_race = 0;
		Biathlon[dele].distance = 0; 
		/*for (dele; dele<num;dele++){
		Biathlon[dele].name=Biathlon[dele+1].name;
		Biathlon[dele].id  = Biathlon[dele+1].id;
		Biathlon[dele].kol_vo_race = Biathlon[dele+1].kol_vo_race;
		Biathlon[dele].distance = Biathlon[dele+1].distance; 
		}*/

	return 1;
}
int list(biathlonist *Biathlon, int num) {
	for (int i = 0; i < num;){
		if (Biathlon[i].id != 0){
		cout << i <<"_______________________________________________________"<< endl;
		cout << "Name: " << Biathlon[i].name << endl;
		cout << "ID: " << Biathlon[i].id << endl;
		cout << "Kol_vo " << Biathlon[i].kol_vo_race << endl;
		cout << "Distance: " << Biathlon[i].distance << endl;
		cout << "Units: " << Biathlon[i].unit << endl;
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
	cout << "  1. Help" << endl << "  2. Add" << endl << "  3. Delete" << endl << "  4. All list" << endl << "  5. Exit" << endl; 
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
			operations(count, Biathlon, num);
			cout << endl << endl << "To back to the main menu press SPACE ";
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
	int num = 4;
	biathlonist *Biathlon = new biathlonist[num];
	//Biathlon[num].~biathlonist();
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