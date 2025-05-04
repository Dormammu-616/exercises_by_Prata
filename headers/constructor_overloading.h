#pragma once
#pragma warning(disable : 4996)
#include <cstring>

class Cow
{
private:
	char name[20]{};
	char* hobby = new char[10];
	double weight = 0.0;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	Cow& operator=(const Cow& ctr1);
	void const ShowCow();
	~Cow();
};

Cow::Cow()
{
	char name2[] = { "Lola" };
	int i = 0;
	while (name2[i] != '\0')
	{
		name[i] = name2[i];
		i++;
	}

	std::string hobby2 = "oats";
	hobby = new char[10];
	std::strcpy(hobby, hobby2.c_str());

	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	int i = 0;
	while (nm[i] != '\0')
	{
		name[i] = nm[i];
		i++;
	}

	std::strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow& ctr1)
{
	int i = 0;
	while (ctr1.name[i] != '\0')
	{
		this->name[i] = ctr1.name[i];
		i++;
	}

	delete[] this->hobby;
	this->hobby = new char[10];
	std::strcpy(this->hobby, ctr1.hobby);

	this->weight = ctr1.weight;
}

Cow::~Cow()
{
	hobby = nullptr;
	delete[] hobby;
	std::cout << "Destructor called successfully!\n";
}

Cow& Cow::operator=(const Cow& c)
{
	delete[] hobby;

	int i = 0;
	while (c.name[i] != '\0')
	{
		this->name[i] = c.name[i];
		i++;
	}

	this->hobby = new char[10];
	std::strcpy(this->hobby, c.hobby);

	this->weight = c.weight;

	return *this;
}

void const Cow::ShowCow()
{
	int i = 0;

	std::cout << "Name cow: ";
	while (this->name[i] != '\0')
	{
		std::cout << name[i];
		i++;
	}

	std::cout << "\nHobby cow: ";
	i = 0;
	while (hobby[i] != '\0')
	{
		std::cout << hobby[i];
		i++;
	}

	std::cout << "\nWeight cow: " << this->weight << "\n\n";
}