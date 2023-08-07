NAME = zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=leak -g3

SRCS = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp zombieHorde.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
	@rm -rf ${OBJS}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean all re

 