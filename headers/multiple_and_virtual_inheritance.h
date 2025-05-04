#pragma once
#include <random>

class Person
{
protected:
	std::string first_name = "";
	std::string last_name = "";
public:
	Person() {};
	Person(const std::string given_name, const std::string surname);
	virtual const void Show();
};

class Gunslinger : virtual public Person
{
protected:
	double ready_time = 0.0;
	int notches_number = 0;
public:
	Gunslinger(const std::string given_name, const std::string surname, const double readiness_transition_time, const int rifle_grooves) : Person(given_name, surname) { this->ready_time = readiness_transition_time; this->notches_number = rifle_grooves; };
	const void Show();
	const double Draw();
};

class PokerPlayer : virtual public Person
{
protected:
	int random_card_value = 0;
	int func_rand_numb();
public:
	PokerPlayer() {};
	PokerPlayer(const std::string given_name, const std::string surname) : Person(given_name, surname) { this->random_card_value = func_rand_numb(); };
	int Draw();
};

class BadDude : public Gunslinger, public PokerPlayer
{
private:
	int weapon_draw_time = 0;
public:
	BadDude(std::string given_name, std::string surname, const double readiness_transition_time, const int rifle_grooves) : Person(given_name, surname), Gunslinger(given_name, surname, readiness_transition_time, rifle_grooves) {};
	int get_weapon_draw_time(const int&);
	int next_card_drawn();
	const void Show();
};

Person::Person(const std::string given_name, const std::string surname)
{
	this->first_name = given_name;
	this->last_name = surname;
}

const void Person::Show()
{
	std::cout << "Name first: " << this->first_name << "\n";
	std::cout << "Name second: " << this->last_name << "\n";
}

const void Gunslinger::Show()
{
	Person::Show();
	std::cout << "Ready time: " << this->ready_time << "\n";
	std::cout << "Notches number: " << this->notches_number << "\n";
}

const double Gunslinger::Draw()
{
	std::cout << "Return Gunslinger::Draw: " << this->ready_time << "\n";
	return this->ready_time;
}

int PokerPlayer::func_rand_numb()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 52);
	return random_card_value = dis(gen);
}

int PokerPlayer::Draw()
{
	std::cout << "Return PokerPlayer::Draw = " << random_card_value << "\n";
	return random_card_value;
}

int BadDude::get_weapon_draw_time(const int& time)
{
	return weapon_draw_time = time;
}

int BadDude::next_card_drawn()
{
	return this->random_card_value = func_rand_numb();
}

const void BadDude::Show()
{
	std::cout << "BadDude = " << "\n";
	Gunslinger::Show();
	PokerPlayer::Draw();
	std::cout << "Time gun: " << this->weapon_draw_time << "\n";
}