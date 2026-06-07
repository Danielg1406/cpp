#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("Error");

		RPN rpn;
		std::cout << rpn.solveFormula(argv[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}