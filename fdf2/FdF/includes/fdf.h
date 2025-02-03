/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:10:04 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/03 18:49:26 by ysaroyan         ###   ########.fr       */
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
# include "libft.h"
# include "get_next_line.h"
# include "events.h"

# define WIDTH 800
# define HEIGHT 600
# define BASE_SCALE 1
# define MIN_SCALE 0.1
# define MAX_SCALE 2.0
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
}	t_isopoint;

typedef struct s_map
{
    int width;
    int height;
    t_point **points; // 2D array of points
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
    void *ptr;
    void *win;
    double angle_x;
    double angle_y;
    double angle_z;
	t_map *map;
}	t_mlx;

void	parse_map(const char *filename, t_map *map);
void	render_map(t_map *map, t_img *img);
void	rotate_point(t_point *point, double angle_x, double angle_y, double angle_z);

#endif
