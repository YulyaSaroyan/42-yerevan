/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:39:22 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 21:35:51 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	render_map(t_map *map, t_img *img)
{
    t_isopoint current, neighbor;
    int row, col;

    for (row = 0; row < map->height; row++)
    {
        for (col = 0; col < map->width; col++)
        {
			if (map ->isometric)
				isometric(map->points[row][col], &current, *map);
			else
				parallel(map->points[row][col], &current, *map);
			current.x += map->x_offset;
            current.y += map->y_offset;
            if (col < map->width - 1)
            {
				if (map->isometric)
                	isometric(map->points[row][col + 1], &neighbor, *map);
				else
					parallel(map->points[row][col + 1], &neighbor, *map);
                neighbor.x += map->x_offset;
                neighbor.y += map->y_offset;
                draw_line(img, current, neighbor);
            }
            if (row < map->height - 1)
            {
				if (map->isometric)
                	isometric(map->points[row + 1][col], &neighbor, *map);
				else
					parallel(map->points[row + 1][col], &neighbor, *map);
                neighbor.x += map->x_offset;
                neighbor.y += map->y_offset;
                draw_line(img, current, neighbor);
            }
        }
    }
}
