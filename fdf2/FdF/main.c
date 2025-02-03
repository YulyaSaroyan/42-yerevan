/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:22:10 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/03 16:18:54 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;

	if (argc != 2)
		return (1);

	parse_map(argv[1], &map);
	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (1);
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx.win)
		return (1);
	img.img = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx.map = &map;
	render_map(&map, &img);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.ptr);
    return (0);
}

