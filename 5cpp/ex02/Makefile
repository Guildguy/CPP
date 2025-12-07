NAME := Bureaucrat

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

SRC_DIR := .
OBJ_DIR := obj

CPP_FILES := Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp main.cpp
OBJ_FILES := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES))

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

v: 
	valgrind --leak-check=full ./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re v
