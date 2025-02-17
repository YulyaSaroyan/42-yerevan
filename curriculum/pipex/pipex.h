/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:16:14 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:49:14 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

void	handle_infile_fail(int	*infile);
void	init_indexes(int *i, int *j, char **argv);
void	close_fds_for_parent(int fd1, int fd2);
void	close_fds_for_child(int fd[2], int outfile, int prev_infile);
void	error_exit(char *message, int error_code);
int		is_heredoc(char *arg);
void	handle_heredoc(char **argv, int write_fd);
char	*confirm_access(char **paths, char *full_path);
void	concat_path(char *full_path, char *cmd, char *path, size_t len);
void	free_splitted(char **splitted);
void	init_vars(char ***result, int *in_quote, char *quote_char, int idx[3]);
void	handle_non_quote(int *in_quote, char *quote_char, char ch);
void	handle_space(char *buffer, int *j, char ***result, int *count);
void	in_quote_char(char c, char *buffer, int *j, int *i);
int		is_quote(char c);
void	execute_cmd(char *cmd, char **envp);
char	**split_command(char *str);
void	pipex(int argc, char **argv, char **envp);

#endif
