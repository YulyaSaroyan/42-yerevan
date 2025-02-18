/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:21:23 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/18 15:35:59 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_for_children(int j, int argc, pid_t *pid)
{
	int	status;
	int	k;

	k = 0;
	while (j < argc - 1)
	{
		waitpid(pid[k++], &status, 0);
		++j;
	}
	free(pid);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

static void	handle_files(char **argv, int argc, int *outfile, int *prev_infile)
{
	int	infile;
	int	fd[2];
	int	heredoc;

	heredoc = is_heredoc(argv[1]);
	if (!heredoc)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			handle_infile_fail(&infile);
		*prev_infile = infile;
	}
	else
	{
		if (pipe(fd) == -1)
			error_exit("Failed to create pipe", EXIT_FAILURE);
		handle_heredoc(argv, fd[1]);
		*prev_infile = fd[0];
	}
	if (heredoc)
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile == -1)
		error_exit("pipex: output", EXIT_FAILURE);
}

static void	handle_redirection(int prev_infile,
		int is_not_last, int fd, int outfile)
{
	dup2(prev_infile, STDIN_FILENO);
	if (is_not_last)
		dup2(fd, STDOUT_FILENO);
	else
		dup2(outfile, STDOUT_FILENO);
}

static void	create_children(int fd[2], pid_t *pid)
{
	if (pipe(fd) == -1)
		error_exit("Failed to create pipe", EXIT_FAILURE);
	*pid = fork();
	if (*pid == -1)
		error_exit("Failed to fork", EXIT_FAILURE);
}

void	pipex(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		outfile;
	int		idx[2];
	int		prev_infile;
	pid_t	*pid;

	pid = malloc(sizeof(pid_t) * (argc - 2));
	handle_files(argv, argc, &outfile, &prev_infile);
	init_indexes(&idx[0], &idx[0], argv);
	while (idx[0] < argc - 1)
	{
		create_children(fd, &pid[idx[0] - idx[1]]);
		if (pid[idx[0] - idx[1]] == 0)
		{
			free(pid);
			handle_redirection(prev_infile, idx[0] < argc - 2, fd[1], outfile);
			close_fds_for_child(fd, outfile, prev_infile);
			execute_cmd(argv[idx[0]], envp);
		}
		close_fds_for_parent(prev_infile, fd[1]);
		prev_infile = fd[0];
		++idx[0];
	}
	close_fds_for_parent(outfile, fd[0]);
	wait_for_children(idx[1], argc, pid);
}
