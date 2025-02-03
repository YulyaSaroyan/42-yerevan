# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 13:47:14 by ysaroyan          #+#    #+#              #
#    Updated: 2025/02/03 15:28:22 by ysaroyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fdf
CC          = cc
INCLUDE     = includes
LIBFT       = libft/
GNL 		= gnl/ 
MLX         = minilibx/
CFLAGS      = -Wall -Wextra -Werror -I$(INCLUDE) -I$(LIBFT) -I$(GNL)

LIBFT_A     = $(addprefix $(LIBFT), libft.a)
GNL_A     = $(addprefix $(GNL), libgnl.a)
MLX_A       = $(addprefix $(MLX), libmlx.a)
RM          = rm -rf

SRCS        = main.c src/parser.c src/render.c #src/rotate.c src/events.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A) $(GNL_A)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(GNL) -lgnl -L$(MLX) -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT)

$(GNL_A):
	@$(MAKE) -C $(GNL)

$(MLX_A):
	@$(MAKE) -C $(MLX)

%.o: %.c $(LIBFT_A) $(GNL_A)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

localclean:
	@$(RM) $(OBJS)

clean: localclean
	@$(MAKE) clean -C $(LIBFT)
	@$(MAKE) clean -C $(GNL)
	@$(MAKE) clean -C $(MLX)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(GNL)
	@$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re localclean bonus

