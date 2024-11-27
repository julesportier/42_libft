# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 10:35:01 by juportie          #+#    #+#              #
#    Updated: 2024/11/25 11:09:53 by juportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a

HEADER := ft_printf.h

SRC := ft_printf.c \
      ft_putnumbers_fd.c \
      ft_puttext_fd.c


OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rs $(NAME) $?

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
