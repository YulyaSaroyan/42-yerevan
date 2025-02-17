# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/19 16:51:21 by ysaroyan          #+#    #+#              #
#    Updated: 2025/02/13 14:25:28 by ysaroyan         ###   ########.fr        #
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
	   src/ft_putnbr_base_helper.c src/ft_putnbr_helper.c src/ft_putnchar.c \
	   src/ft_numlen_base.c src/ft_decimal_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = libft.a

INCLUDES = -I includes -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $@ $(OBJS)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR) 
	cp $(LIBFT_DIR)/$@ $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME)
	@echo "nothing"

clean: 
	$(RM) $(OBJS) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus

