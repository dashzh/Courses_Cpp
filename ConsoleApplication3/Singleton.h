#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream> 
#include <iterator>
#include <exception>
#include <stdexcept>
#include "Exception.h"

using namespace std;

class item {
public:
	void set_name(string name){
		this->name = name;
	}
	string get_name(){
		return this->name;
	}

	void set_last_name(string last_name){
		this->last_name = last_name;
	}
	string get_last_name(){
		return this->last_name;
	}

	void set_id(int id){
		this->id = id;
	}
	int get_id(){
		return this->id;
	}

	void set_gender(string gender){
		this->gender = gender;
	}
	string get_gender(){
		return this->gender;
	}

	void set_shoot(int shoot){
		this->shoot = shoot;
	}
	int get_shoot()	{
		return this->shoot;
	}

	void set_distance(int distance)	{
		this->distance = distance;
	}
	double get_distance(){
		return this->distance;
	}

	void set_rating(int rating)	{
		this->rating = rating;
	}
	double get_rating(){
		return this->rating;
	}

	void set_minutes(int minutes){
		this->minutes = minutes;
	}
	int get_minutes()	{
		return this->minutes;
	}
	void set_seconds(int seconds){
		this->seconds = seconds;
	}
	int get_seconds()	{
		return this->seconds;
	}
	void set_millisec(int millisec){
		this->millisec = millisec;
	}
	int get_millisec()	{
		return this->millisec;
	}
	int get_sum_time(){
		int sum_time;
		sum_time = minutes*60000 + seconds*1000 + millisec;
		return sum_time;
	}
	void set_unit(int type){
		var = (unit)type;
	}
	string get_unit(){
		switch (var){
		case 1:{
				   return "Individual";
				   break;
		}
		case 2:{
				   return "Sprint";
				   break;
		}
		case 3:{
				   return "Pursuit";
				   break;
		}
		case 4:{
				   return "MassStart";
				   break;
		}
		case 5:{
				   return "Relay";
				   break;
		}
		case 6:{
					return "MixedRelay";
					break;
		}
		}
	}
private:
	string name;
	string last_name;
	int id;
	string gender;
	int shoot;
	double distance;
	enum unit{ Individual, Sprint, Pursuit, MassStart, Relay, MixedRelay };
	unit var;
	int minutes;
	int seconds;
	int millisec;
	int rating;
};
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
class Singleton
{
public:
	static Singleton& Instance()
	{
		static Singleton s;
		return s;
	}
/////////////////////////////////////////////////////////////////////////////////
	int change_distance(int unit, int a1[6]){
		int buf_dist;
		switch(unit){
		case 1: 
				buf_dist = a1[0]; 
			break;
		case 2: 
				buf_dist = a1[1];
			break;
		case 3: 
				buf_dist = a1[2];
				break;
		case 4: 
				buf_dist = a1[3];
			break;
		case 5: 
				buf_dist = a1[4];
			break;
		case 6: 
				buf_dist = a1[5];
			break;
		default:
			break;
		}
		return buf_dist;
	}

	void work_file1(){ // add element at the end of the file
		ofstream ate("test.txt");
		if (!ate) {cout << "Your file wasnt open. "; return;} 
		for (int i = 0; i < biathlonist.size(); i++){
				ate << "Name: " << biathlonist[i].get_name() << endl;
				ate << "Last name: " << biathlonist[i].get_last_name() << endl;
				ate << "ID: " << biathlonist[i].get_id() << endl;
				ate << "Type: " << biathlonist[i].get_unit() << endl;
				ate << "Shoot: " << biathlonist[i].get_shoot() << endl;
				ate << "Gender: " << biathlonist[i].get_gender() << endl;
				ate << "Distance(km): " << biathlonist[i].get_distance() << endl;
				ate << "Time_minutes: " << biathlonist[i].get_minutes() << endl;
				ate << "Time_seconds: " << biathlonist[i].get_seconds() << endl;
				ate <<"Time_milliseconds: " << biathlonist[i].get_millisec() << endl;
				ate << ";" << endl;
		}
		ate.close(); 
	}

