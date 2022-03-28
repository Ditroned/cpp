#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, const Form &form) {
	std::cout
	<< "name: " << form.getName() << std::endl
	<< "sign: " << form.getSign() << std::endl
	<< "signGrade: " << form.getGradeSign() << std::endl
	<< "signExec: " << form.getGradeExec();
	return os;
}

std::string Form::getName() const { return m_name; }

bool Form::getSign() const { return m_sign; }

int Form::getGradeSign() const { return m_gradeSign; }

int Form::getGradeExec() const { return m_gradeExec; }

const char *Form::GradeTooHighException::what() const throw() { return "too high"; }

const char *Form::GradeTooLowException::what() const throw() { return "too low"; }

Form::Form() : m_name("default"), note(1), m_sign(0), m_gradeSign(1), m_gradeExec(1) {}

Form::~Form() {}

Form::Form(const std::string name, bool sign,
const int gradeSign, const int gradeExec) :  m_name(name), note(1), 
m_sign(sign), m_gradeSign(gradeSign), m_gradeExec(gradeExec) {
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &form) :
m_name(form.getName()), note(1), m_sign(form.getSign()),
m_gradeSign(form.getGradeSign()), m_gradeExec(form.getGradeExec()) {
	*this = form;
}

Form &Form::operator=(const Form &form) {
	if (this == &form)
		return *this;
	m_sign = form.getSign();
	return *this;
}

void Form::setSign()
{
	this->m_sign = true;
	
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() >= m_gradeSign)
	{
		m_sign = 1;
		std::cout << "the form " << m_name << " is signed" << std::endl;
	}	
}