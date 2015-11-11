#include <string>
#include <iostream>
#include <cstring>
#include <fstream> 
#include <iterator>
#include <exception>
#include <stdexcept>

using namespace std;

class my_exception : public std::exception
{
public:
	my_exception(
		) : exception(
		) {
	}
	
	my_exception(
		std::string str
		) : exception(
		) {
			this->what_arg = str;
	}

    string my_what() 
	{
		return what_arg;
	}
private:
	string what_arg;
};