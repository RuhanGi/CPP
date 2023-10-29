NAME = convert

SRCS = main.cpp ScalarConverter.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror -std=c++98 $(SRCS) -o $(NAME)
	@printf "\x1B[32m$(NAME) ready\x1B[0m\n";

clean:

fclean:
	@rm -rf $(NAME)

re: fclean all
