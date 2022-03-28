#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

std::ostream &			operator<<(std::ostream &COUT, Form const &rhs);

int main(void)
{
  {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Test avec un top bureaucrat" << std::endl;
    std::cout << "---------------------------" << std::endl;
    Bureaucrat top("CEO", 1);
    {
      std::cout << "------ SHRUBERRY ------" << std::endl;
      ShrubberyCreationForm shrub("test target");
      std::cout << "--- signing ---" << std::endl;
      top.signForm(shrub);
      std::cout << "--- executing ---" << std::endl;
      top.executeForm(shrub);
      std::cout << std::endl;

    }
    {
      std::cout << "--- PRESIDENTIAL --" << std::endl;
      PresidentialPardonForm pres("test2 target");
      std::cout << "-- signing --" << std::endl;
      top.signForm(pres);
      std::cout << "-- executing --" << std::endl;
      top.executeForm(pres);
      std::cout << std::endl;
    }
    {
      std::cout << " --- ROBOTOMY --- " << std::endl;
      RobotomyRequestForm req("test3 target");
      std::cout << " --- signing --- " << std::endl;
      top.signForm(req);
      std::cout << " --- executing --- " << std::endl;
      top.executeForm(req);
      std::cout << std::endl;
    }
    std::cout << "-- DESTRUCTORS ---" << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  {
    std::cout << "Test avec bureaucrat low" << std::endl;
    std::cout << "----" << std::endl;
    Bureaucrat low("Low", 46);
    {
      std::cout << "--- SHRUBERRY ---" << std::endl;
      ShrubberyCreationForm shrub("test target");
      std::cout << "--- signing ---" << std::endl;
      low.signForm(shrub);
      std::cout << "--- executing ---" << std::endl;
      low.executeForm(shrub);
      std::cout << std::endl;

    }
    {
      std::cout << "--- PRESIDENTIAL ---" << std::endl;
      PresidentialPardonForm pres("test2 target");
      std::cout << "--- signing ---" << std::endl;
      low.signForm(pres);
      std::cout << "--- executing ---" << std::endl;
      low.executeForm(pres);
      std::cout << "-----------------------" << std::endl;
    }
    {
      std::cout << "--- ROBOTOMY ----" << std::endl;
      RobotomyRequestForm req(" test3  target" );
      std::cout << "-- signing --" << std::endl;
      low.signForm(req);
      std::cout << "-- executing --" << std::endl;
      low.executeForm(req);
      std::cout << std::endl;
    }
    std::cout << "fin et destrcuction " << std::endl;
  }
  return (0);
}
