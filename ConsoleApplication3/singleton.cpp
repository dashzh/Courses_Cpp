#include <string>
#include <algorithm>
#include "singleton.h"
#include "accessory_func.h"

using namespace std;

DistanceAndPoints *DP = new DistanceAndPoints;

void Singleton::id_list(){
	for (int i = 0; i < biathlonist.size(); i++)
	{
		cout << "Name: " << biathlonist[i].get_name() << "; Last name: " << biathlonist[i].get_last_name() << "; ID: " << biathlonist[i].get_id() << endl;
	}
}

void Singleton::add_from_file(string name, string last_name, int id, string gender, vector<int> vec)
{
	item item;
	int count = 0;
	item.set_name(name);
	item.set_last_name(last_name);
	item.set_id(id);
	item.set_gender(gender);
	for (int stage_number = 1; stage_number < 10; stage_number++)
	{
		for (int race_number = 1; race_number < 7; race_number++)
		{
			item.set_shoot(stage_number, race_number, vec[count]);
			count++;
			item.set_minutes(stage_number, race_number, vec[count]);
			count++;
			item.set_seconds(stage_number, race_number, vec[count]);
			count++;
			item.set_millisec(stage_number, race_number, vec[count]);
			count++;
		}
		
	}
	Singleton::add(item);
}

void Singleton::write_to_file(){ // write biathlonist vector to the file
	vector<int> races;
	ofstream ate("test.txt");
	if (!ate) { cout << "Your file wasnt open. "; return; }
	for (int i = 0; i < biathlonist.size(); i++){
		races.clear();
		races.resize(216); //= 4(shoot, minutes, seconds, millisec)*9(stages)*6(races) = 6*9*4 = 216
		//Biatlonist's data
		ate << "Name: " << biathlonist[i].get_name() << endl;
		ate << "Last name: " << biathlonist[i].get_last_name() << endl;
		ate << "ID: " << biathlonist[i].get_id() << endl;
		ate << "Gender: " << biathlonist[i].get_gender() << endl;
		//Race_data - order [stage1, race1]; [stage1, race2]...[stage1, race6]; [stage2,race1];...[stage2, race6]; ... [stage9, race6]. Structure - [shoots, min, sec, millisec].
		int count = 0;
		for (int stage_number = 1; stage_number < 10; stage_number++)
		{
			for (int race_number = 1; race_number < 7; race_number++)
			{
				ate << "[" << biathlonist[i].get_shoot(stage_number, race_number) << ",";
				ate << biathlonist[i].get_minutes(stage_number, race_number) << ",";
				ate << biathlonist[i].get_seconds(stage_number, race_number) << ",";
				ate << biathlonist[i].get_millisec(stage_number, race_number) << "];";
			}
		}
		ate << endl << ";" << endl;
	}
	ate.close();
}

int Singleton::read_from_file(){ //read data from file to biathlonist vector
	ifstream in("test.txt");
	if (!in) {
		cout << "Your file wasnt open. " << endl;
	}
	item item_biathlonist;
	int inner_count = 1;
	string name;
	string last_name;
	int id;
	string gender;
	int shoot;
	int minutes;
	int seconds;
	int millisec;
	vector<int> buf_vec; //for races data

	std::string::size_type pos;
	std::string::size_type pos2;

	for (string line; getline(in, line);)
	{
		switch (inner_count){
		case 1:	//Name
			pos = line.find("Name: ");
			if (pos != string::npos)
			{
				std::string mod_line(line.substr(pos + 6)); // 6 = strlen "Name: "
				if (mod_line.length() < 2) { return 0; }
				name = mod_line;
			}
			else { return 0; }
			break;

		case 2:	//Last Name
			pos = line.find("Last name: ");
			if (pos != string::npos)
			{
				std::string mod_line(line.substr(pos + 11)); // 11 = strlen "Last name: "
				if (mod_line.length() < 2) { return 0; }
				last_name = mod_line;
			}
			else { return 0; }
			break;

		case 3:	//ID
			pos = line.find("ID: ");
			if (pos != string::npos)
			{
				std::string mod_line(line.substr(pos + 4)); // 4 = strlen "ID: "
				if (!is_integer(mod_line)) { return 0; }
				id = atoi(mod_line.c_str());
			}
			else { return 0; }
			break;

		case 4:	//Gender
			pos = line.find("Gender: ");
			if (pos != string::npos){
				std::string mod_line(line.substr(pos + 8)); // 8 = strlen "Gender: "
				if ((mod_line != "w") && (mod_line != "m")) { return 0; }
				gender = mod_line;
			}
			else { return 0; }
			break;

		case 5: //Races
			pos = line.find("[");
			if (pos == 0)
			{
				std::string mod_line(line.substr(pos));
				for (int i = 0; i < 54; i++){ //54 = 6*9 races
					int buf;
					if (i == 0)	//First race
					{
						pos2 = line.find(",", pos + 1); // Find first "," from pos+1 (second symbol)
						buf = atoi(line.substr(pos + 1, pos2 - pos - 1).c_str());
						shoot = buf;

						pos = line.find(",", pos2 + 1);
						buf = atoi(line.substr(pos2 + 1, pos - pos2 - 1).c_str());
						minutes = buf;

						pos2 = line.find(",", pos + 1);
						buf = atoi(line.substr(pos + 1, pos2 - pos - 1).c_str());
						seconds = buf;

						pos = line.find("]", pos2 + 1);
						buf = atoi(line.substr(pos2 + 1, pos - pos2 - 1).c_str());
						millisec = buf;
					}
					else //Other races
					{
						pos2 = line.find(",", pos + 1);
						buf = atoi(line.substr(pos + 3, pos2 - pos - 3).c_str());
						shoot = buf;

						pos = line.find(",", pos2 + 1);
						buf = atoi(line.substr(pos2 + 1, pos - pos2 - 1).c_str());
						minutes = buf;

						pos2 = line.find(",", pos + 1);
						buf = atoi(line.substr(pos + 1, pos2 - pos - 1).c_str());
						seconds = buf;

						pos = line.find("]", pos2 + 1);
						buf = atoi(line.substr(pos2 + 1, pos - pos2 - 1).c_str());
						millisec = buf;
					}
					buf_vec.push_back(shoot);
					buf_vec.push_back(minutes);
					buf_vec.push_back(seconds);
					buf_vec.push_back(millisec);
				}
			}
			break;
		case 6: // ";" symbol
			pos = 0;
			std::string mod_line(line.substr(pos));
			if (mod_line == ";"){

				add_from_file(name, last_name, id, gender, buf_vec); 
				buf_vec.clear();
				inner_count = 0;
			}

			break;
		}//switch_end
		inner_count++;
	}//for_end
	return 1;
}//func_end


