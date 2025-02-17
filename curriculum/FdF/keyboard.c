/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:54 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 21:16:02 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_translate(int key, t_mlx *mlx)
{
	if (key == W_KEY)
		mlx->map->y_offset -= 10;
	else if (key == S_KEY)
		mlx->map->y_offset += 10;
	else if (key == A_KEY)
		mlx->map->x_offset -= 10;
	else if (key == D_KEY)
		mlx->map->x_offset += 10;
}

static void	handle_rotate(int key, t_mlx *mlx)
{
	if (key == UP_KEY)
		mlx->map->x_angle += M_PI / 18;
	else if (key == DOWN_KEY)
		mlx->map->x_angle -= M_PI / 18;
	else if (key == LEFT_KEY)
		mlx->map->y_angle -= M_PI / 18;
	else if (key == RIGHT_KEY)
		mlx->map->y_angle += M_PI / 18;
}

static void	handle_zoom(int key, t_mlx *mlx)
{
	if (key == PLUS_KEY)
	{
		if (mlx->map->zoom < 30.0)
			mlx->map->zoom = mlx->map->zoom * 1.1;
		else
			mlx->map->zoom = 30.0;
	}
	else if (key == MINUS_KEY)
	{
		if (mlx->map->zoom > 0.1)
			mlx->map->zoom = mlx->map->zoom * 0.91;
		else
			mlx->map->zoom = 0.1;
	}
}

static void	handle_projection(int key, t_mlx *mlx)
{
	if (key == ONE_KEY)
	{
		mlx->map->isometric = 1;
		reset_map(mlx->map);
	}
	else if (key == TWO_KEY)
	{
		mlx->map->isometric = 0;
		reset_map(mlx->map);
	}
}

int	handle_key(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (key == ESC_KEY)
	{
		close_window(param);
		return (0);
	}
	handle_translate(key, mlx);
	handle_rotate(key, mlx);
	handle_zoom(key, mlx);
	handle_projection(key, mlx);
	mlx->map->render = 1;
	return (0);
}
