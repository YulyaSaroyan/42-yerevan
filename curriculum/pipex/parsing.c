/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:15:24 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:47:58 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	finalize_word(char *buffer, int *buf_idx,
		char ***result, int *count)
{
	if (*buf_idx > 0)
	{
		buffer[*buf_idx] = '\0';
		(*result)[(*count)++] = ft_strdup(buffer);
		*buf_idx = 0;
	}
}

static void	handle_split_logic(int idx[3], char *buffer,
		char *str, char ***result)
{
	int		in_quote;
	char	quote_char;

	init_vars(result, &in_quote, &quote_char, idx);
	while (str[idx[0]])
	{
		if (is_quote(str[idx[0]]))
		{
			if (in_quote && str[idx[0]] == quote_char)
				in_quote = 0;
			else if (!in_quote)
				handle_non_quote(&in_quote, &quote_char, str[idx[0]]);
			else if (quote_char != str[idx[0]] && is_quote(str[idx[0]]))
				in_quote_char(str[idx[0]], buffer, &idx[1], &idx[0]);
		}
		else if (!in_quote && ft_isspace(str[idx[0]]))
			handle_space(buffer, &idx[1], result, &idx[2]);
		else
		{
			if (str[idx[0]] == '\\')
				++idx[0];
			buffer[idx[1]++] = str[idx[0]];
		}
		++idx[0];
	}
}

char	**split_command(char *str)
{
	char	**result;
	int		idx[3];
	char	buffer[1024];

	handle_split_logic(idx, buffer, str, &result);
	finalize_word(buffer, &idx[1], &result, &idx[2]);
	result[idx[2]] = NULL;
	return (result);
}
