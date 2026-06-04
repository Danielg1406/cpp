#include "PmergeMe.hpp"

// Canonical Form
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; ++i)
	{
		int value = parseNumber(argv[i]);

		if (containsValue(_vector, value))
			throw std::runtime_error("Error");

		_vector.push_back(value);
		_list.push_back(value);
	}

	_jacobOrder = calcJacobsthal<std::vector<std::size_t> >(
		_vector.size() / 2 + 1
	);
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		_vector = other._vector;
		_list = other._list;
		_jacobOrder = other._jacobOrder;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}


// Checker
bool PmergeMe::isPositiveIntegerString(const std::string &str)
{
	std::size_t i = 0;

	if (str.empty())
		return false;

	if (str[0] == '+')
		i = 1;

	if (i == str.size())
		return false;

	while (i < str.size())
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
		++i;
	}
	return true;
}


// Parser
int PmergeMe::parseNumber(const char *arg)
{
	std::string str(arg);
	long value;
	std::istringstream iss(str);

	if (!isPositiveIntegerString(str))
		throw std::runtime_error("Error");

	iss >> value;

	if (iss.fail() || value <= 0 || value > INT_MAX)
		throw std::runtime_error("Error");

	return static_cast<int>(value);
}


// Printer
void PmergeMe::printBefore() const
{
	std::cout << "Before:";
	printContainer(_vector);
}

void PmergeMe::run() const
{
	std::vector<int> sortedVector;
	std::list<int> sortedList;

	printBefore();

	clock_t startVector = clock();
	sortedVector = _vector;
	sortVector(sortedVector, _jacobOrder);
	clock_t endVector = clock();

	clock_t startList = clock();
	sortedList = _list;
	sortList(sortedList, _jacobOrder);
	clock_t endList = clock();

	double vectorTime = static_cast<double>(endVector - startVector)
		* 1000000.0 / CLOCKS_PER_SEC;

	double listTime = static_cast<double>(endList - startList)
		* 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "After:";
	printContainer(sortedVector);

	std::cout << std::fixed << std::setprecision(5);

	std::cout << "Time to process a range of " << _vector.size()
			  << " elements with std::vector : "
			  << vectorTime << " us" << std::endl;

	std::cout << "Time to process a range of " << _list.size()
			  << " elements with std::list   : "
			  << listTime << " us" << std::endl;
}


// Vector Implementation
void PmergeMe::insertVector(
	std::vector<int> &chain,
	int value,
	int limitValue
)
{
	std::size_t high = 0;

	while (high < chain.size() && chain[high] != limitValue)
		++high;

	std::size_t low = 0;

	while (low < high)
	{
		std::size_t mid = low + (high - low) / 2;

		if (chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}

	chain.insert(chain.begin() + low, value);
}

void PmergeMe::insertVectorNoLimit(
	std::vector<int> &chain,
	int value
)
{
	std::size_t low = 0;
	std::size_t high = chain.size();

	while (low < high)
	{
		std::size_t mid = low + (high - low) / 2;

		if (chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}

	chain.insert(chain.begin() + low, value);
}

void PmergeMe::sortVector(
	std::vector<int> &numbers,
	const std::vector<std::size_t> &jacobOrder
)
{
	if (numbers.size() < 2)
		return;

	std::vector<IntPair> pairs;
	std::vector<int> bigs;
	bool hasStray = false;
	int stray = 0;

	for (std::size_t i = 0; i < numbers.size(); i += 2)
	{
		if (i + 1 == numbers.size())
		{
			hasStray = true;
			stray = numbers[i];
			break;
		}

		IntPair pair;

		if (numbers[i] < numbers[i + 1])
		{
			pair.small = numbers[i];
			pair.big = numbers[i + 1];
		}
		else
		{
			pair.small = numbers[i + 1];
			pair.big = numbers[i];
		}

		pairs.push_back(pair);
		bigs.push_back(pair.big);
	}

	sortVector(bigs, jacobOrder);

	std::vector<int> chain = bigs;
	std::vector<IntPair> pend;

	for (std::vector<int>::iterator it = bigs.begin(); it != bigs.end(); ++it)
	{
		for (std::vector<IntPair>::iterator pit = pairs.begin();
			 pit != pairs.end(); ++pit)
		{
			if (pit->big == *it)
			{
				pend.push_back(*pit);
				break;
			}
		}
	}

	for (std::vector<std::size_t>::const_iterator it = jacobOrder.begin();
		 it != jacobOrder.end(); ++it)
	{
		if (*it < pend.size())
			insertVector(chain, pend[*it].small, pend[*it].big);
	}

	if (hasStray)
		insertVectorNoLimit(chain, stray);

	numbers = chain;
}


// List implementation
std::list<int>::iterator PmergeMe::lowerBoundList(
	std::list<int> &chain,
	int value,
	std::list<int>::iterator end
)
{
	std::list<int>::iterator first = chain.begin();
	std::size_t count = std::distance(first, end);

	while (count > 0)
	{
		std::list<int>::iterator it = first;
		std::size_t step = count / 2;

		std::advance(it, step);

		if (*it < value)
		{
			first = it;
			++first;
			count -= step + 1;
		}
		else
			count = step;
	}

	return first;
}

void PmergeMe::insertList(
	std::list<int> &chain,
	int value,
	int limitValue
)
{
	std::list<int>::iterator limit = chain.begin();

	while (limit != chain.end() && *limit != limitValue)
		++limit;

	std::list<int>::iterator pos = lowerBoundList(chain, value, limit);
	chain.insert(pos, value);
}

void PmergeMe::insertListNoLimit(
	std::list<int> &chain,
	int value
)
{
	std::list<int>::iterator pos = lowerBoundList(chain, value, chain.end());
	chain.insert(pos, value);
}

void PmergeMe::sortList(
	std::list<int> &numbers,
	const std::vector<std::size_t> &jacobOrder
)
{
	if (numbers.size() < 2)
		return;

	std::list<IntPair> pairs;
	std::list<int> bigs;
	bool hasStray = false;
	int stray = 0;

	std::list<int>::iterator it = numbers.begin();

	while (it != numbers.end())
	{
		int first = *it;
		++it;

		if (it == numbers.end())
		{
			hasStray = true;
			stray = first;
			break;
		}

		int second = *it;
		++it;

		IntPair pair;

		if (first < second)
		{
			pair.small = first;
			pair.big = second;
		}
		else
		{
			pair.small = second;
			pair.big = first;
		}

		pairs.push_back(pair);
		bigs.push_back(pair.big);
	}

	sortList(bigs, jacobOrder);

	std::list<int> chain = bigs;
	std::list<IntPair> pend;

	for (std::list<int>::iterator bit = bigs.begin();
		 bit != bigs.end(); ++bit)
	{
		for (std::list<IntPair>::iterator pit = pairs.begin();
			 pit != pairs.end(); ++pit)
		{
			if (pit->big == *bit)
			{
				pend.push_back(*pit);
				break;
			}
		}
	}

	for (std::vector<std::size_t>::const_iterator oit = jacobOrder.begin();
		 oit != jacobOrder.end(); ++oit)
	{
		if (*oit < pend.size())
		{
			std::list<IntPair>::iterator pit = pend.begin();
			std::advance(pit, *oit);
			insertList(chain, pit->small, pit->big);
		}
	}

	if (hasStray)
		insertListNoLimit(chain, stray);

	numbers = chain;
}