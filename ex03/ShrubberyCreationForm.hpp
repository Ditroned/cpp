#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class ShrubberyCreationForm: public Form
{
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(ShrubberyCreationForm const & src);
  ShrubberyCreationForm(std::string const target);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm &		operator=(ShrubberyCreationForm const & rhs);

  virtual void    execute(Bureaucrat const & executor);
};

#endif
