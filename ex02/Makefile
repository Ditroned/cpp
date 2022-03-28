CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = a.out

all: $(TARGET)

$(TARGET): main.cpp Form.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
		$(CC) $(CFLAGS) main.cpp Form.cpp Bureaucrat.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

clean:
		$(RM) $(TARGET)
