#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <string>
# include <cstddef>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <iomanip>
#include <iterator>

struct IntPair
{
	int small;
	int big;
};

class PmergeMe
{
	private:
		std::vector<int>         _vector;
		std::list<int>           _list;
		std::vector<std::size_t> _jacobOrder;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void printBefore() const;
		static int  parseNumber(const char *arg);
		static bool isPositiveIntegerString(const std::string &str);

		template <typename Container>
		static void printContainer(const Container &container);
		template <typename Container>
		static bool containsValue(const Container &container, int value);
		template <typename OrderContainer>
		static OrderContainer calcJacobsthal(std::size_t maxInsert);

		static void sortVector(std::vector<int> &numbers, const std::vector<std::size_t> &jacobOrder);
		static void insertVector(std::vector<int> &chain, int value, int limitValue);
		static void insertVectorNoLimit(std::vector<int> &chain, int value);

		static void sortList(std::list<int> &numbers, const std::vector<std::size_t> &jacobOrder);
		static void insertList(std::list<int> &chain,int value,int limitValue);
		static void insertListNoLimit(std::list<int> &chain,int value);
		static std::list<int>::iterator lowerBoundList(std::list<int> &chain,int value,std::list<int>::iterator end);
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();

		void run() const;
};

# include "PmergeMe.tpp"

#endif