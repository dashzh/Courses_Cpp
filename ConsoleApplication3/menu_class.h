#pragma once
#include <windows.h>

class Menu
{
public:
	virtual void draw() = 0;
	virtual void for_prepare() = 0;
	virtual ~Menu() {}
	static int count; // count menu_item

protected:
	static bool exit;
	static int press; //what is the key?
	static int item; // menu_item


	static HANDLE hConsole;
	static COORD position;

	void prepare();
};


class upMenu : public Menu
{
public:
	void draw();
	void for_prepare();
};

class downMenu : public Menu
{
public:
	void draw();
	void for_prepare();
};

class enterMenu : public Menu
{
public:
	void draw();
	void for_prepare();
};

class escMenu : public Menu
{
public:
	void draw();
	void for_prepare();
};


class Factory
{
public:
	virtual Menu* createMenu() = 0;
	virtual ~Factory() {}
};


class upMenuFactory : public Factory
{
public:
	Menu* createMenu() {
		return new upMenu;
	}
};

class downMenuFactory : public Factory
{
public:
	Menu* createMenu() {
		return new downMenu;
	}
};

class enterMenuFactory : public Factory
{
public:
	Menu* createMenu() {
		return new enterMenu;
	}
};

class escMenuFactory : public Factory
{
public:
	Menu* createMenu() {
		return new escMenu;
	}
};