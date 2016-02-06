#pragma once
#include <string>
#include <iostream>
#include <cstring>
#include <fstream> 
#include <assert.h>
#include <vector>
#include <windows.h>

using namespace std;

class Races{
public:
	virtual string get_race_type() = 0;

	void set_shoot(int shoot){
		this->shoot = shoot;
	}
	int get_shoot()	{
		return this->shoot;
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
		sum_time = minutes * 60000 + seconds * 1000 + millisec;
		return sum_time;
	}
protected:
	int shoot = 0;
	int minutes = 0;
	int seconds = 0;
	int millisec = 0;
};

class Individual : public Races{
public:
	string get_race_type()	{
		return this->race_type;
	}
private:
	string race_type = "Individual";
};

class Sprint : public Races{
public:
	string get_race_type()	{
		return this->race_type;
	}
private:
	string race_type = "Sprint";
};

class Pursuit : public Races{
public:
	string get_race_type()	{
		return this->race_type;
	}
private:
	string race_type = "Pursuit";
};

class MassStart : public Races{
public:
	string get_race_type()	{
		return this->race_type;
	}
private:
	string race_type = "MassStart";
};

class Relay : public Races{
public:
	string get_race_type()	{
		return this->race_type;
	}
private:
	string race_type = "Relay";
};

class MixRelay : public Races{
public:
	string get_race_type()	{
		return this->race_type;
	}
private:
	string race_type = "MixRelay";
};

class Race_pack{
public:
	Race_pack() //Create with Empty Races
	{
		V.push_back(new Individual);
		V.push_back(new Sprint);
		V.push_back(new Pursuit);
		V.push_back(new MassStart);
		V.push_back(new Relay);
		V.push_back(new MixRelay);
	}
	void insert_race(Individual *race)
	{
		V[0] = race;
	}
	void insert_race(Sprint *race)
	{
		V[1] = race;
	}
	void insert_race(Pursuit *race)
	{
		V[2] = race;
	}
	void insert_race(MassStart *race)
	{
		V[3] = race;
	}
	void insert_race(Relay *race)
	{
		V[4] = race;
	}
	void insert_race(MixRelay *race)
	{
		V[5] = race;
	}
	Races* get_race(int race_number) //1.Individual, 2.Sprint, 3.Pursuit, 4.MassStart, 5.Relay, 6.MixRelay
	{
		if ((race_number > 0) && (race_number < 7))
		{
			return V[race_number - 1];
		}
		else
		{
			cout << "CRASH!!";
			Sleep(2000);
			exit(3);
			//S->set_shoot(-1);
			//return S; // Если всё плохо вернуть класс Sprint со значением выстрелов -1
		}
	}
	~Race_pack() {
		V.clear();
	}
private:
	vector<Races*> V;
	Sprint *S = new Sprint();
};



class Championship{
public:
	virtual Race_pack* getContent() = 0;
	virtual void addStage(Championship* p) {
		assert(false);
	}
	virtual ~Championship() {}
};

class stage1 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage2 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage3 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage4 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage5 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage6 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage7 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage8 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};

class stage9 :public Championship{
public:
	Race_pack* getContent(){
		return R;
	}
private:
	Race_pack *R = new Race_pack();
};


class TotalComposite : public Championship{
public:
	TotalComposite()
	{
		V.push_back(new stage1());
		V.push_back(new stage2());
		V.push_back(new stage3());
		V.push_back(new stage4());
		V.push_back(new stage5());
		V.push_back(new stage6());
		V.push_back(new stage7());
		V.push_back(new stage8());
		V.push_back(new stage9());
	}

	Race_pack* getContent(){
		return V[0]->getContent();
	}

	Championship* getChampionship(int stage){
		if ((stage > 0) && (stage < 10))
		{
			return V[stage - 1];
		}
		else
		{
			cout << "CRASH!!";
			Sleep(2000);
			exit(3);
		}
	}
private:
	vector<Championship*> V;
};