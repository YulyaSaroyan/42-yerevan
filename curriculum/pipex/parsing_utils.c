/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:20:13 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:25:16 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

void	in_quote_char(char c, char *buffer, int *j, int *i)
{
	if (c == '\\')
		++(*i);
	buffer[(*j)++] = c;
}

void	handle_space(char *buffer, int *j, char ***result, int *count)
{
	if (*j > 0)
	{
		buffer[*j] = '\0';
		(*result)[*count] = ft_strdup(buffer);
		(*count)++;
		*j = 0;
	}
}

void	handle_non_quote(int *in_quote, char *quote_char, char ch)
{
	*in_quote = 1;
	*quote_char = ch;
}

void	init_vars(char ***result, int *in_quote, char *quote_char, int idx[3])
{
	*result = malloc(256 * sizeof(char *));
	*in_quote = 0;
	*quote_char = 0;
	ft_bzero(idx, 3 * sizeof (int));
}