int Singleton::add(item item_biathlonist) {
	this->max_size = 200;
	if (biathlonist.size() < max_size){
		biathlonist.push_back(item_biathlonist);
		write_to_file();
		return 1;
	}
	else {
		return 0;
	}
}
void Singleton::remove(int id) {
	bool check_id_exist = true;
	for (int i = 0; i < biathlonist.size(); i++){
		if (biathlonist[i].get_id() == id){
			check_id_exist = false;
			swap(biathlonist[i], biathlonist.back());
			biathlonist.pop_back();
		}
	}
	if (check_id_exist){
		cout << "There isn`n biathlonist with such id";
	}
	write_to_file(); //ÐÀÑÊÎÌÌÅÍÒÈÐÎÂÀÒÜ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}


void Singleton::change(int id){
	bool check_id_exist = true;
	string buf_str;
	string buf_str1;
	int buf_race;
	int stage_number, race_number;
	for (int i = 0; i < biathlonist.size(); i++){
		if (biathlonist[i].get_id() == id){
			check_id_exist = false;
			cout << "Name - " << biathlonist[i].get_name() << ": ";
			cin >> buf_str;
			if (buf_str != "0"){
				biathlonist[i].set_name(buf_str);
			}
			cout << "Last name - " << biathlonist[i].get_last_name() << ": ";
				cin >> buf_str;
				if (buf_str != "0"){
					biathlonist[i].set_last_name(buf_str);
				}
				cout << "Gender - " << biathlonist[i].get_gender() << ": ";
				while ((buf_str1 != "m") && (buf_str1 != "w") && (buf_str1 != "0")) {
					cout << "Gender: ";
					cin >> buf_str1;
				}
				if (buf_str1 != "0"){
					biathlonist[i].set_gender(buf_str1);
				}

				cout << "Do you want to change any race?(yes or no)" << endl;
				while ((buf_str != "yes") && (buf_str != "no")) {
					cout << "YES or NO: ";
					cin >> buf_str;
				}

				if (buf_str == "yes"){
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

					cout << "Distance: " << DP->get_distance(race_number, biathlonist[i].get_gender()) << "km" << endl;
				}
				else return;

				cout << "Time - minutes - " << biathlonist[i].get_minutes(stage_number, race_number) << ":";
				cin >> buf_race;
				while (cin.fail() || (buf_race <1) || (buf_race>60)){
					cout << "minutes: ";
					cin.clear();
					cin.sync();
					cin >> buf_race;
				} 
				biathlonist[i].set_minutes(stage_number, race_number, buf_race);
				cout << "Seconds - " << biathlonist[i].get_seconds(stage_number, race_number) << endl;
				cin >> buf_race;
				while (cin.fail() || (buf_race<0) || (buf_race>60)){
					cout << "Seconds: ";
					cin.clear();
					cin.sync();
					cin >> buf_race;
				} 
				biathlonist[i].set_seconds(stage_number, race_number, buf_race);
				cout << "Milliseconds - " << biathlonist[i].get_millisec(stage_number, race_number) << endl;
				cin >> buf_race;
				while (cin.fail() || (buf_race<0) || (buf_race>1000)){
					cout << "Milliseconds: ";
					cin.clear();
					cin.sync();
					cin >> buf_race;
				} 
				biathlonist[i].set_millisec(stage_number, race_number, buf_race);
				cout << "Shoot - " << biathlonist[i].get_shoot(stage_number, race_number) << endl;
				switch (race_number){
				case 1:
					buf_race = Shoots(4);
					break;
				case 2:
					buf_race = Shoots(2);
					break;
				case 3:
					buf_race = Shoots(4);
					break;
				case 4:
					buf_race = Shoots(4);
					break;
				case 5:
					buf_race = Shoots(2);
					break;
				case 6:
					buf_race = Shoots(2);
					break;
				default:
					break;
				}
				biathlonist[i].set_shoot(stage_number, race_number, buf_race);
		}
	
	}
	if (check_id_exist){
		cout << "There isn`n biathlonist with such id";
		return;
	}
	write_to_file();
}

void Singleton::write_real_rating(string gender){	//show biathlonists by main rating
	int count = 1;
	for (int i = 0; i < biathlonist.size(); i++){
		if ((biathlonist[i].get_gender() == gender) && (biathlonist[i].get_rating() > 0)){	//only if was in Individual, Sprint, Pursuit, MassStart races
			cout << count << " : " << endl;
			if (count == 1) { cout << "    Red shirt leader  " << endl; }
			cout << "Name:" << biathlonist[i].get_name() << endl;
			cout << "Last name: " << biathlonist[i].get_last_name() << endl;
			cout << "Rating: " << biathlonist[i].get_rating() << endl;
			cout << "ID: " << biathlonist[i].get_id() << endl;
			cout << "            Races results:           " << endl;
			count++;
		}
		int stage;
		int race;
		
		for (stage = 1; stage < 10; stage++){
			for (race = 1; race < 7; race++){
				if (biathlonist[i].get_sum_time(stage, race) == 0){ continue; }
				if ((biathlonist[i].get_gender() == gender) && (biathlonist[i].get_race_type(race) != "Relay") && (biathlonist[i].get_race_type(race) != "MixRelay")){
					cout << "Stage number: " << stage << "; Race number: " << race << endl;
					cout << "Type: " << biathlonist[i].get_race_type(race) << endl;
					cout << "Shoot: " << biathlonist[i].get_shoot(stage, race) << endl;
					cout << "Gender: " << biathlonist[i].get_gender() << endl;
					cout << "Distance: " << DP->get_distance(race, gender) << " km " << endl;
					cout << "Time: " << biathlonist[i].get_sum_time(stage, race) << endl;
					cout << "_____________________________________________" << endl;
		
				}
			}
		}
		if ((biathlonist[i].get_gender() == gender) && (biathlonist[i].get_rating() > 0)){
			cout << "/////////////////////////////////////////////////" << endl;
		}
		
	}
}

void Singleton::real_rating(){
	for (int i = 0; i < biathlonist.size(); i++)
	{
		biathlonist[i].clear_rating();
	}
	int men_place_count;
	int women_place_count;

	for (int stage_number = 1; stage_number < 10; stage_number++)
	{
		for (int race_number = 1; race_number < 5; race_number++) // *5 -> only Individual, Sprint, MassStart & Pursuit
		{
			sort(biathlonist.begin(), biathlonist.end(),
				[stage_number, race_number](item & a, item & b) -> bool
			{
				return a.get_sum_time(stage_number, race_number) < b.get_sum_time(stage_number, race_number);
			}); 
			men_place_count = 1;
			women_place_count = 1;

			for (int i = 0; i < biathlonist.size(); i++) 
			{
				if (biathlonist[i].get_sum_time(stage_number, race_number) > 0) // Only if he takes part in a race
				{
					if (biathlonist[i].get_gender() == "w")
					{
						biathlonist[i].add_rating(DP->balls(women_place_count));
						women_place_count++;
					}
					else
					{
						biathlonist[i].add_rating(DP->balls(men_place_count));
						men_place_count++;
					}
				}
			}
		}
	}
	//Now sort by main rating
	sort(biathlonist.begin(), biathlonist.end(),
		[](item & a, item & b) -> bool
	{
		return a.get_rating() > b.get_rating();
	});

	cout << "(MEN)The general rating list : " << endl << endl;
	string str1 = "m";
	string str2 = "w";
	write_real_rating(str1);

	cout << "(WOMEN)The general rating list : " << endl << endl;
	write_real_rating(str2);
} 