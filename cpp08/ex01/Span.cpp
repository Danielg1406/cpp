#include "Span.hpp"

// Canonical Form
Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int n) : _maxSize(n), _numbers() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
  if (this != &other)
  {
    this->_maxSize = other._maxSize;
    this->_numbers = other._numbers;
  }
  return *this;
}

// Member functions
void Span::addNumber(int number) {
  if (this->_numbers.size() >= this->_maxSize)
    throw Span::SpanFullException();
  this->_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = static_cast<unsigned int>(sorted[1] - sorted[0]);

	for (std::vector<int>::size_type i = 1; i < sorted.size() - 1; ++i)
	{
		unsigned int current = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
		if (current < shortest)
			shortest = current;
	}

	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(*maxIt - *minIt);
}

// Exceptions
const char *Span::SpanFullException::what() const throw() {
  return "Span is full";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
  return "Not enough numbers";
}