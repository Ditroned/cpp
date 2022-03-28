#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
  Intern();
  Intern(Intern const & src);
  virtual ~Intern();
  Intern & operator=(Intern const & rhs);

  Form * makeForm(std::string name, std::string target);
};

#endif
