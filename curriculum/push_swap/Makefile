# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 15:39:53 by ysaroyan          #+#    #+#              #
#    Updated: 2025/03/03 13:27:40 by ysaroyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
LIBFT = libft/
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT) -fsanitize=address
LIBFT_A = $(addprefix $(LIBFT), libft.a)

SRCS = main.c validate.c validate_utils.c list.c array.c operations.c sort.c utils.c
BONUS_SRC = checker.c operations.c list.c array.c utils.c validate.c validate_utils.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME):  $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) -lft -L$(LIBFT) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) -lft -L$(LIBFT) $^ -o $(BONUS_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus
