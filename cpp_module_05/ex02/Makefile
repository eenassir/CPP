NAME = a.out

SRC = main.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Form.cpp AForm.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

CFLAGS =  -std=c++98 -Wall -Wextra -Werror

all:     $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp #Bureaucrat.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Form.hpp AForm.hpp
	$(CC) $(CFLAGS) -c $< -MMD

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ:.o=.d)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(shell ls | grep _shruberry)

re: fclean all

.PHONY: clean

-include $(OBJ:.o=.d)