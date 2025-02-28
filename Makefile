NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

LIBFT = libft/libft.a

SRC_FILES = src/main.c\
			src/errors.c\

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ_FILES)

fclean:
	make -C libft fclean
	rm -rf $(NAME) $(OBJ_FILES)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re
