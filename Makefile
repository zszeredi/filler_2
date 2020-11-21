NAME = zszeredi.filler

SRC_DIR = srcs/

SRC = main.c table.c fill.c tetros.c cut.c algo.c algo2.c utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) libft.a

libft:
	make -C ./libft
	cp ./libft/libft.a ./libft.a

clean:
	make -C ./libft clean
	rm -rf $(OBJ)
	rm -rf libft.a

fclean:
	make -C ./libft fclean
	rm -rf $(OBJ)
	rm -rf libft.a
	rm -rf zszeredi.filler

re: fclean all

.PHONY: libft all $(NAME)
