NAME = character

SRCS = main.cpp AMateria.cpp Character.cpp \
		Cure.cpp Ice.cpp MateriaSource.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror -std=c++98 $(SRCS) -o $(NAME)
	@printf "\x1B[32m$(NAME) ready\x1B[0m\n";

clean:

fclean:
	@rm $(NAME)

re: fclean all
