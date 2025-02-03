/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:38:48 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/27 15:38:49 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotate_point(t_point *point, double angle_x, double angle_y, double angle_z)
{
    double prev_x, prev_y, prev_z;

    // Rotate around X-axis
    prev_y = point->y;
    prev_z = point->z;
    point->y = prev_y * cos(angle_x) - prev_z * sin(angle_x);
    point->z = prev_y * sin(angle_x) + prev_z * cos(angle_x);

    // Rotate around Y-axis
    prev_x = point->x;
    prev_z = point->z;
    point->x = prev_x * cos(angle_y) + prev_z * sin(angle_y);
    point->z = -prev_x * sin(angle_y) + prev_z * cos(angle_y);

    // Rotate around Z-axis
    prev_x = point->x;
    prev_y = point->y;
    point->x = prev_x * cos(angle_z) - prev_y * sin(angle_z);
    point->y = prev_x * sin(angle_z) + prev_y * cos(angle_z);
}
