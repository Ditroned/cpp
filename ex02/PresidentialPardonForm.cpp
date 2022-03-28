#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 5, 25, "default_target")
{
  std::cout << "Presidential Pardon form constructor called" << std::endl;
  return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src): Form(src)
{
  std::cout << "Presidential Pardon form copy constructor called" << std::endl;
  this->_target = src.getTarget();
  return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target): Form("PresidentialPardonForm", 5, 25, target)
{
  std::cout << "Presidential Pardon form target constructor called " << std::endl;
  return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
  std::cout << "Presidential Pardon form destructor called" << std::endl;
  return ;
}

PresidentialPardonForm &				PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	(void)rhs;
  std::cout << "Form assignation operator called" << std::endl;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
  (void)executor;
  std::cout << "Presidential Pardon Form execute" << std::endl;
  try
	{
		Form::execute(executor);
	}
  catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	std::cout << this->_target << " was forgiven by Zafod Beeblebrox" << std::endl;
}
