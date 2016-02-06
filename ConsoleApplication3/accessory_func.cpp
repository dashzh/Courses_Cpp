#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include "accessory_func.h"

using namespace std;

int Shoots(int times){
	int buf_int;
	if (times == 4){
		do{
			cout << "Shoot -" << times << " times: ";
			cin.clear();
			cin.sync();
			cin >> buf_int;
		} while (cin.fail() || (buf_int<0) || (buf_int>20));

	}
	else {
		do{
			cout << "Shoot -" << times << " times: ";
			cin.clear();
			cin.sync();
			cin >> buf_int;
		} while (cin.fail() || (buf_int<0) || (buf_int>10));
	}
	return buf_int;
}


int is_integer(string s)
{
	return (count_if(s.begin(), s.end(), isdigit) == s.size()) ? (1) : (0);
} // is this string are integer?



double DistanceAndPoints::get_distance(int num_race, string gender){
	if (gender == "m"){
		return man_distance[num_race - 1];
	}
	if (gender == "w"){
		return wom_distance[num_race - 1];
	}
}
int DistanceAndPoints::balls(int place){
	return arr_balls[place - 1];
}

double DistanceAndPoints::man_distance[6] = { 20, 10, 12.5, 15, 7.5, 7.5 };
double DistanceAndPoints::wom_distance[6] = { 15, 7.5, 10, 12.5, 6, 6 };
int DistanceAndPoints::arr_balls[40] = { 60, 54, 48, 43, 40, 38, 36, 34, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };





