#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat{

public:

Bureaucrat();
Bureaucrat(int note);
Bureaucrat(std::string const name, int grade);
Bureaucrat(Bureaucrat const & nhs);
~Bureaucrat();
Bureaucrat &operator=(Bureaucrat const & nhs);
std::string getName() const;
int getGrade() const;
void signForm(Form & nhs);
void incr_grade();
void decr_grade();


void	        executeForm(Form &form);

class GradeTooHighException : public std::exception {
		public:

		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:

		const char *what() const throw();
	};
	



private:

const std::string name;
int note;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif