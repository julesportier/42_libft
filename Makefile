# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juportie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:03:35 by juportie          #+#    #+#              #
#    Updated: 2025/05/07 09:57:48 by juportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra
CFLAGS_DB := -Wall -Werror -Wextra -g3

NAME := libft.a

SRC_DIR := src

vpath %.h $(SRC_DIR)
HEADER := libft.h \
	ft_printf.h \
	get_next_line.h

vpath %.c $(SRC_DIR)
SRC :=	ft_isalpha.c \
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
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ftpf_putnumbers_fd.c \
	ftpf_puttext_fd.c \
	ft_printf.c \
	get_next_line_utils.c \
	get_next_line.c \
	ft_ismuloverflow.c \
	ft_atoui_base.c \
	ft_atoi_flag.c \
	ft_atoi_sat.c \
	ft_uhextoui.c \
	ft_dlstnew.c \
	ft_dlstlast.c \
	ft_dlsthead.c \
	ft_dlstadd_back.c \
	ft_dlstadd_front.c \
	ft_dlstsize.c \
	ft_dlstclear.c \
	ft_dlstremove.c \
	ft_dlstsplit.c \
	ft_cdlstadd_back.c \
	ft_cdlstadd_front.c \
	ft_cdlstclear.c \
	ft_cdlstsize.c \
	ft_isdigitstr.c \
	ft_issdigitstr.c \
	ft_isequalstr.c \
	ft_sqrt_floor.c

OBJ_DIR := build
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


all: $(OBJ_DIR) $(NAME)
dbg: CFLAGS := $(CFLAGS_DB)
dbg: all
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(NAME): $(OBJ)
	ar rs $(NAME) $?

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all dbg clean fclean re
