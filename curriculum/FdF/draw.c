/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:55:57 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 20:08:40 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*data;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	data = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)data = color;
}

static t_draw	init_draw(t_isopoint start, t_isopoint end)
{
	t_draw	draw;

	draw.dx = abs(end.x - start.x);
	draw.dy = abs(end.y - start.y);
	calculate_step_direction(start.x, end.x, &draw.sx);
	calculate_step_direction(start.y, end.y, &draw.sy);
	draw.err = calculate_error(draw.dx, draw.dy);
	if (draw.dx > draw.dy)
		draw.total_steps = draw.dx;
	else
		draw.total_steps = draw.dy;
	draw.step = 0;
	return (draw);
}

static int	get_draw_color(t_draw draw, int start_col, int end_col)
{
	int	color;

	if (draw.total_steps)
		draw.factor = (float)draw.step / draw.total_steps;
	else
		draw.factor = 0;
	color = interpolate_color(start_col, end_col, draw.factor);
	return (color);
}

void	draw_line(t_img *img, t_isopoint start, t_isopoint end)
{
	t_draw	draw;

	draw = init_draw(start, end);
	while (1)
	{
		draw.color = get_draw_color(draw, start.color, end.color);
		put_pixel(img, start.x, start.y, draw.color);
		if (start.x == end.x && start.y == end.y)
			break ;
		draw.e2 = draw.err;
		if (draw.e2 > -draw.dx)
		{
			draw.err -= draw.dy;
			start.x += draw.sx;
		}
		if (draw.e2 < draw.dy)
		{
			draw.err += draw.dx;
			start.y += draw.sy;
		}
		draw.step++;
	}
}

void	clear_image(t_mlx mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(mlx.img, x, y, 0x000000);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img->img, 0, 0);
}
