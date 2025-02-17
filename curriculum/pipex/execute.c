/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:30:56 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:33:42 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*build_exec_path(char *path_var, char *cmd)
{
	int		i;
	char	**paths;
	size_t	len;
	char	*full_path;

	i = 0;
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		len = ft_strlen(paths[i]) + ft_strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
			break ;
		concat_path(full_path, cmd, paths[i], len);
		if (access(full_path, X_OK) == 0)
			return (confirm_access(paths, full_path));
		free(full_path);
		i++;
	}
	free_splitted(paths);
	return (NULL);
}

static char	*find_executable(char *cmd, char **envp)
{
	char	*path_var;
	char	*full_path;
	int		i;

	path_var = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_var = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!path_var)
		return (NULL);
	full_path = build_exec_path(path_var, cmd);
	return (full_path);
}

static char	*get_cmd(char ***splitted, char *cmd, int *free_needed, char **envp)
{
	char	*executable;

	*splitted = split_command(cmd);
	if (!*splitted || !*splitted[0])
		error_exit("Failed to split command", EXIT_FAILURE);
	if (ft_strchr(*splitted[0], '/'))
		executable = *splitted[0];
	else
	{
		executable = find_executable(*splitted[0], envp);
		*free_needed = 1;
	}
	if (!executable)
	{
		free_splitted(*splitted);
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	return (executable);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**splitted;
	char	*executable;
	int		free_needed;

	free_needed = 0;
	executable = get_cmd(&splitted, cmd, &free_needed, envp);
	if (access(executable, X_OK) == -1)
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putstr_fd(executable, 2);
		ft_putstr_fd("\n", 2);
		exit(126);
	}
	execve(executable, splitted, envp);
	free_splitted(splitted);
	if (free_needed)
		free(executable);
	error_exit("Failed to execute", 127);
}
