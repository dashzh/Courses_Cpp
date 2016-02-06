#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream> 
#include <exception>
#include <stdexcept>

#include "accessory_func.h"
#include "menu_class.h"
#include "menu_func.h"
#include "composite.h"
#include "item.h"
#include "singleton.h"

using namespace std;


int main(){	Singleton& biathlon = Singleton::Instance();

	biathlon.read_from_file();

	menu(biathlon);

	return 0;
}