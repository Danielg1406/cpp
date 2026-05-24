#include <iostream>
#include <string>

#include "Array.hpp"

int main(void)
{
	Array<int> empty;
	std::cout << "empty size = " << empty.size() << std::endl;

	Array<int> numbers(3);
	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;

	Array<int> copy(numbers);
	copy[1] = 99;

	std::cout << "numbers = " << numbers[0] << ' ' << numbers[1] << ' ' << numbers[2] << std::endl;
	std::cout << "copy = " << copy[0] << ' ' << copy[1] << ' ' << copy[2] << std::endl;

	Array<std::string> words(2);
	words[0] = "hello";
	words[1] = "world";

	Array<std::string> assigned;
	assigned = words;
	assigned[0] = "goodbye";

	std::cout << "words = " << words[0] << ' ' << words[1] << std::endl;
	std::cout << "assigned = " << assigned[0] << ' ' << assigned[1] << std::endl;

	try
	{
		(void)numbers[3];
	} catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}