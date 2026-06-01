#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <algorithm>
#include <vector>

class Span
{
  private:
    unsigned int      _maxSize;
    std::vector<int>  _numbers;
  public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void          addNumber(int number);
    unsigned int  shortestSpan() const;
    unsigned int  longestSpan() const;

    template <typename Iterator>
    void addMultiple(Iterator begin, Iterator end)
    {
      unsigned int count = 0;
      Iterator tmp = begin;

      while (tmp != end)
			{
				++count;
				++tmp;
			}

			if (_numbers.size() + count > _maxSize)
				throw Span::SpanFullException();

			_numbers.insert(_numbers.end(), begin, end);
    }

    class SpanFullException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };

    class NotEnoughNumbersException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif