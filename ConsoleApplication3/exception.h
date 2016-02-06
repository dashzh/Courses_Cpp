#pragma once
#include <iostream>
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

	const char* what() const throw() // redefinition method of basic class
	{
		return "My_exception_happened";
	}

	const string my_what() const throw ()
	{
		return what_arg;
	}
private:
	string what_arg;
};