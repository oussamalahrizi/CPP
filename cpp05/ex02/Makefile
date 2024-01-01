CC = c++
CFLAGS = -Wall -Wextra -Werror --std=c++98

NAME = program

SRCS =	Bureaucrat.cpp \
		main.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp

OBJS = ${SRCS:.cpp=.o}

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean all re