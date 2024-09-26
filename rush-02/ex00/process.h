/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:22:00 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/22 21:25:26 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

int		process_chunk(char *buffer, int bytes_read, int *lines, int *capacity, char ***temp_dict);
int		read_chunks(int fd, char *buffer, int *lines, int *capacity, char ***temp_dict);
int		parse_line(char *line, int *lines, char ***temp_dict, int *capacity);

#endif
