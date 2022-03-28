#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class RobotomyRequestForm: public Form
{
public:
  RobotomyRequestForm(void);
  RobotomyRequestForm(RobotomyRequestForm const &src);
  RobotomyRequestForm(std::string const target);
  virtual ~RobotomyRequestForm(void);
  RobotomyRequestForm &		operator=(RobotomyRequestForm const & rhs);

  virtual void    execute(Bureaucrat const & executor);
};

#endif
