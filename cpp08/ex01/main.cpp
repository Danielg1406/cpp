#include "Span.hpp"
#include <iostream>

static void subjectTest()
{
	std::cout << "\t--- SUBJECT TEST ---" << std::endl;

	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void tooManyNumbersTest()
{
	std::cout << "\n\t--- FULL SPAN ---" << std::endl;

	try
	{
		Span sp(2);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void noSpanTest()
{
	std::cout << "\n\t--- TOO SHORT ---" << std::endl;

	try
	{
		Span sp(5);

		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void duplicateNumbersTest()
{
	std::cout << "\n\t--- DUPLICATE NUMBERS ---" << std::endl;

	try
	{
		Span sp(5);

		sp.addNumber(10);
		sp.addNumber(10);
		sp.addNumber(20);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void rangeTest()
{
	std::cout << "\n\t--- RANGE WITH 10000 NUMBERS ---" << std::endl;

	try
	{
		Span sp(10000);
		std::vector<int> numbers;

		for (int i = 0; i < 10000; ++i)
			numbers.push_back(i * 2);

		sp.addMultiple(numbers.begin(), numbers.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

static void negativeNumbersTest()
{
	std::cout << "\n\t--- NEGATIVE NUMBERS ---" << std::endl;

	try
	{
		Span sp(5);

		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(20);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	subjectTest();
	tooManyNumbersTest();
	noSpanTest();
	duplicateNumbersTest();
	rangeTest();
	negativeNumbersTest();

	return 0;
}