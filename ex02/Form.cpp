#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("default_form"), _signed(false), _gexec(150), _gsign(150), _target("default_target")
{
  std::cout << "Form default constructor called" << std::endl;
  return ;
}

Form::Form(const Form & src): _name(src._name), _signed(false), _gexec(src._gexec), _gsign(src._gsign), _target(src._target)
{
  std::cout << "Form copy constructor constructor called" << std::endl;
  return ;
}

Form::Form(std::string name, int gexec, int gsign, std::string target): _name(name), _signed(false), _gexec(gexec), _gsign(gsign), _target(target)
{
  std::cout << "Form constructor constructor called" << std::endl;
	if (this->_gexec < 1 || this->_gsign < 1)
		throw Form::GradeTooHighException();
	if (this->_gexec > 150 || this->_gsign > 150)
		throw Form::GradeTooLowException();
  std::cout << "Form called" << this->getName() << std::endl;
  std::cout << "Grade for signing : " << this->getGsign() << std::endl;
  std::cout << "Grade for executing : " << this->getGexec() << std::endl;
  std::cout << "Has been created successfully." << std::endl;
  return ;
}
Form::~Form(void)
{
  std::cout << "Form deconstructor called" << std::endl;
  return ;
}

Form &				Form::operator=(Form const & rhs)
{
  (void)rhs;
  std::cout << "Form assignation operator called" << std::endl;
	return *this;
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

const std::string &Form::getTarget(void) const
{
	return (this->_target);
}

const int &Form::getGsign(void) const
{
	return (this->_gsign);
}

const int &Form::getGexec(void) const
{
	return (this->_gexec);
}

bool  Form::isSigned(void) const
{
	return (this->_signed);
}

void Form::setSign(void)
{
  this->_signed = true;
	std::cout << "the form " << this->_name << " is signed" << std::endl;
  return;
}

Form & Form::beSigned(Bureaucrat const &bur)
{
  std::cout << "beSigned function called" << std::endl;
  if (bur.getGrade() > this->getGsign())
    throw Form::GradeTooLowException();
  else if (bur.getGrade() <= this->getGsign())
  {
    this->setSign();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i)
{
	o << "Form " << i.getName() << "." << " Grade required form signature: " << i.getGsign();
	o << ". Grade required for execution: " << i.getGexec() << ".";
	if (i.isSigned())
		o << " This form is signed.";
	else
		o << " This form is not signed yet.";
	return o;
}

void		Form::execute(Bureaucrat const & executor)
{
	if (this->_signed == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->_gexec)
		throw Form::GradeTooLowException();
}
