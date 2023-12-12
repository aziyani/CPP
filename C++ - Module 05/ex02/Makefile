NAME = maggots

CC = C++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HFILE = ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp AForm.hpp Bureaucrat.hpp

OBJ = $(SRC:%.cpp=%.o)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HFILE)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re clean fclean all%