#include "Bureaucrat.hpp"

void test1() {
	std::cout << "t1 : default constructor and operator<< test:\n";
	Bureaucrat bureaucrat;
	std::cout << bureaucrat << std::endl;
}

void test7() {
	std::cout << "t7 : parameter constructor and operator<< test:\n";
	Bureaucrat bureaucrat(50);
	std::cout << bureaucrat << std::endl;
}

void test2() {
	std::cout << "t2 : increment KO test:\n";
	Bureaucrat bureaucrat;
	std::cout << bureaucrat.getGrade() << std::endl;

	try {
		bureaucrat.incr_grade();
	} catch (const std::string message) {
		std::cout << "exception: " << message << std::endl;
		std::cout << bureaucrat.getGrade() << std::endl;
	}
}

void test3() {
	std::cout << "t3 : decrement OK test:\n";
	Bureaucrat bureaucrat;
	try {
		bureaucrat.decr_grade();
	} catch (const std::string message) {
		std::cout << "exception: " << message << std::endl;
		return ;
	}
}

void test4() {
	std::cout << "t4 : decrement KO test:\n";
	Bureaucrat bureaucrat(150);
	try {
		bureaucrat.decr_grade();
	} catch (const std::string message) {
		std::cout << "exception: " << message << std::endl;
	}
}

void test5() {
	std::cout << "t5 : wrong init high test:\n";
	try {
		Bureaucrat bureaucrat(0);
	} catch (const std::string message) {
		std::cout << "exception: " << message << std::endl;
	}
}

void test6() {
	std::cout << "t6 : wrong init low test:\n";
	try {
		Bureaucrat bureaucrat(151);
	} catch (const std::string message) {
		std::cout << "exception: " << message << std::endl;
	}
}

int main() {
	test1();
	std::cout << std::endl;
	test7();
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	test3();
	std::cout << std::endl;
	test4();
	std::cout << std::endl;
	test5();
	std::cout << std::endl;
	test6();
	return 0;
}
