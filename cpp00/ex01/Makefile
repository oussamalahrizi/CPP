NAME = Phonebook

CFLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

SRC = main.cpp PhoneBook.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	@${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

.PHONY : clean fclean all re
