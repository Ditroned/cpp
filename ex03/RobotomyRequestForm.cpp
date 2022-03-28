#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm", 45, 72, "default_target")
{
  std::cout << "Robotomy Request Form constructor called" << std::endl;
  return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): Form(src)
{
  std::cout << "Robotomy Request Form copy constructor called" << std::endl;
  return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form("RobotomyRequestForm", 45, 72, target)
{
  std::cout << "Robotomy Request Form target constructor called" << std::endl;
  return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
  std::cout << "Robotomy Request Form destructor called" << std::endl;
  return ;
}

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	(void)rhs;
  std::cout << "Robotomy Request assignation operator called" << std::endl;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
  (void)executor;
  std::cout << "Robotomy Request Form execution" << std::endl;
	int nbr = rand();
  try
  {
    Form::execute(executor);
  }
  catch(const std::exception &e)
  {
    std::cout << e.what() << std::endl;
    return ;
  }
  std::cout << "drilling noise bzzz" << std::endl;
  if (nbr % 2 == 0)
  {
    std::cout << this->_target << " has been robotomized" << std::endl;
  }
  else
    std::cout << this->_target << "Robotomization failed" << std::endl;
}
