#ifndef RPN_HPP
# define RPN_HPP

#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <stdexcept>

class RPN
{
	private:
		std::deque<int> _stack;

		static bool isOperator(const std::string &token);
		static bool isNumber(const std::string &token);
		void applyOperator(const std::string &op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int solveFormula(const std::string &formula);
};

#endif