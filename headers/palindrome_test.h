#pragma once
#include <string>
#include <algorithm>

class Palindrome
{
private:
	std::string entered_word = "";
	const bool check_word (const std::string& word_for_check) const;
	void print_result();
public:
	void word_request();
};

const bool Palindrome::check_word (const std::string& word_for_check) const
{
	std::string checking_word = word_for_check;
	std::reverse(checking_word.begin(), checking_word.end());

	if (checking_word.compare(entered_word) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Palindrome::print_result()
{
	if (check_word(entered_word) == true)
	{
		std::cout << "\nwords ARE palindromes" << "\n";
	}
	else
	{
		std::cout << "\nwords NOT ARE palindromes" << "\n";
	}
}

void Palindrome::word_request()
{
	std::cout << "Enter word: ";
	std::getline(std::cin, entered_word);
	std::transform(entered_word.begin(), entered_word.end(), entered_word.begin(), ::tolower);
	print_result();
}