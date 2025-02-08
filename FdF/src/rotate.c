/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:38:48 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 22:10:55 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void rotate_point(t_point *point, t_map map)
{
   	float temp_x, temp_y, temp_z;
    float cos_x = cosf(map.x_angle);
    float sin_x = sinf(map.x_angle);
    float cos_y = cosf(map.y_angle);
    float sin_y = sinf(map.y_angle);

    // Rotation around X-axis
    temp_y = point->y * cos_x - point->z * sin_x;
    temp_z = point->y * sin_x + point->z * cos_x;
    point->y = temp_y;
    point->z = temp_z;

    // Rotation around Y-axis
    temp_x = point->x * cos_y + point->z * sin_y;
    temp_z = -point->x * sin_y + point->z * cos_y;
    point->x = temp_x;
    point->z = temp_z;
}
*/

void rotate_point(t_point *point, t_map map)
{
    float temp_x, temp_y, temp_z;

    // Center coordinates for rotation
    float center_x = (float)(map.max_x_3d + map.min_x_3d) / 2.0f;
    float center_y = (float)(map.max_y_3d + map.min_y_3d) / 2.0f;
    float center_z = (float)(map.max_z_3d + map.min_z_3d) / 2.0f;

    // Translate point to the origin (center of the model)
    point->x -= center_x;
    point->y -= center_y;
    point->z -= center_z;

    // Rotation around X-axis
    float cos_x = cosf(map.x_angle);
    float sin_x = sinf(map.x_angle);
    temp_y = point->y * cos_x - point->z * sin_x;
    temp_z = point->y * sin_x + point->z * cos_x;
    point->y = temp_y;
    point->z = temp_z;

    // Rotation around Y-axis
    float cos_y = cosf(map.y_angle);
    float sin_y = sinf(map.y_angle);
    temp_x = point->x * cos_y + point->z * sin_y;
    temp_z = -point->x * sin_y + point->z * cos_y;
    point->x = temp_x;
    point->z = temp_z;
    
	// Rotate around Z-axis (optional)
    float cos_z = cosf(map.z_angle);
    float sin_z = sinf(map.z_angle);
    temp_x = point->x * cos_z - point->y * sin_z;
    temp_y = point->x * sin_z + point->y * cos_z;
    point->x = temp_x;
    point->y = temp_y;
    
	// Translate point back to its original position
    point->x += center_x;
    point->y += center_y;
    point->z += center_z;
}
/*
void rotate_point(t_point *point, t_map map)
{
    float temp_x, temp_y, temp_z;

    // Center coordinates for rotation
    float center_x = (map.max_x_3d + map.min_x_3d) / 2.0f;
    float center_y = (map.max_y_3d + map.min_y_3d) / 2.0f;
    float center_z = (map.max_z_3d + map.min_z_3d) / 2.0f;

    // Translate to origin
    point->x -= center_x;
    point->y -= center_y;
    point->z -= center_z;

    // Rotate around X-axis
    float cos_x = cosf(map.x_angle);
    float sin_x = sinf(map.x_angle);
    temp_y = point->y * cos_x - point->z * sin_x;
    temp_z = point->y * sin_x + point->z * cos_x;
    point->y = temp_y;
    point->z = temp_z;

    // Rotate around Y-axis
    float cos_y = cosf(map.y_angle);
    float sin_y = sinf(map.y_angle);
    temp_x = point->x * cos_y + point->z * sin_y;
    temp_z = -point->x * sin_y + point->z * cos_y;
    point->x = temp_x;
    point->z = temp_z;



    // Translate back to original position
    point->x += center_x;
    point->y += center_y;
    point->z += center_z;
}*/
