# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:03:35 by juportie          #+#    #+#              #
#    Updated: 2024/11/12 17:01:48 by juportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra

NAME=libft.a

HEADER=libft.h

SRC= ft_isalpha.c \
     ft_isdigit.c \
     ft_isalnum.c \
     ft_isascii.c \
     ft_isprint.c \
     ft_strlen.c \
     ft_memset.c \
     ft_bzero.c \
     ft_memcpy.c \
     ft_memmove.c \
     ft_strlcpy.c \
     ft_strlcat.c \
     ft_toupper.c \
     ft_tolower.c \
     ft_strchr.c \
     ft_strrchr.c \
     ft_strncmp.c \
     ft_memchr.c \
     ft_memcmp.c \
     ft_strnstr.c \
     ft_atoi.c \
     ft_calloc.c \
     ft_strdup.c \
     ft_substr.c \
     ft_strjoin.c \
     ft_strtrim.c \
     ft_split.c \
     ft_itoa.c \
     ft_strmapi.c \
     ft_striteri.c \
     ft_putchar_fd.c \
     ft_putstr_fd.c \
     ft_putendl_fd.c \
     ft_putnbr_fd.c

OBJ= $(SRC:%.c=%.o)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	ar r $(NAME) $^

.PHONY: clean

clean:
	rm *.o *.a
