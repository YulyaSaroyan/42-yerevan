/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:09:22 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 18:35:24 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	throw_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	allocate_points(t_map *map)
{
	int	i;

	i = -1;
	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		throw_error("Failed to allocate.");
	i = -1;
	while (++i < map->height)
	{
		map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
		if (!map->points[i])
			throw_error("Failed to allocate.");
	}
}

int	calculate_error(int dx, int dy)
{
	int	result;

	if (dx > dy)
		result = dx;
	else
		result = -dy;
	return (result / 2);
}

void	calculate_step_direction(int start, int end, int *step)
{
	if (start < end)
		*step = 1;
	else
		*step = -1;
}

void	calculate_iso_bounds(t_map *map, t_isopoint point)
{
	if (point.x < map->min_x_2d)
		map->min_x_2d = point.x;
	if (point.x > map->max_x_2d)
		map->max_x_2d = point.x;
	if (point.y < map->min_y_2d)
		map->min_y_2d = point.y;
	if (point.y > map->max_y_2d)
		map->max_y_2d = point.y;
}
