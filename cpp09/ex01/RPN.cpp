#include "RPN.hpp"

// Canonical Form
RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

// Checkers
bool RPN::isOperator(const std::string &token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isNumber(const std::string &token)
{
	return token.size() == 1 && token[0] >= '0' && token[0] <= '9';
}


void RPN::applyOperator(const std::string &op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	int right = _stack.back();
	_stack.pop_back();

	int left = _stack.back();
	_stack.pop_back();

	if (op == "+")
		_stack.push_back(left + right);
	else if (op == "-")
		_stack.push_back(left - right);
	else if (op == "*")
		_stack.push_back(left * right);
	else if (op == "/")
	{
		if (right == 0)
			throw std::runtime_error("Error");
		_stack.push_back(left / right);
	}
}

int RPN::solveFormula(const std::string &formula)
{
	_stack.clear();

	std::istringstream iss(formula);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
			_stack.push_back(token[0] - '0');
		else if (isOperator(token))
			applyOperator(token);
		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.back();
}