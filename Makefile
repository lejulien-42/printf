# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lejulien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 13:57:31 by lejulien          #+#    #+#              #
#    Updated: 2019/12/30 04:59:13 by lejulien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = libft/ft_atoi.c \
		libft/ft_isascii.c \
		libft/ft_memchr.c \
		libft/ft_memset.c \
		libft/ft_strncmp.c \
		libft/ft_toupper.c\
		libft/ft_bzero.c \
		libft/ft_isdigit.c \
		libft/ft_memcmp.c \
		libft/ft_strchr.c \
		libft/ft_strnstr.c \
		libft/ft_isalnum.c\
		libft/ft_isprint.c \
		libft/ft_memcpy.c \
		libft/ft_strlcat.c \
		libft/ft_strrchr.c \
		libft/ft_isalpha.c \
		libft/ft_calloc.c \
		libft/ft_memmove.c \
		libft/ft_memccpy.c \
		libft/ft_strlen.c \
		libft/ft_tolower.c \
		libft/ft_strdup.c \
		libft/ft_strlcpy.c\
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_putchar_fd.c \
		libft/ft_itoa.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_strmapi.c \
		libft/ft_split_charset.c \
		libft/ft_uitoa.c \
		flag_checker.c \
		converters.c \
		addborders.c \
		sorter.c \
		printf.c \
		logic.c \
		precision.c \
		ft_printfcases.c \
		ft_printf_cases_two.c \
		casei.c \
		caseu.c \
		casex.c \
		casepers.c

SRC_BONUS = libft/ft_lstnew_bonus.c \
			libft/ft_lstadd_front_bonus.c \
			libft/ft_lstsize_bonus.c \
			libft/ft_lstlast_bonus.c \
			libft/ft_lstadd_back_bonus.c \
			libft/ft_lstdelone_bonus.c \
			libft/ft_lstclear_bonus.c \
			libft/ft_lstiter_bonus.c \
			libft/ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = libft/libft.h \
		printf.h

CFLAGS = -Wall -Wextra -Werror

.c.o:
		gcc $(CFLAGS) -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

bonus:	$(OBJ_BONUS)
		ar rc $(NAME) $(OBJ_BONUS)

test:
		gcc main1.c $(SRC) && ./a.out

Hypetest:
		gcc garguantest.c $(SRC) && ./a.out

fl:
		gcc fl.c $(SRC) && ./a.out

lldb:
		gcc -g3 -fsanitize=address main.c $(SRC) && lldb ./a.out

clean:
		/bin/rm -f $(OBJ)
		/bin/rm -f $(OBJ_BONUS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
