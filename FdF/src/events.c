/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:55:36 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 22:28:21 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(0);
	return (0);
}

int	handle_key(int key, void *param)
{
	t_mlx	*mlx;

	mlx= (t_mlx *)param;
    if (key == PLUS_KEY)
		mlx->map->zoom = (mlx->map->zoom < 30.0) ? mlx->map->zoom * 1.1 : 30.0;
	else if (key == MINUS_KEY)
    	mlx->map->zoom = (mlx->map->zoom > 0.1) ? mlx->map->zoom * 0.91 : 0.1;
    else if (key == UP_KEY)
        mlx->map->x_angle += M_PI / 18;
    else if (key == DOWN_KEY)
        mlx->map->x_angle -= M_PI / 18;
    else if (key == LEFT_KEY)
        mlx->map->y_angle -= M_PI / 18;
    else if (key == RIGHT_KEY)
        mlx->map->y_angle += M_PI / 18;
    else if (key == W_KEY)
        mlx->map->y_offset -= 10;
    else if (key == S_KEY)
        mlx->map->y_offset += 10;
    else if (key == A_KEY)
        mlx->map->x_offset -= 10;
    else if (key == D_KEY)
        mlx->map->x_offset += 10;
	else if (key == ESC_KEY)
		close_window(param);
	else if (key == ONE_KEY)
	{
		mlx->map->isometric = 1;
		reset_map(mlx->map);
	}
	else if (key == TWO_KEY)
	{
		mlx->map->isometric = 0;
		reset_map(mlx->map);
	}
	else
		return (0);
	mlx->map->render = 1;
	return (0);
}

int	render_frame(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx->map->render)
		return (0);
	clear_image(*mlx);
	render_map(mlx->map, mlx->img);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->img, 0, 0);
	mlx->map->render = 0;
	return (0);
}

int handle_mouse_press(int button, int x, int y, void *param)
{
    t_mlx *mlx = (t_mlx *)param;

    if (button == LEFT_BUTTON)
        mlx->map->left_mouse_pressed = 1;
    if (button == RIGHT_BUTTON)
        mlx->map->right_mouse_pressed = 1;

    mlx->map->last_x = x;
    mlx->map->last_y = y;

    if (button == SCROLL_UP)
        mlx->map->zoom = (mlx->map->zoom < 30.0) ? mlx->map->zoom * 1.1 : 30.0;
    else if (button == SCROLL_DOWN)
        mlx->map->zoom = (mlx->map->zoom > 0.1) ? mlx->map->zoom * 0.91 : 0.1;

    mlx->map->render = 1;
    return (0);
}

int handle_mouse_release(int button, int x, int y, void *param)
{
    t_mlx *mlx = (t_mlx *)param;
	(void)x;
	(void)y;
    if (button == LEFT_BUTTON)
        mlx->map->left_mouse_pressed = 0;
    if (button == RIGHT_BUTTON)
        mlx->map->right_mouse_pressed = 0;
    return (0);
}

int handle_mouse_move(int x, int y, void *param)
{
    t_mlx *mlx = (t_mlx *)param;

    int dx = x - mlx->map->last_x;
    int dy = y - mlx->map->last_y;

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

