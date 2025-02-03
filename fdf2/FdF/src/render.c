/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:39:22 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/03 21:48:49 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define ISO_ANGLE M_PI / 6

void isometric(t_point point, t_isopoint *isopoint, t_map map)
{
    float	x_offset;
    float	y_offset;
	float	scale;
	float	scaleX;
	float	scaleY;

    scaleX = WIDTH / map.width;
	scaleY = HEIGHT / map.height * sin(ISO_ANGLE);
	scale = (scaleX < scaleY) ? scaleX : scaleY;
	printf("11111111111111111111: %f\n", scale);
	x_offset = (WIDTH - (map.width * scale)) / 2;
    y_offset = (HEIGHT - (map.height * sin(ISO_ANGLE) * scale)) / 2;
    isopoint->x = (point.x - point.y) * cos(ISO_ANGLE) * scale + x_offset;
    isopoint->y = (point.x + point.y) * sin(ISO_ANGLE) * scale - point.z * scale + y_offset;
}


void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*data;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
	data = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)data = color;
}

void	draw_line(t_img *img, int color, t_isopoint start, t_isopoint end)
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
	while (1)
	{
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

void	render_map(t_map *map, t_img *img)
{
	t_isopoint	current;
	t_isopoint	neighbor;
	int			row;
	int			col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			isometric(map->points[row][col], &current, *map);
			if (col < map->width - 1)
			{
				isometric(map->points[row][col + 1], &neighbor, *map);
				draw_line(img, map->points[row][col].color, current, neighbor);
			}
			if (row < map->height - 1)
			{
				isometric(map->points[row + 1][col], &neighbor, *map);
				draw_line(img, map->points[row][col].color, current, neighbor);
			}
			++col;
		}
		++row;
	}
}
