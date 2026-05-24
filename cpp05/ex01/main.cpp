#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat lou("lou", 1);
		Bureaucrat daniel("daniel", 149);

		std::cout << lou << std::endl;
		std::cout << daniel << std::endl;

		std::cout << "\n--- Form" << std::endl;
		Form topSecret("TopSecret", 1, 1);
		std::cout << topSecret << std::endl;

		daniel.signForm(topSecret); // fails
		std::cout << std::endl;
		lou.signForm(topSecret); // works

		std::cout << topSecret << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
