/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:38:48 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 21:17:41 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(t_point *point, t_map *map)
{
	float	cos_x;
	float	sin_x;
	float	temp_y;
	float	temp_z;

	sin_x = sinf((float)map->x_angle);
	cos_x = cosf((float)map->x_angle);
	temp_y = point->y * cos_x - point->z * sin_x;
	temp_z = point->y * sin_x + point->z * cos_x;
	point->y = temp_y;
	point->z = temp_z;
}

static void	rotate_y(t_point *point, t_map *map)
{
	float	cos_y;
	float	sin_y;
	float	temp_x;
	float	temp_z;

	sin_y = sinf((float)map->y_angle);
	cos_y = cosf((float)map->y_angle);
	temp_x = point->x * cos_y + point->z * sin_y;
	temp_z = -point->x * sin_y + point->z * cos_y;
	point->x = temp_x;
	point->z = temp_z;
}

void	rotate_point(t_point *point, t_map *map)
{
	point->x -= map->width / 2;
	point->y -= map->height / 2;
	point->z -= (map->max_z + map->min_z) / 2;
	rotate_y(point, map);
	rotate_x(point, map);
	point->x += map->width / 2;
	point->y += map->height / 2;
	point->z += (map->max_z + map->min_z) / 2;
}
