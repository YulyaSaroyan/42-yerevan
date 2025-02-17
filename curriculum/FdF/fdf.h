/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:10:04 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/13 14:45:23 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "struct.h"
# include "events.h"
# include "map_calculations.h"
# include "projections.h"
# include "draw.h"
# include "validate.h"
# include "utils.h"

# define ISO_ANGLE 0.523599
# define WIDTH 800
# define HEIGHT 600
# define BASE_SCALE 0.5
# define TITLE "FdF"

t_map	parse_map(const char *filename);
int		render_frame(void *param);
void	rotate_point(t_point *point, t_map *map);

#endif
