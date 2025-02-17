/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:26:13 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 20:56:08 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_bounds(t_map *map)
{
	t_isopoint	current_2d;
	t_point		current_3d;
	int			row;
	int			col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			current_3d = map->points[row][col];
			if (current_3d.z < map->min_z)
				map->min_z = current_3d.z;
			if (current_3d.z > map->max_z)
				map->max_z = current_3d.z;
			isometric(current_3d, &current_2d, map);
			calculate_iso_bounds(map, current_2d);
			++col;
		}
		++row;
	}
}

void	calculate_offsets(t_map *map)
{
	if (map->isometric)
	{
		map->x_offset = (WIDTH - (map->max_x_2d - map->min_x_2d))
			/ 2 - map->min_x_2d;
		map->y_offset = (HEIGHT - (map->max_y_2d - map->min_y_2d))
			/ 2 - map->min_y_2d;
	}
	else
	{
		map->x_offset = (WIDTH - map->width * map->zoom) / 2;
		map->y_offset = (HEIGHT - map->height * map->zoom) / 2;
	}
}

void	calculate_scale(t_map *map)
{
	float	scale;
	float	scale_x;
	float	scale_y;
	float	actual_width;
	float	actual_height;

	if (map->isometric)
	{
		actual_width = map->width + map->height * sin(ISO_ANGLE);
		actual_height = map->height * cos(ISO_ANGLE);
		scale_x = WIDTH / actual_width;
		scale_y = HEIGHT / actual_height;
	}
	else
	{
		scale_x = WIDTH / map->width;
		scale_y = HEIGHT / map->height;
	}
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	map->zoom *= scale;
}

void	reset_map(t_map *map)
{
	map->zoom = 0.5;
	calculate_scale(map);
	calculate_offsets(map);
	map->x_angle = 0;
	map->y_angle = 0;
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->min_x_2d = INT_MAX;
	map->max_x_2d = INT_MIN;
	map->min_y_2d = INT_MAX;
	map->max_y_2d = INT_MIN;
	map->max_z = INT_MIN;
	map->min_z = INT_MAX;
	map->render = 1;
	map->zoom = 0.5;
	map->x_angle = 0;
	map->y_angle = 0;
	map->isometric = 1;
	map->left_mouse_pressed = 0;
	map->right_mouse_pressed = 0;
	map->last_x = 0;
	map->last_y = 0;
}
