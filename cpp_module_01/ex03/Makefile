NAME=weapon  

SRC=main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ=$(SRC:.cpp=.o)

CC=c++

CFLAGS=-Wall -Wextra -Werror -std=c++98

all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp Weapon.h Weapon.hpp HumanA.hpp HumanB.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re:fclean all

.PHONY:clean