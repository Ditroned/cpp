#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

public:

Form();
Form(const Form & nhs);
~Form();
Form(const std::string name, bool sign,
const int gradeSign, const int gradeExec);
Form &operator=(const Form & nhs);
std::string getName() const;
int getNote() const;
bool getSign() const;
int getGradeSign() const;
int getGradeExec() const;
void setSign();
void beSigned(const Bureaucrat & nhs);

class GradeTooHighException : public std::exception {
		public:

		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:

		const char *what() const throw();
	};


private:

const std::string m_name;
const int note;
bool m_sign;
const int m_gradeSign;
const int m_gradeExec;
};

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif