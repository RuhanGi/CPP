NAME = animal

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp \
		WrongAnimal.cpp WrongCat.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror -std=c++98 $(SRCS) -o $(NAME)
	@printf "\x1B[32m$(NAME) ready\x1B[0m\n";

clean:

fclean:
	@rm $(NAME)

re: fclean all
