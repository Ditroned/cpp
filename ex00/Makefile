CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TARGET = a.out

all: $(TARGET)

$(TARGET): main.cpp Bureaucrat.cpp
		$(CC) $(CFLAGS) main.cpp Bureaucrat.cpp

clean:
		$(RM) $(TARGET)