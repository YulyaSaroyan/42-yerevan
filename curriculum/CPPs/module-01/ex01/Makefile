NAME        := moarBrainz
CPP         := c++
CPPFLAGS    := -Wall -Wextra -Werror -std=c++98
SRC         := main.cpp Zombie.cpp zombieHorde.cpp
OBJ         := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
