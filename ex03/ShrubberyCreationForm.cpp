#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyFormCreation", 137, 145, "Default_target")
{
  std::cout << "Shrubbery Creation Form constructor called" << std::endl;
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & src): Form(src)
{
  std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): Form("ShrubberyCreationForm", 137, 145, target)
{
  std::cout << "Shrubbery Creation Form target constructor called" << std::endl;
  return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
  std::cout << "Shrubbery Creation Form destructor called" << std::endl;
  return ;
}

ShrubberyCreationForm &				ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void)rhs;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
  (void)executor;
  //ecriture dans un fichier plutot que sur l entree standard
  std::cout << "Shrubberry Creation Form execute invoked" << std::endl;
	std::ofstream	output;
	const std::string	name = this->_target + "_shrubbery";
	try
	{
		Form::execute(executor);
		output.open(name.data(), std::ofstream::trunc | std::ofstream::out);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	output << "   000  " << std::endl;
    output << "    ooooo  " << std::endl;
	output << "   ooo  " << std::endl;
	output << "	   o    "<< std::endl;
	output << "XXXXXXXXXX" << std::endl;
  output.close();
  output << "Form " << this->_name << " has been executed by " << executor.getName() << std::endl;
}
