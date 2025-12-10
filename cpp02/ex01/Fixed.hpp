#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
  private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

  public:
    // Default constructor
    Fixed();
    // Int constructor
    Fixed(const int value);
    // Float constructor
    Fixed(const float value);
    // Copy constructor
    Fixed(const Fixed &other);
    // Copy assignment operator
    Fixed& operator=(const Fixed &other);
    // Destructor
    ~Fixed();

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

// Overload of insertion operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif