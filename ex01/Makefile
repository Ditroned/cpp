CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = a.out

all: $(TARGET)

$(TARGET): main.cpp Bureaucrat.cpp Form.cpp
		$(CC) $(CFLAGS) main.cpp Bureaucrat.cpp Form.cpp

clean:
		$(RM) $(TARGET)
