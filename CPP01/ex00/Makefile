NAME = zombie

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME):
	@c++ -Wall -Wextra -Werror -std=c++98 $(SRCS) -o $(NAME)
	@printf "\x1B[32m$(NAME) ready\\x1B[32m\n";

clean:

fclean:
	@rm $(NAME)

re: fclean all