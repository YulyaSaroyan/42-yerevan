/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:10:04 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 22:27:55 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include "events.h"
# include "get_next_line.h"

# define ISO_ANGLE M_PI / 6
# define WIDTH 800
# define HEIGHT 600
# define BASE_SCALE 0.5
# define TITLE "FdF"

typedef struct s_point
{
    int	x;
    int	y;
    int	z;
	int	color;
}	t_point;

typedef struct s_isopoint
{
	int	x;
	int	y;
    int	color;
}	t_isopoint;

typedef struct s_map
{
    int     width;
    int     height;
    t_point **points; // 2D array of points
    int     min_x_2d;
    int     max_x_2d;
    int     min_y_2d;
    int     max_y_2d;
	int		min_x_3d;
	int		max_x_3d;
	int		min_y_3d;
	int		max_y_3d;
	int		min_z_3d;
	int		max_z_3d;
    float   x_offset;
    float   y_offset;
	float	x_angle;
	float	y_angle;
	float	z_angle;
	float	x_center;
	float	y_center;
	float	z_center;
	float	zoom;
	int		render;
	int		isometric;
	int		left_mouse_pressed;
	int		right_mouse_pressed;
	int		last_x;
	int		last_y;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
    void	*ptr;
    void	*win;
	t_map	*map;
	t_img	*img;
}	t_mlx;

# include "map_calculations.h"
# include "projections.h"
# include "draw.h"
# include "validate.h"

t_map	parse_map(const char *filename);
void	render_map(t_map *map, t_img *img);
void	rotate_point(t_point *orig_point, t_map map);
void	throw_error(char *message);

#endif
