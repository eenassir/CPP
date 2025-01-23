NAME = Account

SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -std=c++98 -fsanitize=address -g #-Wall -Wextra -Werror 

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Account.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean