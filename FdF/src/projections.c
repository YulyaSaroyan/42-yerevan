/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:43:22 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 22:26:25 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric(t_point point, t_isopoint *isopoint, t_map map)
{
	float	scale;
	float	scaleX;
	float	scaleY;
	float	actual_width;
	float	actual_height;

	rotate_point(&point, map);
	actual_width = map.width + map.height * sin(ISO_ANGLE);
	actual_height = map.height * cos(ISO_ANGLE);
	scaleX = WIDTH / actual_width;
	scaleY = HEIGHT / actual_height;
	scale = (scaleX < scaleY) ? scaleX : scaleY;
	scale *= map.zoom;
	isopoint->x = (point.x - point.y) * cos(ISO_ANGLE) * scale;
    isopoint->y = (point.x + point.y) * sin(ISO_ANGLE) * scale - point.z * scale;
	isopoint->color = point.color;
}


void parallel(t_point point, t_isopoint *isopoint, t_map map)
{
    float scaleX, scaleY;

    rotate_point(&point, map);
    scaleX = WIDTH / map.width;
    scaleY = HEIGHT / map.height;
    float scale = (scaleX < scaleY) ? scaleX : scaleY;
    scale *= map.zoom;
    isopoint->x = point.x * scale;
    isopoint->y = point.y * scale;
    isopoint->color = point.color;
}

