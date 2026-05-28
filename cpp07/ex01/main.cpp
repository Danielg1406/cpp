#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
void printValue(const T &value) {
	std::cout << value << ' ';
}

template <typename T>
void incrementValue(T &value) {
	++value;
}

int main(void) {
	int integers[] = {1, 2, 3, 4};
	std::size_t integerCount = sizeof(integers) / sizeof(integers[0]);

	iter(integers, integerCount, printValue<int>);
	std::cout << std::endl;
	iter(integers, integerCount, incrementValue<int>);
	iter(integers, integerCount, printValue<int>);
	std::cout << std::endl;

	const std::string words[] = {"alpha", "beta", "gamma"};
	std::size_t wordCount = sizeof(words) / sizeof(words[0]);

	iter(words, wordCount, printValue<std::string>);
	std::cout << std::endl;
	return (0);
}