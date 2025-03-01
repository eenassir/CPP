NAME = a.out

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FlagTrap.cpp DiamondTrap.cpp
OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ClapTrap.h ClapTrap.hpp ScavTrap.h ScavTrap.hpp DiamondTrap.h DiamondTrap.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean