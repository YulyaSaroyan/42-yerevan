/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:08:54 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:52:16 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_index(char **argv)
{
	int	i;
	int	heredoc;

	heredoc = is_heredoc(argv[1]);
	if (heredoc)
		i = 3;
	else
		i = 2;
	return (i);
}

void	close_fds_for_child(int fd[2], int outfile, int prev_infile)
{
	close(fd[0]);
	close(fd[1]);
	close(outfile);
	close(prev_infile);
}

void	close_fds_for_parent(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	init_indexes(int *i, int *j, char **argv)
{
	*i = get_index(argv);
	*j = *i;
}

void	handle_infile_fail(int	*infile)
{
	perror("pipex: input");
	*infile = open("/dev/null", O_RDONLY);
}
