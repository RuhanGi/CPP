NAME = harl

SRCS = main.cpp Harl.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror -std=c++98 $(SRCS) -o $(NAME)
	@printf "\x1B[32m$(NAME) ready\\x1B[32m\n";

clean:

fclean:
	@rm $(NAME)

re: fclean all