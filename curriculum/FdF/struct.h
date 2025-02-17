/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:26:29 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 21:15:55 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int		width;
	int		height;
	t_point	**points;
	int		min_x_2d;
	int		max_x_2d;
	int		min_y_2d;
	int		max_y_2d;
	int		max_z;
	int		min_z;
	float	x_offset;
	float	y_offset;
	double	x_angle;
	double	y_angle;
	double	zoom;
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

#endif
