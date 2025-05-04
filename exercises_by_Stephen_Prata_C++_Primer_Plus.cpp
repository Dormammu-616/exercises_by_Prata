#pragma once
#include <iostream>
#include <array>
#include <fstream>
#include <simple_function_overloading.h>
#include <overload_for_numbers_type_complexxx.h>
#include <constructor_overloading.h>
#include <class_inheritance.h>
#include <multiple_and_virtual_inheritance.h>
#include <palindrome_test.h>
#include <party_invitation.h>

class Exercises
{
private:
	static constexpr size_t NUM_OF_EXERCISES = 7;
	const std::string TASK_DESCRIPTION_FILE_PATH = "files_for_display_on_screen\\task_description.txt";
	const std::string EXPECTED_REZULT_FILE_PATH = "files_for_display_on_screen\\expected_result.txt";
	void fill_description(const std::string&, std::array<std::string, NUM_OF_EXERCISES>&);
	void exercise_simple_function_overloading();
	void exercise_overload_for_numbers_type_complexxx();
	void exercise_constructor_overloading();
	void exercise_class_inheritance();
	void exercise_multiple_and_virtual_inheritance();
	void exercise_palindrome_test();
	void exercise_party_invitation();
public:
	void show_rezult_exercises();
};

void Exercises::fill_description(const std::string& PATH_FILE, std::array<std::string, NUM_OF_EXERCISES>& array_for_fill)
{
	std::fstream read_file (PATH_FILE, std::ios::in);

	if (read_file.is_open())
	{
		for (int i = 0; i < NUM_OF_EXERCISES; ++i)
		{
			if (std::getline(read_file, array_for_fill.at(i))) {}
			else { break; };
		}

		read_file.close();
	}
}

void Exercises::exercise_simple_function_overloading()
{
	Time first_time(7, 40);
	Time second_time(2, 50);

	std::cout << "First time\t\t= " << first_time;
	std::cout << "Second time\t\t= " << second_time;
	std::cout << "Addition operation\t= " << (first_time + second_time);
	std::cout << "Subtraction operation\t= " << (first_time - second_time) << "\n";
}

void Exercises::exercise_overload_for_numbers_type_complexxx()
{
	complexx a(3.0, 4.0);
	complexx b(9.0, 2.0);
	std::cout << "complexx a = " << a;
	std::cout << "complexx b = " << b << "\n";

	std::cout << "a + b = " << a + b;
	std::cout << "a - b = " << a - b;
}

void Exercises::exercise_constructor_overloading()
{
	Cow Lola;
	Cow Milo("Milo", "seno", 5.8);
	Cow copy_Milo(Milo);

	std::cout << "Instance without parameters specified:\n";
	Lola.ShowCow();
	
	std::cout << "Instance with parameters specified:\n";
	Milo.ShowCow();
	
	std::cout << "Instance receiving another instance:\n";
	copy_Milo.ShowCow();

	std::cout << "The instance before using the operator '=':\n";
	Lola.ShowCow();
	Lola = Milo;
	std::cout << "The instance after using the operator '=':\n";
	Lola.ShowCow();

	std::cout << "Explicitly calling a destructor on an instance without parameters specified: ";
	Lola.~Cow();
	std::cout << "Explicitly calling a destructor on an instance with parameters specified: ";
	Milo.~Cow();
	std::cout << "Explicitly calling a destructor on an instance receiving another instance: ";
	copy_Milo.~Cow();
}

void Exercises::exercise_class_inheritance()
{
	Base_Cd Beatles("Beatles", "Parlophone", 13, 39.36);
	Child_Classic SOAD = Child_Classic("SOAD", "Steal This Album!", "Boom!", 16, 43.22);
	Base_Cd* pBase_cd = &Beatles;

	std::cout << "Using object directly through a method 'Report' for class 'Base_Cd':\n";
	Beatles.Report();
	std::cout << "Using object directly through a method 'Report' for class 'Child_Classic':\n";
	SOAD.Report();

	std::cout << "Using a method 'Report' for pointer to 'Base_Cd':\n";
	pBase_cd->Report();
	std::cout << "The pointer to 'Base_Cd' is redefined to a pointer to 'Child_Classic'. \n";
	pBase_cd = &SOAD;
	pBase_cd->Report();

	std::cout << "To test the '=' operator, an object of class 'Child_Classic' is created. The created object is assigned an existing object of the 'Child_Classic' type.\n";
	Child_Classic ob_for_test;
	std::cout << "The created object of type 'Child_Classic' contains:\n";
	ob_for_test.Report();
	std::cout << "An existing object of type 'Child_Classic' contains:\n";
	SOAD.Report();

	std::cout << "The existing object is copied. The existing object then contains:\n";
	ob_for_test = SOAD;
	ob_for_test.Report();
}

void Exercises::exercise_multiple_and_virtual_inheritance()
{
	Person Mile("Mile", "Roles");
	Mile.Show();

	std::cout << "\n";
	Gunslinger Hans("Hans", "Gruber", 1.2, 10);
	Hans.Show();
	Hans.Draw();

	std::cout << "\n";
	PokerPlayer Allo("Allo", "Antonio");
	Allo.Show();
	Allo.Draw();

	std::cout << "\n";
	BadDude Ted("Ted", "Bandy", 5.4, 7);
	Ted.get_weapon_draw_time(4);
	Ted.next_card_drawn();
	Ted.Show();
}

void Exercises::exercise_palindrome_test()
{
	Palindrome word_of_user;
	word_of_user.word_request();
}

void Exercises::exercise_party_invitation()
{
	myFriendsList list_friends;
	list_friends.add_name();
}

void Exercises::show_rezult_exercises()
{
	std::array<std::string, NUM_OF_EXERCISES> description_of_functions = {};
	std::array<std::string, NUM_OF_EXERCISES> example_of_function_output = {};
	const std::array<void (Exercises::*)(), NUM_OF_EXERCISES> function_call = {
		&Exercises::exercise_simple_function_overloading, &Exercises::exercise_overload_for_numbers_type_complexxx,
		&Exercises::exercise_constructor_overloading, &Exercises::exercise_class_inheritance,
		&Exercises::exercise_multiple_and_virtual_inheritance, &Exercises::exercise_palindrome_test, &Exercises::exercise_party_invitation };	// контейнер с самими функциями;

	fill_description(TASK_DESCRIPTION_FILE_PATH, description_of_functions);
	fill_description(EXPECTED_REZULT_FILE_PATH, example_of_function_output);

	std::cout << "Some exercises from Stephen Prata 'C++ Primer Plus':\n";
	for (size_t i = 0; i < NUM_OF_EXERCISES; ++i)
	{
		std::cout << "\n---------------Exercise #" << (i+1) << "---------------\n";
		std::cout << "\t" << description_of_functions.at(i) << "\n\n";
		std::cout << "\t" << example_of_function_output.at(i) << "\n\n";
		std::cout << "\tThe result of the function:\n";
		(this->*(function_call.at(i)))();
	}
}

int main()
{
	Exercises ex_by_Prata;
	ex_by_Prata.show_rezult_exercises();

	return 0;
}
