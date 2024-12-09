NAME	=	FragTrap
SRCS	=	ClapTrap.cpp main.cpp FragTrap.cpp ScavTrap.cpp
CC		=	c++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all