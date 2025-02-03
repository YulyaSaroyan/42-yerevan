/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:40:03 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/03 17:34:24 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_map(t_map *map)
{	
	map->width = 0;
	map->height = 0;
}

static int	count_width(char *line)
{
	int		count;
	char 	**columns;

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
	while (line)
	{
		if (!map->width)
			map->width = count_width(line);
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	fill_points(int fd, t_map *map)
{
	char	*line;
	int		row;
	int		col;
	char	**columns;

	line = get_next_line(fd);
	row = 0;
	while (line)
	{
		columns = ft_split(line, ' ');
		col = -1;
		while (++col < map->width)
		{
			map->points[row][col].x = col;
			map->points[row][col].y = row;
			map->points[row][col].z = ft_atoi(columns[col]);
			map->points[row][col].color = 0xFFFFFF;
			if (ft_strchr(columns[col], ','))
				map->points[row][col].color = ft_hex_to_int(ft_split(columns[col], ',')[1]);
			free(columns[col]);
		}
		free(columns);
		free(line);
		++row;
		line = get_next_line(fd);
	}
}

void	parse_map(const char *filename, t_map *map)
{
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	init_map(map);
	set_map_size(map, fd);
	close(fd);
	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	i = -1;
	while (++i < map->height)
		map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
	fd = open(filename, O_RDONLY);
	fill_points(fd, map);
	close(fd);
}
