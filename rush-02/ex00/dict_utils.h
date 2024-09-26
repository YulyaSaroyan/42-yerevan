/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict-utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:11:01 by ysaroyan          #+#    #+#             */
/*   Updated: 2024/09/22 21:19:51 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_UTILS_H
# define DICT_UTILS_H

int		alc_key_val(char ***temp_dict, int lines, char *key, char *value);
int		exp_dict_if_needed(char ***temp_dict, int *capacity, int lines);
void	increment_lines(int *lines);
char	*trim_spaces(char *str);
char	*find_colon(char *line);
int		add_key_value(char *key, char *value, int *lines, char ***temp_dict, int *capacity);

#endif
