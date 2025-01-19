NAME = PhoneBook

SRC = PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address -g

all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp  classes.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean