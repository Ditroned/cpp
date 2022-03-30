#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
  return ;
}

Intern::~Intern()
{
	std::cout << "Intern default desconstructor called" << std::endl;
  return ;
}

Intern::Intern(Intern const & src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
  return ;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
  std::cout << "Nothing to assign our intern" << std::endl;
	return *this;
}

Form *Intern::schrub(std::string target)
{
  return (new ShrubberyCreationForm(target));
}

Form *Intern::presiden(std::string target)
{
  return (new PresidentialPardonForm(target));
}

Form *Intern::robo(std::string target)
{
  return (new RobotomyRequestForm(target));
}

Form * Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	//Form * ( src[]) = {Intern::schrub(target), Intern::presiden(target), Intern::robo(target)};
  //Form * src[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
  //Form * (Intern::*pointers_to_func_members[3]) (std::string target) = {&Intern::schrub, &Intern::presiden, &Intern::robo};
  //Form * (Intern::*schrub)(std::string target) = 
  //Form * (Intern::*src[3])() = {Intern::schrub(target), Intern::presiden(target), Intern::robo(target)};
  //Form * (src[3])(target) = {(&Intern::schrub), (&Intern::presiden), (&Intern::robo)};
  
  
  Form* rtn;
	typedef Form* (*func)(std::string target);
  typedef struct {func func; } FormTypes;
  FormTypes src[] = {
    {&Intern::schrub},
    {&Intern::presiden},
    {&Intern::robo}};
    
  int i = 0;
  int check = -1;
  while (i < 3)
  {
    if (forms[i] == name)
    {
	    check = i;
	    std::cout << "We found it , the form is " << forms[i] << std::endl;

      break;
    }
    i++;
  }
  if (check == -1)
  {
    throw std::runtime_error(std::string("cant create intern , fail form"));
  }
  if (check != -1)
  {
	std::cout << "Inter creates " << name << std::endl;
    return (src[check].func(target));
  }
  return (NULL);
}
