NAME = Animal

SRC = main.cpp Animal.cpp

OBJ =    $(SRC:.cpp=.o)

CC =     c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Animal.h Animal.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean