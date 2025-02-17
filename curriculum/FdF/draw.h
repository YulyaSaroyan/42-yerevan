/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:57:34 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 17:53:17 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

typedef struct s_draw
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		color;
	int		total_steps;
	int		step;
	float	factor;
}	t_draw;

void	draw_line(t_img *img, t_isopoint start, t_isopoint end);
int		interpolate_color(int start_color, int end_color, float factor);
void	clear_image(t_mlx mlx);
int		color_from_height(int z, int min_z, int max_z, int base_color);
int		generate_base_color(int seed);

#endif
