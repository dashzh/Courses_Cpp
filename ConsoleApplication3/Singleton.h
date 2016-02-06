#pragma once
#include <vector>

#include "item.h"
#include "accessory_func.h"


using namespace std;


class Singleton
{
public:
	static Singleton& Instance()
	{
		static Singleton s;
		return s;
	}
	int add(item item_biathlonist); // add item
	void remove(int d);	// remove item by ID
	void change(int id);

	int read_from_file();	//read data from file to singleton biathlonist
	void Singleton::write_to_file();

	void add_from_file(string name, string last_name, int id, string gender, vector<int> vec);	// add one biathlonist from file
	
	void real_rating();	//Show biathlonists by main rating

	void id_list();

private:
	int max_size;
	vector<item> biathlonist;
	void write_real_rating(string gender);	//Accessory func to real_rating();

	Singleton() {  }
	~Singleton() {  }

	Singleton(Singleton const&);
	Singleton& operator= (Singleton const&);
};