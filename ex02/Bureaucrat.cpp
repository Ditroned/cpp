#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), note(1)
{
    std::cout << "default bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & nhs) : name(nhs.getName()), note(nhs.getGrade())
{
    *this = nhs;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): name(name), note(grade)
{
  std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
  std::cout << "Bureaucrat is called " << this->getName() << " and has grade " << this->getGrade() << std::endl;
  return ;
}

Bureaucrat::Bureaucrat(int notee) : name("default with note")
{
    if (notee < 1)
        throw GradeTooHighException();
    if (notee > 150)
        throw GradeTooLowException();
    note = notee;
    std::cout << "constructor Bureaucrat with arg note" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
}

void			Bureaucrat::executeForm(Form &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " cannot execute " << form.getName() << ": ";
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::cout << this->name << " executs " <<  form.getName() << std::endl;
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat const & nhs)
{
    if (this == &nhs)
        return *this;
    this->note = nhs.getGrade();
    return *this;
}

void Bureaucrat::signForm(Form & nhs)
{
    try {
        if (this->note > nhs.getGsign())
            throw GradeTooHighException();
        nhs.setSign();
    }
    catch(std::exception & e){
            std::cerr << e.what() << std::endl;
        }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "too low"; }

int Bureaucrat::getGrade() const
{
    return this->note;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

void Bureaucrat::incr_grade()
{
        try
        {
            if (note < 1)
                throw GradeTooHighException();
            note--;
            std::cout << "grade increase sucessfully" << std::endl;
        }
        catch(std::exception & e)
        {
            std::cerr << e.what() << '\n';
        }
}

void Bureaucrat::decr_grade()
{
        
        try{
            if (note > 150)
                throw GradeTooLowException();
            note++;
            std::cout << "grade decrease sucessfully"  << std::endl;
        }
        catch(std::exception & e){
            std::cerr << e.what() << std::endl;
        }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	std::cout <<
	bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}