	void work_file(){ // rewrite the file
		ofstream ofs("test.txt");
		if (!ofs) {cout << "Your file wasnt open. "; return;} 
		for (int i = 0; i < biathlonist.size(); i++){
				ofs << "Name: " << biathlonist[i].get_name() << endl;
				ofs << "Last name: " << biathlonist[i].get_last_name() << endl;
				ofs << "ID: " << biathlonist[i].get_id() << endl;
				ofs << "Type: " << biathlonist[i].get_unit() << endl;
				ofs << "Shoot: " << biathlonist[i].get_shoot() << endl;
				ofs << "Gender: " << biathlonist[i].get_gender() << endl;
				ofs << "Distance(km): " << biathlonist[i].get_distance() << endl;
				ofs << "Time_minutes: " << biathlonist[i].get_minutes() << endl;
				ofs << "Time_seconds: " << biathlonist[i].get_seconds() << endl;
				ofs << "Time_milliseconds: " << biathlonist[i].get_millisec() << endl;
				ofs << ";" << endl;
		}
		ofs.close(); 

	}
/////////////////////////////////////////////////////////////////////////////////
int work_file2(){ 
		ifstream in("test.txt" );
		if (!in) {
			throw my_exception("Your file wasnt open. ");
		} 
		item item_biathlonist;
		int count_inner = 0;
		string buf = "Individual";
		string buf1 = "Sprint";
		string buf2 = "Pursuit";
		string buf3 = "MassStart";
		string buf4 = "Relay";
		string buf5 = "MixedRelay";
		int buf_int;
		int id_n;
		int shoot_n;
		int distance_n;
		int minutes_n;
		int seconds_n;
		int millisec_n;
		for (string line; getline(in, line);)
		{
			static int count = 0;
			std::string::size_type pos = line.find(":");
			if (pos != string::npos)
			{
				std::string mod_line(line.substr(pos + 2));
				switch (count_inner){
				case 0:
					item_biathlonist.set_name(mod_line);
					break;
				case 1:
					item_biathlonist.set_last_name(mod_line);
					break;
				case 2:{
					id_n = std::stoi(mod_line) ;
					//int id_n = atoi(mod_line.c_str());
					item_biathlonist.set_id(id_n);
					break;
					   }
				case 3:
				{
					if (mod_line == "Individual"){
						buf_int = 1;
						item_biathlonist.set_unit(buf_int);
					}
					else if (mod_line == "Sprint"){
						buf_int = 2;
						item_biathlonist.set_unit(buf_int);
					}
					else if (mod_line == "Pursuit"){
						buf_int = 3;
						item_biathlonist.set_unit(buf_int);
					}
					else if (mod_line == "MassStart"){
						buf_int = 4;
						item_biathlonist.set_unit(buf_int);
					}
					else if (mod_line == "Relay"){
						buf_int = 5;
						item_biathlonist.set_unit(buf_int);
					}
					else if (mod_line == "MixedRelay"){
						buf_int = 6;
						item_biathlonist.set_unit(buf_int);
					}
					else {
						cout << "Wrong TYPE value" << endl;
						return 1;
					}
					break;
				}
				case 4: {
					shoot_n = std::stoi(mod_line);
					if ((buf_int == 1) || (buf_int == 3) || (buf_int == 4)){
						if ((shoot_n > 0) & (shoot_n < 21)){
							item_biathlonist.set_shoot(shoot_n);
							break;
						}
					}
					if((buf_int == 2) || (buf_int == 5) || (buf_int == 6)){
						if ((shoot_n > 0) & (shoot_n < 11)){
							item_biathlonist.set_shoot(shoot_n);
							break;
						}
					}
					else 
						return 1;
					break;
				}
				case 5:
					item_biathlonist.set_gender(mod_line);
					if ((mod_line =="m" ) & (mod_line == "w")){
						cout << "Wrong GENDER value" << endl;
						return 1;
					}
					break;
				case 6:{
					distance_n = std::stoi(mod_line) ;
					item_biathlonist.set_distance(distance_n);
					break;
				}
				case 7:{
					minutes_n = std::stoi(mod_line) ;
					if ((minutes_n < 0) || (minutes_n > 60)){
						cout << "Wrong MINUTES value" << endl;
						return 1;
					}
					item_biathlonist.set_minutes(minutes_n);
					break;
				}
				case 8:{
					seconds_n = std::stoi(mod_line) ;
					if ((seconds_n < 0) || (seconds_n > 60)){
						cout << "Wrong SECONDS value" << endl;
						return 1;
					}
					item_biathlonist.set_seconds(seconds_n);
					break;
				}
				case 9:{
					millisec_n = std::stoi(mod_line) ;
					if ((millisec_n < 0) || (millisec_n > 100)){
						cout << "Wrong MILLISECONDS value" << endl;
						return 1;
					}
					item_biathlonist.set_millisec(millisec_n);
					break;
					}
				default:
					break;
				}
				count_inner++;
			}
			pos = line.find(";");
			if (pos != string::npos)
			{
				if (biathlonist.size() < 200){
					biathlonist.push_back(item_biathlonist);
					count_inner=0;
				}
				else{
					cout << "You cant add more biathlonist" << endl;
					return 1;
				}
				count++;
			}
		}
		in.close(); 
		return 0;
	}
/////////////////////////////////////////////////////////////////////////////////
	int add(item item_biathlonist, int bif_id) {
		this->max_size = 200;
		if (biathlonist.size() < max_size){
			biathlonist.push_back(item_biathlonist);
			work_file1();
			return 0;
		}
		else {
			return 1;
		}
	}
/////////////////////////////////////////////////////////////////////////////////
	void write_real_rating(string str){
			int count = 1;
			for (int i = 0; i < biathlonist.size(); i++){
			if ((biathlonist[i].get_gender() == str) & (biathlonist[i].get_unit() != "Relay") & (biathlonist[i].get_unit() != "MixRelay")){
			if (count == 1) { cout << "    Red shirt lider  " << endl; }
			cout << count << " : " <<endl;
			cout << "Name:" << biathlonist[i].get_name() << endl;
			cout << "Last name: " << biathlonist[i].get_last_name() << endl;
			cout << "ID: " << biathlonist[i].get_id() << endl;
			cout << "Type: " << biathlonist[i].get_unit() << endl;
			cout << "Shoot: " << biathlonist[i].get_shoot() << endl;
			cout << "Gender: " << biathlonist[i].get_gender() << endl;
			cout << "Distance: " << biathlonist[i].get_distance() << " km " << endl;
			cout << "Time: " << biathlonist[i].get_minutes() << ":" << biathlonist[i].get_seconds() << ":" << biathlonist[i].get_millisec() << endl;
			cout << "___________________________________________________________" << endl;
			count++;
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////
	void remove(int d) {
		bool check_id_exist = true;
		for (int i = 0; i < biathlonist.size(); i++){
		if (biathlonist[i].get_id() == d){
			check_id_exist = false;
			swap(biathlonist[i], biathlonist.back());
			biathlonist.pop_back();
			}
		}
		if (check_id_exist){
			cout << "There isn`n biathlonist with such id";
		}
		work_file();
	}
/////////////////////////////////////////////////////////////////////////////////		
	void real_rating(){
		sort(biathlonist.begin(), biathlonist.end(), 
         []( item & a,  item & b) -> bool
			{ 
			return a.get_sum_time() < b.get_sum_time();
			});
			
		cout << "(MEN)The general rating list : " << endl << endl;
		string str1 = "m";
		string str2 = "w";
		write_real_rating(str1);

		cout << "(WOMEN)The general rating list : " << endl << endl;
		write_real_rating(str2);
		}
/////////////////////////////////////////////////////////////////////////////////
		void changes_b(int id_change){
			bool check_id_exist = true;
			cout << "This is the list with the data which was added earlier. if you donn`t want to change item, you need enter 0. Ghange it: " << endl;
			for (int i = 0 ; i< biathlonist.size(); i++){
				if (biathlonist[i].get_id() == id_change){
				check_id_exist = false;
				cout << "ID: " << biathlonist[i].get_id() << endl;
//_NAME_____LAST_NAME
				cout << "Name: " << biathlonist[i].get_name() << ": ";
					string buf_str;
					cin >> buf_str;
					if (buf_str == "0"){
						biathlonist[i].set_name(biathlonist[i].get_name());
					}
					else{biathlonist[i].set_name(buf_str);
					}
				cout << "Last name: " << biathlonist[i].get_last_name()<< ": ";
					string buf_str1;
					cin >> buf_str1;
					if (buf_str1 == "0"){
						biathlonist[i].set_last_name(biathlonist[i].get_last_name());
					}
					else{biathlonist[i].set_last_name(buf_str1);
					}
//________TYPE
				cout << "Type: " << biathlonist[i].get_unit() << ": ";
					cout << "Enter the units (1..6)" << endl <<"1.Individual, 2.Sprint, 3.Pursuit, 4.MassStart, 5.Relay, 6.MixRelay: ";
					int units;
					string units1;
					cin >> units;
					if (units == 0){
						units1 = biathlonist[i].get_unit();
						if(units1 == "Individual"){units = 1; biathlonist[i].set_unit(units);}
						if(units1 == "Sprint"){units = 2; biathlonist[i].set_unit(units);}
						if(units1 == "Pursuit"){units = 3; biathlonist[i].set_unit(units);}
						if(units1 == "MassStart"){units = 4; biathlonist[i].set_unit(units);}
						if(units1 == "Relay"){units = 5; biathlonist[i].set_unit(units);}
						if(units1 == "MixRelay"){units = 6; biathlonist[i].set_unit(units);}
					}
					else{
						while (cin.fail() || units < 0 || units > 7){
						cout << "Enter (1..6): ";
						cin.clear();
						cin.sync();
						cin >> units;
						} 
					biathlonist[i].set_unit(units);
					}
//________SHOOT
				cout << "Shoot: " << biathlonist[i].get_shoot() << ": ";
					int buf_shoot;
					if ((units == 1) || (units == 3) || (units == 4)){
						do{
							cout << "Shoot - 4 times: ";
							cin.clear();
							cin.sync();
							cin >> buf_shoot;
						} while (cin.fail() || (buf_shoot<-1) || (buf_shoot>21));
						if (buf_shoot == 0){
						biathlonist[i].set_shoot(biathlonist[i].get_shoot());
						}
						else{biathlonist[i].set_shoot(buf_shoot);}
					}
					if((units == 2) || (units == 5) || (units == 6)){
						do{
							cout << "Shoot - 2 times: ";
							cin.clear();
							cin.sync();
							cin >> buf_shoot;
						} while (cin.fail() || (buf_shoot<-1) || (buf_shoot>11));
						if (buf_shoot == 0){
						biathlonist[i].set_shoot(biathlonist[i].get_shoot());
						}
						else{biathlonist[i].set_shoot(buf_shoot);}
					}
					
//________GENDER
				cout << "Gender " << biathlonist[i].get_gender() << ": ";
					string buf_gender;
					while ((buf_gender != "m") & (buf_gender != "w") & (buf_gender != "0")) {
						cout << "Gender: ";
						cin >> buf_gender;
					}
					if (buf_gender == "0"){
						biathlonist[i].set_gender(biathlonist[i].get_gender());
					}
					else {biathlonist[i].set_gender(buf_gender);}
//________DISTANCE				
					//cout << "Distance: " << biathlonist[i].get_distance() << " km " << " : ";
					int arr_dist_m[6]={20, 7.5, 10, 15, 7.5, 7.5};
					int arr_dist_w[6]={15, 10, 12.5, 12.5, 6, 6};
					if (buf_gender == "m"){
						int buf_distance =	change_distance(units, arr_dist_m);
						biathlonist[i].set_distance(buf_distance);
					}
					if (buf_gender == "w"){
						int buf_distance =	change_distance(units, arr_dist_w);	
						biathlonist[i].set_distance(buf_distance);
					}
				cout << "Distance: " << biathlonist[i].get_distance() << " km " << endl;
//________TIME	
				cout << "Time: " << biathlonist[i].get_minutes() << ":" << biathlonist[i].get_seconds() << ":" << biathlonist[i].get_millisec() << endl;
					int buf_min;
					int buf_sec;
					int buf_millisec;
					do{
						cout << "Enter the minutes: ";	
						cin.clear();
						cin.sync();
						cin >> buf_min;
						}while (cin.fail() || (buf_min<-1) || (buf_min>60)); 
					if (buf_min == 0){
						biathlonist[i].set_minutes(biathlonist[i].get_minutes());
					}
					else{biathlonist[i].set_minutes(buf_min);}
					do{
						cout << "Enter the seconds: ";	
						cin.clear();
						cin.sync();
						cin >> buf_sec;
						}while (cin.fail() || (buf_sec<-1) || (buf_sec>60)); 
					if (buf_sec == 0){
						biathlonist[i].set_minutes(biathlonist[i].get_seconds());
					}
					else{biathlonist[i].set_seconds(buf_sec);}
					do{
						cout << "Enter the milliseconds: ";	
						cin.clear();
						cin.sync();
						cin >> buf_millisec;
						}while (cin.fail() || (buf_millisec<-1) || (buf_millisec>1000)); 
					if (buf_millisec == 0){
						biathlonist[i].set_millisec(biathlonist[i].get_millisec());
					}
					else{biathlonist[i].set_millisec(buf_millisec);}
			}
			}
			if (check_id_exist){
				cout << "There isn`n biathlonist with such id";
			}
			work_file();
		}
	
private:
	int max_size;
	vector<item> biathlonist;

	Singleton() {  }  
	~Singleton() {  } 

	Singleton(Singleton const&); 
	Singleton& operator= (Singleton const&);  
};