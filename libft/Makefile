# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maneddam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 20:56:01 by maneddam          #+#    #+#              #
#    Updated: 2023/01/03 22:18:25 by maneddam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC = ft_atoi.c    ft_isalnum.c ft_isdigit.c ft_memchr.c  ft_memmove.c ft_strchr.c  ft_strlcat.c ft_strncmp.c ft_strtrim.c ft_toupper.c\
ft_bzero.c   ft_isalpha.c ft_isprint.c  ft_memset.c  ft_strdup.c  ft_strlcpy.c ft_strnstr.c ft_substr.c\
ft_calloc.c ft_putnbr_fd.c ft_isascii.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_itoa.c  ft_striteri.c  ft_memcpy.c\
ft_split.c  ft_strjoin.c ft_strlen.c ft_strmapi.c ft_strrchr.c ft_tolower.c
BSRC = ft_lstnew_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c\
ft_lstiter_bonus.c ft_lstadd_front_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(BSRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus : $(OBJB)
	ar rc $(NAME) $(OBJB)


clean:
		$(RM) $(OBJ)
		$(RM) $(OBJB)
fclean: clean
		$(RM) $(NAME)

re: fclean all
