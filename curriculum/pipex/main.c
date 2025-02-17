/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:36:58 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/17 15:37:44 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	heredoc;
	int	arg_num;

	if (argc == 1)
		error_exit("Wrong use of program", EXIT_FAILURE);
	heredoc = is_heredoc(argv[1]);
	if (heredoc)
		arg_num = 6;
	else
		arg_num = 5;
	if (argc < arg_num)
	{
		if (arg_num == 6)
			error_exit("Usage error: ./pipex here_doc \
					LIMITER cmd1 ... cmdN outfile", EXIT_FAILURE);
		else
			error_exit("Usage error: ./pipex infile \
					cmd1 ... cmdN outfile", EXIT_FAILURE);
	}
	pipex(argc, argv, envp);
}
