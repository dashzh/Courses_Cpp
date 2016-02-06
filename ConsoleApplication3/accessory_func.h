#pragma once
#include "singleton.h"

int Shoots(int times);

int is_integer(string s);

class DistanceAndPoints{
private:
	static double man_distance[6];
	static double wom_distance[6];
	static int arr_balls[40];
public:
	double get_distance(int num_race, string gender);
	int balls(int place);
};
