#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
  private:
    T *elements;
    unsigned int elementCount;

  public:
    Array(void);
    Array(unsigned int n);
    Array(const Array &other);
    ~Array(void);

    Array &operator=(const Array &other);

    // Access operator
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    unsigned int size(void) const;
};

#include "Array.tpp"

#endif