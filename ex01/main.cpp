#include "Bureaucrat.hpp"
#include "Form.hpp"

void test1() {
	std::cout << "t1 : wrong init high test:\n";
	try {
		Form form("V2", 0, 0, 50);
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}

void test2() {
	std::cout << "t2 : wrong init low test:\n";
	try {
		Form form("V2", 0, 50, 500);
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}

void test3() {
	std::cout << "t3 : operator<< test:\n";
	Form form("V2", 0, 70, 50);
	std::cout << form << std::endl;
}

void test4() {
	std::cout << "t4 : beSigned method test:\n";
	Form form("V2", 0, 70, 50);
	Bureaucrat bureaucrat(80);

	std::cout << form.getSign() << std::endl;
	form.beSigned(bureaucrat);
	std::cout << form.getSign() << std::endl;
}

void test5() {
	std::cout << "t5 : signForm method test:\n";
	Form form("V2", 0, 70, 50);
	Bureaucrat bureaucrat(80);

	bureaucrat.signForm(form);
	form.beSigned(bureaucrat);
	bureaucrat.signForm(form);
}

int main() {
	test1();
	std::cout << std::endl;
	
	test2();
	std::cout << std::endl;
	test3();
	std::cout << std::endl;
	test4();
	std::cout << std::endl;
	test5();
	
	return 0;
}
