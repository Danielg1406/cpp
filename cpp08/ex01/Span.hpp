#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
  private:
    unsigned int      _maxSize;
    std::vector<int>  _numbers;
  public:
    Span();
    explicit Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);

    template <typename InputIterator>
    void addNumber(InputIterator first, InputIterator last)
    {
      unsigned int count = 0;
      InputIterator it = first;

      for (; it != last; ++it)
        ++count;
      if (this->_numbers.size() + count > this->_maxSize)
        throw SpanFullException();
      for (it = first; it != last; ++it)
        this->_numbers.push_back(*it);
    }

    int shortestSpan() const;
    int longestSpan() const;

    unsigned int size() const;
    unsigned int capacity() const;

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