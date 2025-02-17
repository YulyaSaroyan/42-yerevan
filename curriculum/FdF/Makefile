# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 13:47:14 by ysaroyan          #+#    #+#              #
#    Updated: 2025/02/12 20:25:47 by ysaroyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fdf
CC          = cc
LIBFT       = libft/
CFLAGS      = -Wall -Wextra -Werror -I$(LIBFT)

LIBFT_A     = $(addprefix $(LIBFT), libft.a)
RM          = rm -rf

SRCS        = main.c parser.c render.c map.c projections.c draw.c rotate.c validate.c gradient.c keyboard.c mouse.c utils.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

%.o: %.c $(LIBFT_A)
	@$(CC) $(CFLAGS) -c $< -o $@

localclean:
	@$(RM) $(OBJS)

clean: localclean
	@$(MAKE) clean -C $(LIBFT)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re localclean bonus

