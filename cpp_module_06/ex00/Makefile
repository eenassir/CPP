NAME = Converter

SRC = main.cpp ScalarConverter.cpp

OBJ =    $(SRC:.cpp=.o)

CC =     c++

CFLAGS = -std=c++98 #-Wall -Wextra -Werror -fsanitize=address -g

all:     $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean