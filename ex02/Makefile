SRC=$(shell find . -name \*.cpp -type f -print)
OBJ=$(patsubst %.cpp,./obj/%.o,$(SRC))
NAME=cpp02
FLAGS=-Wall -Werror -Wextra -std=c++98

all:
	mkdir -p $(shell dirname $(OBJ))
	make $(NAME)

obj/%.o: src/%.c
	c++ -c $(FLAGS) -g -o $@ $<

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -g -o $@

clean:
	find ./obj -name \*.o -type f -delete

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
