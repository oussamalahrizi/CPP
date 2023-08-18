NAME	= megaphone

SRCS	= megaphone.cpp

OBJS	= $(SRCS:.cpp=.o)

CC		= c++
# CC		= clang++

FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all