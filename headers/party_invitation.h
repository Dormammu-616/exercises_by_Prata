#pragma once
#include <vector>
#include <string>
#include <algorithm>

class myFriendsList
{
private:
	std::vector <std::string> matt_friends_list = {};
	std::vector <std::string> pet_friends_list = {};
	std::vector <std::string> general_friends_list = {};
	int add_name_in_list(std::vector <std::string>& friend_list);
	void show_name(std::vector <std::string>& friend_list);
	void union_name();
public:
	void add_name();
};

int myFriendsList::add_name_in_list(std::vector <std::string>& friend_list)
{
	std::string name = "";
	while (true)
	{
		std::cout << "Enter name (for exit - done): ";
		std::getline(std::cin, name);

		if (name == "done")
		{
			std::sort(friend_list.begin(), friend_list.end());
			return false;
		}
		else
		{
			friend_list.push_back(name);
		}
	}
	return 0;
}

void myFriendsList::show_name(std::vector <std::string>& friend_list)
{
	std::cout << "List of names contains: ";
	for (auto iter = friend_list.begin(); iter != friend_list.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << "\n";
}

void myFriendsList::union_name()
{
	general_friends_list = { matt_friends_list };
	general_friends_list.insert(general_friends_list.end(), pet_friends_list.begin(), pet_friends_list.end());
	std::sort(general_friends_list.begin(), general_friends_list.end());
	general_friends_list.erase(std::unique(general_friends_list.begin(), general_friends_list.end()), general_friends_list.end());
}

void myFriendsList::add_name()
{
	std::cout << "Enter name freind Matt:\n";
	add_name_in_list(matt_friends_list);
	std::cout << "\nEnter name freind Pet:\n";
	add_name_in_list(pet_friends_list);

	std::cout << "\nMatt's friends list contains the names: ";
	show_name(matt_friends_list);
	std::cout << "Pet's friends list contains the names:: ";
	show_name(pet_friends_list);

	union_name();
	std::cout << "The general friends list contains: ";
	show_name(general_friends_list);
}