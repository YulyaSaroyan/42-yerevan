# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 14:04:39 by ysaroyan          #+#    #+#              #
#    Updated: 2025/02/17 16:03:49 by ysaroyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
LIBFT = libft/
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT) #-fsanitize=address

LIBFT_A = $(addprefix $(LIBFT), libft.a)
RM = rm -rf

SRCS = main.c pipex.c execute.c execute_utils.c heredoc.c parsing.c parsing_utils.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

%.o: %.c $(LIBFT_A)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
