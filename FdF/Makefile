# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 13:47:14 by ysaroyan          #+#    #+#              #
#    Updated: 2025/02/07 18:41:22 by ysaroyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fdf
CC          = cc
INCLUDE     = includes
LIBFT       = libft/
MLX         = minilibx/
CFLAGS      = -Wall -Wextra -Werror -I$(INCLUDE) -I$(LIBFT)

LIBFT_A     = $(addprefix $(LIBFT), libft.a)
MLX_A       = $(addprefix $(MLX), libmlx.a)
RM          = rm -rf

SRCS        = main.c src/parser.c src/render.c src/events.c src/map.c src/projections.c src/draw.c src/rotate.c src/validate.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(MLX) -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

$(MLX_A):
	@$(MAKE) -C $(MLX)

%.o: %.c $(LIBFT_A)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

localclean:
	@$(RM) $(OBJS)

clean: localclean
	@$(MAKE) clean -C $(LIBFT)
	@$(MAKE) clean -C $(MLX)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re localclean bonus

