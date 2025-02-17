# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 16:51:21 by ysaroyan          #+#    #+#              #
#    Updated: 2025/01/21 17:17:10 by ysaroyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = src/ft_printf.c src/ft_handle_char.c src/ft_handle_percent.c \
	   src/ft_handle_unsigned.c src/ft_handle_decimal.c src/ft_handle_pointer.c \
	   src/ft_handle_hex.c src/ft_handle_string.c src/ft_putstr_helper.c \
	   src/ft_putnbr_base_helper.c src/ft_putnbr_helper.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)ft_strlen.o

INCLUDES = -I includes -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

