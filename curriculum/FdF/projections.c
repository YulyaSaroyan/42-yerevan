/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:43:22 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 21:18:17 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_point point, t_isopoint *isopoint, t_map *map)
{
	rotate_point(&point, map);
	isopoint->x = (point.x - point.y) * cos(ISO_ANGLE) * map->zoom;
	isopoint->y = (point.x + point.y) * sin(ISO_ANGLE)
		* map->zoom - point.z * map->zoom;
	isopoint->color = point.color;
}

void	parallel(t_point point, t_isopoint *isopoint, t_map *map)
{
	rotate_point(&point, map);
	isopoint->x = point.x * map->zoom;
	isopoint->y = point.y * map->zoom;
	isopoint->color = point.color;
}
