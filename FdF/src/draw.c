/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:55:57 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 21:16:58 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int interpolate_color(int start_color, int end_color, float factor)
{
    int r1 = (start_color >> 16) & 0xFF;
    int g1 = (start_color >> 8) & 0xFF;
    int b1 = start_color & 0xFF;

    int r2 = (end_color >> 16) & 0xFF;
    int g2 = (end_color >> 8) & 0xFF;
    int b2 = end_color & 0xFF;

    int r = r1 + factor * (r2 - r1);
    int g = g1 + factor * (g2 - g1);
    int b = b1 + factor * (b2 - b1);

    return (r << 16) | (g << 8) | b;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*data;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
	data = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)data = color;
}

void	draw_line(t_img *img, t_isopoint start, t_isopoint end)
{
	int dx;
	int dy;
	int sx;
	int sy;
	int err;
	int e2;

	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	sx = start.x < end.x ? 1 : -1;
	sy 	= start.y < end.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;

	int total_steps = dx > dy ? dx : dy;
    int step = 0;
	while (1)
	{
		float factor = total_steps ? (float)step / total_steps : 0;
        int color = interpolate_color(start.color, end.color, factor);
        put_pixel(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			start.y += sy;
		}
	}
}

void	clear_image(t_mlx mlx)
{
	int	x;
	int	y;

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
			put_pixel(mlx.img, x, y, 0x000000);
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img->img, 0, 0);
}
