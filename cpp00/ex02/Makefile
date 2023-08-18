NAME = work

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp tests.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean : 
	@rm -rf ${OBJS}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean re all