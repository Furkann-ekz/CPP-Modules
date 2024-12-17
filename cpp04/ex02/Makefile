NAME	=	Animal
SRCS	=	Dog.cpp Cat.cpp WrongCat.cpp WrongAnimal.cpp Brain.cpp Animal.cpp main.cpp
OBJS	=	$(SRCS:.cpp=.o)
FLAGS	=	-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
		c++ $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all