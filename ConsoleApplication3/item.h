#pragma once
#include "composite.h"

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

	void add_rating(int rating)	{
		this->rating += rating;
	}
	double get_rating(){
		return this->rating;
	}
	void clear_rating(){
		this->rating = 0;
	}
	void set_shoot(int stage_number, int race_number, int shoot){
		TC->getChampionship(stage_number)->getContent()->get_race(race_number)->set_shoot(shoot);
	}
	int get_shoot(int stage_number, int race_number)	{
		return TC->getChampionship(stage_number)->getContent()->get_race(race_number)->get_shoot();
	}
	void set_minutes(int stage_number, int race_number, int minutes){
		TC->getChampionship(stage_number)->getContent()->get_race(race_number)->set_minutes(minutes);
	}
	int get_minutes(int stage_number, int race_number){
		return TC->getChampionship(stage_number)->getContent()->get_race(race_number)->get_minutes();
	}
	void set_seconds(int stage_number, int race_number, int seconds){
		TC->getChampionship(stage_number)->getContent()->get_race(race_number)->set_seconds(seconds);
	}
	int get_seconds(int stage_number, int race_number){
		return TC->getChampionship(stage_number)->getContent()->get_race(race_number)->get_seconds();
	}
	void set_millisec(int stage_number, int race_number, int millisec){
		TC->getChampionship(stage_number)->getContent()->get_race(race_number)->set_millisec(millisec);
	}
	int get_millisec(int stage_number, int race_number){
		return TC->getChampionship(stage_number)->getContent()->get_race(race_number)->get_millisec();
	}
	int get_sum_time(int stage_number, int race_number){
		return TC->getChampionship(stage_number)->getContent()->get_race(race_number)->get_sum_time();
	}
	string get_race_type(int race_number){
		return TC->getChampionship(1)->getContent()->get_race(race_number)->get_race_type();
	}
	void setRace(int stage_number, Individual *race)
	{
		TC->getChampionship(stage_number)->getContent()->insert_race(race);
	}
	void setRace(int stage_number, Sprint *race)
	{
		TC->getChampionship(stage_number)->getContent()->insert_race(race);
	}
	void setRace(int stage_number, Pursuit *race)
	{
		TC->getChampionship(stage_number)->getContent()->insert_race(race);
	}
	void setRace(int stage_number, MassStart *race)
	{
		TC->getChampionship(stage_number)->getContent()->insert_race(race);
	}
	void setRace(int stage_number, Relay *race)
	{
		TC->getChampionship(stage_number)->getContent()->insert_race(race);
	}
	void setRace(int stage_number, MixRelay *race)
	{
		TC->getChampionship(stage_number)->getContent()->insert_race(race);
	}

private:
	string name;
	string last_name;
	int id;
	string gender;
	int rating = 0;

	TotalComposite *TC = new TotalComposite();
};