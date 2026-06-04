#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include <iostream>

template <typename Container>
void PmergeMe::printContainer(const Container &container)
{
	typename Container::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

template <typename Container>
bool PmergeMe::containsValue(const Container &container, int value)
{
	typename Container::const_iterator it;

	for (it = container.begin(); it != container.end(); ++it)
	{
		if (*it == value)
			return true;
	}
	return false;
}

template <typename OrderContainer>
OrderContainer PmergeMe::calcJacobsthal(std::size_t maxInsert)
{
	std::vector<std::size_t> jacob;
	OrderContainer expanded;

	if (maxInsert == 0)
		return expanded;

	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < maxInsert)
	{
		std::size_t i = jacob.size();
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
	}

	expanded.push_back(0);

	for (std::size_t i = 1; i < jacob.size(); ++i)
	{
		std::size_t end = jacob[i];

		if (end > maxInsert)
			end = maxInsert;

		for (std::size_t j = end; j > jacob[i - 1]; --j)
			expanded.push_back(j - 1);

		if (jacob[i] >= maxInsert)
			break;
	}

	return expanded;
}

#endif