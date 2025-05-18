<<<<<<< HEAD
NAME = PmergeMe

SRC = main.cpp
=======
NAME = PmergeMe 

SRC = main.cpp PmergeMe.cpp 
>>>>>>> 84d8ae3c0ac766dc3bff892aaa87e841cb3d5e70

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp PmergeMe.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean