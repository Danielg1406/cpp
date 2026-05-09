#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat test("Daniel", 1);
	std::cout << test << std::endl;
	
	// Too high test
	try {
		test.decrementGrade();
		std::cout << test << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what();
	}

	// Too low test
	try {
		Bureaucrat lowTest("Lou", 151);
	} catch (const std::exception &e) {
		std::cerr << e.what();
	}
	return (0);
}
