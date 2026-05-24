#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat test("Daniel", 1);
	std::cout << test << std::endl;
	
	Bureaucrat lowTest("Low", 150);
	std::cout << lowTest << std::endl;

	// Too high test
	std::cout << "\n-- Too High" << std::endl;
	try {
		test.incrementGrade();
		std::cout << test << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Too low test
	std::cout << "\n-- Too Low" << std::endl;
	try {
		lowTest.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Invalid
	std::cout << "\n-- Invalid" << std::endl;
	try {
		Bureaucrat invalid("test", 151);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
