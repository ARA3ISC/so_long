NAME=so_long
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c libft/ft_split.c libft/ft_strlen.c libft/ft_calloc.c \
check_map.c error.c dimens.c printf/ft_putchar.c printf/ft_printf.c printf/ft_putnbr.c printf/ft_putnbr_add.c \
printf/ft_putnbr_u_dec.c printf/ft_putstr.c printf/ft_strlen_p.c check_path.c move.c swap_images.c libft/ft_strncmp.c \
display_items.c libft/ft_itoa.c display_enemy.c libft/ft_strjoin.c animation.c extend_move.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)

re: fclean all
