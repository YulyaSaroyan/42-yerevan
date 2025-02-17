/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:39:22 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 20:55:09 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	project_point(t_map *map, t_point point, t_isopoint *neighbor)
{
	if (map->isometric)
		isometric(point, neighbor, map);
	else
		parallel(point, neighbor, map);
	neighbor->x += map->x_offset;
	neighbor->y += map->y_offset;
}

static void	render_line(t_mlx *mlx, t_point point,
		t_isopoint current, int base_color)
{
	t_isopoint	neighbor;

	project_point(mlx->map, point, &neighbor);
	if (point.color == 0)
		point.color = color_from_height(point.z, mlx->map->min_z,
				mlx->map->max_z, base_color);
	draw_line(mlx->img, current, neighbor);
}

static void	render_neighbor_lines(t_mlx *mlx, int col, int row, int base_color)
{
	t_isopoint	current;

	project_point(mlx->map, mlx->map->points[row][col], &current);
	if (col < mlx->map->width - 1)
		render_line(mlx, mlx->map->points[row][col + 1], current, base_color);
	if (row < mlx->map->height - 1)
		render_line(mlx, mlx->map->points[row + 1][col], current, base_color);
}

static void	render_map(t_mlx *mlx)
{
	int			row;
	int			col;
	int			base_color;

	row = 0;
	base_color = generate_base_color(mlx->map->width * mlx->map->height);
	while (row < mlx->map->height)
	{
		col = 0;
		while (col < mlx->map->width)
		{
			if (mlx->map->points[row][col].color == 0)
				mlx->map->points[row][col].color
					= color_from_height(mlx->map->points[row][col].z,
						mlx->map->min_z, mlx->map->max_z, base_color);
			render_neighbor_lines(mlx, col, row, base_color);
			++col;
		}
		++row;
	}
}

int	render_frame(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx->map->render)
		return (0);
	clear_image(*mlx);
	render_map(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img->img, 0, 0);
	mlx->map->render = 0;
	return (0);
}
