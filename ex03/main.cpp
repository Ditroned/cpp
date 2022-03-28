#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

std::ostream &			operator<<(std::ostream &COUT, Form const &rhs);

int main(void)
{
  std::cout << "Let's instanciate a Form and an Intern" << std::endl;
  Intern someRandomIntern;
  Form* rrf;
  {
    std::cout << "---------------" << std::endl;
    std::cout << "Mandatory tests" << std::endl;
    std::cout << "---------------" << std::endl;


    std::cout << "The args are 'robotomy request' and 'Bender'" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    delete rrf;
    /* Tests supplementaires */
    std::cout << "---------------" << std::endl;
  }
  
  std::cout << "------ EXTRA TESTS ------" << std::endl;
  {
    std::cout << "The args are 'shrubbery creation' and 'Target'" << std::endl;
    std::string s1 = "shrubbery creation";
    std::cout << "--------------" << std::endl;
    try
    {
      rrf =  someRandomIntern.makeForm(s1, "Target");
      std::cout << *rrf << std::endl;
      delete rrf;
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
    std::cout << "--------------" << std::endl;
    std::cout << "The args are 'does not exist form' and 'Target'" << std::endl;
    std::string s2 = "does not exist form";
    std::cout << "--------------" << std::endl;
    try
    {
      rrf =  someRandomIntern.makeForm(s2, "Target");
      std::cout << *rrf << std::endl;
      delete rrf;
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << "--------------" << std::endl;
  return (0);
}
