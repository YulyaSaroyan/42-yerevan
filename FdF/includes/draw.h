/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:57:34 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/05 14:53:50 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	put_pixel(t_img *img, int x, int y, int color);
void	draw_line(t_img *img,  t_isopoint start, t_isopoint end);
void	clear_image(t_mlx mlx);

#endif
