/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:40:03 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/12 15:44:04 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_width(char *line)
{
	int		count;
	char	**columns;
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	columns = ft_split(line, ' ');
	count = -1;
	while (columns[++count])
		free(columns[count]);
	free(columns);
	return (count);
}

static void	set_map_size(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		throw_error("Empty file.");
	while (line)
	{
		if (!map->width)
			map->width = count_width(line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	handle_cols(t_map *map, char **columns, int row, char *line)
{
	char	**color_parts;
	char	*z;	
	int		num;
	int		col;	

	col = -1;
	while (++col < map->width)
	{
		map->points[row][col].color = 0;
		z = columns[col];
		if (ft_strchr(columns[col], ','))
		{
			color_parts = ft_split(columns[col], ',');
			z = color_parts[0];
			validate_color(color_parts, columns, line);
			map->points[row][col].color = ft_hex_to_int(color_parts[1]);
			free(color_parts);
		}
		num = ft_atoi(z);
		validate_number(z, num, columns, line);
		map->points[row][col].x = col;
		map->points[row][col].y = row;
		map->points[row][col].z = num;
		free(columns[col]);
	}
}

static void	fill_points(int fd, t_map *map)
{
	char	*line;
	int		row;
	char	**columns;

	line = get_next_line(fd);
	row = 0;
	while (line)
	{
		validate_width(count_width(line), map->width, line);
		columns = ft_split(line, ' ');
		handle_cols(map, columns, row, line);
		free(columns);
		free(line);
		++row;
		line = get_next_line(fd);
	}
}

t_map	parse_map(const char *filename)
{
	int		fd;
	t_map	map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		throw_error("Failed to open file.");
	init_map(&map);
	set_map_size(&map, fd);
	close(fd);
	allocate_points(&map);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		throw_error("Failed to open file");
	fill_points(fd, &map);
	calculate_scale(&map);
	calculate_bounds(&map);
	calculate_offsets(&map);
	close(fd);
	return (map);
}
