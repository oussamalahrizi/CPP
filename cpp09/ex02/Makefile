NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Wextra -Werror --std=c++98 -fsanitize=address -g3 

SRCS = main.cpp PmergeMe.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all re


