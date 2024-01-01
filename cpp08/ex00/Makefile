
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

NAME = program
SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all