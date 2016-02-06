#include <windows.h>
#include <conio.h>
#include <time.h>

#include "menu_func.h"
#include "menu_class.h"
#include "singleton.h"


void help() {
	cout << "You can use arrows like UP or DOWN to change the menu item." << endl;
	cout << "To choose the item you should press ENTER and SPACE - to back to the main menu!" << endl;
}


void add_element(Singleton& biathlon)
{
	DistanceAndPoints *DAP = new DistanceAndPoints();
	item built_biathlonist;

	int check;
	string buf;

	int stage_number;
	int race_number;

	int shoots_number; // for shoot

	/////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Name: ";
	cin >> buf;
	built_biathlonist.set_name(buf);
	cout << "Last name: ";

	cin >> buf;
	built_biathlonist.set_last_name(buf);

	srand(time(NULL));
	cout << "ID: ";
	int buf_time = rand() % 10000 + 1;
	cout << buf_time << endl;
	built_biathlonist.set_id(buf_time);
	////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Gender (m or w): ";
	cin >> buf;
	while ((buf != "m") && (buf != "w")) {
		cout << "repeat: ";
		cin >> buf;
	}
	built_biathlonist.set_gender(buf);
	//////////////////////////////////////////////////////////////////////////////////////////////
	do{
		cout << "What is the stage number?(1-9): ";
		cin.clear();
		cin.sync();
		cin >> stage_number;
	} while (cin.fail() || stage_number  < 1 || stage_number  > 9);

	do{
		cout << "Enter the units (1-6)" << endl << "1.Individual, 2.Sprint, 3.Pursuit, 4.MassStart, 5.Relay, 6.MixRelay: ";
		cin.clear();
		cin.sync();
		cin >> race_number;
	} while (cin.fail() || race_number < 1 || race_number > 6);

	cout << "Distance: " << DAP->get_distance(race_number, buf) << "km" << endl;

	switch (race_number){
	case 1:
		shoots_number = Shoots(4);
		break;
	case 2:
		shoots_number = Shoots(2);
		break;
	case 3:
		shoots_number = Shoots(4);
		break;
	case 4:
		shoots_number = Shoots(4);
		break;
	case 5:
		shoots_number = Shoots(2);
		break;
	case 6:
		shoots_number = Shoots(2);
		break;
	default:
		break;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////		
	int buf_min;
	int buf_sec;
	int buf_millisec;
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
		cout << "milliseconds: ";
		cin.clear();
		cin.sync();
		cin >> buf_millisec;
	} while (cin.fail() || (buf_millisec<0) || (buf_millisec>1000));

	Individual *Ind = new Individual();
	Sprint *Spr = new Sprint();
	Pursuit *Pur = new Pursuit();
	MassStart *Mass = new MassStart();
	Relay *Rel = new Relay();
	MixRelay *Mix = new MixRelay();

	switch (race_number){
	case 1:
		Ind->set_shoot(shoots_number);
		Ind->set_minutes(buf_min);
		Ind->set_seconds(buf_sec);
		Ind->set_millisec(buf_millisec);
		built_biathlonist.setRace(stage_number, Ind);
		break;
	case 2:
		Spr->set_shoot(shoots_number);
		Spr->set_minutes(buf_min);
		Spr->set_seconds(buf_sec);
		Spr->set_millisec(buf_millisec);
		built_biathlonist.setRace(stage_number, Spr);
		break;
	case 3:
		Pur->set_shoot(shoots_number);
		Pur->set_minutes(buf_min);
		Pur->set_seconds(buf_sec);
		Pur->set_millisec(buf_millisec);
		built_biathlonist.setRace(stage_number, Pur);
		break;
	case 4:
		Mass->set_shoot(shoots_number);
		Mass->set_minutes(buf_min);
		Mass->set_seconds(buf_sec);
		Mass->set_millisec(buf_millisec);
		built_biathlonist.setRace(stage_number, Mass);
		break;
	case 5:
		Rel->set_shoot(shoots_number);
		Rel->set_minutes(buf_min);
		Rel->set_seconds(buf_sec);
		Rel->set_millisec(buf_millisec);
		built_biathlonist.setRace(stage_number, Rel);
		break;
	case 6:
		Mix->set_shoot(shoots_number);
		Mix->set_minutes(buf_min);
		Mix->set_seconds(buf_sec);
		Mix->set_millisec(buf_millisec);
		built_biathlonist.setRace(stage_number, Mix);
		break;
	default:
		break;
	}

	//////////////////////
	check = biathlon.add(built_biathlonist);
	if (check == 0){
		cout << "You can`t add more biathlonists";
	}
}

void del_element(Singleton& biathlon){
	int buf_id;
	biathlon.id_list();
	cout << endl << "Enter biathlonists ID: ";
	while (cin.fail()){
		cout << "Try again: ";
		cin.clear();
		cin.sync();
		cin >> buf_id;
	}
	biathlon.remove(buf_id);
}

void change(Singleton& biathlon){
	int buf_id;
	biathlon.id_list();
	cout << endl << "This is the list with the data which was added earlier. If you dont want to change item, you need enter 0. ID: " << endl;
	do{
		cin.clear();
		cin.sync();
		cin >> buf_id;
	} while (cin.fail());
	biathlon.change(buf_id);
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
		change(biathlon);
		break;
	case 4:
		del_element(biathlon);
		break;
	case 5:
		biathlon.real_rating();
		break;
	case 6:
		exit(2);
		break;
	}
}


int menu(Singleton& biathlon){
	upMenuFactory* up_factory = new upMenuFactory;
	downMenuFactory* down_factory = new downMenuFactory;
	enterMenuFactory* enter_factory = new enterMenuFactory;
	escMenuFactory* esc_factory = new escMenuFactory;

	Menu* UP = up_factory->createMenu();
	Menu* DOWN = down_factory->createMenu();
	Menu* ENTER = enter_factory->createMenu();
	Menu* ESC = esc_factory->createMenu();

	ENTER->for_prepare(); //initialize menu

	bool exit = false;
	int press; //what is the key?

	while (!exit)
	{
		press = _getch(); //reads from the console 
		switch (press)	{
		case 72: { // up
					 UP->draw();
					 break;
		}
		case 80: {// down
					 DOWN->draw();
					 break;
		}
		case 13: { //enter 
					 system("cls");
					 operations(biathlon, Menu::count);
					 cout << endl << endl << "To back to the main menu press SPACE ";
					 ENTER->draw();
					 ENTER->for_prepare(); // reinitialize menu
					 break;
		}
		case 27: //esc
			ESC->draw();
			exit = true;
			break;
		default:
			break;
		}
	}

	return 0;
}