NAME = prog

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp 

OBJ = $(SRC:.cpp=.o)

CC =  c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp AMateria.hpp ICharacter.hpp IMateriaSource.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean