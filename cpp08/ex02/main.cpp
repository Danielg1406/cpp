#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

static void subjectTest()
{
	std::cout << "\t--- SUBJECT TEST ---" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "Copied to std::stack, top is: " << s.top() << std::endl;
}

static void listComparisonTest()
{
	std::cout << "\n\t--- LIST COMPARISON ---" << std::endl;

	std::list<int> numbers;

	numbers.push_back(5);
	numbers.push_back(3);
	numbers.push_back(5);
	numbers.push_back(737);
	numbers.push_back(0);

	std::list<int>::iterator it = numbers.begin();
	std::list<int>::iterator ite = numbers.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void copyTest()
{
	std::cout << "\n\t--- COPY ---" << std::endl;

	MutantStack<int> original;

	original.push(1);
	original.push(2);
	original.push(3);

	MutantStack<int> copy(original);

	std::cout << "Original top: " << original.top() << std::endl;
	std::cout << "Copy top: " << copy.top() << std::endl;

	copy.push(4);

	std::cout << "Original top after modifying copy: " << original.top() << std::endl;
	std::cout << "Copy top after push: " << copy.top() << std::endl;
}

static void assignmentTest()
{
	std::cout << "\n\t--- ASSIGNMENT ---" << std::endl;

	MutantStack<int> first;
	MutantStack<int> second;

	first.push(10);
	first.push(20);

	second.push(99);

	second = first;

	std::cout << "First top: " << first.top() << std::endl;
	std::cout << "Second top: " << second.top() << std::endl;
}

static void iteratorTest()
{
	std::cout << "\n\t--- ITERATOR ---" << std::endl;

	MutantStack<int> mstack;

	mstack.push(10);
	mstack.push(20);
	mstack.push(30);
	mstack.push(40);

	std::cout << "Forward iterator:" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Modify values through iterator:" << std::endl;

	for (it = mstack.begin(); it != mstack.end(); ++it)
		*it += 1;

	for (it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;
}

static void constIteratorTest()
{
	std::cout << "\n\t--- CONST ITERATOR ---" << std::endl;

	MutantStack<int> mstack;

	mstack.push(100);
	mstack.push(200);
	mstack.push(300);

	const MutantStack<int> constStack(mstack);

	MutantStack<int>::const_iterator it = constStack.begin();
	MutantStack<int>::const_iterator ite = constStack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

static void reverseIteratorTest()
{
	std::cout << "\n\t--- REVERSE ITERATOR ---" << std::endl;

	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);

	std::cout << "Normal order:" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Reverse order:" << std::endl;

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
}

static void constReverseIteratorTest()
{
	std::cout << "\n\t--- CONST REVERSE ITERATOR ---" << std::endl;

	MutantStack<int> mstack;

	mstack.push(7);
	mstack.push(8);
	mstack.push(9);

	const MutantStack<int> constStack(mstack);

	MutantStack<int>::const_reverse_iterator rit = constStack.rbegin();
	MutantStack<int>::const_reverse_iterator rite = constStack.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
}

int main()
{
	subjectTest();
	listComparisonTest();
	copyTest();
	assignmentTest();
	iteratorTest();
	constIteratorTest();
	reverseIteratorTest();
	constReverseIteratorTest();
	return 0;
}