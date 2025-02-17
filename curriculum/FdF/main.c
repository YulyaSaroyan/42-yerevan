/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:22:10 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 21:27:57 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	register_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_MOUSECLICK, 1L << 2, handle_mouse_press, mlx);
	mlx_hook(mlx->win, ON_MOUSEUP, 1L << 3, handle_mouse_release, mlx);
	mlx_hook(mlx->win, ON_MOUSEMOVE, 1L << 13, handle_mouse_move, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, close_window, mlx);
	mlx_key_hook(mlx->win, handle_key, mlx);
	mlx_loop_hook(mlx->ptr, render_frame, mlx);
}

static void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		throw_error("Failed to initialize mlx.");
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx->win)
		throw_error("Failed to create window.");
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;
	char	*filename;

	if (argc != 2)
		throw_error("Wrong number of arguments");
	filename = argv[1];
	validate_file_extension(filename);
	map = parse_map(filename);
	init_mlx(&mlx);
	img.img = mlx_new_image(mlx.ptr, WIDTH, HEIGHT);
	if (!img.img)
		throw_error("Failed to create image");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mlx.map = &map;
	mlx.img = &img;
	register_hooks(&mlx);
	if (mlx.ptr != NULL)
		mlx_loop(mlx.ptr);
	return (0);
}
