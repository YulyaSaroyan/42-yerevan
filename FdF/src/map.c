/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:26:13 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 22:27:08 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void calculate_bounds(t_map *map)
{
	t_isopoint	current_2d;
	t_point		current_3d;
	int row, col;

	for (row = 0; row < map->height; row++)
	{
		for (col = 0; col < map->width; col++)
		{
			current_3d = map->points[row][col]; 
			//if (current_3d.x < map->min_x_3d) map->min_x_3d = current_3d.x;
			//if (current_3d.x > map->max_x_3d) map->max_x_3d = current_3d.x;
			if (current_3d.z < map->min_z_3d) map->min_z_3d = current_3d.z;
			if (current_3d.z > map->max_z_3d) map->max_z_3d = current_3d.z;
			isometric(current_3d, &current_2d, *map);
			if (current_2d.x < map->min_x_2d) map->min_x_2d = current_2d.x;
			if (current_2d.x > map->max_x_2d) map->max_x_2d = current_2d.x;
			if (current_2d.y < map->min_y_2d) map->min_y_2d = current_2d.y;
			if (current_2d.y > map->max_y_2d) map->max_y_2d = current_2d.y;
		}
	}
	map->min_x_3d = map->width;
	map->min_y_3d = map->height;
}

void	calculate_offsets(t_map *map)
{
	if (map->isometric)
	{	
		calculate_bounds(map);
		map->x_offset += (WIDTH - (map->max_x_2d - map->min_x_2d)) / 2 - map->min_x_2d;
    	map->y_offset += (HEIGHT - (map->max_y_2d - map->min_y_2d)) / 2 - map->min_y_2d;
	}
	else
	{
		map->x_offset += (WIDTH - map->width) / 2;
    	map->y_offset += (HEIGHT - map->height) / 2;
	}
}

void	reset_map(t_map *map)
{
	map->zoom = 0.5;
	map->x_angle = 0;
	map->y_angle = 0;
	if (map->isometric)
	{
		map->x_offset = (WIDTH - (map->max_x_2d - map->min_x_2d)) / 2 - map->min_x_2d;
    	map->y_offset = (HEIGHT - (map->max_y_2d - map->min_y_2d)) / 2 - map->min_y_2d;
	}
	else
	{
		map->x_offset = (WIDTH / 2) - (map->width / 4);
		map->y_offset = (HEIGHT / 2) - (map->height / 4);

	}
}

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->min_x_2d = INT_MAX;
	map->max_x_2d = INT_MIN;
	map->min_y_2d = INT_MAX;
	map->max_y_2d = INT_MIN;
	map->min_z_3d = INT_MAX;
	map->max_z_3d = INT_MIN;
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
