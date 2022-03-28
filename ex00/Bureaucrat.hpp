#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class Bureaucrat{

public:

Bureaucrat();
Bureaucrat(int note);
Bureaucrat(Bureaucrat const & nhs);
~Bureaucrat();
Bureaucrat &operator=(Bureaucrat const & nhs);
std::string getName() const;
int getGrade() const;
void incr_grade();
void decr_grade();

std::string GradeTooHighException() const;
std::string GradeTooLowException() const;

private:

const std::string name;
int note;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif