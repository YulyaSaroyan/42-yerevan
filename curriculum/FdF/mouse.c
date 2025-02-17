/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:55:36 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 20:03:07 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
	return (0);
}

int	handle_mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (button == LEFT_BUTTON)
		mlx->map->left_mouse_pressed = 1;
	if (button == RIGHT_BUTTON)
		mlx->map->right_mouse_pressed = 1;
	mlx->map->last_x = x;
	mlx->map->last_y = y;
	if (button == SCROLL_UP)
	{
		if (mlx->map->zoom < 30.0)
			mlx->map->zoom = mlx->map->zoom * 1.1;
		else
			mlx->map->zoom = 30.0;
	}
	else if (button == SCROLL_DOWN)
	{
		if (mlx->map->zoom > 0.1)
			mlx->map->zoom = mlx->map->zoom * 0.91;
		else
			mlx->map->zoom = 0.1;
	}
	mlx->map->render = 1;
	return (0);
}

int	handle_mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	(void)x;
	(void)y;
	if (button == LEFT_BUTTON)
		mlx->map->left_mouse_pressed = 0;
	if (button == RIGHT_BUTTON)
		mlx->map->right_mouse_pressed = 0;
	return (0);
}

int	handle_mouse_move(int x, int y, void *param)
{
	t_mlx	*mlx;
	int		dx;
	int		dy;

	mlx = (t_mlx *)param;
	dx = x - mlx->map->last_x;
	dy = y - mlx->map->last_y;
	if (mlx->map->left_mouse_pressed)
	{
		mlx->map->x_offset += dx;
		mlx->map->y_offset += dy;
	}
	else if (mlx->map->right_mouse_pressed)
	{
		mlx->map->x_angle += dy * 0.01;
		mlx->map->y_angle += dx * 0.01;
	}
	mlx->map->last_x = x;
	mlx->map->last_y = y;
	mlx->map->render = 1;
	return (0);
}
