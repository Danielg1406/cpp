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

static void constIteratorTest()
{
	std::cout << "\n\t--- CONST ITERATOR ---" << std::endl;

	MutantStack<int> stack;

	stack.push(100);
	stack.push(200);
	stack.push(300);

	const MutantStack<int> constStack(stack);

	MutantStack<int>::const_iterator it = constStack.begin();
	MutantStack<int>::const_iterator ite = constStack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	subjectTest();
	listComparisonTest();
	copyTest();
	assignmentTest();
	constIteratorTest();

	return 0;
}