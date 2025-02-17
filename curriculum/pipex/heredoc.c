/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:39:54 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:41:18 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_heredoc(char *arg)
{
	return (ft_strncmp(arg, "here_doc", 8) == 0 && ft_strlen(arg) == 8);
}

void	handle_heredoc(char **argv, int write_fd)
{
	char	*line;
	char	*delimiter;

	delimiter = argv[2];
	while (1)
	{
		ft_putstr_fd("heredoc>", STDIN_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			error_exit("Failed to read line", EXIT_FAILURE);
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
			&& line[ft_strlen(delimiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		free(line);
	}
	close(write_fd);
}
