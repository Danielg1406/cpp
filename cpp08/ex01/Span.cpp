#include "Span.hpp"

#include <algorithm>

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
void Span::addNumber(int number) {
  if (this->_numbers.size() >= this->_maxSize)
    throw Span::SpanFullException();
  this->_numbers.push_back(number);
}

int Span::shortestSpan() const {
  if (this->_numbers.size() < 2)
    throw Span::NotEnoughNumbersException();

  std::vector<int> sortedNumbers = this->_numbers;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());

  long shortest = static_cast<long>(sortedNumbers[1]) - static_cast<long>(sortedNumbers[0]);
  for (std::vector<int>::size_type i = 1; i < sortedNumbers.size(); ++i)
  {
    long span = static_cast<long>(sortedNumbers[i]) - static_cast<long>(sortedNumbers[i - 1]);
    if (span < shortest)
      shortest = span;
  }
  return static_cast<int>(shortest);
}

int Span::longestSpan() const {
  if (this->_numbers.size() < 2)
    throw Span::NotEnoughNumbersException();

  std::vector<int>::const_iterator minIt = std::min_element(this->_numbers.begin(), this->_numbers.end());
  std::vector<int>::const_iterator maxIt = std::max_element(this->_numbers.begin(), this->_numbers.end());

  return static_cast<int>(static_cast<long>(*maxIt) - static_cast<long>(*minIt));
}

unsigned int Span::size() const {
  return static_cast<unsigned int>(this->_numbers.size());
}

unsigned int Span::capacity() const {
  return this->_maxSize;
}

const char *Span::SpanFullException::what() const throw() {
  return "Span is full";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
  return "Not enough numbers to compute a span";
}