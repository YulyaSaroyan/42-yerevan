/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:41:50 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/08 21:00:32 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid_color(char *color)
{
	int	i;
	size_t	len;

	len = ft_strlen(color);
	if (color[len - 1] == '\n')
	{
		color[len - 1] = '\0';
		--len;
	}
	if (!color || len == 8 || (color[0] != '0' || color[1] != 'x'))
		return (0);
	i = 2;
	while (color[i])
	{
		if (!(ft_isdigit(color[i]) ||
		      (color[i] >= 'A' && color[i] <= 'F') || 
		      (color[i] >= 'a' && color[i] <= 'f')))
			return (0);
		i++;
	}
	return (1);
}

void	validate_number(char *num, int nbr, char **columns, char *line)
{
	size_t len;

	len = ft_strlen(num);
	if (num[len - 1] == '\n')
		num[len - 1] = '\0';
	if ((num[0] != '0' && nbr == 0))
	{
		free(columns);
		free(line);
		throw_error("Invalid number.");
	}
}

void	validate_color( char **color_parts, char **columns, char *line)
{
	if (!is_valid_color(color_parts[1]))
	{
		free(color_parts);
		free(columns);
		free(line);
		throw_error("Invalid color.");
	}
}

void	validate_width(int current_width, int first_width, char *line)
{
	if (current_width != first_width)
	{
		free(line);
		throw_error("Invalid line width.");
	}
}
