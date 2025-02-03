/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:12:58 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/01/30 18:26:39 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_window(void *param)
{
    t_mlx *mlx = (t_mlx *)param;

    mlx_destroy_window(mlx->ptr, mlx->win);
    exit(0);
    return (0);
}

int handle_key(int key, void *param)
{
   
	return (0);
}

int handle_mouse(int button,int x,int y,void *param)
{
	return (0);
}
