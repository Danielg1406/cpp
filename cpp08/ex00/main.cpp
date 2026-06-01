#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testVector()
{
	std::cout << "\t--- VECTOR TEST ---" << std::endl;

	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 99);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void testList()
{
	std::cout << "\n\t--- LIST TEST ---" << std::endl;

	std::list<int> numbers;
	numbers.push_back(5);
	numbers.push_back(15);
	numbers.push_back(25);

	try
	{
		std::list<int>::iterator it = easyfind(numbers, 15);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void testDeque()
{
	std::cout << "\n\t--- DEQUE TEST ---" << std::endl;

	std::deque<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	try
	{
		std::deque<int>::iterator it = easyfind(numbers, 1);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	testVector();
	testList();
	testDeque();

	return 0;
}