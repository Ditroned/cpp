#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), note(1)
{
    std::cout << "default bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & nhs) : name(nhs.getName()), note(nhs.getGrade())
{
    *this = nhs;
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

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & nhs)
{
    if (this == &nhs)
        return *this;
    this->note = nhs.getGrade();
    return *this;
}

void Bureaucrat::signForm(Form & nhs)
{
    nhs.setSign();
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
            if (note == 1)
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