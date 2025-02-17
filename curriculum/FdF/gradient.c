/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:08:47 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 16:52:15 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	extract_colors(int *rgb, int color)
{
	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = color & 0xFF;
}

int	interpolate_color(int start_color, int end_color, float factor)
{
	int	rgb_start[3];
	int	rgb_end[3];
	int	r;
	int	g;
	int	b;

	extract_colors(rgb_start, start_color);
	extract_colors(rgb_end, end_color);
	r = rgb_start[0] + factor * (rgb_end[0] - rgb_start[0]);
	g = rgb_start[1] + factor * (rgb_end[1] - rgb_start[1]);
	b = rgb_start[2] + factor * (rgb_end[2] - rgb_start[2]);
	return ((r << 16) | (g << 8) | b);
}

int	generate_base_color(int seed)
{
	double	val;

	val = fabs(sin(seed * 12.9898)) * 16777215.0;
	return ((int)fmod(val, 16777215));
}

int	color_from_height(int z, int min_z, int max_z, int base_color)
{
	double	factor;
	int		red;
	int		green;
	int		blue;
	int		dark_base;

	dark_base = 0x36454F;
	if (max_z == min_z)
		factor = 1;
	else
		factor = (double)(z - min_z) / (max_z - min_z);
	red = ((dark_base >> 16) & 0xFF) + (((base_color >> 16) & 0xFF)
			- ((dark_base >> 16) & 0xFF)) * factor;
	green = ((dark_base >> 8) & 0xFF) + (((base_color >> 8) & 0xFF)
			- ((dark_base >> 8) & 0xFF)) * factor;
	blue = (dark_base & 0xFF) + (((base_color & 0xFF)
				- (dark_base & 0xFF)) * factor);
	return ((red << 16) | (green << 8) | blue);
}
