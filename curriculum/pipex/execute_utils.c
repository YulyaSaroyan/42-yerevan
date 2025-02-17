/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:33:57 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:45:22 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message, int error_code)
{
	perror(message);
	exit(error_code);
}

void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

void	concat_path(char *full_path, char *cmd, char *path, size_t len)
{
	ft_strlcpy(full_path, path, len);
	ft_strlcat(full_path, "/", len);
	ft_strlcat(full_path, cmd, len);
}

char	*confirm_access(char **paths, char *full_path)
{
	free_splitted(paths);
	return (full_path);
}
