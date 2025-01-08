/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:09:28 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/22 21:24:20 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define INITIAL_LINES 10
# define CHUNK_SIZE 1024

int		open_file(char *filename);
int		parse_dict(char *filename, char ***dict, int *line_count);

#endif
