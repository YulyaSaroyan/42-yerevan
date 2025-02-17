/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:04:49 by ysaroyan          #+#    #+#             */
/*   Updated: 2025/02/09 20:22:50 by ysaroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

void	validate_color(char **color_parts, char **columns, char *line);
void	validate_number(char *num, int nbr, char **columns, char *line);
void	validate_width(int current_width, int first_width, char *line);
void	validate_file_extension(char *filename);

#endif
