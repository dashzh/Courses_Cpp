#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iterator>

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
	void set_milisec(int milisec){
		this->milisec = milisec;
	}
	int get_milisec()	{
		return this->milisec;
	}
	int get_sum_time(){
		int sum_time;
		sum_time = minutes*60000 + seconds*1000 + milisec;
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
	int milisec;
};

class Singleton
{
public:
	static Singleton& Instance()
	{
		static Singleton s;
		return s;
	}

	int add(item item_biathlonist) {
		this->max_size= 200;
		if (biathlonist.size() < max_size){
			biathlonist.push_back(item_biathlonist);
			return 0;
		}
		else {
			return 1;
		}
	}
	void remove(int d) {
		for (int i = 0; i < biathlonist.size(); i++){
		if (biathlonist[i].get_id() == d){
			swap(biathlonist[i], biathlonist.back());
			biathlonist.pop_back();
			}
		}
	}
		void real_rating(){

		sort(biathlonist.begin(), biathlonist.end(), 
         []( item & a,  item & b) -> bool
			{ 
			return a.get_sum_time() < b.get_sum_time();
			});
			
		cout << "(MEN)The general rating list : " << endl << endl;
		int count = 1;
		for (int i = 0; i < biathlonist.size(); i++){
			if (biathlonist[i].get_gender() == "m"){
			if (count == 1) { cout << "Red shirt lider  "; }
			cout << count << " : " <<endl;
			cout << "Name:" << biathlonist[i].get_name() << endl;
			cout << "Last name: " << biathlonist[i].get_last_name() << endl;
			cout << "ID: " << biathlonist[i].get_id() << endl;
			cout << "Type: " << biathlonist[i].get_unit() << endl;
			cout << "Shoot: " << biathlonist[i].get_shoot() << endl;
			cout << "Gender: " << biathlonist[i].get_gender() << endl;
			cout << "Distance: " << biathlonist[i].get_distance() << " km " << endl;
			cout << "Time: " << biathlonist[i].get_minutes() << ":" << biathlonist[i].get_seconds() << ":" << biathlonist[i].get_milisec() << endl;
			cout << "___________________________________________________________" << endl;
			cout << "___________________________________________________________" << endl;
			count++;}
		}
		cout << "(WOMEN)The general rating list : " << endl << endl;
		count = 1;
		for (int i = 0; i < biathlonist.size(); i++){
			if (biathlonist[i].get_gender() == "w"){
				if (count == 1) { cout << "Red shirt lider  "; }
				cout << count << " : " << endl;
				cout << "Name:" << biathlonist[i].get_name() << endl;
				cout << "Last name: " << biathlonist[i].get_last_name() << endl;
				cout << "ID: " << biathlonist[i].get_id() << endl;
				cout << "Type: " << biathlonist[i].get_unit() << endl;
				cout << "Shoot: " << biathlonist[i].get_shoot() << endl;
				cout << "Gender: " << biathlonist[i].get_gender() << endl;
				cout << "Distance: " << biathlonist[i].get_distance() << " km " << endl;
				cout << "Time: " << biathlonist[i].get_minutes() << ":" << biathlonist[i].get_seconds() << ":" << biathlonist[i].get_milisec() << endl;
				cout << "___________________________________________________________" << endl;
				cout << "___________________________________________________________" << endl;
				count++;
			}
		}
	}
	
private:
	int max_size;
	vector<item> biathlonist;

	Singleton() {  }  
	~Singleton() {  } 

	Singleton(Singleton const&); 
	Singleton& operator= (Singleton const&);  
};



